#include "header_chan.hpp"

void lshift(std::vector<double>& vec, int n)
{
	int size = vec.size();
	unsigned int anothercounter = 0;
	std::vector<double> temp(size-n);
	for (int i = 0; i < size; i++)
	{
		if  (i >= n)
		{
			temp[anothercounter] = vec[i];
			anothercounter++;
		}
	}
	vec = temp;
}

void rshift(std::vector<double>& vec, int n)
{
	int size = vec.size() + n;
	std::vector<double> temp(size);

	for (int i = 0; i != n; i++)
	{
		temp[i] = 0;
	}
	for (int i = n; i < size; i++)
	{
		temp[i] = vec[i - n];
	}
	vec = temp;
}


//1.2
void remove_negative(std::vector<double>& vec)
{
	std::vector<double> position = {};
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < 0)
		{
			position.push_back(i);
		}
	}
	std::reverse(position.begin(), position.end());
	for (int i = 0; i < position.size(); i++)
	{
		//why would you do this?
		//well, just wanna try using erase.
		//okay, but why not just use pop_back()?
		//because i want to remove the negative number, not the last number
		//oh, okay

		vec.erase(vec.begin() + position[i]);
	}
}


//1.3

std::vector<double> scale(std::vector<double> vec, double multiplier)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] *= multiplier;
	}
	return vec;
}

std::vector<double> add(std::vector<double> vec1, std::vector<double> vec2)
{
	int	size;
	if (vec1.size() > vec2.size())
	{
		size = vec1.size();
	}
	else
	{
		size = vec2.size();
	}
	for (int i = 0; i < size; i++)
	{
		vec1[i] += vec2[i];
	}

	return vec1;
}


void remove_negative_list(std::list<double>& list)
{
	for (auto it = list.begin(); it != list.end();)
	{
		if (*it < 0)
		{
			it = list.erase(it);
		}
		else
		{
			++it;
		}
	}
}
