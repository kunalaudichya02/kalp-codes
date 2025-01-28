#include<stdio.h>
#include<stdlib.h>

int stringLength(char *str){
    int count = 0;
    while(*str!= '\0'){
        count++;
        str++;
    }
    return count;
}
void compressString(char str[], int length){
    char output[200];
    int index = 0;
    int i = 0;

    while (i < length) {
        char ch = str[i];
        int count = 0;
        while (i < length && str[i] == ch) {
            count++;
            i++;
        }
        output[index++] = ch;
        output[index++] = count + '0';
    }

    output[index] = '\0';

    if (stringLength(output) > length) {
        printf("%s\n", str);
    } else {
        printf("%s\n", output);
    }
//    char *output = (char *)malloc(2 * length * sizeof(char));
//     if (output == NULL) {
//         printf("Memory allocation failed\n");
//         return;
//     }
//    char *start = str;
//    int i=0;
//     while(*str != '\0'){
//         char c;
//         c = *str;
//         output[i++] = c;
//         int count = 0;
//         while(*str == c){
//             count++;
//             str++;
//         }
//         output[i++] = (count + '0');
//     }
//     output[i] = '\0';
//     int lengthNew = stringLength(output);

//     if(lengthNew > length){
//         printf("%s", start);
//     }
//     else{
//         printf("%s", output);
//     }

}
int main(){
    char string[100];
    scanf("%[^\n]", string);
    int n = stringLength(string);
    compressString(string, n);
}