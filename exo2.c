#include<stdio.h>

int main(){
    int temp =0, n, T[] = {1,2,3,4,5,6,7,8};
    printf("Entrer une valeure: ");
    scanf("%d", &n);

    for (int i = 0; i < 8; i++){
        if(n < T[i]){
            printf("%d\n", T[i]);
            temp ++;
        }
    }
    printf("le nombre de nuombre plus est %d: ", temp);

    return 0;
}