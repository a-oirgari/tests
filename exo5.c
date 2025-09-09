#include<stdio.h>

int main(){
    int T[] = {2,1, 7,6, 4, 3,5};
    int temp;
    for (int i = 0; i < 7; i++){
        for(int j=0;j<7-i;j++){
            if(T[j] > T[j+1]){
                temp = T[j];
                T[j] = T[j+1];
                T[j+1] = temp;
            }
        }
        printf("%d", T[i]);
    }
    return 0;
}