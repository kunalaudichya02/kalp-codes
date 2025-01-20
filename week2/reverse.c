#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void reverseSentence(char sen[]){
    char *ptr = sen;

    while(*ptr!= '\0'){
        ptr++;
    }
    ptr--;
    
    while(ptr>=sen && *ptr == ' '){ //to handle the trailing spaces
        ptr--;
    }

    while(ptr >= sen){
      char *wordEnd = ptr;

      while(ptr >= sen && *ptr != ' '){ //to move the pointer to start of a word
        ptr--;
      }

      for(char *temp = ptr+1; temp <= wordEnd; temp++){ //printing the word
        printf("%c", *temp);
      }

      if(ptr >= sen){
        printf(" ");
      }

      while(ptr>= sen && *ptr == ' '){
        ptr--;
      }

    }
}
int main() {
    char sentence[100];
    if (scanf("%[^\n]%*c", sentence) != 1) {
        return 0; 
    }
    reverseSentence(sentence);
    return 0;
}


