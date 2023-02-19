#include "standard.hpp"


//Hello dearest TA
//I've carefully read through the subject
//If something is not correct...
//I'm hiding in your closet and I will not hesitate to come out~



//Hewwo I'm a readfile function that does what it says
//Kinda reminds me of Rust one but this one is better.
std::string readfile(std::string filename)
{
	std::ifstream file(filename);
	std::string line;
	std::string data;
	while (std::getline(file, line))
	{
		data += line;
	}
	return data;
}

//1.1
//This code is copy pasted into 1.2 :>
std::string join_splitted(std::string data)
{
	//split the string by semi colon
	std::vector<std::vector<std::string>> splitted_splitted;
	std::vector<std::string> splitted;
	std::string result;
	std::stringstream ss(data);
	std::string item;
	while (std::getline(ss, item, ';'))
	{
		splitted.push_back(item);
	}
	//seperate the vectors by space and put them into splitted_splitted
	for (auto i : splitted)
	{
		std::vector<std::string> temp;
		std::stringstream ss(i);
		std::string item;
		while (std::getline(ss, item, ' '))
		{
			if (item != "")
				temp.push_back(item);
		}
		splitted_splitted.push_back(temp);
	}

	//join the splitted_splitted by space. First index of the second vector will go after the first index of the first one
	
	int vector1_size = splitted_splitted[0].size();
	int vector2_size = splitted_splitted[1].size();
	int biggest_size = vector1_size > vector2_size ? vector1_size : vector2_size;

	for (int i = 0; i < biggest_size; i++)
	{
		if (i < vector1_size)
		{
			result += splitted_splitted[0][i];
			result += " ";
		}
		
		if (i < vector2_size)
		{
			result += splitted_splitted[1][i];
			result += " ";
		}
	}

	return result;
}

//1.2
//The subject said to 'calculate' no way it says to print the output so I'm returning int.
int calculate_sop(std::string data)
{
	//split the string by semi colon
	std::vector<std::vector<std::string>> splitted_splitted;
	std::vector<std::string> splitted;
	std::stringstream ss(data);
	std::string item;
	while (std::getline(ss, item, ';'))
	{
		splitted.push_back(item);
	}
	//seperate the vectors by space and put them into splitted_splitted
	for (auto i : splitted)
	{
		std::vector<std::string> temp;
		std::stringstream ss(i);
		std::string item;
		while (std::getline(ss, item, ' '))
		{
			if (item != "")
				temp.push_back(item);
		}
		splitted_splitted.push_back(temp);
	}

	//join the splitted_splitted by space. First index of the second vector will go after the first index of the first one
	
	int vector1_size = splitted_splitted[0].size();
	int vector2_size = splitted_splitted[1].size();
	int biggest_size = vector1_size > vector2_size ? vector1_size : vector2_size;
	int result = 0;
	int first = 0;
	int second = 0;


	for (int i = 0; i < biggest_size; i++)
	{
		if (i < vector1_size)
		{
			first = std::stoi(splitted_splitted[0][i]);
		}
		
		if (i < vector2_size)
		{
			second = std::stoi(splitted_splitted[1][i]);
		}
		result += first * second;
		first = 0;
		second = 0;
	}

	return result;
}

std::string cartesian_product(std::string data)
{
	//split the string by semi colon
	std::vector<std::vector<std::string>> splitted_splitted;
	std::vector<std::string> splitted;
	std::stringstream ss(data);
	std::string item;
	while (std::getline(ss, item, ';'))
	{
		splitted.push_back(item);
	}
	//seperate the vectors by space and put them into splitted_splitted
	for (auto i : splitted)
	{
		std::vector<std::string> temp;
		std::stringstream ss(i);
		std::string item;
		while (std::getline(ss, item, ' '))
		{
			if (item != "")
				temp.push_back(item);
		}
		splitted_splitted.push_back(temp);
	}

	//cast first value into second one
	std::vector<std::string> result;
	for (auto i : splitted_splitted[0])
	{
		for (auto j : splitted_splitted[1])
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
	return final_result;
}

int main()
{
	std::string data = readfile("data1.txt");
	std::cout << "source:" << std::endl;
	std::cout << data << std::endl;
	std::cout << "<1.1>" << std::endl;
	std::cout << "result:" << std::endl;
	std::cout << join_splitted(data) << std::endl;

	std::cout << "<1.2>" << std::endl;
	std::cout << "result:" << std::endl;
	std::cout << calculate_sop(data) << std::endl;
	std::cout << "<1.3>" << std::endl;
	std::cout << "result:" << std::endl;
	std::cout << cartesian_product(data) << std::endl;



	return 0;
}