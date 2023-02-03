#include <iostream>
#include <string>

void simpleiter(int count)
{
    for (int x = 0; x != count + 1; x++)
    {
        std::cout << std::string(x, '*') << std::endl;
    }
}

void rightwave(int count)
{
	simpleiter(count);
	for (int x = count - 1; x > 0; x--)
	{
		std::cout << std::string(x, '*') << std::endl;
	}		
}

void leftwave(int count)
{
	for (int filler = count -1 ; filler > - 1; filler--)
	{
		std::cout << std::string(filler, ' ') << std::string(count - filler, '*') <<std::endl;
	}
	for (int filler = 1 ; filler < count ; filler++)
	{
		std::cout << std::string(filler, ' ') << std::string(count - filler, '*') <<std::endl;
	}
}
int main()
{
	std::cout << "Output Size = ";
	int OS;
	std::cin >> OS;

	simpleiter(OS);
	rightwave(OS);
	leftwave(OS);


return 0;
}