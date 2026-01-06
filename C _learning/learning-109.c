#include<stdio.h>

int cal_num(int num);
int reverse(int number,int funtion);
int count = 0;
int main()
{
    int n;
    if(scanf("%d", &n) != 1) return 0;
    cal_num(n);


    return 0;
}

int cal_num(int num)
{
    int max = reverse(num,1) ;
    int min = reverse(num,-1);
    int result = max - min;
    count++;
    printf("%d: %d - %d = %d\n",count,max,min,result);
    if(result==495)
    {
        return 0;
    }
    return cal_num(result);


}

int reverse(int number,int funtion)
{
    int arr[10] = {0};
    int temp_num = number;
    int index = 0;
    while(temp_num != 0)  //虽然已知是三位数.....
    {
        int temp = temp_num % 10;
        temp_num = temp_num / 10;
        arr[index] = temp;
        index++;
    }

    for(int j = 0;j < 2;j++)
    {
        for(int i = 0;i < 2-j;i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    if(funtion == 1) return (arr[2]*100+arr[1]*10+arr[0]);  //最大
    if(funtion == -1) return (arr[0]*100+arr[1]*10+arr[2]); //最小
    

}