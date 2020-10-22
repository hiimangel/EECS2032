#include <stdio.h>
int main(){
    char cumle[500];
    scanf("%[^\n]s", cumle);
    int i = 0;
    int length = 0;
    int tabSpace_count = 0;
    int word_count = 0;

    while(1){
        int wordorno = 0;
        char harf = cumle[length];
        //if harften sonraki index space ve ya tab ve ya '\0' ise, wordcount ++ olabilir
        
        if ((cumle[length]) == '\0'){
            printf("%d\n%d\n%d\n", length, tabSpace_count, word_count);
            break; 
        }else{
            if (cumle[length] == ' ' || cumle[length] == '\t'){
                tabSpace_count++;
            }
            if ((harf != '\t' && harf != ' ') && (cumle[length + 1] == ' ' || (cumle[length + 1] == '\t' || cumle[length + 1] == '\0' ))){
                word_count++;
            }
            length++;
        }
    }

    return 0;
}
