#include <iostream>
#include <queue>
int main()
{
    int t;
    std::cin >> t;
    int belong[10000] = {};
    std::queue<int> groupQueue[10];
    std::queue<int> teamQueue;
    bool inQueue[10] = {};
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            std::cin >> x;
            belong[x] = i;
        }
    }
    std::string command;
    while (std::cin >> command)
    {
        if (command == "STOP")
        {
            break;
        }
        if (command == "ENQUEUE")
        {
            int x;
            std::cin >> x;
            int group = belong[x];
            if (!inQueue[group])
            {
                teamQueue.push(group);
                inQueue[group] = true;
            }
            groupQueue[group].push(x);
        }
        else if (command == "DEQUEUE")
        {
            int group = teamQueue.front();
            int x = groupQueue[group].front();
            groupQueue[group].pop();
            std::cout << x << " ";
            if (groupQueue[group].empty())
            {
                teamQueue.pop();
                inQueue[group] = false;
            }
        }
    }
    return 0;
}