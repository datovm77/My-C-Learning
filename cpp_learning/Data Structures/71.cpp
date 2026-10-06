#include <iostream>
#include <stack>
#include <vector>
struct point
{
    int xp;
    int yp;
    point(int xp, int yp) : xp(xp), yp(yp) {}
};

std::stack<point> s1;
bool findpath(std::vector<std::vector<int>> &v1, int n, int xp, int yp)
{
    if (xp >= n || yp >= n || xp < 0 || yp < 0)
        return false;
    if ((xp == n - 1) && (yp == n - 1) && (v1[xp][yp] == 0))
    {
        s1.push(point(xp, yp));
        return true;
    }
    if (v1[xp][yp] == 0)
    {
        // ---- 被删除代码位置说明 ----
        // 原先此处被删除的代码是：标记当前格已访问，防止重复搜索。
        // 若缺失该句，0区域会在“右/下/左/上”试探时来回往返
        // (如 (0,0)->(0,1)->(0,0)->... )，造成无限递归直至栈溢出段错误。
        // ---- 新增代码(补回被删除的功能) ----
        v1[xp][yp] = 1; // 新增：把当前可通过格标为已访问(当墙处理)，避免重复进入
        bool sta1 = findpath(v1, n, xp, yp + 1); // 原有：向右试探(顺序1)
        if (sta1)
        {
            s1.push(point(xp, yp));
            return true;
        }

        bool sta2 = findpath(v1, n, xp + 1, yp); // 原有：向下试探(顺序2)
        if (sta2)
        {
            s1.push(point(xp, yp)); // 原有：回溯时把当前格压入堆栈s1保存路径
            return true;
        }

        bool sta3 = findpath(v1, n, xp, yp - 1); // 原有：向左试探(顺序3)
        if (sta3)
        {
            s1.push(point(xp, yp));
            return true;
        }
        bool sta4 = findpath(v1, n, xp - 1, yp); // 原有：向上试探(顺序4)
        if (sta4)
        {
            s1.push(point(xp, yp)); // 原有：回溯时压栈
            return true;
        }
        return false; // 原有：四个方向都走不通则回溯，返回false
    }
    else
        return false;
}

int main()
{
    int t;
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        while (!s1.empty()) // 原有：多组迷宫前清空路径堆栈s1
            s1.pop();
        int n;
        if (!(std::cin >> n))
            return 0;
        std::vector<std::vector<int>> v1(n, std::vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int number;
                std::cin >> number;
                v1[i][j] = number;
            }
        }
        findpath(v1, n, 0, 0); // 原有：从起点[0,0]按右、下、左、上顺序深搜
        if (s1.empty())
            std::cout << "no path" << '\n'; // 原有：找不到路径
        else
        {
            // 说明：原思路是递归回溯时压栈，终点最先入栈、起点最后入栈，
            // 所以栈顶就是起点，直接依次pop即为正序输出。
            // 题面参考代码中的path1倒序是针对“迭代压栈终点在栈顶”的情况，
            // 此处不需要再倒一次，故保留原输出逻辑即可。
            int i = 0; // 原有：计数，每4个换行
            while (!s1.empty())
            {
                point cpos = s1.top();
                if ((++i) % 4 == 0)
                    std::cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--" << '\n';
                else
                    std::cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--";
                s1.pop();
            }
            std::cout << "END" << '\n';
        }
    }
}