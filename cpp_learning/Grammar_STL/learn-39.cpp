// 练习用队列解决约瑟夫环问题与队列循环操作
#include <iostream>
#include <string>
// P1996 约瑟夫问题
#include <queue>

void test01()
{
    int n, m;
    std::cin >> n >> m;

    std::queue<int> que;

    for (int i = 1; i <= n; ++i)
    {
        que.push(i);
    }

    int index = 0;
    while (!que.empty() && ++index)
    {
        if (index == m)
        {
            index = 0;
            if (que.size() == n)
                std::cout << que.front();
            else
                std::cout << ' ' << que.front();
            que.pop();
        }
        else
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
    }
    std::cout<<'\n';
}

int main()
{
    test01();
    return 0;
}