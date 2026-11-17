// P1135 奇怪的电梯
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int UP_DOWN[] = {-1, 1};
vector<int> v;
queue<int> q;
vector<int> disk;
int main()
{
    int N, A, B;
    if (!(cin >> N >> A >> B))
        return 0;
    v.resize(N + 1);
    v[0] = 0;
    disk.resize(N + 1, -1);
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }
    // q里面push存放当前楼层
    q.push(A);
    // 令初始楼层到初始楼层步数为0
    disk[A] = 0;

    while (!q.empty())
    {
        int x = q.front();
        if (x == B)
        {
            break;
        }
        for (int i = 0; i < 2; i++)
        {
            int nx = x + UP_DOWN[i] * v[x];

            // 当超过范围与已经路过该楼层
            if (nx < 1 || nx > N || disk[nx] != -1)
            {
                continue;
            }
            disk[nx] = disk[x] + 1;
            q.push(nx);
        }
        q.pop();
    }
    cout << disk[B] << '\n';
}