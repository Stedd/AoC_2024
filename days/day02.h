//
// Created by stedd on 02.12.24.
//

#ifndef DAY02_H
#define DAY02_H
#include <vector>


class day02
{
public:
	static void Calculate();

	static bool IsSafe(const std::vector<int>& numbers,bool secondPass);

	static int SafetyChecks(int current, int previous, bool increasing, bool decreasing);
};

#endif //DAY02_H
