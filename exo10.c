#include<stdio.h>

int main(){
    int T[] = {10,100, 7,6, 4, 3,5,89,132,100};
    //int temp;
    for (int i = 0; i < 10; i++){
        if(T[i] >= 100){
            printf("l'indice est %d", i);
                break;
            }
        
    }
    return 0;
}