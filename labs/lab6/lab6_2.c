#include <stdio.h>

int main(){
    char cumle[500];
    scanf("%[^\n]s", cumle);
    int c = 0; 
    int numberOfAlp;
    while(cumle[c] != '\0'){
        c++;
    }

    int i;
    for(i = 0; i < c - 2; i++){
        char ilkharf = cumle[i];
        int difference1 = cumle[i+1] - ilkharf;
        int difference2 = cumle[i+2] - ilkharf;

        if(difference1 == 33 || difference1 == -31 || difference1 == 1){
            if(difference2 == 34 || difference2 == -30 || difference2 == 2){
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;

} 
   
