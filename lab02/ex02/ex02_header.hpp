#ifndef EX02_HEADER_HPP
#define EX02_HEADER_HPP

#include <iostream>
#include <string>
#include <list>

std::string unstylize(const std::string& s);
std::string stylize(const std::string& s);
std::string translate(const std::string& s);
std::string print_table(std::initializer_list<const char*> words);
void print_html_table(std::initializer_list<const char*> words);
void newline();


#endif