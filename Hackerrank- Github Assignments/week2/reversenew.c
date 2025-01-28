#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int reverseSentence(char sen[]){
    char* ptr = sen;
    char* array[100];
    int i=0;
    while(*ptr != '\0'){
        while(*ptr == ' ') ptr++;
        
        if(*ptr != ' '){
            array[i++]= ptr;
        }
    
        while(*ptr != ' ' && *ptr != '\0') ptr++;

        if(*ptr != '\0'){
            *ptr = '\0';
            ptr++;
        }
    }

    int firstword=1;
    for(int j=i-1; j>=0; j--){
        if(!firstword){
            printf(" ");
        }
        printf("%s", array[j]);
        firstword = 0;
    }
}
int main() {
    char sentence[100];
    scanf("%[^\n]%*c", sentence);
    reverseSentence(sentence);
    return 0;
}

// void reverseSentence(char sen[]){
//     char *ptr = sen;

//     while(*ptr!= '\0'){
//         ptr++;
//     }
//     ptr--;
    
//     while(ptr>=sen && *ptr == ' '){
//         ptr--;
//     }

//     while(ptr >= sen){
        
//       char *wordEnd = ptr;

//       while(ptr >= sen && *ptr != ' '){ //to move the pointer to start of a word
//         ptr--;
//       }


//       for(char *temp = ptr+1; temp <= wordEnd; temp++){ //traversing for the word to the end of the word
//         printf("%c", *temp);
//       }

//       if(ptr >= sen){
//         printf(" ");
//       }

//       while(ptr>= sen && *ptr == ' '){
//         ptr--;
//       }

//     }
    
// }

