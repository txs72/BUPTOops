#include <stdio.h>
#include "A.h"

void A::f(int x){
    printf("namespace: A\nversion: int\nthe value of int is: %d", x);
}



void A::f(char c){
    printf("namespace: A\nversion: char\nthe value of char is: %c", c);
}
