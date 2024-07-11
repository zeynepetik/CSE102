#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SUIT 4
#define FACE 13
#define MAX_COORD 5

typedef struct{
    const char *face;
    const char *suit;
}Card;

typedef struct{
    char *name;
    char cities_served[3];
}Hospital;

int numPathsHome(int street, int avenue){
    int num_str, num_ave;
    if(street==1&&avenue==1){
        return 1;
    }
    if(street==1){
        return numPathsHome(street, avenue-1);
    }
    if(avenue==1){
        return numPathsHome(street-1, avenue);
    }
    return numPathsHome(street-1, avenue)+numPathsHome(street, avenue-1);
}
void part_1(int street, int avenue){
    printf("Enter the street number: \n");
    do{
        /*get street coordinate until right value is entered*/
        scanf("%d", &street);
        if(street<1 || street>MAX_COORD)
        printf("Street number should be in between 1-%d\n", MAX_COORD);
    }while(!(street<=MAX_COORD && street>=1));
    printf("Street: %d\n", street);
    printf("Enter the avenue: ");
    do{
        /*get avenue coordinate until right value is entered*/
        scanf("%d", &avenue);
        if(avenue<1 || avenue>MAX_COORD)
        printf("Avenue should be in between 1-%d\n", MAX_COORD);
    }while(!(avenue<=MAX_COORD && avenue>=1));
    printf("Avenue: %d\n", avenue);
    int num_path=numPathsHome(street, avenue);
    /*print the optional paths*/
    printf("Number of optional paths to take back home: %d\n\n", num_path);
}

int HealthCare(Hospital *hospital,int hospital_num,int hospital_to_be_const,int *not_served){
    int i,j,k;  
    if(strlen(hospital[hospital_num].cities_served)==0){
        return 0;
    }  
    /*if user desired number of hospitals is less than covered hospitals*/
    if(strlen(hospital[hospital_num].cities_served)<hospital_to_be_const)
        return 1;
    return HealthCare(hospital,hospital_num-1,hospital_to_be_const,not_served);
}

void shuffle_Cards(Card deck[]){
    /*seed the random number*/
    srand(time(NULL));
    Card temp;
    int i=0;
    while(i<FACE*SUIT){
        /*generate random and according to that shuffle the deck*/
        int random=rand()%FACE*SUIT;
        temp=deck[i];
        deck[i]=deck[random];
        deck[random]=temp;
        i++;
    }
}
void print_Deck(const Card *deck){
    int i,j;
    /*i is increased by two to print two cards in a row*/
    for(i=0;i<SUIT;i+=2){
        for(j=0;j<FACE;j++){
            /*adjust the spaces and print the cards*/
            printf("%5s of %-8s%10s of %s\n", deck[i*FACE+j].face,deck[i*FACE+j].suit,deck[(i+1)*FACE+j].face,deck[(i+1)*FACE+j].suit);
        }
    }
}
int main(){
    int street, avenue;
    /*call the part_1 function for part 1*/
    part_1(street, avenue);

    Card deck[SUIT*FACE];
    /*array of strings to store suits and faces*/
    char *faces[]={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", 
    "Jack", "Queen", "King"};
    char *suits[]={"Hearts", "Diamonds", "Clubs", "Spades"};
    int i,j;
    /*store the cards*/
    for(i=0;i<SUIT;i++){
        for(j=0;j<FACE;j++){
            deck[i*FACE+j].face=faces[j];/*face de faces[] de bir adrese ulaşıyor*/
            deck[i*FACE+j].suit=suits[i];
        }
    }
    /*call the function to shuffle the deck*/
    shuffle_Cards(deck);
    /*call the function to print shuffled deck*/
    print_Deck(deck);

    int hospital_to_be_constructed;
    Hospital hospital[]={"Hospital 1", {'A', 'B', 'C'},"Hospital 2",{'A', 'C', 'D'},"Hospital 3",{'B', 'F'},"Hospital 4",{'C', 'E','F'}};
    char cities[]={ 'A', 'B', 'C', 'D', 'E', 'F'};
    /*number of city*/
    int size_city=sizeof(cities)/sizeof(cities[0])-1;/*-1 for null character*/
    /*number of hospitals*/
    int num_Hospital=sizeof(hospital)/sizeof(Hospital);
    int served=0;
    /*maximum served hospital*/
    int max_served_hospital=strlen(hospital->cities_served);
    /*ask user to desired number of huspital*/
    printf("Enter the maximum number of hospitals that can be constructed: ");
    scanf("%d", &hospital_to_be_constructed);
    /*call function and according to the result print the warning*/
    int result=HealthCare(hospital,num_Hospital,hospital_to_be_constructed,&served);
    if(result==1)printf("some cities are not covered\n");
    else{
        printf("can offer health care to all\n");
    }
}