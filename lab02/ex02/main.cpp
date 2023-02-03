
#include "ex02_header.hpp"


int main()
{
auto words = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};

/*for (const auto& w: words) {
	std::cout << unstylize(w) << std::endl;
}

newline();

for (const auto& w: words) {
	std::cout << stylize(w) << std::endl;

}*/

newline();

print_html_table(words);	

}
