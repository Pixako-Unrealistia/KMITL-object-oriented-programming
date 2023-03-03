
#include <iostream>

template <typename T>
class Nd_vec{
private:
	int dimension;
	int capacity;
	T* data;

public:
	Nd_vec() : dimension(0), capacity(0), data(nullptr) {}
	Nd_vec(const Nd_vec& other) : dimension(other.dimension), capacity(other.capacity), data(nullptr)
	{
		data = new T[capacity];
		for (int i = 0; i < dimension; ++i)
		{
			data[i] = other.data[i];
		}
	}
	~Nd_vec()
	{
		delete[] data;
	}
	Nd_vec& operator=(const Nd_vec& other)
	{
		if (this != &other)
		{
			delete[] data;
			dimension = other.dimension;
			capacity = other.capacity;
			data = new T[capacity];
			for (int i = 0; i < dimension; ++i)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	
	Nd_vec& operator+=(Nd_vec& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < other.dimension; ++i)
			{
				push_back(other.data[i]);
			}
		}
		return *this;
	}

	
	void push_back(const T& value)
	{
		if (dimension == capacity)
		{
			capacity = capacity == 0 ? 1 : capacity * 2;
			T* new_data = new T[capacity];
			for (int i = 0; i < dimension; ++i)
			{
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
		}
		data[dimension] = value;
		++dimension;
	}

	void emplace_back(T&& value)
	{
		if (dimension == capacity)
		{
			capacity = capacity == 0 ? 1 : capacity * 2;
			T* new_data = new T[capacity];
			for (int i = 0; i < dimension; ++i)
			{
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
		}
		data[dimension] = std::move(value);
		++dimension;
	}

	const T& operator[](int index) const
	{
		return data[index];
	}
	int get_dimension() const
	{
		return dimension;
	}

	void clear() 
	{
		dimension = 0;
		capacity = 0;
		delete[] data;
		data = nullptr;
	}
};

/*
expected output
<svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">
<polyline fill="none" stroke="black"
points="10, 10 190, 20 180, 180 80, 110 10, 10"
/>
</svg>


*/


class Poly_line{
private:
	Nd_vec<int> x;
	Nd_vec<int> y;

public:
	Poly_line() = default;
	Poly_line(const Poly_line& other) : x(other.x), y(other.y) {}
	Poly_line& operator=(const Poly_line& other)
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;
		}
		return *this;
	}
	void add_point(int x, int y)
	{
		this->x.push_back(x);
		this->y.push_back(y);
	}
	void clear()
	{
		x.clear();
		y.clear();
	}

	Nd_vec<Nd_vec<int>> call_for_segs (const Poly_line& other) const
	{
		Nd_vec<Nd_vec<int>> segs;
		segs.push_back(other.x);
		segs.push_back(other.y);
		return segs;
	}

	void print(Nd_vec<Nd_vec<int>> segs, std::ostream os)
	{
		for (int i = 0; i < x.get_dimension(); ++i)
		{
			os << segs[0][i] << ", " << segs[1][i] << " ";
		}
	}

	void gen_svg(Nd_vec<Nd_vec<int>> segs, std::ostream& os) const
	{
		os << "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
		os << "<polyline fill=\"none\" stroke=\"black\"" << std::endl;
		os << "points=\"";
		for (int i = 0; i < x.get_dimension(); ++i)
		{
			os << segs[0][i] << ", " << segs[1][i] << " ";
		}
		os << "\"" << std::endl;
		os << "/>" << std::endl;
		os << "</svg>" << std::endl;
	}
};



int main()
{
	Poly_line p1;
	p1.add_point(10, 10);
	p1.add_point(190, 20);
	p1.add_point(180, 180);
	p1.add_point(80, 110);
	p1.add_point(10, 10);
	p1.gen_svg(p1.call_for_segs(p1), std::cout);

/*
	Poly_line p2;
	p2.add_point(10, 10);
	p2.add_point(190, 20);
	p2.add_point(180, 180);
	p2.add_point(80, 110);
	p2.add_point(10, 10);
	p2.gen_svg(p2.call_for_segs(p2), std::cout);
*/

	return 0;
}