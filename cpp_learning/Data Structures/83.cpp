#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct president
{
    std::string votes;
    int id;
};

int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<president> v1;
    for (int i = 1; i <= n; i++)
    {
        std::string votes;
        president p1;
        std::cin >> p1.votes;
        p1.id = i;
        v1.push_back(p1);
    }
    std::sort(v1.begin(), v1.end(), [](const president &p1, const president &p2)
              {
        if(p1.votes.size() != p2.votes.size())
        {
            return p1.votes.size() > p2.votes.size();
        }
        else
        {
            return p1.votes > p2.votes;
        } });

    std::cout << v1[0].id << '\n';
    std::cout << v1[0].votes << '\n';

    return 0;
}