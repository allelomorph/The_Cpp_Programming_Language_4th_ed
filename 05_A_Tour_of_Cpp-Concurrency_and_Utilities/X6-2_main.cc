#include "X6-2_TSafePrintPerSec.hh"
#include <thread>


// Using direct manipulation of threads and mutexes as in sections 5.3.1-5.3.3,
//   as there is no need for the two printing threads to communicate. Otherwise,
//   one could use the future/promise/packaged_task STL idioms in 5.3.5.x


int main() {
	TSafePrintPerSec tspps1, tspps2;

	// std::thread can be created with function pointers or functors (with
	//   operator() overload,) and their parameters as an intializer list
	std::thread t1 {tspps1, "hello", 50};
	std::thread t2 {tspps2, "world!", 50};

	t1.join();
	t2.join();

}
