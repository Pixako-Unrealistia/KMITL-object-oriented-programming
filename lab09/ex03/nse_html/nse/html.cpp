#include "html.hpp"

namespace nse::html {

void Element::write_to(const Writer& w, int lv) const
{
    std::visit(
        [&w, lv](const auto& p) { p->write_to(w, lv); },
        node);
}

void Text_node::write_to(const Writer& w, int lv) const
{
    const std::string spaces(w.indent_size() * lv, ' ');
    w.write(spaces + txt + '\n');
}

void Element_node::write_to(const Writer& w, int lv) const
{
    const std::string spaces(w.indent_size() * lv, ' ');
    auto otag = name;
    for (const auto& [k, v]: attrs) {
        if (const auto* p = std::get_if<bool>(&v)) {
            if (*p)
                otag += ' ' + k;
        }
        else if (const auto* p = std::get_if<std::string>(&v)) {
            otag += ' ' + k + "=\"" + *p + "\"";
        }
    }

    if (children.empty()) {
        w.write(spaces + '<' + otag + " />\n");
        return;
    }

    w.write(spaces + '<' + otag + ">\n");
    for (const auto& obj: children) {
        obj.write_to(w, lv + 1);
    }
    w.write(spaces + "</" + name + ">\n");
}

Element Element::text(std::string_view t)
{
    return Element(new Text_node{t});
}

Element::Element(std::string_view n)
: Element(new Element_node{n})
{
}

Element::Element(std::string_view n, const std::vector<Element>& elems)
: Element(new Element_node(n, elems))
{
}

Element::Element(
    std::string_view n, const Attribute_map& attr_map,
    const std::vector<Element>& elems)
: Element(new Element_node(n, attr_map, elems))
{
}

Writer::~Writer() = default;

} // namespace nse::html
