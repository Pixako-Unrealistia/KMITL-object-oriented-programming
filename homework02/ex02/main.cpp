
/*

Hello dear evaluator!!!
Please refer to my git link in order to make sure that copy-pasting this into your environment doesn't cause any issues.

Tests
Leo 5000 1200 2000 4500
Mike 3800 2400 3200
Raph 1500 2200 1200 4000 4800
Don 5000 1600 3200 4600
May 4400 3300 5800

To stop loop, ctrl + z for windows; ctrl + d for linux and mac


*/

//2.3
#include "header.hpp"



//Oh lookie! It's the main function again!!!
int	main()
{
	std::string s;
	std::vector<std::string> scores;
	//One could assume when this assignment was made ;-;
	std::map<std::string, std::vector<int>> map;

	//Orignally, there's supposed to be an exit key, but then someone told me that
	//we can just use ctrl z/ ctrl d to exit the loop. So I did that instead :D
	while (std::getline(std::cin, s))
	{
		std::istringstream iss(s);
		std::string name;
		std::vector<int> score;
		iss >> name;
		int temp;
		while (iss >> temp)
		{
			score.push_back(temp);
		}
		map[name] = score;
	}
	
	std::getline(std::cin, s);
	std::cout << "Test cases" << std::endl;
	for (auto it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first << ": ";
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "2.1" << std::endl;
	sorter(map);
	remove_first(map);

	printer(map);

	std::cout << "2.2" << std::endl;
	print_max(map);

}