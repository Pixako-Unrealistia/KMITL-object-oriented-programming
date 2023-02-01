
//pseudo-pseudo code

//prompt(exitkey = q)
//loop -> append farenheight to its list -> convert to celcius -> append value its list
//if exit -> endloop
//print table_header
//iterate list -> print converted farenheight, celcius

#include <iostream>
#include <vector>
#include <string>


int main()
{
	//loop until exit
	using namespace std;
	string exitkey = "q";
	string input;
	vector<double> farenheight_list;
	vector<double> celcius_list;
	double farenheight;
	double celcius;

	cout << fixed;
	cout.precision(1);
	cout << "Enter a temperature in farenheight to convert to celcius. Enter q to quit." << endl;
	while (input != exitkey)
	{
		cin >> input;
		if (input == exitkey)
		{
			break;
		}
		else
		{
			farenheight = stod(input);
			celcius = (farenheight - 32) * 5 / 9;
			celcius_list.push_back(celcius);
			farenheight_list.push_back(farenheight);
		}
	}
	cout << "Fahr" << "\t" << "Celcius" << endl;
	for (int i = 0; i < celcius_list.size(); i++)
	{
		cout << farenheight_list[i] << "\t" << celcius_list[i] << endl;
	}
	return 0;

}

