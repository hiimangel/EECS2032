#include <stdio.h>

int main()  {
    int numberOfFloats;
    scanf("%d", &numberOfFloats);

    float numbers[numberOfFloats];
    int i;
    
    for (i = 0; i < numberOfFloats; i++){
       scanf("%f", &numbers[i]);
    }
    if (i < 2){
        printf("\nNO\n");
        return 0;
    }
    // ADD IF AN ELEMENT IS 0, RETURN 0 AND PRITN NO
    // okay what I need to do is have 2 sections here and later for  number%2 == 0 and 1or smthng else idk
    // if odd, make a formula where i and i+1 are somehow realted (division or mult) and results of - + = - and - - = + and + + = +
    for (int j = 0; j < numberOfFloats; j++){
        if (numbers[j] == 0){
            printf("\nNO\n");
            return 0;
        }
    }

    if (numberOfFloats % 2 != 0){
        if ((numbers[numberOfFloats - 1] * numbers[0]) > 0){
            for (int k = 0; k < ((numberOfFloats - 1)/2); k+=2){
                if ((numbers[k]/numbers[k+1]) > 0){
                    printf("\nNO\n");
                    return 0;
                } 
            }
        printf("\nYES\n");
        return 0;
        }else{
        printf("\nNO\n");
        return 0;
        }
    }

    else if(numberOfFloats % 2 == 0){
        for (int k = 0; k < ((numberOfFloats)/2); k+=2){
            if ((numbers[k]/numbers[k+1]) > 0){
               printf("\nNO\n");
               return 0;
            } 
        }
        printf("\nYES\n");
        return 0;
    }
    return 0;
    // I did it 
}

     
