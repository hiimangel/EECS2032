#include <stdio.h>
//Alp Baran Sirek
//217329251

int main(){
    int binSize;
    int numOfBins;
    int arrayOfNums[500];
    printf("Please enter the bin size:");
    scanf("%d", &binSize);
    printf("What is the number of bins");
    scanf("%d", &numOfBins);
    
    int i;
    int increment = 0;
    int lengthOfArray = 0;
    while(scanf("%d", &arrayOfNums[lengthOfArray]) != EOF){
       lengthOfArray++;
    }
    for(i = 0; i < numOfBins; i++){
        int endValue = increment + binSize - 1;
        int k; 
        int yeah = 0;
        for(k = 0; k < lengthOfArray; k++){
            if(arrayOfNums[k] >= increment && arrayOfNums[k] <= endValue){ 
                //printf("%d and %d\n", increment, endValue);
                yeah++;

            }
        }
        printf("[%-3d:%3d]:%d\n", increment, endValue, yeah);
        increment = increment + binSize; 
    } 
    return 0;
}
