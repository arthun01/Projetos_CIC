#include <stdio.h>

/*com iteração

int somaite(int a, int b){
    for(int i = 0; i < b; i++){
        a++;
    }
    return a;
}

*/

int somarec(int a, int b){
    if(b == 0){
        return a;
    }else{
        if(b > 0){
            a++;
            return somarec(a, b-1);            
        }else{
            a--;
            return somarec(a, b+1);
        }
    }
}

int multi(int a, int b){
    if(b == 1){
        return a;
    }else{
        a *= b-1;
        somarec(a, b-1);
    }
}

int main(void){

    printf("%d\n", somarec(5, -7));
    printf("%d\n", multi(-5, 7));


    return 0;
}