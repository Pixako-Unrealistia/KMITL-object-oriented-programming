


#ifndef HEADER_CHAN_HPP
# define HEADER_CHAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>

void lshift(std::vector<double>& vec, int n);
void rshift(std::vector<double>& vec, int n);
void remove_negative(std::vector<double>& vec);
std::vector<double> scale(std::vector<double> vec, double multiplier);
std::vector<double> add(std::vector<double> vec1, std::vector<double> vec2);
void remove_negative_list(std::list<double>& list);


#endif