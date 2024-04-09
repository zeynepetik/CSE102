#include <stdio.h>
#define key 3  /*My student id is 2+2+0+1+0+4+0+0+4+0+3+5=21 and 2+1=3 so key will be 3*/
int main(){
    char input, comment; /*input variable gets the original text and comment variable gets comment line*/
    int comment_length=0; /*comment_length calculates the length of the comment*/
    int incomment=0; /* incomment indicates whether the data we got is in the comment or not*/
 
	char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
		'(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?', 
		'\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4', 
		'5', '6', '7', '8', '9'};
	/*To read all data from the file i started a infinite loop*/
	while(1){
	scanf("%c", &input);
	/*Find the start of the comment*/
	if(input=='/' && !incomment){
		incomment=1;
	}
	else if(input=='*' && incomment){
		/*Not to read comment lines i declared a new variable*/
		while(comment!='*'){
		if(comment!=' ' || comment!='\n' || comment!='\t'){
		scanf("%c", &comment);
		comment_length++;
		}
		}
	}
	/*Find the end of the comment*/
	else if(input=='/' && incomment){
		incomment=0;
		printf(" Z %d",comment_length-4);/* -4 is for star(*) character */
	}
		
	/*print space, new line, tab*/
	else if(!incomment){
	if(input=='\n' || input=='\t' || input==' '){
		printf("%c", input);
		}
	int i;
	for(i=0; i<61; i++){
	/*Ecryption of the data*/
	if((input!='\n') || (input!='\t') || (input!=' ')){
		if(alphabet[i]==input){
		input=alphabet[(i+key)%61];
		printf("%c", input);
		/*To compare data from file with every character of the alphabet i break whenever a new characer comes in*/
		break;
		}
		}
	}
	}
	}
		return 0;
	
	
}
	
