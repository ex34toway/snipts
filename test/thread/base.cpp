#include <iostream>


#include <gtest/gtest.h>
#include <boost/thread/thread.hpp>

void hello()
{
	std::cout<<"Hello world,I'm a thread"<<std::endl;
}

TEST(helloTest,helloThread)
{
	boost::thread thrd(&hello);
	thrd.join();
	fgetc(stdin);
}
