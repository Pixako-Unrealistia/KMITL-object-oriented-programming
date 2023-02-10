#include "header.hpp"
#include <map>


std::map<std::string, int> pair_map(std::vector<std::string> vec)
{
	std::map<std::string, int> map;
	std::string buffer;
	for (int i = 0; i < vec.size(); i++)
	{
		if (i % 2 == 0 || i == 0)
		{
			buffer = vec[i];
		}
		else
		{
		if (i % 2 != 0 && i != 0)
		{
			if (map.find(buffer) != map.end())
			{
				map[buffer] += std::stoi(vec[i]);
			}
			else
			{
				map.insert(std::pair<std::string, int>(buffer, std::stoi(vec[i])));
			}
		}
		}


	}


	for (auto it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}

	return map;
}

std::map<std::string, std::vector<int>> pair_map_modified(std::vector<std::string> vec)
{
	std::map<std::string, std::vector<int>> map;
	std::string buffer;
	for (int i = 0; i < vec.size(); i++)
	{
		if (i % 2 == 0 || i == 0)
		{
			buffer = vec[i];
		}
		else
		{
		if (i % 2 != 0 && i != 0)
		{
			if (map.find(buffer) != map.end())
			{
				map[buffer].push_back(std::stoi(vec[i]));
			}
			else
			{
				map.insert(std::pair<std::string, std::vector<int>>(buffer, { std::stoi(vec[i]) }));
			}
		}
		}
	}

	for (auto it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
		{
			if (i == it->second.size() - 1)
			{
				std::cout << it->second[i];
			}
			else
				std::cout << it->second[i] << ", ";
		}
		std::cout << std::endl;
	}


	return map;
}



int main()
{
	//3.1

	std::cout << "3.1" << std::endl;
	std::cout << "Enter the list of word and number: " << std::endl;

	std::vector<std::string> vec;
	std::string x;

	while (std::cin >> x && x != "*")
	{
		vec.push_back(x);
	}



	pair_map(vec);

	std::cout << "\n3.2\n" << std::endl;
	pair_map_modified(vec);
	return 0;


}