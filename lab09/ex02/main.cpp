#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <fstream>
#include "html.hpp"

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
    static std::unique_ptr<Hero> read(std::istream& iss) {
    char type;
	std::string name;
		iss >> type >> name;
	    switch (type) {
        case 'W':
            return std::make_unique<Warrior>(name);
        case 'F':
            return std::make_unique<Fighter>(name);
        case 'M':
            return std::make_unique<Mage>(name);
        }
        return nullptr;
    }
};

void make_html(std::vector<std::unique_ptr<Hero>>& vec) {
	std::ofstream ofs("heroes.html");

	ofs << "<!DOCTYPE html>\n";
	ofs << "<table>\n";
	for (auto& hero : vec) {
		ofs << "<tr>\n";
		ofs << "<td>" << hero->get_name() << "</td>\n";
		ofs << "<td>" << hero->get_greetings() << "</td>\n";
		ofs << "</tr>\n";
	}
	ofs << "</table>\n";
	ofs << "</html>\n";

}

class Stream_writer: public nse::html::Writer {
public:
    void write(std::string_view msg) const override;
    void write(const Element& e, int lv = 0) const override;

    Stream_writer(std::ostream& o): os(o) {}
private:
    std::ostream& os;
};

void Stream_writer::write(std::string_view msg) const
{
    os << msg;
}

void Stream_writer::write(const Element& e, int lv) const
{
    e.write_to(*this, lv);
}






int main() {
 
	using Hero_ptr = std::unique_ptr<Hero>;

	std::vector<Hero_ptr> vec;
	vec.push_back(std::make_unique<Warrior>("Cecil"));
	vec.push_back(std::make_unique<Fighter>());
	vec.push_back(std::make_unique<Mage>("Vivi"));


	//make_html(vec);
	//nse_make_html(vec);
	
	
	using namespace nse::html;
    Stream_writer out(std::cout);

    auto title = Element("title", {Element::text("Table")});
    auto doc_head = Element("head", {title});

    std::vector<Element> body_vec; 
    for (auto &v : vec) {

        auto t = Element::text(v->get_name()); 
        auto n = Element::text(v->get_greetings()); 
        // auto e = Element("em", {t, Element("p", {t})});

        auto attrs = Attribute_map{
            {"id", "id001"},
            {"class", "class001"},
            {"enabled", true},
            {"selected", false}
        };

        auto tr = Element("tr", {Element("td", {t}), Element("td", {n})});

        body_vec.push_back(tr);

    }

    auto tbl = Element(
            "table", body_vec);
    auto doc_body = Element("body", {tbl});
    auto doc = Element("html", {doc_head, doc_body});

    std::cout << "<!DOCTYPE html>\n";
    out.write(doc);

    return 0;
		
}