#include <chrono>
#include <iostream>

#include "days/day01.h"

int main()
{
	const auto startTime = std::chrono::high_resolution_clock::now();
	day01::Run();
	const auto endTime = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<double> diff = endTime - startTime;
	std::cout << "Execution time: " << diff.count() * 1e6 << " μs" << std::endl;
}
