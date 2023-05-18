#include "nse/html.hpp"

#include <iostream>

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

int main()
{
    using namespace nse::html;
    Stream_writer out(std::cout);

    auto t = Element::text("Text001");
    auto e = Element("em", {t, Element("p", {t})});
    out.write(t);
    out.write(e);

    e = Element(std::string_view("img"));
    std::cout << "-----\n\n";
    out.write(e);

    std::cout << "-----\n\n";

    auto attrs = Attribute_map{
        {"id", "id001"},
        {"class", "class001"},
        {"enabled", true},
        {"selected", false}
    };
    for (const auto& [k, v]: attrs) {
        std::cout << k << ": ";
        std::visit([](const auto& val) { std::cout << val; }, v);
        std::cout << '\n';
    }

    std::cout << "-----\n\n";

    auto tr = Element("tr", std::vector(3, Element("td", {t})));
    auto tbl = Element(
        "table", {{"class", "table-1"}, {"selected", true}},
        {tr, tr, tr});

    auto title = Element("title", {Element::text("Test #1")});
    auto doc_head = Element("head", {title});
    auto doc_body = Element("body", {tbl});
    auto doc = Element("html", {doc_head, doc_body});

    std::cout << "<!DOCTYPE html>\n";
    out.write(doc);
}
