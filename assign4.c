#include <stdio.h>
char first_initial(FILE *id_fp, int id){
    char first_initial;
    /*counters to count semicolons and characters after the specific semicolon*/
    int stu_id, counter1=0, counter2=0;
    /*get the student id unti the end of file*/
    while(fscanf(id_fp, "%d", &stu_id)!=EOF){
        /*get characters after the id*/
        fscanf(id_fp, "%c", &first_initial);
        /*count how many characters you get*/
        counter2++;
        /*count the semicolons*/
        if(first_initial==';')counter1++;
        /*this function is for first name therefore there will be 1 semicolon and 2 characters (including initial letter) after the id*/
        if(counter1==1 && counter2==2&&id==stu_id){
            return first_initial;
        }
        /*if 4 semicolons are counted and new character is new line reset counters for next iteration*/
        if(counter1==4 && first_initial=='\n'){
            counter1=0;
            counter2=0;
        }
    }
    /*if student could not find return -1*/
    return -1;
}
char last_initial(FILE * id_fp, int id){
    char last_initial;
    int stu_id, counter1=0, counter2=0;
    /*get id until the end of file*/
    while((fscanf(id_fp, "%d", &stu_id))!=EOF){
        /*get the characters after the student id*/
        fscanf(id_fp,"%c",&last_initial);
        /*count semicolons*/
        if(last_initial==';')counter1++;
        if(counter1==2){
            /*when second semicolon is gotten counter2 will count characters*/
            counter2++;
            /*if counter2 is two that means last name's initial is gotten compare the student ids*/
            if(counter2==2 && stu_id==id){
                return last_initial;
            }
        }
        /*if 4 semicolons and new line character are gotten reset the counters for the next iteration*/
        if(counter1==4 && last_initial=='\n'){
            counter1=0, counter2=0;
        }
    }
    /*if the given id is not found return -1*/
    return -1;
}
int get_id_fi(FILE *id_fp, char first_initial){
    /*variable to get characters from the file and make comparision*/
    char ch;
    int id, counter1=0, counter2=0;
    /*get student id until the end of the file*/
    while((fscanf(id_fp, "%d", &id))!=EOF){
        /*get the characters after the id*/
        fscanf(id_fp, "%c", &ch);
        /*count the characters after the file*/
        counter2++;
        /*count the semicolons*/
        if(ch==';'){
            counter1++;
        }
        /*if 1 semicolon and 2 characters which are semicolon and first name's initial are gotten compare if the character is the same with the wanted one */
        if(counter1==1 && counter2==2){
            if(ch==first_initial){
            printf("%d\n", id);
        }
        }
        /*if 4 semicolons and new line character are gotten reset the counters for the next iteration */
        if(counter1==4 && ch=='\n'){
            counter1=0;
            counter2=0;
        }
    }
    /*if the wanted letter could not find return -1*/
        return -1; 
}
int get_id_li(FILE * id_fp, char first_initial){
    int id, counter1=0, counter2=0;
    char ch;
    /*get the student id until the end of the file*/
    while((fscanf(id_fp,"%d",&id))!=EOF){
        /*get the characters after the id*/
        fscanf(id_fp,"%c",&ch);
        /*count the semicolons*/
        if(ch==';')counter1++;
        if(counter1==2){
            /*count the characters after semicolon*/
            counter2++;
            /*if two characters are gotten including the last name's initial compare it with the wanted letter*/
            if(counter2==2&&ch==first_initial){
                return id;
            }
        }
        /*if 4 semicolons and new line are gotten from the file then reset the counters for the next iteration*/
        if(counter1==4&& ch=='\n'){
            counter1=0,counter2=0;
        }
    }
    /*if wanted letter could not find return -1*/
    return -1;
}
int average_grade(FILE * info_fp, int id){
    float final_ave, mid_ave, total_mid, total_mid2, total_final, total_final2, stu_mid=0, gpa,gpa1=0,gpa2=0;
    int stu_final2=0, mid, final2, lecture,stu_id, stu_mid2;
    int stu_final=0, mid1, mid2, final, curr_id, lecture2;
    int stu_counter=0, stu_counter2=0;
    /*get the datas for the first lecture*/
    while(fscanf(info_fp,"%d;%d;%d;%d;%d;",&curr_id, &mid1, &mid2, &final, &lecture)==5){
        /*control if it is the right lecture*/
        if(lecture==102){
            if(curr_id==id){
                /*get the midterms and final for the specific student id*/
                stu_mid=((float)(mid1+mid2))/2;
                stu_final=final;
            }
            else{
                stu_counter++;
                /*calculate the sum of the final and midterms*/
                total_final=stu_final+final+total_final;
                total_mid=+stu_mid+(mid1+mid2)/2+total_mid;
            }
        }
    }
                    /*calculate the average of the first lecture*/
                    final_ave=total_final/stu_counter;
                    mid_ave=total_mid/stu_counter;
                    /*compare the values and calculate the gpa*/
                    if(stu_mid>90){
                        if(stu_final<40&&stu_final<final_ave){
                            gpa1=(4+1.0)/2;
                        }if(stu_final>40&&stu_final<final_ave){
                            gpa1=(4+2.5)/2;
                        }if(stu_final>40&&stu_final>final_ave){
                                gpa1=(4+3)/2;
                        }if(stu_final<90&&stu_final>final_ave){
                                gpa1=(4+3.5)/2;
                        }if(stu_final>90){
                                gpa1=4;
                        }
                    }
                    else if(stu_mid>40&&stu_mid>mid_ave){
                        if(stu_final<40&&stu_final<final_ave){
                            gpa1=(1.0+3.5)/2;
                        }if(stu_final>40&&stu_final<final_ave){
                            gpa1=(3.5+2.5)/2;
                        }if(stu_final>40&&stu_final>final_ave){
                                gpa1=(3.5+3)/2;
                        }if(stu_final<90&&stu_final>final_ave){
                                gpa1=3.5;
                        }if(stu_final>90){
                                gpa1=(3.5+4)/2;
                        }
                    }
                    else if(stu_mid>40&&stu_mid<mid_ave){
                        if(stu_final<40&&stu_final<final_ave){
                            gpa1=(3+1.0)/2;
                        }if(stu_final>40&&stu_final<final_ave){
                            gpa1=(3+2.5)/2;
                        }if(stu_final>40&&stu_final>final_ave){
                                gpa1=3;
                        }if(stu_final<90&&stu_final>final_ave){
                                gpa1=(3+3.5)/2;
                        }if(stu_final>90){
                                gpa1=(3+4)/2;
                        }
                    }
                    else if(stu_mid>40&&stu_mid<mid_ave){
                        if(stu_final<40&&stu_final<final_ave){
                            gpa1=(2.5+1.0);
                        }if(stu_final>40&&stu_final<final_ave){
                            gpa1=2.5;
                        }if(stu_final>40&&stu_final>final_ave){
                                gpa1=(2.5+3)/2;
                        }if(stu_final<90&&stu_final>final_ave){
                                gpa1=(2.5+3.5)/2;
                        }if(stu_final>90){
                                gpa1=(2.5+4)/2;
                        }
                    }
                    else if(stu_mid<40&&stu_mid<mid_ave){
                        if(stu_final<40&&stu_final<final_ave){
                            gpa1=1.0;
                        }if(stu_final>40&&stu_final<final_ave){
                            gpa1=(1+2.5)/2;
                        }if(stu_final>40&&stu_final>final_ave){
                                gpa1=(1+3)/2;
                        }if(stu_final<90&&stu_final>final_ave){
                                gpa1=(1+3.5)/2;
                        }if(stu_final>90){
                                gpa1=(1+4)/2;
                        }
                    }
    total_final=0.0, total_mid=0.0, final_ave=0.0, mid_ave=0.0;
    while(fscanf(info_fp,"%d;%d;%d;%d;%d;",&stu_id, &mid, &final2, &lecture2)==4){
        if(lecture==108){
            if(stu_id==id){
                /*get the midterms and final for the specific student id*/
                stu_mid2=mid;
                stu_final2=final;
            }
            else{
                stu_counter2++;
                /*calculate the sum of the final and midterms*/
                total_final2=stu_final2+final2+total_final2;
                total_mid2=+stu_mid2+mid+total_mid2;
            }
        }
    }
    /*calculate the average of the first lecture*/
                    final_ave=total_final2/stu_counter2;
                    mid_ave=total_mid2/stu_counter2;
                    /*compare the values and calculate the gpa*/
                    if(stu_mid2>90){
                        if(stu_final2<40&&stu_final2<final_ave){
                            gpa2=(4+1.0)/2;
                        }if(stu_final2>40&&stu_final2<final_ave){
                            gpa2=(4+2.5)/2;
                        }if(stu_final2>40&&stu_final2>final_ave){
                                gpa2=(4+3)/2;
                        }if(stu_final2<90&&stu_final2>final_ave){
                                gpa2=(4+3.5)/2;
                        }if(stu_final2>90){
                                gpa2=4;
                        }
                    }
                    else if(stu_mid2>40&&stu_mid2>mid_ave){
                        if(stu_final2<40&&stu_final2<final_ave){
                            gpa2=(1.0+3.5)/2;
                        }if(stu_final2>40&&stu_final2<final_ave){
                            gpa2=(3.5+2.5)/2;
                        }if(stu_final2>40&&stu_final2>final_ave){
                                gpa2=(3.5+3)/2;
                        }if(stu_final2<90&&stu_final2>final_ave){
                                gpa2=3.5;
                        }if(stu_final2>90){
                                gpa2=(3.5+4)/2;
                        }
                    }
                    else if(stu_mid2>40&&stu_mid2<mid_ave){
                        if(stu_final2<40&&stu_final2<final_ave){
                            gpa2=(3+1.0)/2;
                        }if(stu_final2>40&&stu_final2<final_ave){
                            gpa2=(3+2.5)/2;
                        }if(stu_final2>40&&stu_final2>final_ave){
                                gpa2=3;
                        }if(stu_final2<90&&stu_final2>final_ave){
                                gpa2=(3+3.5)/2;
                        }if(stu_final2>90){
                                gpa2=(3+4)/2;
                        }
                    }
                    else if(stu_mid2>40&&stu_mid2<mid_ave){
                        if(stu_final2<40&&stu_final2<final_ave){
                            gpa2=(2.5+1.0);
                        }if(stu_final2>40&&stu_final2<final_ave){
                            gpa2=2.5;
                        }if(stu_final2>40&&stu_final2>final_ave){
                                gpa2=(2.5+3)/2;
                        }if(stu_final2<90&&stu_final2>final_ave){
                                gpa2=(2.5+3.5)/2;
                        }if(stu_final2>90){
                                gpa2=(2.5+4)/2;
                        }
                    }
                    else if(stu_mid2<40&&stu_mid2<mid_ave){
                        if(stu_final2<40&&stu_final2<final_ave){
                            gpa2=1.0;
                        }if(stu_final2>40&&stu_final2<final_ave){
                            gpa2=(1+2.5)/2;
                        }if(stu_final2>40&&stu_final2>final_ave){
                                gpa2=(1+3)/2;
                        }if(stu_final2<90&&stu_final2>final_ave){
                                gpa2=(1+3.5)/2;
                        }if(stu_final2>90){
                                gpa2=(1+4)/2;
                        }
                    }
    /*calculate the total gpa and return according to that*/
    gpa=(gpa1+gpa2)/2;
    if(gpa<=1){
        gpa=1;
        return gpa;
    }
    if(gpa<=2.5){
        gpa=2.5;
        return gpa;
    }
    if(gpa<=3){
        gpa=3;
        return gpa;
    }
    if(gpa<=3.5){
        gpa=3.5;
        return gpa;
    }
    if(gpa<=4){
        gpa=4;
        return gpa;
    }
}
int main(){
    char menu,f_initial, l_initial,role,department,ch;
    int id, counter1=0, counter2=0, counter=0, lecture;
    int mid1,mid2,final,course_id;
    printf("'p': Print all the users pass or fail\n");
    printf("'n': Print only the user with a specific first initial\n");
    printf("'g': Calculate the GPA of a given student\n");
    printf("'c': Print whether each user passed or failed the same class\n");
    printf("'t': Print the number of classes for the instructor\n");
    printf("'d': Print the department of all persons according to the role\n");
    printf("'l': Print the course_id of a given student\n");
    printf("'e': Quit the program\n");
    /*open the files*/
    FILE *info_fp=fopen("first.txt", "r");
    FILE *id_fp=fopen("second.txt", "r");
    /*start a loop to choose a menu until exit is chosen*/
    do
    {
        /*choose the menu*/
        printf("Please choose a menu: ");
        scanf(" %c",&menu);
        /*according to the chosen menu do the operation*/
        switch(menu){
            case 'p':
            printf("menu p\n");
                break;
            /*this menu will write the id according to chosen initial letter*/
            case 'n':
                printf("Enter an letter:\n");
                /*get the letter from the user*/
                scanf(" %c", &f_initial);
                printf("Student id with initial letter %c :\n",f_initial);
                /*call the function to list ids*/
                id=get_id_fi(id_fp, f_initial);
                /*file pointer will go back to the begining when operation is done*/
                rewind(id_fp);
                break;
            /*this menu will give the gpa of the chosen student*/
            case 'g':
                printf("enter a student id: ");
                scanf("%d",&id);
                /*call the function*/
                float gpa=(float)average_grade(info_fp, id);
                printf("GPA of the student with id %d: %.1f\n", id,gpa);
                /*file pointer will go to the begining of the file when operation is done*/
                rewind(info_fp);
                break;
            case 'c':
                printf("menu c\n");
                break;
            case 't':
                printf("menu t\n");
                break;
            case 'd':
                printf("menu d\n");                
                break;
            /*this menu will give the course id of the chosen id*/
            case 'l':
                printf("Please enter a id: ");
                scanf(" %d", &id);
                int stu_id,stu_id2,mid,final2,course_id2,lecture108=0, lecture102=0;
                /*get the datas from the file and decide if chosen id belongs to a lecture 102's student*/
                while((fscanf(info_fp," %d; %d; %d; %d; %d", &stu_id,&mid1,&mid2,&final,&course_id))==5){
                    if(stu_id==id&&course_id==102){
                        printf("%d\n", course_id);
                        lecture102=1;
                    }
                }
                /*get the data from the file and look if the chosen id is belongs to lecture 108's student*/
                while((fscanf(info_fp," %d; %d; %d; %d", &stu_id2,&mid,&final2,&course_id2))==4){
                    if(stu_id2==id&&course_id2==108){
                        printf("%d\n", course_id2);
                        lecture108=1;
                    }
                }
                /*if id does not belong to a student give a warning*/
                    if(!lecture108 && !lecture102){
                        printf("This id does not belong to a student\n");
                    }
                    /*file pointer will go to the begining of the file when the operarion is done*/
                    rewind(info_fp);
                break;
            case 'e':
                printf("exitting...");
                break;
            /*if user choose a menu that does not exist give warning*/
            default: printf("Please enter a valid menu\n");
        }
    /*when menu e is chosen finish the loop*/
    }while (menu!='e');
    /*close the files*/
    fclose(id_fp);
    fclose(info_fp);
    return 0;
}
