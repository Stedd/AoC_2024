//
// Created by stedd on 01.12.24.
//

#include "day01.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>


void day01::Calculate()
{
	std::vector<int> col1;
	std::vector<int> col2;
	std::unordered_map<int, int> occurrence_map;
	int totalDistance = 0;
	int similarityScore = 0;

	size_t estimated_size = 1000;
	col1.reserve(estimated_size);
	col2.reserve(estimated_size);
	occurrence_map.reserve(estimated_size);

	std::ifstream input("input/challenges.txt");

	if (!input)
	{
		std::cerr << "Failed to open input file." << std::endl;
		std::cout << "Current path is " << std::filesystem::current_path() << '\n';

		return;
	}

	int num1, num2;
	while (input >> num1 >> num2)
	{
		col1.emplace_back(num1);
		col2.emplace_back(num2);
		occurrence_map[num2]++;
	}

	std::sort(col1.begin(), col1.end());
	std::sort(col2.begin(), col2.end());

	for (size_t i = 0; i < col1.size(); i++)
	{
		totalDistance += std::abs(col1[i] - col2[i]);
		similarityScore += col1[i] * occurrence_map[col1[i]];
	}

	printf("Total distance: %d\n", totalDistance);
	printf("Similarity score: %d\n", similarityScore);
}

//Correct answers:
//part1: 1889772
//part2: 23228917
