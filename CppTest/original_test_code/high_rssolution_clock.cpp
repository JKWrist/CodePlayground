#include <iostream>
#include <chrono>
#include <thread>
 
void timed_piece_of_code() 
{
		std::chrono::milliseconds simulated_work(2);
		std::this_thread::sleep_for(simulated_work);
}
 
int main() 
{
		auto start = std::chrono::high_resolution_clock::now();
 
		std::cout << "Running some timed piece of code..." << '\n';
		timed_piece_of_code();
 
		auto stop = std::chrono::high_resolution_clock::now();
 
		// A floating point milliseconds type
		using FpMilliseconds = std::chrono::duration<float, std::chrono::milliseconds::period>;
 
		static_assert(std::chrono::treat_as_floating_point<FpMilliseconds::rep>::value, 
									"Rep required to be floating point");
 
		// Note that implicit conversion is not allowed here    
		auto i_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
 
		// Note that implicit conversion is allowed here
		auto f_ms = FpMilliseconds(stop - start);
 
		std::cout << "Time in milliseconds, using default rep: "
							<< i_ms.count() << '\n';
 
 
		std::cout << "Time in milliseconds, using floating point rep: "
							<< f_ms.count() << '\n';
 
}