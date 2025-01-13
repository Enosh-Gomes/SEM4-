# include<stdio.h>
#include<limits.h>
#define MAX 100
int arr[MAX];
int n;

void display(){
    printf("\n ");
    for (int i = 1; i <= n; i++)
    {
        printf("[%d] ",i);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("----");
    }
    printf("-\n");
    for (int i = 0; i < n; i++)
    {
        printf("|%03d",arr[i]);
    }
    printf("|\n");
    for (int i = 0; i < n; i++)
    {
        printf("----");
    }
    printf("-\n");
}

int partition(int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        while(arr[i]<=pivot && i<=high)
            i++;
        while(arr[j]>pivot)
            j--;
        display();
        printf("i=%d j=%d pivot=%d\n",i+1,j+1,pivot);
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;      
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    display();
printf("i=%d j=%d pivot=%d\n",i+1,j+1,pivot);
return j;
}

void quicksort(int low,int high){
    if(low<high){
        int pivloc=partition(low,high);
        quicksort(low,pivloc-1);
        quicksort(pivloc+1,high);
    }
}

// void display(){
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     printf("\n");   
// }

int main(){

printf("Enter the number of elements: ");
scanf("%d",&n);

for (int  i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}
arr[n]=INT_MAX;
quicksort(0,n-1);

display();


return 0;
}