#include "ex02_header.hpp"

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

std::string stylize(const std::string& s)
{
	std::string result;
	if (s.front() == '*' && s.back() == '*' && s.size() > 1)
	{
		result = s.substr(1, s.size() - 2);
		result = "<strong>" + result + "</strong>";
	}
	else
	{
		result = s;
	}
	return result;
}

std::string translate(const std::string& s)
{
	std::string result;
	result = s;
	return result;
}

std::string print_table(std::initializer_list<const char*> words)
	{
	std::string result;
	const int med_width = 4;
	const std::string firstheader = "unstylized";
	const std::string secondheader = "stylized";

	//find largest sized string in the list
	int largest = 0;
	for (const auto& w: words) {
		if (words.size() > largest)
		{
			largest = words.size();
		}
	}
 
	int unstylized_width;
	if (largest < firstheader.size())
		unstylized_width = abs(firstheader.size() + largest - firstheader.size());
	else
		unstylized_width = largest;


	int stylized_width = abs(largest - secondheader.size());


	std::cout << std::string(largest + med_width, ' ') << firstheader << std::string(med_width, ' ') << secondheader << std::string(med_width, ' ') << std::endl;


	for (const auto&w : words)
	{
		std::string unstylized = unstylize(w);
		std::string stylized = stylize(w);
		std::cout << w << std::string(largest + med_width - translate(w).size() , ' ') << unstylized << std::string(unstylized_width + med_width + med_width - unstylized.size() , ' ') << stylized << std::endl;
	}


	return result;
}

void print_html_table(std::initializer_list<const char*> words)
{
	std::cout << "<!DOCTYPE html>" << std::endl;
	std::cout << "<html>" << std::endl;

	std::cout << "<table>" << std::endl;
	std::cout << "<tr>" << std::endl;
	std::cout << "<th></th>" << std::endl;
	std::cout << "<th>unstylized</th>" << std::endl;
	std::cout << "<th>stylized</th>" << std::endl;
	std::cout << "</tr>" << std::endl;
	for (const auto& w : words)
	{
		std::cout << "<tr>" << std::endl;
		std::cout << "<td>" << w << "</td>" << std::endl;
		std::cout << "<td>" << unstylize(w) << "</td>" << std::endl;
		std::cout << "<td>" << stylize(w) << "</td>" << std::endl;
		std::cout << "</tr>" << std::endl;
	}
	std::cout << "</table>" << std::endl;
	std::cout << "</html>" << std::endl;

}
	
void newline()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
	}
}