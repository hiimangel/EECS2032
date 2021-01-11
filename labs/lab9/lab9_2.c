#include <stdio.h>
//Alp Baran Sirek
//217329251

int main(){
    int maxValue;
    int numOfBins;
    int arrayOfNums[500];
    printf("What is the number of bins");
    scanf("%d", &numOfBins);
    printf("Please enter the Maximum Value:");
    scanf("%d", &maxValue);
    int binSize = (int) maxValue / numOfBins;
    
    int i;
    int increment = 0;
    int lengthOfArray = 0;
    while(scanf("%d", &arrayOfNums[lengthOfArray]) != EOF){
       lengthOfArray++;
    }
    for(i = 0; i < numOfBins; i++){
        int endValue = increment + binSize;
        int k; 
        int yeah = 0;
        for(k = 0; k < lengthOfArray; k++){
            if(arrayOfNums[k] >= increment && arrayOfNums[k] <= endValue && arrayOfNums[k] <= maxValue){
                yeah++;
            }
        }
        printf("[%-3d:%3d]:%3d\n", increment, endValue, yeah);
        increment = increment + 1 + binSize; 
    } 
    return 0;
}