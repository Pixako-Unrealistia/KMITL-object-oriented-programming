#include <iostream>
#include <istream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <sstream>


class Shape {
	public :
		virtual double area() {
			return 0;
		}
	
		virtual void print(std::ostream& os)
		{
			
		}



};

class Circle : public Shape {
	public :

		Circle(double a, double b, double c)
		{
			x = a;
			y = b;
			r = c;
		}
		Circle()
		{
			x = 50;
			y = 50;
			r = 10;
		}

		double area()
		{
			return 3.14 * r * r;
		}

		void print(std::ostream& os)
		{
			os << "C " << x << " " << y << " " << r <<  " area: " << area() << std::endl;
		}
	
	
		double x;
		double y;
		double r;



};


class Rectangle : public Shape {
	public :
	
		Rectangle()
		{
			x = 45;
			y = 45;
			w = 10;
			h = 10;
		}
		Rectangle(double a, double b, double c, double d)
		{
			x = a;
			y = b;
			w = c;
			h = d;
		}


		double area()
		{
			return w * h;
		}

		void print(std::ostream& os)
		{
			os << "R " << x << " " << y << " " << w << " " << h << " area:" << area() << std::endl;
		}

		double x;
		double y;
		double w;
		double h;
};


class shape_creation {
public:
    static std::shared_ptr<Shape> read(std::istream& iss) {
    char type;
	iss >> type;

	    if (type == 'R') 
		{
			
            Rectangle tempo = Rectangle();
			iss >> tempo.x >> tempo.y >> tempo.w >> tempo.h;
			return std::make_shared<Rectangle>(tempo);
		}
        if (type == 'C')
		{
	        Circle tempo2 = Circle();
			iss >> tempo2.x >> tempo2.y >> tempo2.r;
			return std::make_shared<Circle>(tempo2);
		}
        return nullptr;
    
	}
	
};


int main()
{
	std::istringstream iss("C 50 50 15 R 40 40 20 20");
	std::vector<std::shared_ptr<Shape>> shapes;
	while (iss) {
		auto shape = shape_creation::read(iss);
		if (shape) {
			shapes.push_back(shape);
		}
	}

	std::sort (shapes.begin(), shapes.end(), [](std::shared_ptr<Shape> a, std::shared_ptr<Shape> b) {return a->area() < b->area(); });
	for (auto& shape : shapes) {
		shape->print(std::cout);
	}

	

	return 0;
}