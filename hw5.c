#include <stdio.h>
/*if a is chosen from the menu*/
void menu_a(char news){
    char yes_no,option,ch;
    	/*It opens and takes data according to the chosen file*/
        if(news=='1'){
            FILE *text_fp=fopen("1.txt", "r");
            /*Control whether file is open or not*/
            if(text_fp==NULL){
                printf("Could not open the file\n");
            }
            else{
            	int i;
            	/*Take data from the file and print them on screen*/
                while((fscanf(text_fp, "%c", &ch))!=EOF){
                printf("%c", ch);
                if(ch=='\0'){
                    printf("\n");
                }
                }
            }
            /*Close the file for the next operations*/
            fclose(text_fp);
        }
        if(news=='2'){
            FILE *text_fp=fopen("2.txt", "r");
            /*Control whether file is open or not*/
            if(text_fp==NULL){
                printf("Could not open the file\n");
            }
            else{
            	while((fscanf(text_fp, "%c", &ch))!=EOF){
                printf("%c", ch);
                if(ch=='\0'){
                    printf("\n");
                }
                }  
            }
            /*Close the file for the next operations*/
            fclose(text_fp);
        }
        if(news=='3'){
            FILE *text_fp=fopen("3.txt", "r");
            /*Control whether file is open or not*/
            if(text_fp==NULL){
                printf("Could not open the file\n");
            }
            else{
            	while((fscanf(text_fp, "%c", &ch))!=EOF){
                printf("%c", ch);
                if(ch=='\0'){
                    printf("\n");
                }
                }
            }
            /*Close the file for the next operations*/
            fclose(text_fp);
        }
        if(news=='4'){
            FILE *text_fp=fopen("4.txt", "r");
            /*Control whether file is open or not*/
            if(text_fp==NULL){
                printf("Could not open the file\n");
            }
            else{
            	while((fscanf(text_fp, "%c", &ch))!=EOF){
                printf("%c", ch);
                if(ch=='\0'){
                    printf("\n");
                }
                }
            }
            /*Close the file for the next operations*/
            fclose(text_fp);
        }
}
/*Function for menu b*/
void menu_b(){
    char ch;
    printf("Readed news are listed below:\n");
    FILE *readed_fp=fopen("readed_news_id.txt","r");
    if(readed_fp==NULL){
    	printf("File could not open\n");
    }
    else{
    	/*Read the file until the end of the file and take characters*/
    	while((fscanf(readed_fp, "%c", &ch))!=EOF){
        	printf("%c. new is readed\n",ch);
    	}
    }
    /*Close the file for the next operations*/
    fclose(readed_fp);
}
/*Function for menu c*/
void menu_c(char news){
    int magic;
    int key=0;
    char ch;
    /*It will open the file according to the chosen file and do the operations*/
    if(news=='1'){
        FILE *text_fp=fopen("1.txt", "r");
        /*Control whether file is open or not*/
        if(text_fp==NULL){
                printf("Could not open the file\n");
        }
        else{
        /*Strats to take data from the file until the end of the file*/
        while((fscanf(text_fp,"%c",&ch))!=EOF){
            /* when it encounters with the # sign it will take the integer next to it and will perform the operation*/
            if(ch=='#'){
                fscanf(text_fp,"%d",&magic);
                key=key+(magic*magic*magic-magic*magic+2)*(magic*magic*magic-magic*magic+2);
            }
        }
        }
        /*Close the file for the next operations*/
        fclose(text_fp);
    }
    if(news=='2'){
        FILE *text_fp=fopen("2.txt", "r");
        if(text_fp==NULL){
                printf("Could not open the file\n");
        }
        else{
        while((fscanf(text_fp,"%c",&ch))!=EOF){
            if(ch=='#'){
                fscanf(text_fp,"%d",&magic);
                key=key+(magic*magic*magic-magic*magic+2)*(magic*magic*magic-magic*magic+2);
            }
        }
        }
        /*Close the file for the next operations*/
        fclose(text_fp);
    }
    if(news=='3'){
        FILE *text_fp=fopen("3.txt", "r");
        if(text_fp==NULL){
                printf("Could not open the file\n");
        }
        else{
        while((fscanf(text_fp,"%c",&ch))!=EOF){
            if(ch=='#'){
                fscanf(text_fp,"%d",&magic);
                key=key+(magic*magic*magic-magic*magic+2)*(magic*magic*magic-magic*magic+2);
            }
        }
        }
        /*Close the file for the next operations*/
        fclose(text_fp);
    }
    if(news=='4'){
        FILE *text_fp=fopen("4.txt", "r");
        if(text_fp==NULL){
                printf("Could not open the file\n");
        }
        else{
        while((fscanf(text_fp,"%c",&ch))!=EOF){
            if(ch=='#'){
                fscanf(text_fp,"%d",&magic);
                key=key+(magic*magic*magic-magic*magic+2)*(magic*magic*magic-magic*magic+2);
            }
        }
        }
        /*Close the file for the next operations*/
        fclose(text_fp);
    }
    /*print the result and reset the key for the next operations*/
    printf("Key Value: %d\n", key);
    key=0;
}
/*Function to control if the chosen file is readed before*/
int read_control(char news){
    char ch, yes_no;
    /*Open the file*/
    FILE *readed_fp=fopen("readed_news_id.txt", "r");
    if(readed_fp==NULL){
                printf("Could not open the file\n");
     }
     else{  
    /*Take and control if chosen file is in the file*/
    while((fscanf(readed_fp, "%c", &ch))!=EOF){
        /*If chosen ile had opened ask if they want to read it again*/
        if(ch==news){
            printf("This news is readed. Do you want to read it again? Yes(1)/No(0)\n");
            scanf(" %c", &yes_no);
            /*If yes then go to menu_a() to print it again*/
            if(yes_no=='1'){
                menu_a(news);
                return 1;
            }
            else{
                return 1;
            }
        }
    }
    }
    /*Close the file for the next operations*/
    fclose(readed_fp);
    /*If file had not opened then return 0*/
    return 0;
}
void menu(){
    char choice, yes_no, news;
    /*Print the opening*/
    printf("******* Daily Press *******\n");
    printf("Today's news are listed for you :\n");
    printf("Title of 1. news:Astronot Alperen Gezeravcı'nın Dünya'ya dönüşü ertelendi\n");
    printf("Title of 2. news:Bakan Kacır, Astronot Gezeravcı ile Videokonferans Görüşmesi Gerçekleştirdi\n");
    printf("Title of 3. news:Alper Gezeravcı uzayda 9. deneyini yaptı\n");
    printf("Title of 4. news:Astronotların uzaydaki ilk sözleri\n");
    /*Start a do wihle loop to show menu on and on*/
    do{
        printf("What do you want to do?\n");
        printf("a. Read a new\n");
        printf("b. List the readed news\n");
        printf("c. Get decrypted information from the new\n");
        scanf(" %c", &choice);
        switch(choice){
            case 'a':
                printf("Which text would you like to read? ");
                scanf(" %c", &news);
                /*Control if the file had opened before*/
                int control=read_control(news);
                /*If file hadn't open before save the file id*/
                if(!control){
                    menu_a(news);
                    FILE *readed_fp=fopen("readed_news_id.txt", "a");
                    if(readed_fp==NULL){
                	printf("Could not open the file\n");
        	    }
        	    else{
                    fprintf(readed_fp,"%c", news);
                    }
                    /*Close the file for the next operations*/
                    fclose(readed_fp);
                }
                printf("Do you want to continue? Yes(y)/No(n)\n");
                scanf(" %c", &yes_no);             
                break;
            case 'b':
                /*Call the function to perform operation*/
                menu_b();
                printf("Do you want to continue? Yes(y)/No(n)\n");
                scanf(" %c", &yes_no); 
                break;  
            case 'c':
                printf("Which news would you like to decrypt?\n");
                scanf(" %c", &news);
                /*Call the functions to print the text and key value*/
                menu_a(news);
                menu_c(news);
                printf("Do you want to continue? Yes(y)/No(n)\n");
                scanf(" %c", &yes_no); 
            break;
            default:printf("Please choose a valid menu\n");
            break;        
        }
     /*End the loop according to user's preference*/
    }while(yes_no!='n');
    /*Print ending message*/
    printf("Goodbye!\n");
}

int main(){
    /*Call the function to perform operations*/
    menu();
    return 0;
}
