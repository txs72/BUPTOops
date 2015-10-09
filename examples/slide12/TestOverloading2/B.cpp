#include <stdio.h>
#include "B.h"

void B::f(int x){
    printf("namespace: B\nversion: int\nthe value of int is: %d", x);
}

void B::f(char c){
    printf("namespace: B\nversion: char\nthe value of char is: %c", c);
}
