#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 16
#define FIRST_COURSE 4
#define SECOND_COURSE 3
#define WALL_IN 8
#define WALL_OUT 24
char board[256];
int inner_wall[WALL_IN], outer_wall[WALL_OUT];
int player_row, player_col;
int ECTS=0;
void initialize_game(){
  int i, j;
  int first,second,course_counter1=0,course_counter2=0;
  int inner_index=0, outer_index=0;
  for(i=0; i<BOARD_SIZE; i++){
    for(j=0; j<BOARD_SIZE; j++){
      /*Indicate X's place for ending*/
      if(i==BOARD_SIZE-1 && j==BOARD_SIZE-1){
        board[i*BOARD_SIZE+j]='X';
      }
      /*Indicate borders for inner wall*/
      else if((i == 6 && j >=6 && j<11) || (i ==10 && j >=6 && j <11)||( i>6 && i<11 && j==6) ||( i>6 && i<11 && j==10)){
        board[i*BOARD_SIZE+j]='#';
      }
      /*Indicate borders for outer wall*/
      else if((i ==4 && j >=4 && j <13) || (i == 12 && j >=4 && j <13)||( i>4 && i<13 && j==4)||( i>4 && i<13 && j==12)){
        board[i*BOARD_SIZE+j]='#';
      }
      /*Indicate points where first course may be placed*/
      else if((j==7 && i>=6 && i<=8) ||(j==9 && i>=6 && i<=8) ||(i==7 && j>=6 && j<=9) ||(i==9 && j>=6 && j<=9)){
        board[i*BOARD_SIZE+j]= '.';
        inner_wall[inner_index]=i*BOARD_SIZE+j;
        inner_index++;  
      }
      /*Indicate points where the second course may be placed*/
      else if((j==5 && i>=4 && i<=10) ||(j==11 && i>=4 && i<=10) ||(i==5 && j>=4 && j<=10) ||(i==11 && j>=4 && j<=11)){
        board[i*BOARD_SIZE+j]= '.';
        outer_wall[outer_index]=i*BOARD_SIZE+j;
        outer_index++;  
      }
      else{
        /*Place dot(.) for the spaces*/
        board[i*BOARD_SIZE+j]='.';
      }
    }
  }
  srand(time(0));/*Seed the random number*/
  /*Place first course randomly*/
  while(course_counter1<FIRST_COURSE){
    first=inner_wall[rand()%WALL_IN];
    if(board[first]=='.'){
      board[first]='1';
      course_counter1++;
    }
  }
  /*Place second course randomly*/
  while(course_counter2<SECOND_COURSE){
    second=outer_wall[rand()%WALL_OUT];
    if(board[second]=='.'){
      board[second]='2';
      course_counter2++;
    }
  }
  /*indicate player's location*/
  player_row=BOARD_SIZE/2;
  player_col=BOARD_SIZE/2;
  board[player_col*BOARD_SIZE+player_row]='P';  
}
void print_game(){
  int a,b;
  for(a=0; a<BOARD_SIZE; a++){
    for(b=0; b<BOARD_SIZE; b++){
      printf("%c  ", board[a*BOARD_SIZE+b]);
    }
    printf("\n");
  }
}
void move_player(char direction){
  /*Calculate new place of player*/
  int new_row=player_row;
  int new_col= player_col;
  switch(direction){
    case 'a': new_row--;
    break;
    case 'A': new_row--;
    break;
    case 'd': new_row++;
    break;
    case 'D': new_row++;
    break;
    case 's': new_col++;
    break;
    case 'S': new_col++;
    break;
    case 'w': new_col--;
    break;
    case 'W': new_col--;
    break;
    default: printf("Invalid move\n");
    return;
  }
  /*Update player's position according to given conditions*/
  if((ECTS<32)&& !(new_col>=7 && new_col<10 && new_row>=7 && new_row<10)){
    printf("Can Not Move There\n");
    return;
  }
  else if(ECTS<56 && !(new_col>=5 && new_col<12 && new_row>=5 && new_row<12)){
    printf("Can Not Move There\n");
    return;
  }
  else if(new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE){
    printf("Can Not Move There\n");
    return;
  }
  else{
  /*Do not change walls with dot when player pass through it*/
    if((player_col== 6 && player_row>=6 && player_row<11) || (player_col==10 && player_row>=6 && player_row<11)||( player_col>6 && player_col<11 && player_row==6) ||( player_col>6 && player_col<11 && player_row==10)){
     board[player_col*BOARD_SIZE+player_row]='#'; 
    }
    else if((player_col==4 && player_row>=4 && player_row<13) || ( player_col== 12 && player_row>=4 && player_row<13)||(  player_col>4 &&  player_col<13 && player_row==4)||(player_col>4 && player_col<13 && player_row==12)){
      board[player_col*BOARD_SIZE+player_row]='#';
    }
    /*If the point player passed is not a wall*/
    else{
      board[player_col*BOARD_SIZE+player_row]='.';
    }
    /*Update ECTS and players position*/
    player_row=new_row;
    player_col=new_col;
    if(board[player_col*BOARD_SIZE+player_row]=='1' || board[player_col*BOARD_SIZE+player_row]=='2'){
      ECTS+=8;
    }
    board[player_col*BOARD_SIZE+player_row]='P';
  }
}
int main(){
/*Call the related functions and print the game table's first version*/
  initialize_game();
  print_game();
  /*Take a character and move the player according to that value*/
  char move;
  while(1){
    printf("Total ECTS: %d\n", ECTS);
    printf("Enter Your Move\nW(up), A(left), S(down), D(right), E(exit)\n");
    scanf(" %c", &move);
    move_player(move);
    print_game();
    /*When player gets to X's place break the loop and end the game*/
    if(board[(BOARD_SIZE-1)*BOARD_SIZE+BOARD_SIZE-1]=='P'){
      printf("You stepped on the X\nGame Over");
      break;
    }
  }
  return 0;
}
