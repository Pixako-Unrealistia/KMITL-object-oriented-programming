#include <iostream>
#include <vector>
#include <string_view>

int main(int argc, const char* const* const argv)
{
    /*
        Is A Better `main` Possible?
        https://www.youtube.com/watch?v=zCzD9uSDI8c

        https://github.com/roger-dv/better-main
    */
    std::vector<std::string_view> args(
        argv, std::next(argv, static_cast<std::ptrdiff_t>(argc)) );

    auto i = 0;
    for (auto arg: args) {
        std::cout << '[' << i << ":" << arg.size() << "] "
                  << arg << std::endl;
        ++i;
    }
    return 0;
}
