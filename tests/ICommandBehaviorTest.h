// ****************************************************************************
// File: ICommandBehaviorTest.h
// Author: alucardthefish
// Created: Mon Mar 16 23:35:50 2020
// Description:
// ****************************************************************************

#include <string>

#include "../headers/ICommandBehavior.h"
#include "../headers/OnlyFileBehavior.h"
#include "../headers/cnh_structs.h"
#include "../headers/cnhengine.h"

#include "gtest/gtest.h"

class TestBehavior : public ICommandBehavior
{
    public:
    TestBehavior() {}
    void CreateCode() {
        std::cout << "In TestBehavior CreateCode" << std::endl;
    }
};

namespace {

using ::testing::TestWithParam;
using ::testing::Values;


typedef ICommandBehavior* CreateICommandBehaviorFunc();

ICommandBehavior* CreateOnlyFile() {
    return new OnlyFileBehavior();
}

ICommandBehavior* CreateTestBehavior() {
    return new TestBehavior();
}

class ICommandBehaviorTest : public TestWithParam<CreateICommandBehaviorFunc*> {
    public:
        ~ICommandBehaviorTest() override { delete behavior_; }
        void SetUp() override { behavior_ = (*GetParam())(); }
        void TearDown() override {
            delete behavior_;
            behavior_ = nullptr;
        }

