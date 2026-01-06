#include<stdio.h>
//插入排序——优化前
int Insertion_Sort(int arr[],int len);
int main()
{
    int arr[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    Insertion_Sort(arr,len);

    for(int i = 0; i < len; i++) printf("%d ", arr[i]);

    return 0;
}

int Insertion_Sort(int arr[],int len)
{
    for(int j = 1;j < len;j++)
    { 
        int temp = arr[j];
        int i = j - 1;
        for( i ;i >= 0;i--)
        {
            
            if(temp < arr[i])
            {
                arr[i+1] = arr[i]; 
                continue;
            }
            else
            {
                break;
            }
        }

        arr[i+1] = temp;

    } 


}