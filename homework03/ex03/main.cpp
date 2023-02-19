
#include "standard.hpp"



std::string read_line()
{
	std::string line;
	std::getline(std::cin, line);
	return line;
}

std::vector<std::vector<std::string>> classifier(std::string line)
{
	//if the input have asterisk, then put it into first vector
	//if not, put it into second vector
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> first;
	std::vector<std::string> second;
	std::stringstream ss(line);
	std::string item;
	while (std::getline(ss, item, ' '))
	{
		if (item[0] == '*' && item[item.size() - 1] == '*')
		{
			first.push_back(item);
		}
		else
		{
			second.push_back(item);
		}
	}
	result.push_back(first);
	result.push_back(second);
	return result;
}

std::string cartesean_follower(std::vector<std::vector<std::string>> data)
{
	std::vector<std::string> result;
	for (auto i : data[0])
	{
		for (auto j : data[1])
		{
			result.push_back("(" + i + "," + j + "), ");
		}
	}
	//trim the last comma
	result[result.size() - 1].erase(result[result.size() - 1].size() - 2, 2);
	std::string final_result;
	for (auto i : result)
	{
		final_result += i;
	}
	return final_result;}

int main()
{

	//test input Red *Green* Blue Cyan *Black* White

	std::string line = read_line();
	std::cout << cartesean_follower(classifier(line));
	return 0;
}