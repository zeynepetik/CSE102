#include <stdio.h>
#define max_size 750
int find_size_of_array(int array[]) {
    int counter = 0;
    int i;
    /*It will count the numbers until it encounters with -1*/
    for (i = 0; array[i] != -1 && i < max_size; i++) {
        counter++;
    }
    return counter;
}
/*Function to add new numbers to array*/
void add_new_number(int array[], int *size, int new_number) {
    if (*size < max_size) {
    /*It will locate new number in the end of the array*/
        array[*size] = new_number;
        (*size)++;
       /*If updated size is greater than max_size it will give an error*/
    } else {
        printf("Array is full, cannot add new number.\n");
    }
}

double average_cal(int array[], int size) {
    int i, sum = 0;
    /*It will add the number of array one by one*/
    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double) sum / size;
}

void mode_cal(int array[], int size) {
    int max_repeat = 0,repeat_cnt=0, mode;
    int frequency_array[max_size] = {0};
    int i, j, k;
    /*Find the maximum repitition*/
    for (i = 0; i < size; i++) {
        frequency_array[array[i]]++;
        if (frequency_array[array[i]] > max_repeat) {
            max_repeat = frequency_array[array[i]];
        }
    }
    /*Count the repetitions and print the numbers which has most repetition*/
    for(k=0;k<size;k++){
        for(j=k;j<size;j++){
            if(k!=j && array[k]==array[j]){
                repeat_cnt++;
            }
        }
        /*repeat_cnt does not count when j==k so it is less than max_repeat by 1*/
        if(repeat_cnt+1==max_repeat){
            mode=array[k];
            printf("mode: %d\n", mode);
        }
        /*Reset the counter to be able to count every number*/
        repeat_cnt=0;
    }
}

void median_cal(int array[], int size) {
    int i, j, temp;
    /*Sort the numbers to find the median*/
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    /*Calculate the median according to size of the array*/
    if (size % 2 != 0) {
        printf("median: %.2f\n", (double) array[size / 2]);
    } else {
        printf("median: %.2f\n", (double) (array[size / 2 - 1] + array[size / 2]) / 2);
    }
}

void histogram(int array[], int size, int a, int b) {
    /*Initiliaze the numbers of the array to zero to count numbers*/
    int frequency_array[200] = {0};
    
    int i, j;
    /*Get the frequencies of the numbers and store in an array*/
    for (i = 0; i < size; i++) {
        frequency_array[array[i]]++;
    }
    int max_repeat=0;
    /*Find the maximum repetition*/
    for(j=0;j<200;j++){
    	if(frequency_array[j]>max_repeat){
    	    max_repeat=frequency_array[j];
    	}
    }
    int n,k;
    /*Print asterisk according to its repetition*/
    for(k=max_repeat;k>0;k--){
        for(n=a;n<=b;n++){
            if(frequency_array[n]<k){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    int number_array[max_size] = {45, 46, 47, 48, 49, 50, 133, 52, 53, 54, 55, 111, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 55, 55, 69, 70, 55, 45, 73, 55, 75, 76, 77, 78, 79, 80, 81, 82, 55, 55, 85, 86, 87, 88, 89, 90, 91, 92, 93, 193, 95, 133, 76, 191, 55, 100, 101, 102, 76, 104, 105, 106, 107, 108, 120, 110, 111, 112, 113, 114, 115, 116, 117, 118, 163, 120, 121, 122, 193, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 193, 133, 144, 145, 146, 147, 148, 149, 150, 151, 193, 153, 154, 155, 156, 157, 158, 111, 160, 120, 162, 163, 128, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 111, 179, 180, 181, 111, 120, 184, 133, 186, 187, 188, 125, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 125, 201, 202, 203, 173, 205, 61, 128, 173, 76, 111, 133, 45, -1};
    int size, new_size = 0;
    int yes_no, new_number, a, b;
    double average;
    /*Decide on an interval*/
    printf("Please enter the numbers for the interval (min:50 max:200)\n");
    scanf("%d%d", &a, &b);
    /*Control the intervals*/
    if (!(a >= 50 && a <= 200 && b >= 50 && b <= 200)) {
        do {
            printf("ERROR: Enter numbers within the given interval (min:50 max:200)\n");
            scanf("%d%d", &a, &b);
        } while (!(a >= 50 && a <= 200 && b >= 50 && b <= 200));
    }
    /*a should be less than b for other calculation so control it*/
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }

    printf("Would you like to add new numbers? (Press 1 for yes and 0 for no)\n");
    scanf("%d", &yes_no);
    
    size = find_size_of_array(number_array);
    /*Make a new array for the given interval*/
    int i;
    for (i = 0; i < size; i++) {
        if (number_array[i] >= a && number_array[i] <= b) {
            new_size++;
        }
    }
    
    int interval_array[max_size];
    int index = 0;
    
    for (i = 0; i < size; i++) {
        if (number_array[i] >= a && number_array[i] <= b) {
            interval_array[index] = number_array[i];
            index++;
        }
    }
    
    switch (yes_no) {
        /*If they do not want to add a new number just make the calculations and print the histogram*/
        case 0:
            histogram(interval_array, new_size, a, b);
            average = average_cal(interval_array, new_size);
            printf("average: %.2f\n", average);
            mode_cal(interval_array, new_size);
            median_cal(interval_array, new_size);
            break;
        /*If they want to add new numbers*/
        case 1:
            printf("Please enter the numbers\n");
            do {
                /*Add new numbers according to the decided interval until user enter -1*/
                scanf("%d", &new_number);
                if (new_number >= a && new_number <= b) {
                    add_new_number(interval_array, &new_size, new_number);
                }
            } while (new_number != -1 && new_size < max_size);
            /*Print the histogram and do the calculations for the new array*/
            histogram(interval_array, new_size, a, b);
            average = average_cal(interval_array, new_size);
            printf("average: %.2f\n", average);
            mode_cal(interval_array, new_size);
            median_cal(interval_array, new_size);
            break;
        default:
            
            printf("Unvalid number\n");
    }

    return 0;
}
