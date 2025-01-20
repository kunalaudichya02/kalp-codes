#include<stdio.h>
#include<stdlib.h>

int findSubstring(char *input, char *substring){
    char *ptr = input;
    char *find;
    int index=0;

    if (*substring == '\0') return 0;
    while(*ptr != '\0'){ 
        if (*ptr == *substring) {
            char *find = substring;
            char *temp = ptr;

            while (*find == *temp && *find != '\0' && *temp != '\0') {
                find++;
                temp++;
            }

            if (*find == '\0') return index;
        }

        ptr++;
        index++;

    }
    return -1;
}
int main()
{
    char *input = (char *)malloc(100 * sizeof(char));
     if(input == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    printf("enter a string:");
    scanf("%[^\n]%*c", input);
    char *substring = (char *)malloc(100 * sizeof(char));
     if(substring == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    printf("enter a substring:");
    scanf("%[^\n]%*c", substring);
    int result = findSubstring(input, substring);
    printf("Output: %d\n", result);
    free(input);
    free(substring);
    return 0;
}


        // while(*find != *ptr){
        //     ptr++;
        //     index++;
        // }
        // int found=1;
        // if(*find == *ptr){  
        //  while(*find != '\0'){
        //     if(*find == *ptr){
        //             find++;
        //             ptr++;
        //         }
        //     else{
        //             found =0;
        //             break;
        //         }
        //     }
        //  }
        // else found =0;

        // if(found == 1){
        //     return index;
        // }
        // else 
        // return -1;