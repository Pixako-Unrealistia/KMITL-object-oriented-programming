
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


template <typename T>
Nd_vec<T> subtract(const Nd_vec<T>& v1, const Nd_vec<T>& v2)
{
	Nd_vec<T> v3;
	for (int i = 0; i < v1.get_dimension(); ++i)
	{
		v3.push_back(v1[i] - v2[i]);
	}
	return v3;
}

template <typename T>
Nd_vec<T> add(const Nd_vec<T>& v1, const Nd_vec<T>& v2)
{
	Nd_vec<T> v3;
	for (int i = 0; i < v1.get_dimension(); ++i)
	{
		v3.push_back(v1[i] + v2[i]);
	}
	return v3;
}

template <typename T>
Nd_vec<T> scale(const Nd_vec<T>& v1, const Nd_vec<T>& v2)
{
	Nd_vec<T> v3;
	for (int i = 0; i < v1.get_dimension(); ++i)
	{
		v3.push_back(v1[i] * v2[i]);
	}
	return v3;
}

void supercool_print(const Nd_vec<int>& v)
{
	std::cout << "(";
	for (int i = 0; i < v.get_dimension(); ++i)
	{
		if (i == v.get_dimension() - 1)
		{
			std::cout << v[i];
		}
		else
		{
			std::cout << v[i] << ",";
		}
	}
	std::cout << ")" << std::endl;
}

int main()
{
	Nd_vec<int> v;
	v.push_back(1);
	v.push_back(2);

	std::cout << "base vectors:" << std::endl;
	supercool_print(v);
	std::cout << "added vector:" << std::endl;

	Nd_vec<int> v2 = v;
	Nd_vec<int> v3 = add(v,v2);
	
	
	supercool_print(v3);

	std::cout << "scaled vector:" << std::endl;
	Nd_vec<int> v4 = scale(v, v2);
	supercool_print(v4);

	std::cout << "subtracted vector:" << std::endl;
	Nd_vec<int> v5 = subtract(v, v2);
	supercool_print(v5);
	

	v.clear();

	std::cout << "cleared\n" << v.get_dimension() << std::endl;

	return (0);
}