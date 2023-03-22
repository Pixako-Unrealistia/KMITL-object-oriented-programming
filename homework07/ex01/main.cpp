#include <iostream>
#include <string>


//Because 1.3 states that standard is not allowed. C style string will be utilised instead.
struct Person
{
	char* name;
	int age;
};

int size_of_person(Person* lst)
{
	int size = 0;
	while (lst[size].name != NULL)
	{
		size++;
	}
	return size;
}

void sort_by_name_ascending(Person* lst)
{
	int size = size_of_person(lst);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (lst[j].name > lst[j + 1].name)
			{
				Person temp = lst[j];
				lst[j] = lst[j + 1];
				lst[j + 1] = temp;
			}
		}
	}
}

void sort_by_age_ascending(Person* lst)
{
	int size = size_of_person(lst);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (lst[j].age > lst[j + 1].age)
			{
				Person temp = lst[j];
				lst[j] = lst[j + 1];
				lst[j + 1] = temp;
			}
		}
	}
}

void sort_by_name_descending(Person* lst)
{
	int size = size_of_person(lst);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (lst[j].name < lst[j + 1].name)
			{
				Person temp = lst[j];
				lst[j] = lst[j + 1];
				lst[j + 1] = temp;
			}
		}
	}
}

void sort_by_age_descending(Person* lst)
{
	int size = size_of_person(lst);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (lst[j].age < lst[j + 1].age)
			{
				Person temp = lst[j];
				lst[j] = lst[j + 1];
				lst[j + 1] = temp;
			}
		}
	}
}

Person* combine_fields(char** names, int* ages)
{
	int size = 0;
	while (names[size] != NULL)
	{
		size++;
	}
	Person* lst = (Person*)malloc(sizeof(Person) * size);
	for (int i = 0; i < size; i++)
	{
		lst[i].name = names[i];
		lst[i].age = ages[i];
	}
	return lst;
}

char** extract_names(Person* lst)
{
	int size = size_of_person(lst);
	char** names = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++)
	{
		names[i] = lst[i].name;
	}
	return names;
}

int* extract_ages(Person* lst)
{
	int size = size_of_person(lst);
	int* ages = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		ages[i] = lst[i].age;
	}
	return ages;
}

void print_lst(Person* lst)
{
	int size = size_of_person(lst);
	for (int i = 0; i < size; i++)
	{
		std::cout << lst[i].name << " " << lst[i].age << std::endl;
	}
}




int main()
{
	//abandon new, return to monke.
	Person* test_lst = (Person*)malloc(sizeof(Person) * 5);
	test_lst[0].name = (char*)"Judge";
	test_lst[0].age = 20;
	//those who attended discrete math will understand
	test_lst[1].name = (char*)"Tom";
	test_lst[1].age = 21;
	test_lst[2].name = (char*)"Bob";
	test_lst[2].age = 22;
	test_lst[3].name = (char*)"Alice";
	test_lst[3].age = 23;
	test_lst[4].name = (char*)"John";
	test_lst[4].age = 24;

	std::cout << "Original List" << std::endl;
	print_lst(test_lst);
	
	std::cout << "Sort by name ascending" << std::endl;
	sort_by_name_ascending(test_lst);
	print_lst(test_lst);

	std::cout << "Sort by age ascending" << std::endl;
	sort_by_age_ascending(test_lst);
	print_lst(test_lst);

	std::cout << "Sort by name descending" << std::endl;
	sort_by_name_descending(test_lst);
	print_lst(test_lst);

	std::cout << "Sort by age descending" << std::endl;
	sort_by_age_descending(test_lst);
	print_lst(test_lst);

	//1.2
	char** names = extract_names(test_lst);
	int* ages = extract_ages(test_lst);
	Person* new_lst = combine_fields(names, ages);
	
	//custom for 1.2 because reason you may find out yourself
	std::cout << "New List" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << new_lst[i].name << " " << new_lst[i].age << std::endl;
	}


	return 0;
}