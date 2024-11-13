#include <iostream>

double fastInverseSQRT(double num) // can have error of 1%
{
	const float threeHalfs = 1.5f;
	double x2 = num * 0.5;
	double y = num;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threeHalfs - (x2 * y * y));

	return y;
}

// does not work
int main() { std::cout << fastInverseSQRT(10.0) << '\n'; }
