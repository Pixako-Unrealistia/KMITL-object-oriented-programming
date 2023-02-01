//The pseudo-pseudo code!!!

//steal lab1's q4 header and initialiser
//prompt user for N
//loop N times -> generate random number -> difference between random number and 0.5 -> square -> add to sum
//calculate mse -> print mse.



//The code!

#include "random.hpp"
#include <iomanip>
#include <iostream>
#include <vector>


int main()
{
constexpr double rnd_min = 0.0, rnd_max = 1.0;
Rand_double rnd{rnd_min, rnd_max};
std::random_device rd;
rnd.seed(rd());
std::cout << std::fixed << std::setprecision(5);

double mean_square_error = 0.0;
double sum_square = 0.0;
double drawn_against = 0.5;

std::cout << "N = ";
int N;
std::cin >> N;

//The above looks familiar :OO

for (int i = 0; i < N; ++i)
{
	double x = rnd();
	sum_square += (drawn_against - x) * (drawn_against - x);
	//std::cout << x << std::endl;
}
mean_square_error = sum_square / N;
std::cout << "Mean square error = " << mean_square_error << std::endl;
return 0;
}





//Now you maybe wondering;
//why didn't I use namespace std like ex02?
//since the upper half of the code is pulled out of lab1's
//I just go with the convention of that code :D:D:D:D:D

