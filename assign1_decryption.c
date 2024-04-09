#include <stdio.h>
#define key 3 /*My student id is 2+2+0+1+0+4+0+0+4+0+3+5=21 and 2+1=3 so key will be 3*/

int main(){
    char input;/*Variable to get encrypted text*/
    int comment;/*Variable to get the number of characters of the original text's comment*/
	char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
		'(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?', 
		'\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4', 
		'5', '6', '7', '8', '9'};
		while(1){
		scanf("%c", &input);
		/*When input variable get the comment marker it gets the number of character of the original text's comment*/
		if(input=='Z'){
			scanf("%d", &comment);
			printf(" /*There's %d characters as comment*/", comment);
			}
		/*print space, new line, tab*/
		if(input==' ' || input=='\n'|| input=='\t'){
			printf("%c", input);
		}
		int i;
		/*Decryption of the data*/
		for(i=0; i<61; i++){
			if(input==alphabet[i]){
				input=alphabet[(i-key+61)%61];
				printf("%c", input);
		/*To compare all of the characters of the encrypted data with every character of the alphabet i break whenever a new characer comes in*/
				break;
			}
		}
		
	}
	return 0;
}
