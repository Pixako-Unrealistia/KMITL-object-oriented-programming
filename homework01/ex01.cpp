#include <iostream>
#include <string>
#include <algorithm>

void spaces()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;    
}


void twob(int bufferone, int buffertwo, int bufferthree, int bufferfour, std::string p1_name , std::string p2_name, std::string p3_name, std::string p4_name,char border, char hori, char verti, char mittle)
{
    int greatest;
	greatest = std::max({bufferone, buffertwo, bufferthree, bufferfour});


    int secondconstant = 13;
    


	//Q4
    std::cout << border << std::string(secondconstant + greatest - 2, hori) << border << std::string(secondconstant + greatest - 2, hori) << border << std::endl;
    std::cout << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::endl;
    std::cout << verti << " Warrior: " << p1_name  << std::string(abs(greatest - bufferone), ' ') << verti<< " Mage: " << p2_name  << std::string(abs(greatest - buffertwo), ' ') << "   " << verti << std::endl;
    std::cout << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::endl;



    std::cout << border << std::string(secondconstant + greatest - 2, mittle) << border << std::string(secondconstant + greatest - 2, mittle) << border << std::endl;



    std::cout << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::endl;
    std::cout << verti << " Ninja: " << p3_name  << std::string(abs(greatest - bufferthree), ' ') << "  " << verti << " Fighter: " << p4_name  << std::string(abs(greatest - bufferfour), ' ') << verti << std::endl;
	std::cout << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::string(secondconstant + greatest - 2, ' ') << verti << std::endl;
    std::cout << border << std::string(secondconstant + greatest - 2, hori) << border << std::string(secondconstant + greatest - 2, hori) << border << std::endl;

    
}


int main()
{
int bufferconstant = 27;
int lesserconstant = 12;
int bufferone = 0;
int buffertwo = 0;
int	bufferthree = 0;
int bufferfour = 0;

std::cout << "Warrior name: ";
std::string p1_name;
std::cin >> p1_name;
bufferone += p1_name.length(); 

std::cout << "Mage name: ";
std::string p2_name;
std::cin >> p2_name;
buffertwo += p2_name.length();

std::cout << "Ninja name: ";
std::string p3_name;
std::cin >> p3_name;
bufferthree += p3_name.length();

std::cout << "Fighter name: ";
std::string p4_name;
std::cin >> p4_name;
bufferfour += p4_name.length();


std::cout << std::endl;

p1_name.append(" ");
p2_name.append(" ");
p3_name.append(" ");
p4_name.append(" ");

spaces();
std::cout << 1.1 << std::endl;
twob(bufferone,buffertwo,bufferthree,bufferfour, p1_name , p2_name,p3_name,p4_name,'*','*', '*', '*');
spaces();


std::cout << 1.2 << std::endl;
twob(bufferone,buffertwo,bufferthree,bufferfour, p1_name , p2_name,p3_name,p4_name,'+','=', '|', '-');
spaces();

return 0;
}
