#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 200

struct freq{
    int value;
    int freq;
};

typedef struct freq Freq;

void empty_stdin (void);
unsigned int init_array(int *const ptr);
void display(const int * const ptr, const unsigned int size);
unsigned int frequency(const int * const ptr,Freq * const wFreq,const unsigned int size);
void display_freq(const Freq * const wFreq,const unsigned int fSize);

int main() {

    Freq freqArray[MAXSIZE];

    const char *nameInst[] = {"Initialize an Array","Display Array",
                              "Reverse Array","Apply to Frequency", "Display Frequency",
                              "End Program"};

    int array[200],
        count =200,
        rtn=0;

    unsigned int instruction = 0,
                 size =0,
                 freqSize =0;

    while(instruction!=6){
        printf("%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s",
               "1. ",nameInst[0],"2. ",nameInst[1],
               "3. ",nameInst[2],"4. ",nameInst[3],
               "5. ",nameInst[4],"6. ",nameInst[5],
               "Enter a number (1-6) to select an instruction:\n");

        rtn = scanf(" %d", &instruction);

        if(rtn == 0) {                                 //matching failure
            fputs (" error: invalid integer input.\n", stderr);
            empty_stdin();
        }
        else if (instruction < 1 || 6 < instruction) {  // validate range
            fputs (" error: integer out of range [1-8]\n", stderr);
            empty_stdin();
        } else {                                        // right input
            empty_stdin();
        }

        switch(instruction){
            case 1:
                printf("you selected %d. %s\n",instruction,nameInst[instruction-1]);
                size = init_array(array);
                count =0;
                break;
            case 2:
                display(array,size);
                printf("you selected %d. %s\n",instruction,nameInst[instruction-1]);
                break;
            case 3:
                printf("you selected %d. %s\n",instruction,nameInst[instruction-1]);
                break;
            case 4:
                freqSize = frequency(array,freqArray,size);
                printf("you selected %d. %s\n",instruction,nameInst[instruction-1]);
                break;
            case 5:
                display_freq(freqArray,freqSize);
                printf("you selected %d. %s\n",instruction,nameInst[instruction-1]);
                break;
            case 6:
                printf("you selected %d. %s\n",instruction,nameInst[instruction-1]);
                break;
            default:
                printf("you selected %d which isn't an instruction\n",instruction);
        }
    }
    return 0;
}

void empty_stdin (void) // simple helper-function to empty stdin
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

unsigned int init_array(int *const ptr){
    unsigned int count=0;
    int num;
    bool user = false;
    printf("Enter a number to continue:");//enter a number
    while(count<=200 && user==false) {// loop for each input

        if (scanf("%d", &num)) {// if letter it goes to else function
            ptr[count] = num;
            count++;
            printf("Enter a number to continue:");
            empty_stdin();//empty input
        } else {
            user = true;//other condition to be satasfied
            empty_stdin();//empty input due to logic error
        }
    }
    return count;
}

void display(const int * const ptr, const unsigned int size){
    unsigned count = 0;
    printf("{\n\t\"array\": [\n");//print start
    while(count<size){//for loop to print all values and offsets
        printf("\t\t{\n\t\t\t\"offset\": \"%.2d\",\n\t\t\t\"value\": \"%.2d\"\n\t\t},\n",count,ptr[count]);
        count++;
    }
    printf("\t]\n}\n");//print finish
}

unsigned int frequency(const int * const ptr,Freq * const wFreq,const unsigned int size){
    unsigned int fSize = 0;
    bool alreadyFound= false;
    for(int i= 0;i<size;i++){
        // going through each of the array lists
        alreadyFound = false;
        for(int k =0; k<fSize;k++) {
            //checking if value already found
            if (ptr[i] == wFreq[k].value) { //if value already exists already found = to true
                alreadyFound = true;
            }
        }

        if(alreadyFound == false) {
            wFreq[fSize].value = ptr[i];//frequancy value stored
            wFreq[fSize].freq = 0; //frequancy freq started
            for (int j = 0; j < size; j++) { //look through each of the ptr
                if (wFreq[fSize].value == ptr[j]) { //check if ptr == to current value
                    wFreq[fSize].freq++; //add to frequancy
                }
            }
            fSize++; //freqancy count
        }

    }
    return fSize;
}

void display_freq(const Freq * const wFreq,const unsigned int size){
    unsigned count = 0;
    printf("{\n\t\"frequancy\": [\n");//start of print
    while(count<size){ //print each freq value
        printf("\t\t{\n\t\t\t\"value\": \"%.2d\",\n\t\t\t\"frequancy\": \"%.2d\"\n\t\t},\n",wFreq[count].value,wFreq[count].freq);
        count++;
    }
    printf("\t]\n}\n");//print finish
}