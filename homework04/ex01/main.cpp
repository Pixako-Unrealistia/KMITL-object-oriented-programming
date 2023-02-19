#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>


//Hello dearest TAs..... I really don't feel well so no commentary on this one..
//But there's one thing; Returning things from function is overrated

void prompt(std::string& buffer)
{
	std::cout << ">> ";
	std::getline(std::cin, buffer);
}

void ft_split(const std::string str, std::vector<std::string>& buffer_vector)
{
	std::string buffer;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, buffer, ' '))
	{
		buffer_vector.push_back(buffer);
	}
}

int main()
{
	std::string buffer = "";
	std::map<std::string, std::string> map = {};
	std::vector<std::string> buffer_vector = {};
	
	std::cout << "If you get seg fault it's your fault for inputting invalid arguments ;-;" << std::endl;

	while (true)
	{
		prompt(buffer);
		ft_split(buffer, buffer_vector);

		if (buffer_vector[0] == "set")
		{
			map[buffer_vector[1]] = buffer_vector[2];
		}
		else if (buffer_vector[0] == "get")
		{
			if (map.find(buffer_vector[1]) == map.end())
				std::cout << "<N/A>" << std::endl;
			else
				std::cout << buffer_vector[1] << ": " << map[buffer_vector[1]] << std::endl;
		}	
		else if (buffer_vector[0] == "add")
		{
			if (map.find(buffer_vector[1]) == map.end() || map.find(buffer_vector[2]) == map.end())
				std::cout << "<N/A>" << std::endl;
			else
			{
				float a = std::stof(map[buffer_vector[1]]);
				float b = std::stof(map[buffer_vector[2]]);
				std::cout << buffer_vector[1] + " + " + buffer_vector[2];
				std::cout << ": " << a+b << std::endl;
			
			}
		}
		else if (buffer_vector[0] == "sub")
		{
			if (map.find(buffer_vector[1]) == map.end() || map.find(buffer_vector[2]) == map.end())
				std::cout << "<N/A>" << std::endl;
			else
			{
				float a = std::stof(map[buffer_vector[1]]);
				float b = std::stof(map[buffer_vector[2]]);
				std::cout << buffer_vector[1] + " - " + buffer_vector[2];
				std::cout << ": " << a-b << std::endl;
			}
		}

		else
		{
			std::cout << "Invalid Operation" << std::endl;
		}
		buffer_vector.clear();
		buffer.clear();
	}

	return 0;
}