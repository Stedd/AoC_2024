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

/*
--- Day 2: Red-Nosed Reports ---

Fortunately, the first location The Historians want to search isn't a long walk from the Chief Historian's office.

While the Red-Nosed Reindeer nuclear fusion/fission plant appears to contain no sign of the Chief Historian, the
engineers there run up to you as soon as they see you. Apparently, they still talk about the time Rudolph was saved
through molecular synthesis from a single electron.

They're quick to add that - since you're already here - they'd really appreciate your help analyzing some unusual data
from the Red-Nosed reactor. You turn to check if The Historians are waiting for you, but they seem to have already
divided into groups that are currently searching every corner of the facility. You offer to help with the unusual data.

The unusual data (your puzzle input) consists of many reports, one report per line. Each report is a list of numbers
called levels that are separated by spaces. For example:

7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9

This example data contains six reports each containing five levels.

The engineers are trying to figure out which reports are safe. The Red-Nosed reactor safety systems can only
tolerate levels that are either gradually increasing or gradually decreasing. So, a report only counts as safe if
both of the following are true:

    The levels are either all increasing or all decreasing.
    Any two adjacent levels differ by at least one and at most three.

In the example above, the reports can be found safe or unsafe by checking those rules:

    7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
    1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
    9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
    1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
    8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
    1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.

So, in this example, 2 reports are safe.

Analyze the unusual data from the engineers. How many reports are safe?

 */

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
		if (IsSafe(line))
		{
			safeReports++;
		}
	}
	std::cout << safeReports << '\n';
}

bool day02::IsSafe(const std::string &line)
{
	std::istringstream iss(line);
	std::vector<int> numbers(std::istream_iterator<int>{iss}, std::istream_iterator<int>());
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

		if (SafetyChecks(currentNumber, previousNumber, increasing, decreasing) == 1)
		{
			// numbers.erase(numbers.begin() + i);
			// if (i + 1 < numbers.size())
			// {
			// 	previousNumber = numbers.at(i + 1);
			// } else
			// {
			// 	printf("wtf do i do here?");
			// }
			// //currentNumber = numbers.at(i);
			// if (SafetyChecks(currentNumber, previousNumber, increasing, decreasing) == 1)
			// {
			safe = false;
			return false;
			// }
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
