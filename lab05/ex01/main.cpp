#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <istream>
/*
struct struct_ISBN
{
	std::string first;
	std::string second;
	std::string third;
	std::string fourth;
};*/


/*
test cases

0-3995-1100-8
Visit's return
Pjudge
2020
fiction

0-1726-7833-1
The Visit, Prestige edition
Pjudge
2022


*/

enum class genre
{
	fiction, nonfiction, periodical, biography, children
};

class Book
{
	public:
		std::string	ISBN;
		std::string title;
		std::string author;
		std::string copyright_year;
		genre s_genre;

	//check if ISBN is valid
		bool checkISBN(std::string ISBN)
		{
			std::string buffer;
			std::stringstream ss(ISBN);
			std::vector<std::string> tokens;
			int count = 0;
			while (std::getline(ss, buffer, '-'))
			{
				tokens.push_back(buffer);
			}

			if (tokens.size() != 4)
				return false;

			for (int i = 0; i < tokens.size(); i++)
			{
				//std::cout << tokens[i] << std::endl;
				count += tokens[i].length();
			}
			if (count != 10)
				return false;
			return true;
		}

		void checkin()
		{
			if (status)
			{
				std::cout << "Already checked in!" << std::endl;
			}
			else
			{
				std::cout << "Checked in!" << std::endl;
				status = true;		
			}
		}

		void checkout()
		{
		
			if (!status)
			{
				std::cout << "Already checked out!" << std::endl;
			}
			else
			{
				std::cout << "Checked out!" << std::endl;
				status = false;		
			}
		}
		void Compare(Book book)
		{
			if (ISBN == book.ISBN)
				std::cout << "They are the same book!" << std::endl;
			else
				std::cout << "They aren't the same book" << std::endl;
		}

		void Print()
		{
			std::cout << "ISBN: " << ISBN << std::endl;
			std::cout << "Title: " << title << std::endl;
			std::cout << "Author: " << author << std::endl;
			std::cout << "Year: " << copyright_year << std::endl;
		}

	private:
		bool status = false;
	
};



Book makeBook()
{
	Book book;

	std::cin >> book.ISBN;
	if (!book.checkISBN(book.ISBN))
	{
		std::cout << "Invalid ISBN" << std::endl;
		
		book.ISBN = "0-0-0-0";
		book.title = "0";
		book.author = "0";
		book.copyright_year = "0";
		book.s_genre = genre::fiction;
		return book;
	}
	std::cin >> book.title;
	std::cin >> book.author;
	std::cin >> book.copyright_year;

	std::string genre_buffer;
	std::cin >> genre_buffer;

	book.s_genre = static_cast<genre>(std::stoi(genre_buffer));

	return book;
}


Book findBook(std::vector<Book> books, std::string ISBN)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].ISBN == ISBN)
			return books[i];
	}

	Book book;
	book.ISBN = "0-0-0-0";
	book.title = "0";
	book.author = "0";
	book.copyright_year = "0";
	book.s_genre = genre::fiction;


	return book;
}


int main()
{
	//constructor for Book
	Book book;
	book.ISBN = "0-1726-7833-1";
	book.title = "The Visit";
	book.author = "Zoh'rah vis";
	book.copyright_year = "2019";
	book.s_genre = genre::periodical;


	//exit if isbn is invalid
	if (!book.checkISBN(book.ISBN))
	{
		std::cout << "Invalid ISBN" << std::endl;
		return (0);
	}

	book.Print();
	//later half
	std::cout << std::endl; 

	//make a vector of books
	std::vector<Book> books;
	books.push_back(book);
	Book book2 = makeBook();
	if (book2.checkISBN(book2.ISBN))
		books.push_back(book2);	

	//find
	std::string ISBN;
	std::cout << std::endl << std::endl;
	std::cout << "Enter ISBN to find: ";
	std::cin >> ISBN;
	Book buffer = findBook(books, ISBN);
	if (buffer.checkISBN(buffer.ISBN))
		buffer.Print();
	else
		std::cout << "Book not found" << std::endl;



	return (0);
}