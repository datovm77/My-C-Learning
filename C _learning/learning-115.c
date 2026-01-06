#include<stdio.h>
int check(int num)
{
    int temp = num;
    int count = 0;
    int arr [1000] = {0};
    
    while(temp != 0)
    {
        arr[count] = temp % 10;
        temp = temp / 10;
        count++;
    } 
    if(count % 2 != 0) //代表位数为奇数
    {
        for(int i = 0; i < (count-1)/2;i++ )
        {
            if(arr[i] != arr[count - 1 -i])
            {
                return 0;//表示不是回文数
            }
        }
    }
    else   //位数为偶数
    {
        for(int i = 0; i <= (count/2)-1;i++ )
        {
            if(arr[i] != arr[count - 1 -i])
            {
                return 0;//表示不是回文数
            }
        }
    }
    return 1;//表示是回文数
}
int main()
{
    //printf("%d\n",check(151)) ;
    int n,m;
    scanf("%d %d",&n,&m);
    for(n;n<=m;n++)
    {
        if(check(n))
        {
            printf("%d\n",n);
        }
    }
    return 0;
}