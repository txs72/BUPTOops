//parser_impl.h
#include "parser.h"
//包含parser.h是为了使编译器能检查一致性
#include "error.h"
#include "lexer.h"

namespace Parser{ //给实现的界面
    double prim(bool get);
    double term(bool get);
    double expr(bool get);

    using Lexer::get_token;
    using Lexer::curr_tok;
}