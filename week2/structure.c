#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Represents an item in the cart
typedef struct item_t
{
    char *item_name;
    int item_cost;
    
} item;

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
    }else{
        return 1;
    }
}

int main() {
    item *cart[100];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cart[i] = (item*)malloc(sizeof(item));
        cart[i]->item_name = (char*)malloc(50 * sizeof(char));
        scanf("%[^,],%d", cart[i]->item_name, &cart[i]->item_cost);
    }
    printf("item list");
    int totalCost=0;
    for(int i=0; i<n; i++){
        printf("%s,%d", cart[i]->item_name, cart[i]->item_cost);
        totalCost += cart[i]->item_cost;
    }
    printf("\nTotal cost %d", totalCost);
    printf("\nitem quantities");

    int processed[100]={0};
    for(int i=0; i<n; i++){
        if(processed[i]==0){
          int quantities=1;
            for(int j=i+1; j<n; j++){
                if(compareString(cart[i]->item_name, cart[j]->item_name)==0){
                    quantities++;
                    processed[j]=1;
                    free(cart[j]->item_name);
                }
            }
            printf("%s - %d", cart[i]->item_name, quantities);
            processed[i]=1;
        } 
    }
    for(int i=0; i<n; i++){
        free(cart[i]);
    }
    return 0;
}




/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Represents an item in the cart
typedef struct item_t
{
    char *item_name;
    int item_cost;
    int quantity;
} item;

int compareString(char str1[], char str2[])
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 1; // the strings are different
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0; // the strings are same
    }
    else
    {
        return 1;
    }
}

int main()
{
    item *cart[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cart[i] = (item *)malloc(sizeof(item));
        cart[i]->item_name = (char *)malloc(50 * sizeof(char));
        scanf("%[^,],%d", cart[i]->item_name, &cart[i]->item_cost);
    }
    printf("item list");
    int totalCost = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%s,%d", cart[i]->item_name, cart[i]->item_cost);
        totalCost += cart[i]->item_cost;
    }
    printf("\nTotal cost %d", totalCost);
    printf("\nitem quantities");

    for (int i = 0; i < n; i++)
    {
        int quantities = 1;
        if (cart[i]->quantity > 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (compareString(cart[i]->item_name, cart[j]->item_name) == 0)
                {
                    quantities++;
                    cart[j]->quantity = -1;
                }
            }
            cart[i]->quantity = quantities;
            printf("%s - %d", cart[i]->item_name, cart[i]->quantity);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     free(cart[i]);
    //     if (cart[i]->quantity != -1)
    //     {
    //         free(cart[i]->item_name);
    //     }
    // }
    return 0;
}
*/