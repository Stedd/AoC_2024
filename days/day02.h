//
// Created by stedd on 02.12.24.
//

#ifndef DAY02_H
#define DAY02_H
#include <string>


class day02
{
public:
	static void Calculate();

	static bool IsSafe(const std::string &line);

	static int SafetyChecks(int current, int previous, bool increasing, bool decreasing);
};

#endif //DAY02_H
