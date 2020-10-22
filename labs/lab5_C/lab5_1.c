#include <stdio.h>

int main()  {
    int numberOfFloats;
    scanf("%d", &numberOfFloats);

    float numbers[numberOfFloats];
    int i = 0;
    for (i = 0; i < numberOfFloats; i++){
       scanf("%f", &numbers[i]);
    }
    if (i < 2){
        printf("NO\n");
        return 0;
    }
    int j;
    for (j = 0; j < numberOfFloats; j++){
        if (numbers[j] == 0){
            printf("NO\n");
            return 0;
        }
    }

    int trueorfalse = 1;
    int k; 
    for(k = 0; k < numberOfFloats - 1; k++){
        if(trueorfalse == 0){
            break;
        }
        if ((numbers[k]*numbers[k+1]) > 0){
            trueorfalse = 0;
        } 
    }

    if (trueorfalse){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}