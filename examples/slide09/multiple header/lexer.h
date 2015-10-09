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
