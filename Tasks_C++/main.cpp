#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tasks.h"

int get_count(int prev_level, int n) 
{
	if (0 == n)
		return 1;

	int count = 0;
	for (int level = 1; level < prev_level; level++) 
	{
		if ((n - level) < 0)
			break;
		count += get_count(level, n - level);
	}

	return count;
}

int main() {
	std::ifstream in("../INPUT.txt");
	std::ofstream out("../OUTPUT.txt");
	int n, count = 0;
	in >> n;
	out << get_count(n + 1, n);
}