#include <stdio.h>
//Alp Baran Sirek
//217329251
//please dont mind the comments
int main(){
    int length;
    scanf("%d", &length);
    //printf("%d\n", length); // testing the first input
    char arrayA[length];
    char arrayB[length];
    int i;
    int k;
    scanf("%s", arrayA);
    scanf("%s", arrayB);

    //printf("%s\n", arrayA); // arrayA testing
    // her seyi initilaze edicem
    int n = 0;
    int maxOc = 0;
    int maxIndex;
    for(i = 0; i < length; i++){
        if(arrayA[i] == arrayB[i] || arrayA[i] == arrayB[i] + 1 || arrayA[i] == arrayB[i] - 1){
            while(arrayA[n + i] == arrayB[n + i] || arrayA[n + i] == arrayB[n + i] + 1 || arrayA[n + i] == arrayB[n + i] - 1){
                if(arrayA[n + i] == '\0'){
                    break;
                }
                if((arrayA[n + i] == 65 && arrayB[n + i] == 64) || (arrayB[n + i] == 64 && arrayA[n + i] == 65) || (arrayA[n + i] == 90 && arrayB[n + i] == 91) || (arrayB[n + i] == 91 && arrayA[n + i] == 90)){
                    break;
                }
                n++;
            }

            if (n > maxOc){
                maxOc = n;
                maxIndex = i;
            }
            n = 0;
        }
    }
    printf("%d\t%d\n", maxIndex, maxOc);
    return 0;
}

