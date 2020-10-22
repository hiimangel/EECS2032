#include <stdio.h>

int main() {
    char cumle[500];
    scanf("%[^\n]s ", cumle);
       // until the last element is '\0', try it
    int i = 0;
    for(i = 0; cumle[i] != '\0'; i++){
        if (cumle[i] == ' ' || cumle[i] == '\t'){
            printf("%6d\n", i);
            return 0;
        }
    }
    int this_case = 0;
    printf("%6d\n", this_case);
    return 0;
}

