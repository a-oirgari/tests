#include<stdio.h>

int main(){
    int T[10];
    
    

    for (int i = 0; i < 10; i++){
        printf("Entrer le %d element du tableau: ",i+1);
        scanf("%d", &T[i]);
    }
    int max = T[0];
    for (int i = 0; i < 10; i++){
         if(max < T[i]){
            max = T[i];
         }
    }
    printf("le maximum est %d: ", max);

    return 0;
}