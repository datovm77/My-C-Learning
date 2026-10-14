#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct student
{
    /* data */
    std::string name;
    int year;
    int month;
    int day;
    int id;
};

int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<student> v;
    while (n--)
    {
        std::string name;
        int year;
        int month;
        int day;
        student s1;
        std::cin >> s1.name >> s1.year >> s1.month >> s1.day;
        s1.id = n;
        v.push_back(s1);
    }
    std::sort(v.begin(), v.end(), [](const student &s1, const student &s2)
              {
        if(s1.year != s2.year)
        {
            return s1.year<s2.year;
        }
        else if(s1.month != s2.month)
        {
            return s1.month<s2.month;
        }
        else if(s1.day !=s2.day)
        {
            return s1.day<s2.day;
        }
        return s1.id<s2.id; });

    for (student s : v)
    {
        std::cout << s.name << '\n';
    }
}