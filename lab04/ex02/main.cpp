#include "header.hpp"

using std::vector;
using std::list;
using std::string;

template <class T>
T remove_negative(T vec)
{
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](double d) {return d < 0; }), vec.end());
	return vec;
}

template <class T>
bool all_zeroes(T begin, T end)
{
	vector<double> vec(begin, end);
	for (auto d : vec)
	{
		if (d != 0) return false;
	}
	return true;

}

template <class T>
string str_join(string sep, T begin, T end)
{
	vector<string> vec(begin, end);
	string result;
	for (auto slice : vec)
	{
		result += slice + sep;
	}
	result = result.substr(0, result.size() - sep.size());
	return result;
}

int main()
{
	//2.1 tests COMMENT THE OTHER ONE WHEN USING OR FIX IR URSELF XDDD
	
	vector<double> vec1{
		0.8, -5.1, 1.6, -6.5, 10.5
	};
	auto vec2 = remove_negative(vec1);
	list<double>
		li1(vec1.rbegin(), vec1.rend());
	auto li2 = remove_negative(li1);
	
	std::cout << "2.1\nvec2: ";
	for (auto d : vec2)
	{
		std::cout << d << " ";
	}

	std::cout << "\nli2: ";
	for (auto d : li2)
	{
		std::cout << d << " ";
	}
	

	//2.2 tests

	std::cout << "\n2.2 tests\n";
	vector<int> vec3{1, 0, 2, 3};
	vector<int> vec4(10);
	bool z1 = all_zeroes(vec3.begin(), vec3.end());
	bool z2 = all_zeroes(vec4.begin(), vec4.end());
	list<int> li3(vec3.rbegin(), vec3.rend());
	list<int> li4(10);
	bool zz1 = all_zeroes(li3.begin(), li3.end());
	bool zz2 = all_zeroes(li4.begin(), li4.end());
	
	std::cout << "vec3: " << z1 << "\nvec4: " << z2 << "\nli3: " << zz1 << "\nli4: " << zz2 << std::endl;

	//2.3 tests

	std::cout << "2.3 tests\n";
	auto words = vector<string>{"C", "Rust", "C++", "Python"};
	auto str1 = str_join(string(", "), words.begin(), words.end());
	auto words2 = list<string>(words.rbegin(), words.rend());
	auto str2 = str_join(string(", "), words2.begin(), words2.end());

	std::cout << str1 << std::endl << str2 << std::endl;

}

