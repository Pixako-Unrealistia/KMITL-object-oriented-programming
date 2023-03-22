#include <iostream>
//John Morris edition.
//Clean code
//No magic numbers
//No stdlib


void inverse_number(double* v, size_t n)
{
	for (auto *it = v; it != v + n; ++it)
	{
		*it = -*it;
	}
}

void replace(char* s,char c1, char c2)
{
	for (auto *it = s; *it != '\0'; ++it)
	{
		if (*it == c1)
		{
			*it = c2;
		}
	}
}

void ft_strcpy(char* dest, char* src)
{
	for (auto *it = src; *it != '\0'; ++it)
	{
		*dest = *it;
		++dest;
	}
	*dest = '\0';
}

//Maybe not so john morris one but it's pointer arithmetics so idk how else I should do it
char* encode_hex(const char* s)
{
    const char* hex = "0123456789ABCDEF";
    size_t size = 0;
    for (auto *it = s; *it != '\0'; ++it)
    {
        ++size;
    }
    char* hex_str = (char*)malloc(size * 2 + 1);
    char* hex_start = hex_str; 
    for (auto *it = s; *it != '\0'; ++it)
    {
        *hex_str = hex[(*it >> 4) & 0xF];
        ++hex_str;
        *hex_str = hex[*it & 0xF];
        ++hex_str;
    }
    *hex_str = '\0';


    return hex_start;
}


int main()
{

	//1.1 stuffs
	const size_t size = 3;
	double* array_of_doubles = (double*)malloc(size * sizeof(double));
	array_of_doubles[0] = 1.1;
	array_of_doubles[1] = 0.3;
	array_of_doubles[2] = 7.0;


	//1.2 stuffs
	size_t size_of_str = 20;
	char* str = (char*)malloc(size_of_str * sizeof(char));
	
	//Might as well re-implement strcpy so it's not using stdlib :>>
	ft_strcpy(str, (char*)"Pjudge is not a cat!");
	char target = 'a';
	char replace_with = 'o';



	//process

	inverse_number(array_of_doubles, size);
	replace(str, target, replace_with);
	char* hex_str = encode_hex("Hello world!");


	//output
	std::cout << "1.1 Output:" << std::endl;
	for (auto *it = array_of_doubles; it != array_of_doubles + size; ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "1.2 Output:" << std::endl;
	std::cout << str << std::endl;


	std::cout << "1.3 Output:" << std::endl;
	std::cout << hex_str << std::endl;

	//No leak pls
	free(array_of_doubles);
	free(str);
	free(hex_str);

	return 0;
}