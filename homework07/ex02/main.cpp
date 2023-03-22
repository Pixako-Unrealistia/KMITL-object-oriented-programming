#include <iostream>

struct Point
{
	int x;
	int y;
};

int len_list(int* lst)
{
	int size = 0;
	while (lst[size])
	{
		size++;
	}
	return size;
}

Point* create_point(int* x, int* y)
{
	Point* p = (Point*)malloc(sizeof(Point) * len_list(x));	
	for (int i = 0; i < len_list(x); i++)
	{
		p[i].x = x[i];
		p[i].y = y[i];
	}
	return p;
}


int main()
{
	int* x = (int*)malloc(sizeof(int) * 3);
	int* y = (int*)malloc(sizeof(int) * 3);
	x[0] = 1;
	x[1] = 2;
	x[2] = 3;
	y[0] = 4;
	y[1] = 5;
	y[2] = 6;
	

	std::cout << "data size" << std::endl;
	std:: cout << len_list(x) << std::endl;

	Point* p = create_point(x, y);
	for (int i = 0; i < len_list(x); i++)
	{
		std::cout << p[i].x << " " << p[i].y << std::endl;
	}

	return 0;
}