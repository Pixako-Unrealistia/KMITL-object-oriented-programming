#include "header.hpp"


//Behold the sorting function! And that's why we do homework late :)
void sorter(std::map<std::string, std::vector<int>>& map)
{
	//define everything we need!
	std::map<std::string, std::vector<int>> temp;
	std::vector<int> temp2;
	std::string temp3;
	int temp4;
	//classic loop and eliminate! Method that got me 60/100 in one of Mr John's assignment :o
	while (map.size() > 0)
	{
		for (auto it = map.begin(); it != map.end(); it++)
		{

			if (it->second[0] > temp4)
			{
				temp4 = it->second[0];
				temp2 = it->second;
				temp3 = it->first;
			}
		}
		temp[temp3] = temp2;
		map.erase(temp3);
		temp4 = 0;
	}
	//reassign the thing back to the original map.
	map = temp;
}

//because of a bug I can't seem to find the root, I have to make seperate function to remove empty thingies :<
void remove_first(std::map<std::string, std::vector<int>>& map)
{
	//remove first key and value from the map
	map.erase(map.begin());
	
}


//why is this print and the above actual sorting? The subject doesn't specify ;-;
void print_max (std::map<std::string, std::vector<int>>& map2)
{
	for (auto it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << it->first << ": " << it->second[0] << std::endl;
	}
}

void printer(std::map<std::string, std::vector<int>>& map)
{
	for (auto it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first << ": ";
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
}