//Create a thread to sort given array of 10 integers using selection sort.
// Main thread should print the result after sorting is completed.

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define size 10
#define swap(a,b) int temp=a;a=b;b=temp;
int arr[size];
void* bubble_sort(void *para)
{
    int *arr=(int *)para;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size-1-i;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        

        }
    }
    return arr;
}

int main()
{
    pthread_t th1;
    int arr1[size];
    printf("ENter the arraay elements\n");
    for(int i=0;i<size;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    int ret = pthread_create(&th1,NULL,bubble_sort,&arr);
    if(ret!=0)
    {
        perror("failed\n");
    }
    pthread_join(th1,(void**)&arr1);//arr
    for(int i=0;i<size;i++)
    {
    printf("arr[%d]=%d\n",i,arr[i]);
    }
    return 0;

    

}