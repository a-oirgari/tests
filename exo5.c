#include<stdio.h>

int main(){
    int T[] = {0,1, 7,6, 4, 3,5};
    //int temp = T[0];
    

    for (int i = 0; i < 7; i++){
        if(T[i] < T[i+1]){
            T[i] = T[i+1];
         }
         printf("%d", T[i]);
    }


    
    
    

    return 0;
}