#include <iostream>
#include <algorithm>
#include <vector>

struct ExamPaper
{
    int stu_num;
    std::string ans1;
    std::string ans2;
    std::string ans3;
};

bool is_similar(const std::string &a, const std::string &b)
{
    const std::size_t common_len = std::min(a.size(), b.size());
    std::size_t same_count = 0;

    for (std::size_t i = 0; i < common_len; ++i)
    {
        if (a[i] == b[i])
        {
            ++same_count;
        }
    }

    const std::size_t len_a = a.size();
    const std::size_t len_b = b.size();

    return same_count * 10 >= 9 * len_a || same_count * 10 >= 9 * len_b;
}

int check_copy(const std::vector<ExamPaper> &papers, int i, int j)
{
    if (is_similar(papers[i].ans1, papers[j].ans1))
    {
        return 1;
    }
    if (is_similar(papers[i].ans2, papers[j].ans2))
    {
        return 2;
    }
    if (is_similar(papers[i].ans3, papers[j].ans3))
    {
        return 3;
    }
    return 0;
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<ExamPaper> papers(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> papers[i].stu_num;
        std::cin >> papers[i].ans1;
        std::cin >> papers[i].ans2;
        std::cin >> papers[i].ans3;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int question_num = check_copy(papers, i, j);
            if (question_num != 0)
            {
                std::cout << papers[i].stu_num << ' ' << papers[j].stu_num << ' ' << question_num << '\n';
            }
        }
    }

    return 0;
}
