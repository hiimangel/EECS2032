#include <stdio.h>

int main(){

        int a;

        scanf("%d", &a);
        float array[a];
        for (int index = 0; index < a; index++){
            scanf("%f", &array[index]);
        }
        int i=0;

        while ( i < a && i + 1 != a )  {
        float abc = array[i];
        float xyz = array[i+1];
        float num = abc*xyz;


        if ( num > 0 ) {
            printf("NO\n");
                return 0;
            }
            i++;
        }
        printf("YES\n");
return 0;
}