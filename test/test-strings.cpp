#include <gtest/gtest.h>
#include <stdlib.h>
#include <string>
#include "strings.h"

class test_strings : public ::testing::Test{
  protected:
    test_strings(){}
    virtual ~test_strings(){}
    virtual void SetUp(){
      puts("SetUp...");
    }
    virtual void TearDown(){
      puts("TearDown...");
    }
};

TEST(test_strings,ends_with)
{
  SetUp();
  std::string fileName = "liliang";
  std::string fix = "txt";
  std::vector<std::string> vct = {"li","liliang"};
  //::snipts_util::JoinStrings(vct,",",&fix);
  ASSERT_TRUE(::snipts_util::starts_with("liliang","li"));
  TearDown();
}

