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

INSTANTIATE_TEST_SUITE_P(CommandBehavior, ICommandBehaviorTest, Values(&CreateOnlyFile, &CreateTestBehavior));


} //namespace
