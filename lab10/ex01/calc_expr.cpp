#include "nse/ptr.hpp"

#include <variant>
#include <string>

using Expr = std::variant<
    nse::Ptr<class Val_expr>, nse::Ptr<class Bin_expr>>;

class Expression {
public:
    std::string repr() const;

    explicit Expression(double v);
    Expression(char bin_op, const Expression& l, const Expression& r);
private:
    template <class T>
    explicit Expression(T* ptr): expr{nse::Ptr(ptr)} {}

    Expr expr;
};

class Val_expr {
public:
    std::string repr() const { return std::to_string(val); }

    explicit Val_expr(double v): val{v} {}
private:
    double val;
};

class Bin_expr {
public:
    std::string repr() const;

    Bin_expr(char bin_op, const Expression& l, const Expression& r)
    : op{bin_op}, left{l}, right{r} {}
public:
    char op;
    Expression left;
    Expression right;
};

//============================================================================

std::string Expression::repr() const
{
    auto repr_v = [](const auto& x) { return x->repr(); };
    return std::visit(repr_v, expr);
}

Expression::Expression(double v)
: Expression(new Val_expr{v})
{
}

Expression::Expression(
    char bin_op, const Expression& l, const Expression& r)
: Expression(new Bin_expr{bin_op, l, r})
{
}

std::string Bin_expr::repr() const
{
    return '(' + left.repr() + op + right.repr() + ')';
}

//============================================================================

/*
Grammar
=======

Expression:
    Term
    Expression "+" Term    // addition
    Expression "–" Term    // subtraction
Term:
    Primary
    Term "*" Primary    // multiplication
    Term "/" Primary    // division
Primary:
    Number
    "(" Expression ")"    // grouping
*/

#include <istream>

struct Token {
public:
    char kind;
    double value;

    static constexpr char print = ';';
    static constexpr char quit = 'q';
    static constexpr char number = '8';

    explicit Token(char k): kind{k}, value{} {}
    Token(char k, double v) : kind{k}, value{v} {}
};

class Token_stream {
public:
    Token get();              // get a Token
    void putback(Token t);    // put a token back

    [[noreturn]]
    static void error(const std::string& s)
    { throw std::runtime_error(s); }

    explicit Token_stream(std::istream& is): input{is} {}
private:
    std::istream& input;
    Token buffer{'0'};        // here is where putback() stores a Token
    bool full = false;        // is there a Token in the buffer?
};

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

Expression expression(Token_stream& ts);

Expression primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // "(" Expression ")"
        {
            auto expr = expression(ts);
            t = ts.get();
            if (t.kind != ')')
                Token_stream::error("')' expected");
            return expr;
        }
    case Token::number:    // Number
        return Expression{t.value};
    default:
        Token_stream::error("primary expected");
    }
}

Expression term(Token_stream& ts)
{
    auto left = primary(ts);
    Token t = ts.get();
    for (;;) {
        switch (t.kind) {
        case '*':    // Term "*" Primary
            left = Expression('*', left, primary(ts));
            t = ts.get();
            break;
        case '/':    // Term "/" Primary
            left = Expression('/', left, primary(ts));
            t = ts.get();
            break;
        default:    // Primary
            ts.putback(t);    // put `t' back into the Token_stream
            return left;
        }
    }
}

Expression expression(Token_stream& ts)
{
    auto left = term(ts);        // read and evaluate a term
    Token t = ts.get();            // get next token from Token_stream
    for (;;) {
        switch (t.kind) {
        case '+':    // Expression "+" Term
            left = Expression('+', left, term(ts));
            t = ts.get();
            break;
        case '-':    // Expression "-" Term
            left = Expression('-', left, term(ts));
            t = ts.get();
            break;
        default:    // Term
            ts.putback(t);    // put `t' back into the Token_stream
            return left;
        }
    }
}

int main()
try {
    Token_stream ts_input(std::cin);

    Expression expr{0};
    while (std::cin) {
        Token t = ts_input.get();
        if (t.kind == Token::quit)
            break;
        if (t.kind == Token::print)
            std::cout << "= " << expr.repr() << '\n';
        else
            ts_input.putback(t);

        expr = expression(ts_input);
    }
    return 0;
}
catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
}

Token Token_stream::get()
{
    if (full) {             // do we already have a Token?
        full = false;       // remove Token from buffer
        return buffer;
    }

    char ch;
    input >> ch;            // note that >> skips whitespace

    switch (ch) {
    case Token::print:
    case Token::quit:
    case '(': case ')': case '{': case '}': case '!':
    case '+': case '-': case '*': case '/':
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {
        input.putback(ch);  // put digit back into input stream

        double val;
        input >> val;
        return Token{Token::number, val};
    }
    default:
        error("Bad token");
    }
}
