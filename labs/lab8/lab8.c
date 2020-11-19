#include <stdio.h>
#include <string.h>
//Alp Baran Sirek


typedef struct{
    int ID, grade;
    char name[20];

}Student;

int main(int argc, char *argv[]){
    int numberOfStudents = 0;
    int caseNo;
    Student stud;
    Student studs[100];

    FILE *file = fopen("dat.txt", "r");

    while(fread(&stud, sizeof(Student), 1, file)){
        studs[numberOfStudents] = stud;
        numberOfStudents++;
    }

    if(strcmp(argv[1], "-count") == 0){
        caseNo = 1;
    }else if(strcmp(argv[1], "-grade") == 0){
        caseNo = 2;
    }else if(strcmp(argv[1], "-name") == 0){
        caseNo = 3;
    }
    
    int i;
    int k;
    int trueOrFalseTwo;
    int trueOrFalse;
    char firstName[10];
    char lastName[10];
    switch(caseNo){
        case 1:
            printf("%d\n", numberOfStudents);
            break;
        case 2:
            printf("St. ID\tName\n");
            for(i = 0; i < numberOfStudents; i++){
                if(studs[i].grade == argv[2][0]){
                    printf("%d\t%s\n", studs[i].ID, studs[i].name);
                    trueOrFalse = 1;
                }
            }
            if (trueOrFalse != 1){
                printf("No students with the grade of %c\n", argv[2][0]);
            }
            break;
        case 3:
            for(i = 0; i < numberOfStudents; i++){
                for(k = 0; studs[i].name[k] != ' '; k++){
                    firstName[k] = studs[i].name[k];
                }
                if(strcmp(firstName, argv[2]) == 0){
                    printf("%d\t%s\t%c\n", studs[i].ID, studs[i].name, studs[i].grade);
                    trueOrFalseTwo = 1;
                }
            }
            if(trueOrFalseTwo != 1){
                printf("NO such student");
            }
            break;
    }
    return 0;
}