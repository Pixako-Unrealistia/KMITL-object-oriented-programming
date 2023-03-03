
#include <iostream>
#include <vector>
#include <array>
#include <istream>



unsigned int ft_strlen(const char *s)
{
	unsigned int len = 0;
	while (*s)
	{
		++len;
		++s;
	}
	return len;
}

void to_upper(char* s)
{
	int len = ft_strlen(s);
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}


char* rev_dup(const char* s)
{
	unsigned int len = ft_strlen(s);
	char* newstr = (char*)malloc(len + 1);
	
	for (int i = 0; i < len; ++i)
	{
		newstr[i] = s[len - i - 1];
	}

	newstr[len] = '\0';
	return newstr;

}

char* read_text(std::istream&)
{
	char* str = (char*)malloc(1);
	char c = 0;
	int it = 0;
	while (std::cin.get(c))
	{
		if (c == '!')
		{
			break;
		}
		str[it] = c;
		++it;
		str = (char*)realloc(str, it + 1);
	}
	str[it] = '\0';
	return str;
}

int main()
{
	double coords[3] = {};
	double* p1 = coords;

	std::array<double,4> pt4d;
	auto arr_it = pt4d.begin();

	std::vector<double> vec;
	auto vec_it = vec.begin();

	std::cout << sizeof(coords) << std::endl;
	std::cout << sizeof(p1) << std::endl;

	char* teststr = (char*)"Catgirl ain't real";
	std::cout << teststr << std::endl;
	std::cout << teststr << std::endl;
	std::cout << teststr << std::endl;
	//1.1


	//1.2
	//to_upper(teststr);
	std::cout << teststr << std::endl;

	//1.3
	char* revstr = rev_dup((teststr));
	std::cout << revstr << std::endl;
	free(revstr);

	//1.4
	char* text = read_text(std::cin);
	std::cout << text << std::endl;
	free(text);

	return 0;



	//coords = 24 because it pre allocates
	//p1 = 8 because it is a pointer of double

}