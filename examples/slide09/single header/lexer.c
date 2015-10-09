//lexer.c

#include "dc.h"
#include <iostream>
#include <cctype>

Lexer::Token_value Lexer::cur_tok;
double Lexer::number_value;
std::string LExer::string_value;

Lexer::Token_value Lexer::get_token()
{
    /*...*/
}

/* 编译lexer.c时，编译器看到的是
namespace Lexer{
    // ...
    Token_value get_token();
}

//...

Lexer::Token_value Lexer::get_token()
*/