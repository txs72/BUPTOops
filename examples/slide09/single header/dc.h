//dc.h
namespace Error{
    struct Zero_divide{};
    struct Syntax_error
    {
        const char* p;
        Syntax_error(const char* q){ p=q; }
    };
}
#include <string>
namespace Lexer{
    enum Token_value{
        NAME, NUMBER, END, 
        PLUS='+', MINUS='-', NUL='*', DIV='/',
        PRINT=';', ASSIGN='=', LP='(', RP=')'
    };
    extern Token_value curr_tok;
    extern double number_value;
    extern std::string string_value;
    Token_value get_token();
}

namespace Parser{
    double prim(bool get);
    double term(bool get);
    double expr(bool get);

    using Lexer::get_token;
    using Lexer::curr_tok;
}

#include <map>
extern std::map<std::string,double> table;

namespace Driver{
    extern int no_of_errors;
    extern std::istream* input;
    void skip();
}
