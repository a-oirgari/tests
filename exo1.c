#include<stdio.h>

int main(){
    int T[10];
    for (int i = 0; i < 10; i++){
        printf("Entrer le %d element du tableau: ", i+1);
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < 10; i++){
        if(T[i]%2 == 1){
            printf("%d", T[i]);
        }
    }

    return 0;
}