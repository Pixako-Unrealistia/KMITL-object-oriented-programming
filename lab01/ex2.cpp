#include <iostream>
#include <string>

void spaces()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;    
}


void twoa(int bufferone, int buffertwo, std::string p1_name , std::string p2_name)
{
    int greatest;
    int secondconstant = 14;
    
    if (bufferone > buffertwo)
    {
        greatest = bufferone;
    }
    else
    {
        greatest = buffertwo;
    }
    
    std::cout << std::string(secondconstant + greatest, '*') << std::endl;
    std::cout << "*" << std::string(secondconstant + greatest - 2, ' ') << "*" << std::endl;
    std::cout << "* " << "Player 1: " << p1_name  << std::string(abs(greatest - bufferone), ' ') << "*" << std::endl;
    std::cout << "*" << std::string(secondconstant + greatest - 2, ' ') << "*" << std::endl;

    std::cout << std::string(secondconstant + greatest, '*') << std::endl;

    std::cout << "*" << std::string(secondconstant + greatest - 2, ' ') << "*" << std::endl;
    std::cout << "* " << "Player 2: " << p2_name  << std::string(abs(greatest - buffertwo), ' ') << "*" << std::endl;
    std::cout << "*" << std::string(secondconstant + greatest - 2, ' ') << "*" << std::endl;

    std::cout << std::string(secondconstant + greatest, '*') << std::endl;
    
}

void twob(int bufferone, int buffertwo, std::string p1_name , std::string p2_name, char border, char hori, char verti)
{
    int greatest;
    int secondconstant = 14;
    
    if (bufferone > buffertwo)
    {
        greatest = bufferone;
    }
    else
    {
        greatest = buffertwo;
    }
    
    std::cout << border << std::string(secondconstant + greatest - 2, hori) << border << std::endl;
    std::cout << border << std::string(secondconstant + greatest - 2, ' ') << border << std::endl;
    std::cout << verti << " Player 1: " << p1_name  << std::string(abs(greatest - bufferone), ' ') << verti << std::endl;
    std::cout << border << std::string(secondconstant + greatest - 2, ' ') << border << std::endl;

    std::cout << border << std::string(secondconstant + greatest - 2, hori) << border << std::endl;

    std::cout << border << std::string(secondconstant + greatest - 2, ' ') << border << std::endl;
    std::cout << verti << " Player 2: " << p2_name  << std::string(abs(greatest - buffertwo), ' ') << verti << std::endl;
    std::cout << border << std::string(secondconstant + greatest - 2, ' ') << border << std::endl;

    std::cout << border << std::string(secondconstant + greatest - 2, hori) << border << std::endl;
    
}


int main()
{
int bufferconstant = 27;
int lesserconstant = 12;
int bufferone = 0;
int buffertwo = 0;


std::cout << "Please enter P1 name: ";
std::string p1_name;
std::cin >> p1_name;
bufferone += p1_name.length(); 

std::cout << "Please enter P2 name: ";
std::string p2_name;
std::cin >> p2_name;
buffertwo += p2_name.length();

std::cout << std::endl;

p1_name.append(" ");
p2_name.append(" ");


std::cout << std::string(bufferconstant + bufferone + buffertwo, '*') << std::endl;

std::cout << "*" << std::string(bufferone + lesserconstant, ' ') << "*" << std::string(buffertwo + lesserconstant, ' ') << "*" << std::endl;
std::cout << "* " << "Player 1: " << p1_name << "* " << "Player 2: " << p2_name << "*" << std::endl;
std::cout << "*" << std::string(bufferone + lesserconstant, ' ') << "*" << std::string(buffertwo + lesserconstant, ' ') << "*" << std::endl;

std::cout << std::string(bufferconstant + bufferone + buffertwo, '*') << std::endl;


spaces();

//2.3
twoa(bufferone,buffertwo, p1_name , p2_name);
spaces();
twob(bufferone,buffertwo, p1_name , p2_name,'+','-', '|');
spaces();
twob(bufferone,buffertwo, p1_name , p2_name,'+', '=' , '|');

return 0;
}
