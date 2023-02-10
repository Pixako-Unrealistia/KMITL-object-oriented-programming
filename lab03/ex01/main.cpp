#include "header_chan.hpp"

int main()
{
	std::vector<double> vec{2,1,4,3,7};
	std::vector<double> neg_vec{-1,1,0,-3,7};

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	lshift(vec, 3);

	std::cout << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	rshift(vec, 4);

	std::cout << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl << "NEGATIVE" << std::endl;
	
	for (int i = 0; i < neg_vec.size(); i++)
	{
		std::cout << neg_vec[i] << " ";
	}

	std::cout << std::endl;

	remove_negative(neg_vec);

	for (int i = 0; i < neg_vec.size(); i++)
	{
		std::cout << neg_vec[i] << " ";
	}

	std::cout << std::endl;

	std::vector<double> vec3 = scale(add(vec, vec), 1.2);
	for (int i = 0; i < vec3.size(); i++)
	{
		std::cout << vec3[i] << " ";
	}

	std::cout << std::endl << "LISTTTT" << std::endl;

	std::list<double> list{ 1,-1,0,3,-7 };
	for (auto i : list)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	remove_negative_list(list);
	for (auto i : list)
	{
		std::cout << i << " ";
	}

}