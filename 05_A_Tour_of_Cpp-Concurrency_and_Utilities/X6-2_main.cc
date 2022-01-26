#include "X6-2_TSafePrintPerSec.hh"
#include <thread>


int main() {
	TSafePrintPerSec tspps1, tspps2;

	// std::thread can be created with function pointers or functors (with
	//   operator() overload,) and their parameters as an intializer list
	std::thread t1 {tspps1, "hello", 50};
	std::thread t2 {tspps2, "world!", 50};

	t1.join();
	t2.join();

}
