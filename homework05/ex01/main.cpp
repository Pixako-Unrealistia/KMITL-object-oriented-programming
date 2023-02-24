#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <list>

/*

REMINDER

DO NOT EVER COPY PASTE TESTS INTO CONSOLE

 
*/

/*
test cases

0-3995-1100-8
Visit's return
Pjudge
2020
periodical
0-3995-1100-8

0-1726-7833-1
The Visit, Prestige edition
Pjudge
2022
fiction

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
			switch (s_genre)
			{
			case genre::fiction:
				std::cout << "Genre: fiction" << std::endl;
				break;
			case genre::nonfiction:
				std::cout << "Genre: nonfiction" << std::endl;
				break;
			case genre::periodical:
				std::cout << "Genre: periodical" << std::endl;
				break;
			case genre::biography:
				std::cout << "Genre: biography" << std::endl;
				break;
			case genre::children:
				std::cout << "Genre: children" << std::endl;
				break;
			}

		}

	private:
		bool status = false;
	
};



Book makeBook()
{
	Book book;
	std::string genre_buffer = "";
	//substitute cin with getline
	std::cout << "Enter ISBN: ";
	std::getline(std::cin, book.ISBN);
	std::cout << "Enter title: ";
	std::getline(std::cin, book.title);
	std::cout << "Enter author: ";
	std::getline(std::cin, book.author);
	std::cout << "Enter year: ";
	std::getline(std::cin, book.copyright_year);
	std::cout << "Enter genre: ";
	std::getline(std::cin, genre_buffer);

	
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


	//limited type can be put to switch and since the initial is unique, might as well :)
	switch(genre_buffer[0])
	{
		case 'f':
			book.s_genre = genre::fiction;
			break;
		case 'n':
			book.s_genre = genre::nonfiction;
			break;
		case 'p':
			book.s_genre = genre::periodical;
			break;
		case 'b':
			book.s_genre = genre::biography;
			break;
		case 'c':
			book.s_genre = genre::children;
			break;
		default:
			book.s_genre = genre::fiction;
			break;
	}

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

//1.2
std::list<Book> by_genre(std::vector<Book> books, genre s_genre)
{
	std::list<Book> book_list;
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].s_genre == s_genre)
			book_list.push_back(books[i]);
	}
	return book_list;
}

//std::sort arguments: start, end, lambda function
//since a certain TA loves lambda so much I will obligate
void sort_by_title(std::vector<Book>& books)
{
	std::sort(books.begin(), books.end(), [](Book a, Book b) {return a.title < b.title; });
}

void sort_by_ISBN(std::vector<Book>& books)
{
	std::sort(books.begin(), books.end(), [](Book a, Book b) {return a.ISBN < b.ISBN; });
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


	std::cout << "Demostration of .Print(): " << book.ISBN << std::endl;
	book.Print();
	//later half
	std::cout << std::endl; 

	//make a vector of books
	std::vector<Book> books;
	books.push_back(book);

	std::cout << "Your input: " << std::endl;
	
	Book book2 = makeBook();
	if (book2.checkISBN(book2.ISBN))
		books.push_back(book2);	

	//find
	std::string ISBN;
	std::cout << std::endl << std::endl;
	std::cout << "Enter ISBN to find: " << std::endl;
	std::cin >> ISBN;
	Book buffer = findBook(books, ISBN);
	if (buffer.checkISBN(buffer.ISBN))
		buffer.Print();
	else
		std::cout << "Book not found" << std::endl;

	sort_by_title(books);
	std::cout << std::endl << "Sorted by title: " << std::endl;

	std::list<Book> book_list = by_genre(books, genre::periodical);		
	std::cout << std::endl << "Books by periodical genre: " << std::endl;
	for (auto i : book_list)
		i.Print();

	return (0);
}