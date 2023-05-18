#ifndef NSE_HTML_HPP
#define NSE_HTML_HPP

// https://www.foonathan.net/2022/05/recursive-variant-box

#include "ptr.hpp"

#include <map>
#include <vector>
#include <string>
#include <variant>

namespace nse::html {

class Writer;

using Attribute_value = std::variant<std::string, bool>;
using Attribute_map = std::map<std::string, Attribute_value>;

using Doc_node = std::variant<
    nse::Ptr<class Text_node>, nse::Ptr<class Element_node>>;

class Element {
public:
    void write_to(const Writer& w, int lv) const;

    static Element text(std::string_view t);
    static Element create(std::string_view n);
    static Element
        create(std::string_view, std::vector<Element>&& children);

    explicit Element(std::string_view n);
    Element(std::string_view n, const std::vector<Element>& elems);
    Element(
        std::string_view n, const Attribute_map& attr_map,
        const std::vector<Element>& elems);
private:
    template <class T>
    explicit Element(T* ptr): node{Ptr(ptr)} {}
    Doc_node node;
};

class Text_node {
public:
    void write_to(const Writer& w, int lv) const;

    explicit Text_node(std::string_view t): txt(t) {}

    // need C++20 #include <concepts>
    /*
    explicit Text_node(std::same_as<std::string> auto&& t)
    : txt(std::move(t)) {}
    */
private:
    std::string txt;
};

class Element_node {
public:
    void write_to(const Writer& w, int lv) const;

    explicit Element_node(std::string_view n): name{n} {}
    Element_node(std::string_view n, const std::vector<Element>& elems)
    : name{n}, attrs{}, children{elems} {}
    Element_node(
        std::string_view n, const Attribute_map& attr_map,
        const std::vector<Element>& elems)
    : name{n}, attrs{attr_map}, children{elems} {}
private:
    std::string name;
    Attribute_map attrs;
    std::vector<Element> children;
};

class Writer {
public:
    using Element = html::Element;

    virtual void write(std::string_view msg) const = 0;
    virtual void write(const Element& e, int lv = 0) const = 0;

    int indent_size() const { return in_sz; }
    void set_indent_size(int sz) { in_sz = sz; }

    virtual ~Writer() = 0;
private:
    int in_sz = 2;
};

} // namespace nse::html

#endif /* NSE_HTML_HPP */
