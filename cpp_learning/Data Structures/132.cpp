// P8667 [蓝桥杯 2018 省 B] 递增三元组
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> C(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> C[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        int num = B[i];
        int a_num = std::lower_bound(A.begin(), A.end(), num) - A.begin();
        int c_num = C.end() - std::upper_bound(C.begin(), C.end(), num);
        count += 1LL * a_num * c_num;
    }
    std::cout << count << '\n';
}
