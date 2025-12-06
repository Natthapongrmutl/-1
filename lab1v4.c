#include <stdio.h>

int GetSet(int arr[]){
    int n;
    
        printf("enter number: ");
        scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("enter element: ");
        scanf("%d", &arr[i]);
    }

    return n;
    
}

int main(){
    int data[100];
    int num;

    num = GetSet(data);

    for (int i = 0; i < num; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
    
}
