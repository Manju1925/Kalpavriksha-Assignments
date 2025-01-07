#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_LENGTH 50

int main(){
    int row, col;

    printf("Enter number of rows: ");
    scanf("%d",&row);
    printf("Enter number of columns: ");
    scanf("%d",&col);

    if(row<1 || row>10 || col<1 || col>101){
        printf("Invalid Input\n");
        return 0;
    }

    char names[row][col][NAME_LENGTH];
    char longest_name[NAME_LENGTH] = "";
    int count = 0; 

    printf("Enter the names: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("Name at (%d,%d): ",i,j);
            scanf("%s", names[i][j]);

            char ch=tolower(names[i][j][0]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                count++;
            }

            if(strlen(names[i][j]) > strlen(longest_name)){
                strcpy(longest_name, names[i][j]);
            }
        }
    }

    printf("The 2D array of names is:\n");
    for(int i=0; i<row; i++){
        for (int j=0; j<col; j++) {
            printf("%s ",names[i][j]);
        }
        printf("\n");
    }

    printf("Number of names starting with a vowel: %d\n",count);
    printf("The longest name: %s\n",longest_name);

    return 0;
}