    protected:
        ICommandBehavior* behavior_;
};


TEST_P(ICommandBehaviorTest, ReturnsNameOfLanguage) {
    EXPECT_EQ("java", behavior_->getLang("file.java"));
    EXPECT_EQ("java", behavior_->getLang("file.j"));
    EXPECT_EQ("python", behavior_->getLang("file.py"));
    EXPECT_EQ("picat", behavior_->getLang("file.pi"));
}


TEST_P(ICommandBehaviorTest, ReturnsTrueIfUnknowFileNameExtension) {
    EXPECT_TRUE(behavior_->getLang("file.javancer").empty());
    EXPECT_TRUE(behavior_->getLang("file.pythoniza").empty());
}

TEST_P(ICommandBehaviorTest, OptionThisTestFeeding) {
    // Simulating a feeding data from CLI option this
    cnh::arguments testArgs = cnh::initForOptionThis("sample.test", "Joe", "No desc", false);
    behavior_->feed(testArgs);
    EXPECT_EQ("sample.test", behavior_->fileName);
    EXPECT_EQ("Joe", behavior_->author);
    EXPECT_EQ("No desc", behavior_->description);
    EXPECT_EQ(false, behavior_->hasCopyRight);
}

TEST_P(ICommandBehaviorTest, OptionTheseTestFeeding) {
    // Simulating a feeding data from CLI option these
    std::vector<std::string> testFiles = {"samp1.test", "samp2.test", "samp3.test"};
    cnh::arguments testArgs = cnh::initForOptionThese(testFiles, "Mike", true);
    behavior_->feed(testArgs);
    EXPECT_EQ(testFiles, behavior_->fileNames);
    EXPECT_EQ("Mike", behavior_->author);
    EXPECT_EQ(true, behavior_->hasCopyRight);
}

TEST_P(ICommandBehaviorTest, OptionBunchTestFeeding) {
    // Simulating a feeding data from CLI option bunchof
    cnh::arguments testArgs = cnh::initForOptionBunch(4, ".php", "Donald", false);
    behavior_->feed(testArgs);
    EXPECT_EQ(4, behavior_->numOfFiles);
    EXPECT_EQ("Donald", behavior_->author);
    EXPECT_EQ(".php", behavior_->bunchExt);
    EXPECT_EQ(false, behavior_->hasCopyRight);
}

TEST_P(ICommandBehaviorTest, ReturnTrueIfFoundComment) {
    behavior_->blowCommentByExtensions(".cpp");
    EXPECT_TRUE(!behavior_->comment.empty());
    EXPECT_EQ("//", behavior_->comment);
    behavior_->blowCommentByExtensions(".go");
    EXPECT_TRUE(!behavior_->comment.empty());
    EXPECT_EQ("//", behavior_->comment);
    behavior_->blowCommentByExtensions(".py");
    EXPECT_TRUE(!behavior_->comment.empty());
    EXPECT_EQ("#", behavior_->comment);
    behavior_->blowCommentByExtensions(".css");
    EXPECT_TRUE(!behavior_->comment.empty());
    EXPECT_EQ("/*", behavior_->comment);
    behavior_->blowCommentByExtensions(".java");
    EXPECT_TRUE(!behavior_->comment.empty());
    EXPECT_EQ("//", behavior_->comment);
    behavior_->blowCommentByExtensions(".cs");
    EXPECT_TRUE(!behavior_->comment.empty());
    EXPECT_EQ("//", behavior_->comment);
}

TEST_P(ICommandBehaviorTest, LoadArgsToCNHEngine) {
    // Set up the necessary data
    behavior_->fileName = "testfile.txt";
    behavior_->author = "Test Author";
    behavior_->description = "Test Description";
    behavior_->hasCopyRight = true;
    behavior_->year = 2025;
    behavior_->comment = "//";
    behavior_->commentClosureOpt = "*/";

    // Call the method
    behavior_->loadArgsToCNHEngine();
    behavior_->engine.LoadDataValue("cnh_date", "2025-03-09"); // Avoid using dateOfCreation to avoid time issues

    // Verify that the data has been correctly loaded into the CnhEngine instance
    EXPECT_EQ(behavior_->engine.GetValue("cnh_file"), "testfile.txt");
    EXPECT_EQ(behavior_->engine.GetValue("cnh_name"), "Test Author");
    EXPECT_EQ(behavior_->engine.GetValue("cnh_date"), "2025-03-09");
    EXPECT_EQ(behavior_->engine.GetValue("cnh_description"), "Test Description");
    EXPECT_EQ(behavior_->engine.GetValue("cnh_has_copyright"), "Copyright (C) 2025 Test Author. All rights reserved.");
    EXPECT_EQ(behavior_->engine.GetValue("cnh_comment"), "//");
    EXPECT_EQ(behavior_->engine.GetValue("cnh_comment_closure"), "*/");
}

TEST_P(ICommandBehaviorTest, WriteFile) {
    // Set up the necessary data
    string fileName = "testfile.py";
    behavior_->fileName = fileName;
    behavior_->author = "Anderson";
    behavior_->description = "Test Description 2";
    behavior_->hasCopyRight = true;
    behavior_->year = 2025;

    // Call the WriteFile method
    behavior_->WriteFile();

    // Verify the contents of the file
    std::ifstream file(fileName);
    ASSERT_TRUE(file.is_open());

    std::string py_comment_decorator = "# **************************************************************************************************************";
    std::string py_filename = "# File: testfile.py";
    std::string py_author = "# Author: Anderson";
    std::string py_created = "# Created: ";
    std::string py_description = "# Description: Test Description 2";
    std::string py_copyright = "# Copyright (C) 2025 Anderson. All rights reserved.";
    std::string py_main_1 = "def main():";
    std::string py_main_2 = "    print(\"Hello World!\")";
    std::string py_main_3 = "if __name__ == \"__main__\":";
    std::string py_main_4 = "    main()";

    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, py_comment_decorator);

    std::getline(file, line);
    EXPECT_EQ(line, py_filename);

    std::getline(file, line);
    EXPECT_EQ(line, py_author);

    // Created line skiped
    std::getline(file, line);

    std::getline(file, line);
    EXPECT_EQ(line, py_copyright);

    std::getline(file, line);
    EXPECT_EQ(line, py_description);

    std::getline(file, line);
    EXPECT_EQ(line, py_comment_decorator);

    // 2 new lines
    std::getline(file, line);
    std::getline(file, line);

    std::getline(file, line);
    EXPECT_EQ(line, py_main_1);

    std::getline(file, line);
    EXPECT_EQ(line, py_main_2);

    // 2 new lines
    std::getline(file, line);
    std::getline(file, line);

    std::getline(file, line);
    EXPECT_EQ(line, py_main_3);

    std::getline(file, line);
    EXPECT_EQ(line, py_main_4);

    file.close();

    // Clean up the temporary files
    std::remove("testfile.py");
}

INSTANTIATE_TEST_SUITE_P(CommandBehavior, ICommandBehaviorTest, Values(&CreateOnlyFile, &CreateTestBehavior));


} //namespace
