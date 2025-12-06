#include <stdio.h>

int GetSet(int arr[]){
    int number;

        printf("enter number: ");
        scanf("%d",&number);

    for (int i = 0; i < number; i++)
    {
        printf("enter element %d : ",i + 1);
        scanf("%d", &arr[i]);
    }
    return number;
}

int main(){
    int data[100];
    int numbervalue;

    numbervalue = GetSet(data);
    printf("\nYour number: \n");
    for (int i = 0; i < numbervalue; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}
