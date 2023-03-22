
#include <iostream>

//Reimplementation of std because the instruction said not to use them

void ft_memcpy(void* dest, void* src, size_t n)
{
    char* char_dest = (char*)dest;
    char* char_src = (char*)src;
    for (auto it_dest = char_dest, it_src = char_src; it_src != char_src + n; ++it_dest, ++it_src)
    {
        *it_dest = *it_src;
    }
}



void ft_memset(void* dest, char c, size_t n)
{
	for (auto *it = (char*)dest; it != (char*)dest + n; ++it)
	{
		*it = c;
	}
}

int ft_strlen(char* s)
{
	int size = 0;
	for (auto *it = s; *it != '\0'; ++it)
	{
		++size;
	}
	return size;
}

int ft_max(int a, int b)
{
	return a > b ? a : b;
}


class Picture {
public:
    // Constructors, may or may not copy pasted from my previous lab work
    Picture(int width = 0, int height = 0) : width(width), height(height) {
		data = new char*[height];
        for(int i = 0; i < height; i++) {
            data[i] = new char[width];
            ft_memset(data[i], ' ', width);
        }
    }
    Picture(const Picture& other) : width(other.width), height(other.height) {
        data = new char*[height];
        for(int i = 0; i < height; i++) {
            data[i] = new char[width];
            ft_memcpy(data[i], other.data[i], width);
        }
    }

    // Destructor as required
    ~Picture() {
        for(int i = 0; i < height; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

	void resize(int new_width, int new_height) {
		char** new_data = new char*[new_height];
		for (int i = 0; i < new_height; ++i) {
			new_data[i] = new char[new_width];
			ft_memset(new_data[i], ' ', new_width);
		}
		for (int i = 0; i < height && i < new_height; ++i) {
			for (int j = 0; j < width && j < new_width; ++j) {
				new_data[i][j] = data[i][j];
			}
		}
		for (int i = 0; i < height; ++i) {
			delete[] data[i];
		}
		delete[] data;
		data = new_data;
		width = new_width;
		height = new_height;
	}


	// Assignment operator
	Picture& operator=(char* other) {
		// Calculate the dimensions of the rectangular picture
		int new_width = 0, new_height = 1;
		for (char* p = other; *p != '\0'; ++p) {
			if (*p == '\n') {
				new_width = ft_max(new_width, p - other);
				++new_height;
			}
		}
		new_width = ft_max(new_width, ft_strlen(other) - (new_height - 1));

		resize(new_width, new_height);

		int i = 0, j = 0;
		for (char* p = other; *p != '\0'; ++p) {
			if (*p == '\n') {
				++i;
				j = 0;
			} else {
				data[i][j] = *p;
				++j;
			}
		}

		return *this;
	}


    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void print(std::ostream& out) const {
        for (auto it = data; it != data + height; ++it) {
			for (auto it2 = *it; it2 != *it + width; ++it2) {
				out << *it2;
			}
			out << std::endl;
		}
    }



private:
    char** data; 
    int width;
    int height;
};


int main() {
	
	char* data =
(char*)R"(_____/\\\\\\\\\________/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\__/\\\\\\\\\\\_        
 ___/\\\\\\\\\\\\\____/\\\/////////\\\_____/\\\////////__\/////\\\///__\/////\\\///__       
  __/\\\/////////\\\__\//\\\______\///____/\\\/_______________\/\\\_________\/\\\_____      
   _\/\\\_______\/\\\___\////\\\__________/\\\_________________\/\\\_________\/\\\_____     
    _\/\\\\\\\\\\\\\\\______\////\\\______\/\\\_________________\/\\\_________\/\\\_____    
     _\/\\\/////////\\\_________\////\\\___\//\\\________________\/\\\_________\/\\\_____   
      _\/\\\_______\/\\\__/\\\______\//\\\___\///\\\______________\/\\\_________\/\\\_____  
       _\/\\\_______\/\\\_\///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\\\\\__/\\\\\\\\\\\_ 
        _\///________\///____\///////////___________\/////////__\///////////__\///////////__)";

	Picture p1(300, 10);
	p1 = data;

    std::cout << "Picture contents:" << std::endl;

	p1.resize(100, 10);
	p1.print(std::cout);

	return 0;
}