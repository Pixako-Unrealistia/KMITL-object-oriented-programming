#include "ex03_header.hpp"
#include "random.hpp"

int main()
{
	constexpr double rnd_min = 0, rnd_max = 640;
	Rand_double rnd{rnd_min, rnd_max};
	std::random_device rd;
	rnd.seed(rd());

	
	constexpr double rng_min = 0, rng_max = 480;
	Rand_double rng{rng_min, rng_max};
	rng.seed(rd());



	std::cout << std::fixed << std::setprecision(5);

	int N;
	std::cin >> N;

	std::cout << "<svg width=\"640\" height=\"480\" xmlns=\"http://www.w3.org/2000/svg\"><rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" /><circle cx=\"220\" cy=\"240\" r=\"200\"stroke=\"black\" stroke-width=\"2\" fill=\"#8080FF80\" /><circle cx=\"420\" cy=\"240\" r=\"200\"stroke=\"black\" stroke-width=\"2\" fill=\"#8080FF80\" />";

	for (int i = 0; i < N; ++i)
	{
		double x = rnd();
		double y = rng();

		if (x < 320)
		{
			if (std::sqrt(std::pow(x - 220, 2) + std::pow(y - 240, 2)) <= 200)
			{
				if (std::sqrt(std::pow(x - 420, 2) + std::pow(y - 240, 2)) <= 200)
				{
					std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"5\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />";
				} 
				else
				{
					std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"5\" stroke=\"black\" stroke-width=\"1\" fill=\"red\" />";
				}
			}
			else
			{
				std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"5\" stroke=\"black\" stroke-width=\"1\" fill=\"green\" />";
			}
		}
		else
		{
			if (std::sqrt(std::pow(x - 420, 2) + std::pow(y - 240, 2)) <= 200)
			{
				if (std::sqrt(std::pow(x - 220, 2) + std::pow(y - 240, 2)) <= 200)
				{
					std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"5\" stroke=\"black\" stroke-width=\"1\" fill=\"blue\" />";
				}
				else
				{
				std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"5\" stroke=\"black\" stroke-width=\"1\" fill=\"yellow\" />";
				}
			}
			else
			{
				std::cout << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"5\" stroke=\"black\" stroke-width=\"1\" fill=\"green\" />";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "</svg>" << std::endl;
	return 0;
}