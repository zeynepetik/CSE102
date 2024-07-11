#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
#define SIZE 15
#define OPCODE 30
/*declare the struct type*/
typedef struct{
    char opcode[9];
    char type;
    char format[SIZE];
    char exp[MAX_LEN];
}instruction;
void read_instruction(FILE *fp, instruction ins_set[]){
    if(fp==NULL){
        printf("File could not open\n");
    }
    else{
        int index=0;
        /*get the instructions from the file*/
        while (fscanf(fp, "%[^|]|%c|%[^|]|%[^\n]\n", ins_set[index].opcode, &ins_set[index].type, ins_set[index].format, ins_set[index].exp) == 4 && index<OPCODE) {
            index++;
        }
    }
}
/*convert decimal number to binary*/
int to_binary(int dec_number){
    int binary= 0, digit= 1;
    while (dec_number > 0) {
        binary += (dec_number % 2) * digit;
        dec_number =dec_number/2;
        digit*= 10;
    }
    return binary;
}
/*convert binary to decimal number*/
int to_decimal(char binary[]){
    int dec_number = 0;
    for (int i = 0; i < 8; i++) {
        dec_number = dec_number * 2 + (binary[i] - '0');
    }
    return dec_number;
}
int main(){
    char asm_file[MAX_LEN];
    char A[8], B[8];
    int PC[16],IR[24];
    int yes_no=1;
    instruction ins_set[OPCODE];
    FILE *fp_ins=fopen("instructions 1.txt", "rt");
    read_instruction(fp_ins,ins_set);
    do{
        if(yes_no==1){
            /*get the input file from the user*/
            printf("Enter the filename with .asm extension\n");
            scanf("%s", asm_file);
            if ((strstr(asm_file, ".asm")) != NULL) {
                FILE *fp_asm = fopen(asm_file, "r");
                printf("Do you want to continue? if yes press 1 else press 0\n");
                scanf("%d",&yes_no);
            }
            else{
                /*if user do not enter .asm file*/
                printf("Enter the filename with .asm extension\n");
                scanf("%s", asm_file);
            }
        }
        if(yes_no!=0 && yes_no!=1){
            printf("invalid choice\n try again!\n");
            scanf("%d",&yes_no);
        }
    }while(yes_no!=0);
    printf("exitting...\n");
    fclose(fp_ins);
}
