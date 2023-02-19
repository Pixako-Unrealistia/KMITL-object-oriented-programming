#include "standard.hpp"

//This looks awfully familiar :OOOOOO
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


//No more strings... :(
//2.0
std::vector<std::vector<double>> seperate_by_semicolon(std::string data)
{
	std::vector<std::vector<double>> splitted_splitted;
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
		std::vector<double> temp;
		std::stringstream ss(i);
		std::string item;
		while (std::getline(ss, item, ' '))
		{
			if (item != "")
				temp.push_back(std::stof(item));
		}
		splitted_splitted.push_back(temp);
	}
	return splitted_splitted;

}

//2.1 Now that this time the seperation is done seperately, we can simplify this operation
std::vector<double> average(std::vector<std::vector<double>> data)
{
	std::vector<double> result;
	for (auto i : data)
	{
		double sum = 0;
		for (auto j : i)
		{
			sum += j;
		}
		result.push_back(sum / i.size());
	}
	return result;
}

std::string better_to_string(double data)
{
	std::stringstream ss;
	ss << data;
	return ss.str();
}

std::string cartesean_product(std::vector<std::vector<double>> data)
{
	/* Expected output, 
	(3.5, 4.2, 3), (3.5, 4.2, 7), (3.5, 4.2, 2),
(3.5, 2.7, 3), (3.5, 2.7, 7), (3.5, 2.7, 2),
(1.2, 4.2, 3), (1.2, 4.2, 7), (1.2, 4.2, 2),
(1.2, 2.7, 3), (1.2, 2.7, 7), (1.2, 2.7, 2),
(2.4, 4.2, 3), (2.4, 4.2, 7), (2.4, 4.2, 2),
(2.4, 2.7, 3), (2.4, 2.7, 7), (2.4, 2.7, 2)	
	*/

	std::string result;
	for (auto i : data[0])
	{
		for (auto j : data[1])
		{
			for (auto k : data[2])
			{
				result += "(" + better_to_string(i) + ", " + better_to_string(j) + ", " + better_to_string(k) + "), ";
			}
		}
	}



	return result;
}

int main()
{
	std::string data = readfile("data.txt");
	std::vector<std::vector<double>> cleaned_data = seperate_by_semicolon(data);

	std::cout << "Data: " << std::endl;
	for (auto i : cleaned_data)
	{
		for (auto j : i)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "<2.1>" << std::endl;
	for (auto i : average(cleaned_data))
	{
		std::cout << i << " ";
	}
	std::cout << std::endl << "The example output is wrong XDDDDD";

	std::cout << std::endl << "<2.2>" << std::endl;
	std::cout << cartesean_product(cleaned_data);



	return 0;
}