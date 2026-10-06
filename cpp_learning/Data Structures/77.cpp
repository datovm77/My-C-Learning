#include <iostream>
#include <queue>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }
    int count = m;
    while (q.size() != 0)
    {
        while (count--)
        {
            int number = q.front();
            q.pop();
            if (count != 0)
                q.push(number);
            else
            {
                if (q.size() == 0)
                {
                    std::cout << number << '\n';
                }
                else
                {
                    std::cout << number << ' ';
                }
            }
        }
        count = m;
    }

    return 0;
}