#include <stdio.h>

int main(){
    int nxm;
    scanf("%d", &nxm);
    double sistemA[nxm][nxm];
    double sistemB[nxm][nxm];
    int i;
    int j;
    for(i = 0; i < nxm; i ++){ // the inpput system for the sysofequations(matrix) A
        for(j = 0; j < nxm; j++){
            double entry;
            scanf("%la", &entry);
            sistemA[i][j] = entry;
        }
    }
    for(i = 0; i < nxm; i ++){ // the inpput system for the sysofequations(matrix) B
        for(j = 0; j < nxm; j++){
            double entry;
            scanf("%la", &entry);
            sistemB[i][j] = entry;
        }
    }
    // testing if it works printf("%f\n", sistem[1][1]);
    int p;
    int o;
    double sumB;
    int isittrue = 1;
    for(p = 0; p < nxm; p++){
        sumB = 0;
        for(o = 0; o < nxm; o++){
            if(o != p){sumB = sumB + sistemB[p][o];}    
        }
        if(sistemA[p][p] < sumB){
            isittrue = 0;
            break;
        }
    }
    if(isittrue){
    printf("Diag(A) is greater than or equal rows of B\n");
    }
    return 0;
}