/* ponteiro para ponteiros*/


#include <stdio.h>

int main(void){
    int var = 5;
    int* p;
    int** pp;
    int*** ppp;

    p = &var;
    pp = &p;
    ppp = &pp;

    printf("*p: %d\n", *p);
    printf("**pp: %d\n", **pp);

    printf("&var: %p\n", (void*) &var);

    printf("&p: %p | p: %p | *p: %d\n", (void*)&p, (void*)p, *p);
    printf("&pp: %p | pp: %p | *pp: %p | **pp: %d\n", (void*)&pp, (void*)pp, *pp, **pp);
    printf("&ppp: %p | ppp: %p | *ppp: %p | **ppp: %p | ***ppp: %d\n", (void*)&ppp, (void*)ppp, *ppp, **ppp, ***ppp);


    return 0;
}