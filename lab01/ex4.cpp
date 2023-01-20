//// lab1_3.cpp
#include "random.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
template<typename T_>
inline constexpr
T_ pi_v{3.141592653589793238462643383279502884L};
inline constexpr double pi = pi_v<double>;
int main()
{
constexpr double rnd_min = -1.0, rnd_max = 1.0;
Rand_double rnd{rnd_min, rnd_max};
std::random_device rd;
rnd.seed(rd());
std::cout << std::fixed << std::setprecision(5);

std::cout << "Set N = ";
int N;
std::cin >> N;
double newN = 0.0;



for (int i = 0; i < N; ++i)
{
	double x = rnd();
	double y = rnd();
	double d = std::sqrt(x * x + y * y);
	if (d <= 1 && d >= -1)
	{
		newN += 1.0;
	}
}

double estimated_pi = 4 * newN / N;

std::cout << "Approximation = " << estimated_pi << " Relative error of " <<  pi - estimated_pi << "Percentage error of" << 100.0 - (estimated_pi * 100.0 / pi) << "%" << std::endl;

return 0;
}