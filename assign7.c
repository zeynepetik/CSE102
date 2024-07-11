#include <stdio.h>
#define SMALL_CUP 6
#define LARGE_CUP 2
#define COL 5
#define ROW 35
void printBoard();
void initiliazeGame();
void gamePlay();
void move();
void initiliazeGame(int stones, int board[][ROW], int cups[]){
    /*store -4 for all array elements*/
    int k,m;
    for(k=0; k<COL; k++){
        for(m=0; m<ROW; m++){
            board[k][m]=-4;
        }
    }
    /*indicate the border of the board*/
    int j,i;
    for(j=0;j<COL;j++){
        for(i=0;i<ROW;i++){
            /*place the stones for the players*/
            int n;
            for(n=0;n<SMALL_CUP;n++){
                if((j==1||j==3)&&(i==7+4*n)){
                    board[j][i]=4;
                    cups[n]=board[j][i];
                }
                if(((j==2)&&((i==2||i==31)))){
                    board[j][i]=0;
                }
            }           
            if(i!=0 && i!=5 && i!=9 && i!=13 && i!=17 && i!=21 && i!=25 && i!=29 && i!=34){
                if(j==0 || (i>5 && i<29 && j==2) || j==4){
                    /*-1 for - symbol on the table*/
                    board[j][i]=-1;
                } 
            }
            else{
                /*-2 for | symbol on the table*/
                if(j==1 || (j==2 && (i==0 || i==5 || i==29 || i==34)) || j==3){
                    board[j][i]=-2;
                }
                else{
                    /*-3 for + symbol on the table*/
                    board[j][i]=-3;
                }
            }
        }
    }
}
void printBoard(int board[][ROW]){
    printf("            PLAYER\n");
    int i,j;
    for(i=0; i<COL; i++){
        for(j=0; j<ROW; j++){
        /*print symbols according to the given integers*/
            if(board[i][j]==-1){
                printf("-");
            }
            else if(board[i][j]==-2)
                printf("|");
            else if(board[i][j]==-3)
                printf("+");
            else if(board[i][j]==-4)
                printf(" ");
            else{
                printf("%d",board[i][j]);
            }
        }
        printf("\n");
    }
    printf("            COMPUTER\n");
}
void gamePlay(int board[COL][ROW], int cups[]){
    int i,j,n,chosen_cup;
    do{
    /*player choose a cup between 0-5 if not print an error and choose again*/
        printf("Choose a cup between 0 to 5\n");
        scanf("%d", &chosen_cup);
        n=cups[chosen_cup];
        if(chosen_cup<0 || chosen_cup>6)printf("ERROR: ");
        else{
            do{
                for(i=chosen_cup,j=cups[chosen_cup];i>=0, j>0;i--, j--){
                    if(7+4*i==7 && board[1][7]>=1){
                        board[1][7+4*chosen_cup]=0;
                        if(i==1){
                            board[2][2]++;
                        }
                        else{
                            board[2][2]++;
                            i--;
                            board[3][7+4*i]++;
                        }
                        /*call the function to print board's new version*/
                        move(board);
                    }
                }
            }while(board[1][7+4*chosen_cup]==0 || board[3][7+4*chosen_cup]==0);
        }
    /*if the distance between small cup and large cup is equal to the number of stones' -1*/
    /*the loop will stop when stone is in the large cup or next cup is empty*/
    }while(chosen_cup<0 || chosen_cup>6|| (chosen_cup+1==n)|| board[1][7+4*chosen_cup==0]);
}
void move(int board[][ROW]){
/*print the board*/
    printBoard(board);
}
int main(){
/*initiliaze the variables*/
    int stones=4;
    int board[COL][ROW];
    int cups[SMALL_CUP+LARGE_CUP];
    initiliazeGame(stones, board, cups);
    printBoard(board);
    gamePlay(board, cups);
}
