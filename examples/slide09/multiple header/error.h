//error.h

namespace Error{
    struct Zero_divided    {    };
    struct Syntax_error
    {
        const char* p;
        Syntax_error(const char* q){p=q;}
    };
}