#include "ex03_header.hpp"
#include <fstream>

//read visit.html file
int main()
{
std::ifstream file("visit.html");

std::istream& in2 = file;
std::vector<std::string> words;
std::string word;


std::cout << "<svg width=\"640\" height=\"480\" xmlns=\"http://www.w3.org/2000/svg\"><rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" /><circle cx=\"220\" cy=\"240\" r=\"200\"stroke=\"black\" stroke-width=\"2\" fill=\"#8080FF80\" /><circle cx=\"420\" cy=\"240\" r=\"200\"stroke=\"black\" stroke-width=\"2\" fill=\"#8080FF80\" />";

const size_t mode = 1;

if (mode == 0)
{
	while (std::getline(in2, word, '\n'))
	{
		if (word.find("red") != std::string::npos)
		{
			std::cout << word << std::endl;
		}
		else if (word.find("yellow") != std::string::npos)
		{
			std::cout << word << std::endl;
		}
	}
}
else if (mode == 1)
{
	while (std::getline(in2, word, '\n'))
	{
		if (word.find("blue") != std::string::npos)
		{
			std::cout << word << std::endl;
		}
	}
}
else
{
while (std::getline(in2, word, '\n'))
	{
		if (word.find("green") != std::string::npos)
		{
			std::cout << word << std::endl;
		}
	}
}

std::cout << "</svg>" << std::endl;

return 0;
}