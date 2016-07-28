#include <gtest/gtest.h>

#include "foo.h"

TEST(foo,max)
{
	EXPECT_EQ(-1,max(2,-1));
}


int main(int argc,char* argv[])
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
