#include <stdio.h>
#include <string.h>
#define LINE 40
#define ROW 5
void search_p1(char str[][LINE], int num_rows,int matches[][2], int * num_matches){
    char pattern[]="***++++***++++***";
    int pat_len=strlen(pattern);
    int i,j,k;
    int index=0;
    for(i=0;i<num_rows;i++){
        /*control if the pattern exists in that line of the array*/
        if(strstr(str[i],pattern)){
            k=0;
            /*if it exits, start to compare elements*/
            while(k<strlen(str[i])){
                for(j=0;j<pat_len;j++){
                    if(str[i][k+j]!=pattern[j]){
                        *num_matches=0;
                        break;
                    }
                    else{
                        (*num_matches)++;
                    }
                }
                /*store the locations*/
                if(*num_matches==pat_len){
                    matches[*num_matches][0]=i+1;/*which row*/
                    matches[*num_matches][1]=k+1;/*which column*/
                    break;
                }
                k++;
            }
        }
    }
}
void search_p2(char str[][LINE], int num_rows,int matches[][2], int * num_matches){
    char pattern[]="+*+*+";
    int pat_len=strlen(pattern);
    int i,j,k;
    int index=0;
    for(i=0;i<num_rows;i++){
        /*control if the pattern exists in that line of the array*/
        if(strstr(str[i],pattern)){
            k=0;
            /*if it exits, start to compare elements*/
            while(k<strlen(str[i])){
                for(j=0;j<pat_len;j++){
                    if(str[i][k+j]!=pattern[j]){
                        *num_matches=0;
                        break;
                    }
                    else{
                        (*num_matches)++;
                    }
                }
                /*store the locations*/
                if(*num_matches==pat_len){
                    matches[*num_matches][0]=i+1;/*which row*/
                    matches[*num_matches][1]=k+1;/*which column*/
                    break;
                }
                k++;
            }
        }
    }
}
void search_p3(char str[][LINE], int num_rows,int matches[][2], int * num_matches){
    char pattern[]="+**+++****+++**+";
    int pat_len=strlen(pattern);
    int i,j,k;
    int index=0;
    for(i=0;i<num_rows;i++){
        /*control if the pattern exists in that line of the array*/
        if(strstr(str[i],pattern)){
            k=0;
            /*if it exits, start to compare elements*/
            while(k<strlen(str[i])){
                for(j=0;j<pat_len;j++){
                    if(str[i][k+j]!=pattern[j]){
                        *num_matches=0;
                        break;
                    }
                    else{
                        (*num_matches)++;
                    }
                }
                /*store the locations*/
                if(*num_matches==pat_len){
                    matches[*num_matches][0]=i+1;/*which row*/
                    matches[*num_matches][1]=k+1;/*which column*/
                    break;
                }
                k++;
            }
        }
    }
}
int main(){
    int index=0,num_matches=0;
    int i,j;
    char pattern[ROW][LINE];
    int matches[LINE][2];
    FILE *fp=fopen("input2.txt", "r");
    if(fp==NULL){
        printf("File could not open\n");
    }
    else{
        /*getting data from the file into the array*/
        while((fgets(pattern[index],LINE,fp))!=0){
            if(pattern[index][strlen(pattern[index])-1]=='\n'){
                pattern[index][strlen(pattern[index])-1]='\0';
                index++;
            }
        }
        search_p1(pattern,ROW,matches,&num_matches);
        /*if index for the matches array is different from the 0*/
        if(num_matches!=0){
            printf("P1 @ (%d,%d)\n", matches[num_matches][0],matches[num_matches][1]);
        }
        else{
            printf("P1 does not exist in the file\n");
        }
        num_matches=0;
        search_p2(pattern,ROW,matches,&num_matches);
        if(num_matches!=0){
            printf("P2 @ (%d,%d)\n", matches[num_matches][0],matches[num_matches][1]);
        }
        else{
            printf("P2 does not exist in the file\n");
        }
        num_matches=0;
        search_p3(pattern,ROW,matches,&num_matches);
        if(num_matches!=0){
            printf("P3 @ (%d,%d)", matches[num_matches][0],matches[num_matches][1]);
        }
        else{
            printf("P3 does not exist in the file\n");
        }
    }
    
}
