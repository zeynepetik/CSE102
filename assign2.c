#include <stdio.h>
int main(){
    int menu;
    int R1, R2, R3, R4;/*I will use these variables for nearly all menus so I initiliazed them outside of the menus.*/
    int x_separator, y_seperator;
    int X_Min, Y_Min, X_Max, Y_Max;/*to save absolute min and max values*/
    printf("**WELCOME TO MENU**\n");
    printf("1) EXPLORE THE DATA\n");
    printf("2) TRAIN A MODEL\n");
    printf("3) TEST A MODEL\n");
    printf("4) EXIT FROM THE PROGRAM\n");
    /*Start a infinite loop to choose a new menu continuously*/
    while (1)
    {
    printf("PLEASE SELECT A MENU FROM ABOVE OPTIONS:\n");
    scanf("%d", &menu);
    
    if(menu==1){
    	/*Variables to take data from file*/
        int x, y, class;
        /*Saving class 0's max and min values*/
        int Xmin_zero=-1, Xmax_zero=0, Ymin_zero=-1, Ymax_zero=0;
        /*Saving class 1's max and min values*/
        int Xmin_one=-1, Xmax_one=0, Ymin_one=-1, Ymax_one=0;
        /*Open the relevant file*/
        FILE *fp=fopen("data.txt", "r");
        if(fp==NULL){
            printf("File could not open\n");
        }
        else{
            /*Getting data from the file and contunie to get until there is no data*/	
            while(fscanf(fp, "%d %d %d", &x,&y,&class)==3){
            /*Comparing the datas we get from the file by using class labels*/  
                if(class==0){
                    if(x<Xmin_zero || Xmin_zero==-1)
                        Xmin_zero=x;
                    if(x>Xmax_zero || Xmax_zero==-1)
                        Xmax_zero=x;
                    if(y<Ymin_zero || Ymin_zero==-1)
                        Ymin_zero=y;
                    if(y>Ymax_zero || Ymax_zero==-1)
                        Ymax_zero=y;
                }
                if(class==1){
                    if(x<Xmin_one || Xmin_one==-1)
                        Xmin_one=x;
                    if(x>Xmax_one || Xmax_one==-1)
                        Xmax_one=x;
                    if(y<Ymin_one || Ymin_one==-1)
                        Ymin_one=y;
                    if(y>Ymax_one || Ymax_one==1)
                        Ymax_one=y;
                }
            }
            /*Get the max and min values without separating them into classes*/
            if(Xmax_one<Xmax_zero){
                    X_Max=Xmax_zero;
                }
                if(Xmax_one>Xmax_zero){
                    X_Max=Xmax_one;
                }
                if(Xmin_one<Xmin_zero){
                    X_Min=Xmin_one;
                }
                if(Xmin_zero<Xmin_one){
                    X_Min=Xmin_zero;
                }
                if(Ymax_one<Ymax_zero){
                    Y_Max=Ymax_zero;
                }
                if(Ymax_one>Ymax_zero){
                    Y_Max=Ymax_one;
                }
                if(Ymin_one<Ymin_zero){
                    Y_Min=Ymin_one;
                }
                if(Ymin_zero<Ymin_one){
                    Y_Min=Ymin_zero;
                }
            /*Close the file*/
            fclose(fp);
            printf("Minimum and Maximum X and Y values:\n");
            printf("Class 0: X in [%d %d], Y in [%d %d]\n", Xmin_zero, Xmax_zero, Ymin_zero,Ymax_zero);
            printf("Class 1: X in [%d %d], Y in [%d %d]\n", Xmin_one, Xmax_one, Ymin_one, Ymax_one);
        }
    }
    else if(menu==2){
    	/*Variables to take data from the file*/
        int data_x, data_y, class;
        /*Variables to count how many data is there in that relevant class*/
        int R1_1=0,R2_1=0, R3_1=0, R4_1=0, R1_0=0, R2_0=0, R3_0=0,R4_0=0;
        /*Variables to store classes for each loop*/
        int try_R1,try_R2,try_R3,try_R4;
        /*Variables to get error*/
        int error=0, min_error=0;
        /*Open the relevant file*/
        FILE *fp=fopen("data.txt", "r");
        if(fp==NULL){
            printf("File could not open\n");
        }
        else{
        	/*Get data from the file*/
        	fscanf(fp, "%d %d %d", &data_x, &data_y, &class);
        	/*Continue to get data until there is no data*/
                while((fscanf(fp, "%d %d %d", &data_x, &data_y, &class))==3){
                int x,y;
                /*To find separator try all of the possible combinations with loop*/
                for(x=X_Min; x<=X_Max; x++){
                    for(y=Y_Min; y<=Y_Max; y++){
                    /*Count the data whose class is zero*/
                        if(class==0){
                            if(data_x<=x && data_y>y){
                                R1_0++;
                            }
                            if(data_x>x && data_y>y){
                                R2_0++;
                            }
                            if(data_x<=x && data_y<=y){
                                R3_0++;
                            }
                            if(data_x>x && data_y<=y){
                                R4_0++;
                            }
                        }
                        /*Count the data whose class is one*/
                        if(class==1){
                            if(data_x<=x && data_y>y){
                                R1_1++;
                            }
                            if(data_x>x && data_y>y){
                                R2_1++;
                            }
                            if(data_x<=x && data_y<=y){
                                R3_1++;
                            }
                            if(data_x>x && data_y<=y){
                                R4_1++;
                            }
                        }
                        /*Compare the amount of data that classes have and add least one to error*/
                        if(R1_0<R1_1){
                            try_R1=1;
                            error+=R1_0;
                        }
                        if(R1_0>R1_1){
                            error+=R1_1;
                            try_R1=0;
                        }
                        if(R2_0<R2_1){
                            error+=R2_0;
                            try_R2=1;
                        }
                        if(R2_0>R2_1){
                            error+=R2_1;
                            try_R2=0;
                        }
                        if(R3_0<R3_1){
                            error+=R3_0;
                            try_R3=1;
                        }
                        if(R3_0>R3_1){
                            error+=R3_1;
                            try_R3=0;
                        }
                        if(R4_0<R4_1){
                            error+=R4_0;
                            try_R4=1;
                        }
                        if(R4_0>R4_1){
                            error+=R4_1;
                            try_R4=0;
                        }
                        /*if minimum error is zero or error is less than minimum error store that classes and separators*/
                        if(error<min_error || min_error==0){
                            min_error=error;
                            x_separator=x;
                            y_seperator=y;
                            R1=try_R1;
                            R2=try_R2;
                            R3=try_R3;
                            R4=try_R4;
                        }
                }
            }
        }
            /*Close the file*/
            fclose(fp);
            printf("Separator coordinates: X = %d, Y = %d\n", x_separator, y_seperator);
            printf("Training error of the model = %d\n", min_error);
            printf("Labels of the regions: R1 = %d, R2 = %d, R3 = %d, R4 =%d\n",R1, R2, R3, R4);   
    }
    }
    else if(menu==3){
    	/*Count truly predicted datas from test_1 file*/
        int truly_predicted=0;
        /*Variable to get data from test_1 file*/
        int x1, y1, class1;
        /*Variable to count how many data test_1 file has*/
        int data_counter=0;
        /*Variable to store success rate*/
        float sucess;
        /*Variables to get data from test_final file*/
        int x_final, y_final, class_final;
        /*Open the relevant file*/
        FILE *fp=fopen("test_1.txt", "r");
        if(fp==NULL){
            printf("File could not open");
        }
        else{
        /*Get data from the file until there is no data*/
        while((fscanf(fp, "%d %d %d", &x1, &y1, &class1))==3){
            data_counter++;
            /*Compare coordinates according to separators and control if the classes have same value*/
            if(x1<=x_separator && y1>y_seperator){
                if(class1==R1){
                    truly_predicted++;
                }
            }
            if(x1>x_separator && y1>y_seperator){
                if(class1==R2){
                    truly_predicted++;
                }
            }
            if(x1<=x_separator && y1<=y_seperator){
                if(class1==R3){
                    truly_predicted++;
                }
            }
            if(x1>x_separator && y1<=y_seperator){
                if(class1==R4){
                    truly_predicted++;
                }
            }
        }
    }
    	/*Calculate success rate*/
        sucess=((float)truly_predicted/data_counter)*100;
        /*Close the file*/
        fclose(fp);
        printf("Sucess Rate For Test_1 File\n");
        printf("Sucess rate: %.2f\n\n", sucess);
        /*Open the test_finel file to guess coordinates classes*/
        FILE *file=fopen("test-final.txt", "r");
        if(file==NULL){
            printf("File could not open");
        }
        else{
        /*Get the coordinates from the file*/
        printf("Predicted Classes for test-final File\n");
        while((fscanf(file, "%d %d", &x_final, &y_final))==2){
            /*To guess their classes separate them according to their region*/
            if(x_final<=x_separator && y_final>y_seperator){
                printf("X: %d  Y: %d  Class: %d\n", x_final, y_final,R1);
            }
            if(x_final>x_separator && y_final>y_seperator){
                printf("X: %d  Y: %d  Class: %d\n", x_final, y_final, R2);
            }
            if(x_final<=x_separator && y_final<=y_seperator){
                printf("X: %d  Y: %d  Class: %d\n", x_final, y_final, R3);
            }
            if(x_final>x_separator && y_final<=y_seperator){
                printf("X: %d  Y: %d  Class: %d\n", x_final, y_final, R4);
            }
        }
        /*Close the test_final file*/
        fclose(file);
        }
    }
    /*If menu is 4 break the while infinite loop*/
    else if(menu==4){
        printf("Exiting...");
        break;
    }
    /*If user choose a number that is not in the menu*/
    else {
        printf("There's No Such A Menu\nPlease Try Again...\n");
    }
    
    }
}
