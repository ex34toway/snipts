#include <gtest/gtest.h>
#include <boost/thread/thread.hpp>
#include <boost/noncopyable.hpp>

class ClassThread;

class ClassThread : public boost::noncopyable
{
public:
	void hello()
	{
		std::cout<<"Hello world,I'm a thread"<<std::endl;
	}
	static void start()
	{
		boost::thread thrd(boost::bind(&ClassThread::hello,&ClassThread::getInstance()));
	}
	static ClassThread& getInstance()
	{
		if(!instance)
			instance = new ClassThread;
		return *instance;
	}

private:
	ClassThread(){}
	static ClassThread* instance;
};

ClassThread* ClassThread::instance = 0;

TEST(ClassThreadTest,startTest)
{
	ClassThread::start();
}
