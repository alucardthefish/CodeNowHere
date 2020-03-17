// **************************************************************************** 
// File: ICommandBehaviorTest.h 
// Author: alucardthefish 
// Created: Mon Mar 16 23:35:50 2020 
// Description:  
// **************************************************************************** 

#include <string>

#include "../headers/ICommandBehavior.h"
#include "../headers/OnlyFileBehavior.h"

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

INSTANTIATE_TEST_SUITE_P(CommandBehavior, ICommandBehaviorTest, Values(&CreateOnlyFile, &CreateTestBehavior));


} //namespace
