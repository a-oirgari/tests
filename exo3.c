#include<stdio.h>

int main(){
    int T[] = {0,-1, -3,-4, -7, -3};
    int sum = 0, temp;
    

    for (int i = 0; i < 6; i++){
        sum+=T[i];
    }
    if(sum > 0){
        for(int i = 0; i < 3; i++){
            temp = T[5-i];
            T[5-i] = T[i];
            T[i] = temp;
        }
        for(int i = 0; i<6; i++){
            printf("%d", T[i]);
        }
        
    }
    if (sum <= 0){
        printf("Erreur");
    }
    

    return 0;
}