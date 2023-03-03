#include <vector>
#include <iostream>

template <class T>
using Vec = std::vector<T>;


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





template <class C>
Vec<Vec<double>> create_ragged_array(const C& c, double val)
{
	Vec<Vec<double>> out;
	for (auto n: c)
		out.emplace_back(n, val);
	return out;
}

Nd_vec<Nd_vec<double>> create_ragged_array_2(const Nd_vec<int>&c, double val)
{
	Nd_vec<Nd_vec<double>> out;
	for (int i = 0; i < c.get_dimension(); ++i)
	{
		Nd_vec<double> temp;
		for (int j = 0; j < c[i]; ++j)
		{
			temp.push_back(val);
		}
		out.push_back(temp);
	}
	return out;
}


Nd_vec<Nd_vec<double>> copy_ragged_array(const Nd_vec<Nd_vec<double>>& data)
{
	Nd_vec<Nd_vec<double>> out;
	for (int i = 0; i < data.get_dimension(); ++i)
	{
		Nd_vec<double> temp;
		for (int j = 0; j < data[i].get_dimension(); ++j)
		{
			temp.push_back(data[i][j]);
		}
		out.push_back(temp);
	}
	return out;
}

void del_ragged_array(Nd_vec<Nd_vec<double>>& data)
{
	data.clear();
}


class Ragged_array {
private:
	Nd_vec<Nd_vec<double>> data;
public:
	Ragged_array() = default;
	Ragged_array(const Nd_vec<Nd_vec<double>>& data) : data(data) {}
	Ragged_array(const Ragged_array& other) : data(other.data) {}
	Ragged_array& operator=(const Ragged_array& other)
	{
		if (this != &other)
		{
			data = other.data;
		}
		return *this;
	}
	~Ragged_array() = default;

	const Nd_vec<Nd_vec<double>>& get_data() const
	{
		return data;
	}

	void clear()
	{
		data.clear();
	}
};

Ragged_array deep_copy_ragged_array(const Ragged_array& other)
{
	return Ragged_array(copy_ragged_array(other.get_data()));
}



int main()
	{
	auto dims = {2, 5, 3};
	auto rg_arr	= create_ragged_array(dims, 1.3);
	for (const auto& v: rg_arr) {
		for (auto x: v)
		std::cout << ' ' << x;
	std::cout << '\n';
	}

	std::cout << std::endl;

	Nd_vec<int> dims_2;
	dims_2.push_back(2);
	dims_2.push_back(5);
	dims_2.push_back(3);


	auto rg_arr_2 = create_ragged_array_2(dims_2, 1.3);
	for (int i = 0; i < rg_arr_2.get_dimension(); ++i)
	{
		for (int j = 0; j < rg_arr_2[i].get_dimension(); ++j)
		{
			std::cout << ' ' << rg_arr_2[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}