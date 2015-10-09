#include "A.h"
#include "B.h"

using A::f(int);
using namespace B;

int main()
{
    f(10);
    return 0;
}
