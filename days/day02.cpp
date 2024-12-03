//
// Created by stedd on 02.12.24.
//

#include "day02.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

void day02::Calculate()
{
	//std::ifstream input("input/day02short.txt");
	std::ifstream input("input/day02.txt");

	if (!input)
	{
		std::cerr << "Failed to open input file." << std::endl;
		std::cout << "Current path is " << std::filesystem::current_path() << '\n';

		return;
	}

	int safeReports = 0;
	for (std::string line; std::getline(input, line, '\n');)
	{
		std::istringstream iss(line);
		std::vector numbers(std::istream_iterator<int>{iss}, std::istream_iterator<int>());
		if (IsSafe(numbers, false))
		{
			safeReports++;
		}
	}
	std::cout << safeReports << '\n';
}

bool day02::IsSafe(const std::vector<int> &numbers, const bool secondPass)
{
	int previousNumber = numbers.at(numbers.size() - 1);
	bool increasing = false;
	bool decreasing = false;
	bool safe = true;
	for (int i = numbers.size() - 2; i >= 0; i--)
	{
		const int currentNumber = numbers.at(i);

		if (i == numbers.size() - 2)
		{
			if (previousNumber < currentNumber)
			{
				increasing = true;
			}
			if (previousNumber > currentNumber)
			{
				decreasing = true;
			}
		}

		if (SafetyChecks(currentNumber, previousNumber, increasing, decreasing) == 1 && !secondPass)
		{

			if (IsSafe(numbers, true))
			{
				safe = false;
				return false;
			}
		}

		previousNumber = currentNumber;
	}
	if (safe)
	{
		return true;
	}
	return false;
}

int day02::SafetyChecks(const int current, const int previous, const bool increasing, const bool decreasing)
{
	const int diff = abs(current - previous);
	if (previous > current && increasing)
	{
		return 1;
	}
	if (previous < current && decreasing)
	{
		return 1;
	}
	if (current == previous)
	{
		return 1;
	}
	if (diff < 1 || diff > 3)
	{
		return 1;
	}
	//safe
	return 0;
}
