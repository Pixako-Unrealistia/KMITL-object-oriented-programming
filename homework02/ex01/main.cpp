#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>

//Hello dear evaluator, since I'm slowly going insane from several stuffs going on in my life,
//I shall share the agony by typing these pointless comments to mess with you!

//The assignment asked me to make a function of unstylized, with the rest (1.2, 1.3) 
//being just modifications of the program so I did that! 
//Originally there are headerfiles and stuffs, but wouldn't that be painful for the TA to check? :o

//Unstylize function! Copy and pasted from one of the lab exercises :D
std::string unstylize(const std::string& s)
{
	std::string result;
	if (s.front() == '*' && s.back() == '*' && s.size() > 1)
	{
		result = s.substr(1, s.size() - 2);
	}
	else
	{
		result = s;
	}
	return result;
}


//Main function! :D
int	main()
{
	std::string s;
	std::cout << "Please enter your desired string: " << std::endl;

	std::getline(std::cin, s);


	std::istringstream iss(s);
	std::string word;
	std::list<std::string> words;


	//1.1
	while (iss >> word)
	{
		std::cout << unstylize(word) << " ";
		words.push_back(unstylize(word));
	}
	std::cout << std::endl << "1.2" << std::endl;

	//1.2 modify the program not function :>
	for (auto it = words.end(); it != words.begin(); it--)
	{
		std::cout << *it << " ";
	}

	//1.3 same but sorted!!!
	words.sort();
	std::cout << std::endl << "1.3" << std::endl;
	for (auto it = words.begin(); it != words.end(); it++)
	{
		std::cout << *it << " ";
	}
	



	return 0;
}

