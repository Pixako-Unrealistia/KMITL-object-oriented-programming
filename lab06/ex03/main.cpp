
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

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>


class Picture
{
	public:
		Nd_vec<std::string> data;
	
		Picture() = default;

		Picture(const Picture& other) : data(other.data) {}

		Picture& operator=(const Picture& other)
		{
			if (this != &other)
			{
				data = other.data;
			}
			return *this;
		}


		void printme()
		{
			for (int i = 0; i < data.get_dimension(); ++i)
			{
				std::cout << data[i] << std::endl;
			}
		}

		int get_width() const
		{
			int max = 0;
			for (int i = 0; i < data.get_dimension(); ++i)
			{
				if (data[i].size() > max)
				{
					max = data[i].size();
				}
			}
			return max;
		}

		int get_height() const
		{
			return data.get_dimension();
		}

		void vcat(const Nd_vec<std::string>& other)
		{
			int width = get_width();
			int height = get_height();
			int other_width = other.get_dimension();
			int other_height = other[0].size();
			int new_width = std::max(width, other_width);
			int new_height = height + other_height;
			Nd_vec<std::string> new_data;
			for (int i = 0; i < new_height; ++i)
			{
				std::string new_line;
				for (int j = 0; j < new_width; ++j)
				{
					if (j < width && i < height)
					{
						new_line += data[i][j];
					}
					else if (j < other_width && i >= height)
					{
						new_line += other[i - height][j];
					}
					else
					{
						new_line += ' ';
					}
				}
				new_data.push_back(new_line);
			}
			data = new_data;
		}

		void hcat(const Nd_vec<std::string>& other)
		{
			int width = get_width();
			int height = get_height();
			int other_width = other.get_dimension();
			int other_height = other[0].size();
			int new_width = width + other_width;
			int new_height = std::max(height, other_height);
			Nd_vec<std::string> new_data;
			for (int i = 0; i < new_height; ++i)
			{
				std::string new_line;
				for (int j = 0; j < new_width; ++j)
				{
					if (j < width && i < height)
					{
						new_line += data[i][j];
					}
					else if (j >= width && i < other_height)
					{
						new_line += other[i][j - width];
					}
					else
					{
						new_line += ' ';
					}
				}
				new_data.push_back(new_line);
			}
			data = new_data;
		}

		void clear()
		{
			data.clear();
		}
};




int main()
{

/*
	std::string data =
R"(_____/\\\\\\\\\________/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\__/\\\\\\\\\\\_        
 ___/\\\\\\\\\\\\\____/\\\/////////\\\_____/\\\////////__\/////\\\///__\/////\\\///__       
  __/\\\/////////\\\__\//\\\______\///____/\\\/_______________\/\\\_________\/\\\_____      
   _\/\\\_______\/\\\___\////\\\__________/\\\_________________\/\\\_________\/\\\_____     
    _\/\\\\\\\\\\\\\\\______\////\\\______\/\\\_________________\/\\\_________\/\\\_____    
     _\/\\\/////////\\\_________\////\\\___\//\\\________________\/\\\_________\/\\\_____   
      _\/\\\_______\/\\\__/\\\______\//\\\___\///\\\______________\/\\\_________\/\\\_____  
       _\/\\\_______\/\\\_\///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\\\\\__/\\\\\\\\\\\_ 
        _\///________\///____\///////////___________\/////////__\///////////__\///////////__)";
*/


	std::string buffer;
	Nd_vec<std::string> data;

	while (std::getline(std::cin, buffer))
	{
		if (buffer == "!")
		{
			break;
		}
		data.push_back(buffer);
	}

/*
	"test \n \
	test \n \
	testttttt \n \
	";
*/



	Picture picture;
	picture.data = data;
	std::cout << picture.get_width() << std::endl;
	std::cout << picture.get_height() << std::endl;
	picture.printme();

	picture.hcat(data);
	picture.printme();
	

	return 0;
}