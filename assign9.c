#include <stdio.h>
#include <string.h>
#define ROW 100
#define COL 100
/*declare user defined types*/
typedef struct{
    char map[ROW][COL];
    int width;
    int height;
    /*total_flower variable to store number of flowers*/
    int total_flower;
    int flower_x[ROW];
    int flower_y[COL];
}Forest;
typedef struct{
    int coord_X;
    int coord_Y;
    int number_of_bottle;
}Botanist;
void init_game(Forest *forest, Botanist *botanist){
    char sign;
    int ind_x=0, ind_y=0, ind_flower=0;
    (*forest).total_flower=0;
    FILE *fp=fopen("init.txt", "rt");
    if(fp==NULL){
        printf("File could not open");
    }
    else{
        /*get related data from the file*/
        fscanf(fp,"%d,%d",&(*forest).width, &(*forest).height);
        fscanf(fp,"%d,%d,%d\n", &(*botanist).coord_Y,&(*botanist).coord_X,&(*botanist).number_of_bottle);
        while((feof(fp))==0){
            sign=fgetc(fp);
            /*if taken character from the file is not comma nor new line character*/
            if(sign!=',' && sign!='\n'){
                forest->map[ind_x][ind_y]=sign;
                ind_y++;
                /*when it encounters with X increment total flowers and index for the flower_x and flower_y*/
                if(sign=='X'){
                    (*forest).total_flower++;
                    forest->flower_x[ind_flower]=ind_x;
                    forest->flower_y[ind_flower]=ind_y;
                    ind_flower++;
                }
            }
            /*when it encounters with new line character reset the index for columns and increment the index for rows*/
            if(sign=='\n'){
                /*add null character at the end of the array*/
                forest->map[ind_x][ind_y]='\0';
                ind_x++;
                ind_y=0;
            }
        }
    }
    fclose(fp);
}
void display_forest(Forest forest, Botanist botanist){
    int i,j;
    /*print the board according to its width and height*/
    for(i=0;i<forest.height;i++){
        for(j=0;j<forest.width;j++){
            printf("%c ",forest.map[i][j]);
        }
        printf("\n");
    }
    /*print related informations*/
    printf("Remained flower: %d\n", forest.total_flower);
    printf("Remained bottle: %d\n", botanist.number_of_bottle);
    printf("Coordinations of the botanist: [%d,%d]\n",botanist.coord_X, botanist.coord_Y);
}
void search(Forest *forest, Botanist *botanist, char *move) {
    /*store the first coordination of the botanist to variables*/
    int new_x = botanist->coord_X;
    int new_y = botanist->coord_Y;
    /*get the users movement*/
    printf("Enter your move\n");
    scanf(" %c", move);
    switch (*move) {
        /*change location variables according to user's movement*/
        case 'u': new_y--; break;
        case 'd': new_y++; break;
        case 'l': new_x--; break;
        case 'r': new_x++; break;
        case 'e': return; break;
        default: printf("Invalid move\n"); return;
    }
    /*control if the new locations are on the board*/
    if (new_x >= 0 && new_x < forest->width && new_y >= 0 && new_y < forest->height) {
        /*if new location is on the tree*/
        if (forest->map[new_y][new_x] == 'T') {
            /*prompt a warning and return*/
            printf("There's a tree\n");
            return;
        } else {
            if (forest->map[new_y][new_x] == 'X') {
                /*if new location is on the X update botanist position*/
                forest->map[botanist->coord_Y][botanist->coord_X]=' ';
                botanist->coord_X = new_x;
                botanist->coord_Y = new_y;
                forest->map[botanist->coord_Y][botanist->coord_X]='B';
                /*update remained flowers and bottles*/
                forest->total_flower--;
                botanist->number_of_bottle--;
                /*print the message*/
                printf("I've found it!\n");
                display_forest(*forest, *botanist);
            } else {
                /*if new location is just a space character the just update the botanist position*/
                forest->map[botanist->coord_Y][botanist->coord_X]=' ';
                botanist->coord_X = new_x;
                botanist->coord_Y = new_y;
                forest->map[botanist->coord_Y][botanist->coord_X]='B';
                display_forest(*forest, *botanist);
            }
        }
    } else {
        /*if new locations are not on the map return*/
        printf("Invalid direction\n");
        return;
    }
    /*else call the function recursively*/
        search(forest, botanist, move);
}

int main(){
    /*declare the variables*/
    Forest forest;
    Botanist botanist;
    char move;
    init_game(&forest, &botanist);
    display_forest(forest, botanist);
    while(forest.total_flower!=0){
        search(&forest, &botanist, &move);
        /*if user wants to quit */
        if(move=='e'){
            printf("Exitting...\n");
            break;
        }
    }
    /*if all flowers found print the message*/
    if(forest.total_flower==0){
        printf("All flowers found!\n");
    }
    /*open a file to store the last version of the game*/
    FILE *fp=fopen("last_view.txt", "wt");
        int i,j;
        /*write map's last view to the file*/
        for(i=0;i<forest.height;i++){
        for(j=0;j<forest.width;j++){
            fprintf(fp,"%c ",forest.map[i][j]);
        }
        fprintf(fp,"\n");
    }
    /*write last updates to the file*/
    fprintf(fp,"Remained flower: %d\n", forest.total_flower);
    fprintf(fp,"Remained bottle: %d\n", botanist.number_of_bottle);
    fprintf(fp,"Coordinations of the botanist: [%d,%d]\n",botanist.coord_X, botanist.coord_Y); 
}
