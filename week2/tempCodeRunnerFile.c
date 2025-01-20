#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compareString(char str1[], char str2[]){

    while(*str1 != '\0' && *str2 != '\0'){

        if(*str1 != *str2){
            return 1; //the strings are different
        }

        str1++;
        str2++;
    }

    if(*str1 == '\0' && *str2 == '\0'){
            return 0; //the strings are same
    }
    
}
void function(char sentence[]){
    
    char * ptr = sentence;
    char* array[100];
    int i=0;
    while(*ptr != '\0'){
        while(*ptr == ' ') ptr++;
        
        array[i++]= ptr;

        while(*ptr != ' ') ptr++;

        if(*ptr != '\0'){
            *ptr = '\0';
            ptr++;
        }
    }


    for(int j=0; j<i; j++){
        int repeating=0;
        for(int k=0; k<i; k++){
            if((compareString(array[j], array[k]))==1){
                repeating=1;
            }
        }

        if(!repeating){
            printf("%s", array[j]);
        }
    }

    // for(int j=0; j<i; j++){
    //     printf("%s\n", array[j]);
    // }

}
int main() {
    char sentence[100];
    scanf("%[^\n]%*c", sentence); 
    function(sentence);
    return 0;
}
