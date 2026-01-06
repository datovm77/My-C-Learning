#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct spot
{
    char name[100];
    int count;
};

int main()
{
    struct spot arr[4] = {{"A",0},{"B",0},{"C",0},{"D",0}};

    //模拟投票
    srand(time(NULL));
    for(int i = 0;i < 80;i++)
    {
        int choose = rand() % 4; //结果是0，1，2，3
        arr[choose].count++;
    }

    //遍历数组
    int max = arr[0].count;//这里已经找到最大的count为多少了
    for(int i = 1; i < 4;i++)
    {
        struct spot temp = arr[i];
        if(temp.count > max)
        {
            max = temp.count;
        }
    }
    //遍历数组，看哪一个组的的票数最大
    for(int i = 0; i < 4;i++)
    {
        struct spot temp = arr[i];
        if(temp.count == max)  //max是上面已经找到的
        {
            printf("投票最多的是%s组一共有 %d票 \n",temp.name,temp.count);
            break;//其实从0索引开始遍历，就已经说明了在票数相同的情况下A优于B优于C优于D
        }
    }

    //遍历数组
    for (int i = 0; i < 4;i++)
    {
        struct spot temp = arr[i];
        printf("%s %d \n",temp.name,temp.count);        
    }

}