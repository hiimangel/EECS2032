#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//Alp Baran Sirek
//217329251
int main(){
    char words[50000];
    /*
    FILE *dosya;
    dosya = fopen(dosyaName, "r");
    */
    char c = ':'; 
    int i = 0;
    double alpArr[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0, 0, 0};
    int count = 0;
    while(c != EOF){
        c = getchar();
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
            words[i] = c;
            words[i] = tolower(words[i]);
            i++;
            count++;
        }
    }
    int k = 0;
    while(words[k] != '\0'){
        alpArr[words[k] - 97]+= 1;  
        k++;
    } 

    int o;
    for(o = 0; o<26; o++){
        printf("%c:\t%%%0.2lf\n", o + 65, (alpArr[o]/(double)count) * 100);
    }
    return 0;
}