#include <boost/atomic.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class spinlock
{
public:
	spinlock(): state_(Unlocked){}
	void lock(){
		while (state_.exchange(Locked,boost::memory_order_acquire) == Locked)
		{
			/** busy wait*/
		}
		atomic_thread_fence(boost::memory_order_acquire);
	}

	void unlock(){
		state_.store(Unlocked,boost::memory_order_release);
	}

private:
	typedef enum {
		Locked,
		Unlocked
	} LockState;
	boost::atomic<LockState> state_;
};

int main()
{
	spinlock s;
	s.lock();
	boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(5));
	s.unlock();
	boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(5));
}
