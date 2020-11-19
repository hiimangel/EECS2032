#include <stdio.h>

int main(){
    float num_first;
    float num_second;
    float num_aftercalc;
    char num_instring[150];
    scanf("%f", &num_first);
    scanf("%f", &num_second);

    num_aftercalc = num_first + num_second;
    sprintf(num_instring, "%f", num_aftercalc);
    int i = 0;

    while(1){ //finding the index of dot.
        if (num_instring[i] == '.'){
            break;
        }
        i++;
    }

    int k = 0;
    int j = i - 1; 
   
    while (k < j)
    {
       char oylesine = num_instring[k];
       num_instring[k] = num_instring[j];
       num_instring[j] = oylesine;
       k++;
       j--;
    }

    printf("%s\n", num_instring);



    return 0;
}
