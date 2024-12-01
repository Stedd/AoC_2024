#include <chrono>
#include <iostream>

#include "days/day01.h"

int main()
{
	double lowest = 10000;
	double totalTime = 0;
	constexpr int cycles = 10000;
	for (int i = 1; i <= cycles; i++)
	{
		const auto startTime = std::chrono::high_resolution_clock::now();
		day01::Part2();
		const auto endTime = std::chrono::high_resolution_clock::now();
		const std::chrono::duration<double> diff = endTime - startTime;

		totalTime += diff.count();
		if (diff.count() < lowest)
		{
			lowest = diff.count();
		}
	}
	const double average = totalTime / cycles;
	std::cout << "Execution time avg: " << average * 1e6 << " μs. Lowest: " << lowest * 1e6 << " μs" << std::endl;
}
