#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>

class Hero {
protected:
    std::string name;
    std::string greetings;
public:
    Hero() {};
    std::string get_name() {
        return name;
    }
    void set_name(std::string n) {
        name = n;
    }

	std::string get_greetings() {
		return greetings;
	}

	void print(std::ostream& os)
	{
		os << name << " " << greetings << std::endl;
	}
};

class Warrior : public Hero {
public:
    Warrior(std::string n) {
        name = n;
        greetings = "I'm " + name + ", I will save the world.";
    }
	Warrior() {
		name = "Unknown Warrior";
		greetings = "I'm " + name + ", I will save the world.";
	}
};

class Fighter : public Hero {
public:
    Fighter(std::string n) {
        name = n;
        greetings = "I'm " + name + ", my fists will crush the evil.";
    }
	Fighter() {
		name = "Unknown Fighter";
		greetings = "I'm " + name + ", my fists will crush the evil.";
	}
};

class Mage : public Hero {
public:
    Mage(std::string n) {
        name = n;
        greetings = "I'm " + name + ", I can cook with fire magic.";
    }
	Mage() {
		name = "Unknown Mage";
		greetings = "I'm " + name + ", I can cook with fire magic.";
	}
};

class hero_creation {
public:
    static std::shared_ptr<Hero> read(std::istream& iss) {
    char type;
	std::string name;
		iss >> type >> name;
	    switch (type) {
        case 'W':
            return std::make_shared<Warrior>(name);
        case 'F':
            return std::make_shared<Fighter>(name);
        case 'M':
            return std::make_shared<Mage>(name);
        }
        return nullptr;
    }
};




int main() {
    Warrior w;
    Fighter f;
    Mage m;

    std::cout << w.get_greetings() << std::endl;
    std::cout << f.get_greetings() << std::endl;
    std::cout << m.get_greetings() << std::endl;

    hero_creation builder;

    std::istringstream iss("W Cecil F Ryu M Vivi");
    auto hero1 = builder.read(iss);
    auto hero2 = builder.read(iss);
    auto hero3 = builder.read(iss);

    std::cout << hero1->get_greetings() << std::endl;
    std::cout << hero2->get_greetings() << std::endl;
    std::cout << hero3->get_greetings() << std::endl;

	std::cout << "\n\n\n\nPrint" << std::endl;

	hero1->print(std::cout);
	hero2->print(std::cout);
	hero3->print(std::cout);

	
	//2.4 doesn't specify to use function.
	std:: cout << "\n\n\n\n2.4" << std::endl;
	
	std::vector<std::shared_ptr<Hero>> heroes = {};
	std::istringstream iss2("F Visit M Judge W Name");
	while (iss2)
	{
		if (iss2.peek() == EOF)
		{
			break;
		}
		heroes.push_back(builder.read(iss2));
	}
	//sort by name using standard because no restrictions :>
	std::sort(heroes.begin(), heroes.end(), [](std::shared_ptr<Hero> a, std::shared_ptr<Hero> b) {return a->get_name() < b->get_name(); });
	for (auto hero : heroes)
	{
		hero->print(std::cout);
	}

	return 0;
	
}