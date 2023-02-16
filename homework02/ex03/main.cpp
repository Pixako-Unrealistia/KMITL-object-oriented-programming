#include "ex03_header.hpp"
#include "random.hpp"

int main()
{
	constexpr double rnd_min = -1.0, rnd_max = 1.0;
	Rand_double rnd{rnd_min, rnd_max};
	std::random_device rd;
	rnd.seed(rd());
	std::cout << std::fixed << std::setprecision(5);

	int N;
	std::cin >> N;

	std::cout << "<svg width=\"500\" height=\"500\" xmlns=\"http://www.w3.org/2000/svg\"><rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" /><circle cx=\"250\" cy=\"250\" r=\"250\"stroke=\"black\" stroke-width=\"2\" fill=\"none\" />";

	for (int i = 0; i < N;)
	{
		double x = rnd();
		double y = rnd();

		if (x * x + y * y <= 1)
		{
			std::cout << "<circle cx=\"" << 250 + 250 * x << "\" cy=\"" << 250 + 250 * y << "\" r=\"10\" fill=\"#00FFFF\" />" << std::endl;
			i++;
		}
		//else
		//	std::cout << "<circle cx=\"" << 250 + 250 * x << "\" cy=\"" << 250 + 250 * y << "\" r=\"10\" fill=\"#F8C8DC\" />" << std::endl;

	}

	std::cout << "</svg>" << std::endl;
	return 0;

}