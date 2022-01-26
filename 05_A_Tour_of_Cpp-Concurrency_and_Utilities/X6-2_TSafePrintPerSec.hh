#ifndef TSAFEPRINTPERSEC_HH
#define TSAFEPRINTPERSEC_HH


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>


// multiple threads accessing cout can cause race conditions that interleave output
// C++20 provides osyncstream, but one can use a custom solution, see:
//   - https://stackoverflow.com/a/53288135


class TSafePrintPerSec {
private:
	// static to ensure all instances accross all threads share the mutex, see:
	//   - https://stackoverflow.com/a/18277334
	static std::mutex _tspps_mtx;
public:
	TSafePrintPerSec() {}
	~TSafePrintPerSec() {}

	void operator()(std::string &s, int reps) {
		for (int i = 0; i < reps; ++i) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			// lock_guard and relying on unlock in mutex destructor
			//   prevents the need for explicit _tspps_mtx.lock()
			//   and .unlock() calls, see:
			//   - https://stackoverflow.com/a/35252160
			std::lock_guard<std::mutex> lock(_tspps_mtx);
			std::cout << s << std::endl;
		}
	}

	void operator()(const char *s, int reps) const {
		for (int i = 0; i < reps; ++i) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::lock_guard<std::mutex> lock(_tspps_mtx);
			std::cout << s << std::endl;
		}
	}
};


// static attributes must be declared in a scope where all can access them
std::mutex TSafePrintPerSec::_tspps_mtx/*{}*/;


#endif /* TSAFEPRINTPERSEC_HH */
