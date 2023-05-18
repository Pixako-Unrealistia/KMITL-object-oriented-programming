#include <iostream>
#include <istream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <variant>

class Shape {
	public :
		virtual double area() {
			return 0;
		}
	
		virtual void print(std::ostream& os)
		{
			
		}

		virtual void svg(std::ostream& os)
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

		void svg(std::ostream& os)
		{
			os << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << r << "\" fill=\"red\" />" << std::endl;
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

		void svg(std::ostream& os)
		{
			os << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << w << "\" height=\"" << h << "\" fill=\"red\" />" << std::endl;
		}
};


using ShapeVariant = std::variant<Circle*, Rectangle*>;

class shape_creation {
public:
    static ShapeVariant read(std::istream& iss) {
    char type;
	iss >> type;

	    if (type == 'R') 
		{
			
            Rectangle* tempo = new Rectangle();
			iss >> tempo->x >> tempo->y >> tempo->w >> tempo->h;

			return tempo;
			
		}
        if (type == 'C')
		{
	        Circle* tempo2 = new Circle();
			iss >> tempo2->x >> tempo2->y >> tempo2->r;
			return tempo2;
		}
		
    
	}
	
};

void make_svg(std::vector<std::shared_ptr<Shape>> shapes)
{
	std::ofstream ofs("shapes.svg");
	ofs << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << std::endl;
	for (auto& shape : shapes) {
		shape->svg(ofs);
	}
	ofs << "</svg>" << std::endl;

}


int main()
{
	std::istringstream iss("C 50 50 15 R 400 40 20 20 R 450 140 20 20");
	std::vector<std::shared_ptr<Shape>> shapes;
	while (iss) {
		ShapeVariant shape = shape_creation::read(iss);
		if (std::holds_alternative<Circle*>(shape)) {
			shapes.push_back(std::make_shared<Circle>(*std::get<Circle*>(shape)));
		
		}
	}
/*
	std::sort (shapes.begin(), shapes.end(), [](std::shared_ptr<Shape> a, std::shared_ptr<Shape> b) {return a->area() < b->area(); });
	for (auto& shape : shapes) {
		shape->print(std::cout);
	}
*/
	make_svg(shapes);
	return 0;
}