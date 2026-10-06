#include <iostream>
#include <vector>
#include <algorithm>

struct student
{
    int yuwen;
    int math;
    int english;
    int id;
    int sum;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<student> students;
    for (int i = 1; i <= n; i++)
    {
        student s1;
        std::cin >> s1.yuwen >> s1.math >> s1.english;
        s1.id = i;
        s1.sum = s1.english + s1.yuwen + s1.math;
        students.push_back(s1);
    }
    std::sort(students.begin(), students.end(),
              [](student &s1, student &s2)
              {
                  if (s1.sum != s2.sum)
                  {
                      return s1.sum > s2.sum;
                  }
                  if (s1.yuwen != s2.yuwen)
                  {
                      return s1.yuwen > s2.yuwen;
                  }
                  return s2.id > s1.id;
              });

    for (int i = 0; i < 5; i++)
    {
        std::cout << students[i].id << ' ' << students[i].sum << '\n';
    }
    return 0;
}