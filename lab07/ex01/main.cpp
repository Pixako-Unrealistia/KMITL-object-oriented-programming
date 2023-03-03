#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <cstring> reimplement everything for that gigachad energy



//1.1
std::string substitute(std::string text,std::string word,std::string rep)
{
	std::string::size_type n = text.find(word);
	if (n != std::string::npos)
	{
		text.replace(n, word.length(), rep);
	}
	return text;

}

size_t ft_strlen(const char* str)
{
	int i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return i;
}


void* ft_memcpy(void* dest, const void* src, size_t n)
{
	char* d = (char*)dest;
	const char* s = (const char*)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return dest;
}

int ft_memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	const unsigned char* p1 = (const unsigned char*)ptr1;
	const unsigned char* p2 = (const unsigned char*)ptr2;
	while (num--)
	{
		if (*p1 != *p2)
		{
			return *p1 - *p2;
		}
		p1++;
		p2++;
	}
	return 0;
}


char* ft_strstr(const char* str, const char* target)
{
	while (*str != '\0')
	{
		if (ft_strlen(str) < ft_strlen(target))
		{
			return NULL;
		}
		if (ft_memcmp(str, target, ft_strlen(target)) == 0)
		{
			return (char*)str;
		}
		str++;
	}
	return NULL;
}


//1.2 
char* c_substitute(char* text, const char* word, const char* rep)
{
    char* new_text = (char*)malloc(ft_strlen(text) + 1);
    char* q = new_text;

    if (!new_text)
    {
        return NULL;
    }

    while (*text != '\0')
    {
        if (ft_strstr(text, word) == text)
        {
            size_t word_len = ft_strlen(word);
            size_t rep_len = ft_strlen(rep);
            char* temp = (char*)realloc(new_text, ft_strlen(new_text) + rep_len - word_len + 1);
            if (!temp)
            {
                free(new_text);
                return NULL;
            }
            new_text = temp;
            ft_memcpy(q, rep, rep_len);
            q += rep_len;
            text += word_len;
        }
        else
        {
            *q++ = *text++;
        }
    }
    *q = '\0';

    return new_text;
}



//1.3
template <typename T1, typename T2>
class pair
{
public:
	pair(double a, double b) : first(a), second(b) {}
	double first;
	double second;
};

std::vector<pair<double, double>> create_pairs(const std::vector<double>& arr)
{
	std::vector<pair<double, double>> pairs;
	for (int i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 >= arr.size())
		{
			break;
		}
		pairs.push_back(pair<double, double>(arr[i], arr[i + 1]));
	}
	return pairs;
}


size_t sizeof_arr(double arr[])
{
	size_t i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}

double** create_pairs_2(double arr[])
{
	double** pairs = (double**)malloc(sizeof_arr(arr) * sizeof(double*));
	for (int i = 0; i < sizeof_arr(arr); i += 2)
	{
		if (i + 1 >= sizeof_arr(arr))
		{
			break;
		}
		pairs[i] = (double*)malloc(2 * sizeof(double));
		pairs[i][0] = arr[i];
		pairs[i][1] = arr[i + 1];
	}
	return pairs;
}

int main()
{

std::string text1 = "abc python javapythonx";
std::string text2 = "abcx yja helx yz01 23";

char* text3 = (char*)"abc python javapythonx";
char* text4 = (char*)"abcx yja helx yz01 23";

const char* word1 = "python";
const char* word2 = "visit";
const char* word3 = c_substitute(text3, word1, word2);


std::clog << "c_substitute" << std::endl << word3 << std::endl;

std::clog << "substitute" << std::endl;
std::clog << substitute(text1, "python", "rust") << std::endl; // == "abc rust javarustx"
std::clog << substitute(text1, "", "rust") << std::endl;       // == "abc python javapythonx"
std::clog << substitute(text2, "python", "rust") << std::endl; // == "abcx yja helx yz01 23"
std::clog << substitute(text2, "x y", "a b") << std::endl;     // == "abca bja hela bz01 23"


std::clog << "1.3" << std::endl;


std::vector<pair<double, double>> create_pairs(const std::vector<double>& arr);
std::vector<double> data{
1.2, 2.3, 5, 2, 1.1, 3, 7
};
auto pairs = create_pairs(data);


for (auto& p : pairs)
{
	std::clog << p.first << " " << p.second << std::endl;
}

std::cout << "1.4" << std::endl;

double data2[] = { 1.2, 2.3, 5, 2, 1.1, 3, 7, '\0' };

auto pairs2 = create_pairs_2(data2);

for (int i = 0; i < sizeof_arr(data2); i += 2)
{
	if (i + 1 >= sizeof_arr(data2))
	{
		break;
	}
	std::clog << pairs2[i][0] << " " << pairs2[i][1] << std::endl;
}



return 0;


}