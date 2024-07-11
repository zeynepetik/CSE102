#include <stdio.h>
#include <string.h>
#define SCIENTIST 25
#define INFO 5
#define MAX_FIELD 50
#define MAX_CHAR 2000
#define DELIM ",\n\r"
void remove_space(char list[SCIENTIST][INFO][MAX_FIELD]){
    int i,j,k;
    for(i=0;i<SCIENTIST;i++){
        for(j=0;j<INFO;j++){
            for(k=0;k<MAX_FIELD;k++){
                /*if there is a space character in between information and comma*/
                if(list[i][j][k]==' ' && list[i][j][k+1]!=' '){
                    do{
                        /*shift the elements of the array until \0 character*/
                        list[i][j][k]=list[i][j][k+1];
                        k++;
                    }while(list[i][j][k]!='\0');list[i][j][k+1]='\0';/*be sure last element is null*/
                }
                else{
                    break;
                }
            }
        }
    }
}
void fill_str_array(char list[SCIENTIST][INFO][MAX_FIELD], int *num_sci){
    char line[MAX_CHAR];/*temprory array to get datas line b line*/
    char *token;/*it will store the value that strtok returned*/
    int index=0;
    FILE *fp=fopen("input1.txt", "r");
    if(fp==NULL){
        printf("File could not open\n");
    }
    else{
        /*getting data from the file*/
        while((fgets(line, MAX_CHAR, fp))){
            /*when it encounters \n it will chnge it into \0*/
        	if(line[strlen(line)-1]=='\n'){
        		line[strlen(line)-1]='\0';
        	}
            /*takes the data until it encounters with \n or ,*/
            token=strtok(line, DELIM);
            /*store the value that strtok returned to the original array*/
            while(token!=NULL){      	
                strcpy(list[*num_sci][index], token);
                token=strtok(NULL, DELIM);
                index++;
            }
            (*num_sci)++;
            index=0;
        }
    }
    fclose(fp);
}
void sort_people_by_age(char list[SCIENTIST][INFO][MAX_FIELD]){
	int i,j,k;
    char temp[MAX_FIELD];
    int age_col=2;/*column that age informations stored*/
    for(i=0;i<SCIENTIST-2;i++){
        for(j=1;j<SCIENTIST-i-2;j++){
            /*compare adjacent elements and swap them if it is necessary*/
            if((strcmp(list[j-1][age_col], list[j][age_col]))>0){
                for(k=0;k<INFO;k++){
                    strcpy(temp,list[j-1][k]);
                    strcpy(list[j-1][k],list[j][k]);
                    strcpy(list[j][k],temp);
                }
            }
        }
    }
}
void sort_people_by_branch(char list[SCIENTIST][INFO][MAX_FIELD]){
    int i,j,k,n;
    char temp[MAX_FIELD];
    int branch_col1=3, branch_col2=4;/*columns that store branches*/
    int age_col=2;/*column that store age*/
    for(i=0;i<SCIENTIST-2;i++){
        for(j=1;j<SCIENTIST-i-2;j++){
            /*compare branches*/
            if((strcmp(list[j-1][branch_col1], list[j][branch_col1]))>0){
                for(k=0;k<INFO;k++){
                    strcpy(temp,list[j-1][k]);
                    strcpy(list[j-1][k],list[j][k]);
                    strcpy(list[j][k],temp);
                }
            }
        }
    }
    for(i=0;i<SCIENTIST-2;i++){
        for(j=1;j<SCIENTIST-i-2;j++){
            /*compare age and branches and swap data if it is necessary*/
            if((strcmp(list[j-1][branch_col1],list[j][branch_col1]))==0 && (strcmp(list[j-1][branch_col2],list[j][branch_col2]))==0 && (strcmp(list[j-1][age_col],list[j][age_col]))>0){
                for(n=0;n<INFO;n++){
                    strcpy(temp,list[j-1][k]);
                    strcpy(list[j-1][k],list[j][k]);
                    strcpy(list[j][k],temp);
                }
            }
        }
    }
}
void filter_people_by_branch(char list[SCIENTIST][INFO][MAX_FIELD]){
    char branch[] = "SCIENCE";
    int branch_col1 = 3, branch_col2 = 4;
    int branch_len = strlen(branch);
    int i, j;
    for (i = 0; i < SCIENTIST; i++) {
        /*control if given branch exists for that scientist*/
        if (strstr(list[i][branch_col1], branch) != NULL || strstr(list[i][branch_col2], branch) != NULL) {
            /*if the branch name is found in one of the columns, print the information*/
            for (j = 0; j < INFO; j++){
                printf("%-20s", list[i][j]);
            }
            printf("\n");
        }
    }
}
void filter_people_by_profession(char list[SCIENTIST][INFO][MAX_FIELD]){
    int i,j, branch_col1=3, branch_col2=4;
    char branch1[]="MATHEMATICS", branch2[]="COMPUTER SCIENCE";
    for (i = 0; i < SCIENTIST; i++) {
        /*control if computer science exists and mathematichs does not exist*/
        if ((strstr(list[i][branch_col1], branch1) == NULL && strstr(list[i][branch_col2], branch2) != NULL) || (strstr(list[i][branch_col1], branch2) != NULL && strstr(list[i][branch_col2], branch1) == NULL)) {
            for (j = 0; j < INFO; j++){
                printf("%-20s", list[i][j]);
            }
            printf("\n");
        }
    }
}
int main(){
    int menu;
    char list[SCIENTIST][INFO][MAX_FIELD];
    int num_sci=0;
    int i,j,k;
    /*fill array with \0 to prevent confusions*/
    for(i=1;i<SCIENTIST;i++){
        for(j=0;j<INFO;j++){
            for(k=0;k<MAX_FIELD;k++){
                list[i][j][k]='\0';
            }
        }
    }
    /*call the functions to storeinformations into the array*/
    fill_str_array(list, &num_sci);
    remove_space(list);
    printf("*******MENU******\n");
    printf("1. Sort and display all individuals by age\n");
    printf("2. Sort and display in the branch by age\n");
    printf("3. Show individuals with branch 'SCIENCE'\n");
    printf("4. Show computer scientists who are not mathematicians\n");
    printf("5. Exit\n");
    do{
        printf("Make a choice from the menu\n");
        scanf("%d", &menu);
        switch(menu){
            case 1:
            sort_people_by_age(list);
                printf("Name                 Surname            Age                 Branch1                 Branch2\n");
                for(i=0;i<num_sci;i++){
                    for(j=0;j<INFO;j++){
                        printf("%-20s",list[i][j]);
                    }
                    printf("\n");
                }
            break;
            case 2:
                sort_people_by_branch(list);
            	printf("Name                 Surname            Age                 Branch1                 Branch2\n");
                for(i=0;i<num_sci;i++){
                    for(j=0;j<INFO;j++){
                        printf("%-20s",list[i][j]);
                    }
                    printf("\n");
                }
            break;
            case 3:
                printf("Name                 Surname            Age                 Branch1                 Branch2\n");
                filter_people_by_branch(list);
            break;
            case 4:
                printf("Name                 Surname            Age                 Branch1                 Branch2\n");
                filter_people_by_profession(list);
            break;
            case 5: printf("exitting...\n");
            break;
            default:printf("Choose a valid menu\n");
            break;
        }
    }while(menu!=5);
}
