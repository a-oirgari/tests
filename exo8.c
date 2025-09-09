#include<stdio.h>

int main(){
    int T[] = {8,1, 7,6, 4, 3,5};
    int temp;
    for (int i = 0; i < 7; i++){
        
            if(T[0] > T[7]){
                temp = T[7];
                T[0] = T[7];
                T[7] = temp;
            }
        
        printf("%d", T[i]);
    }
    return 0;
}