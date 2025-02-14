#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct phonebook{
    char *name;
    char number[12];
} phoneBook;

int searchContact(phoneBook *ph,int *size,char *name)
{
    int ans=-1;
    for(int index=0;index<*size;index++)
    {
        if(strcmp(ph[index].name,name)==0)
        {
            ans=index;
            break;
        }
    }
    return ans;
}
void addContactDetails(char *operation,phoneBook *ph,int *size)
{
    char name[101];
    char phoneNumber[11];
    int Index=0;
    int start=5;
    while(operation[start]!='\"')
    {
        name[Index++]=operation[start++];
    }
    name[Index]='\0';
    start+=3;
    Index=0;
    while(operation[start]!=')')
    {
        phoneNumber[Index++]=operation[start++];
    }
    phoneNumber[Index]='\0';
    
    int prevIndex=searchContact(ph,size,name);
    if(prevIndex!=-1)
    {
        strcpy(ph[prevIndex].number,phoneNumber);
    }
    else
    {
    ph[*size].name=(char *)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(ph[*size].name,name);
    strcpy(ph[*size].number,phoneNumber);
    (*size)++;
    }
    printf("Success\n");
}


void deleteContactDetails(char *operation,phoneBook *ph,int *size)
{
    char name[101];
    int Index=0;
    int start=8;
     while(operation[start]!='\"')
    {
        name[Index++]=operation[start++];
    }
    name[Index]='\0';
    int contactIndex=searchContact(ph,size,name);
    if(contactIndex==-1)
        printf("Not Found\n");
    else
    {
        for(int index=contactIndex;index<(*size)-1;index++)
        {
            ph[index]=ph[index+1];
        }
        (*size)--;
        printf("Success\n");
    }
}

void searchContactDetails(char *operation,phoneBook *ph,int *size)
{
    char name[101];
    int Index=0;
    int start=8;
     while(operation[start]!='\"')
    {
        name[Index++]=operation[start++];
    }
    name[Index]='\0';
    int contactIndex=searchContact(ph,size,name);
    if(contactIndex==-1)
        printf("Not Found\n");
    else
        printf("%s\n",ph[contactIndex].number);
}

int main() {
        int n;
    char operation[150];
    phoneBook *ph=NULL;
    int size=0;
    scanf("%d",&n);
    ph=(phoneBook *)malloc(sizeof(phoneBook)*n);
     while(getchar()==' ');
    for(int index=0;index<n;index++)
    {
       
        scanf("%[^\n]s",operation);
        if(strncmp(operation,"add",3)==0)
        {
            addContactDetails(operation,ph,&size);
        }
        else if(strncmp(operation,"search",6)==0)
            searchContactDetails(operation,ph,&size);
         else if(strncmp(operation,"delete",6)==0)
             deleteContactDetails(operation,ph,&size);
        while(getchar()==' ');
    }
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
