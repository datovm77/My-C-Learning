#include <iostream>
#include <string>
#include <vector>

/**
 * ============================================================================
 * 教学代码：基于 KMP 算法与 C++ STL 思想的字符串查找与替换
 * 
 * 【STL 思想体现】：
 * 1. 契约设计（Interface Design）：
 *    - 查找函数 kmpFind 设计为与 std::string::find 一致的接口规范：
 *      成功时返回匹配起始位置（0-based 下标，类型为 std::string::size_type），
 *      失败时返回 std::string::npos。
 * 2. 容器与内存管理（Containers & Resource Management）：
 *    - 使用 std::string 动态管理文本与模式串；
 *    - 使用 std::vector<int> 动态管理 next 数组，避免裸数组与手动内存分配。
 * 3. 算法与数据操作分离（Separation of Concerns）：
 *    - 利用 std::string::replace 成员函数高效完成变长字符串替换，
 *      自动处理 pattern 与 replacement 长度不一致的内存搬移与扩容收缩。
 * 4. 传参优化（Const Reference）：
 *    - 严格使用 const std::string& 避免不必要的数据深拷贝。
 * ============================================================================
 */

/**
 * @brief 构建 KMP 算法的 next 数组（失配转移表）
 * 
 * @param pattern 模式串
 * @param next    输出参数：存储模式串各位置失配时的回退位置
 * 
 * 【原理说明】：
 * next[i] 表示当模式串在下标 i 处失配时，模式串指针应该回退到的下标。
 * 本实现采用经典写法：next[0] = -1。
 * 本质是求解 pattern[0 ... i-1] 的最长相等真前缀与真后缀的长度。
 */
void getNext(const std::string &pattern, std::vector<int> &next)
{
    int len = static_cast<int>(pattern.size());
    int i = 0;   // 后缀末尾指针
    int j = -1;  // 前缀末尾指针

    next.assign(len, 0);
    next[0] = -1;

    while (i < len - 1)
    {
        // 当 j == -1（已经回退到最开头）或者前后缀字符匹配成功时
        if (j == -1 || pattern[i] == pattern[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            // 字符不匹配，前缀指针利用已计算的 next 数组向前回退
            j = next[j];
        }
    }
}

/**
 * @brief 使用 KMP 算法在主串中查找模式串的首次出现位置
 * 
 * @param text    主串（待查找文本）
 * @param pattern 模式串
 * @param next    预处理好的 next 数组
 * @return std::string::size_type 首次匹配的起始索引（0-based），未找到则返回 std::string::npos
 * 
 * 【STL 风格】：
 * 返回类型与 std::string::find 保持一致，遵循 STL "未找到返回 npos" 的惯用法。
 */
std::string::size_type kmpFind(const std::string &text,
                               const std::string &pattern,
                               const std::vector<int> &next)
{
    int tLen = static_cast<int>(text.size());
    int pLen = static_cast<int>(pattern.size());

    int i = 0;  // 主串指针（单调递增，不回溯）
    int j = 0;  // 模式串指针

    while (i < tLen && j < pLen)
    {
        if (j == -1 || text[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            // 失配时，主串指针 i 不动，模式串指针 j 根据 next 数组滑动
            j = next[j];
        }
    }

    // 若 j 走到了模式串末尾，说明匹配成功
    if (j == pLen)
    {
        return static_cast<std::string::size_type>(i - j);
    }

    // 未找到匹配，遵循 STL 契约返回 std::string::npos
    return std::string::npos;
}

/**
 * @brief 在主串中用替换串替换首次出现的模式串
 * 
 * @param text        主串（输入并直接原地修改）
 * @param pattern     待查找的模式串
 * @param replacement 用于替换的新串
 * @return true 发生了替换；false 未找到模式串，未发生替换
 * 
 * 【STL 核心优势】：
 * 调用 text.replace(pos, pattern.size(), replacement)
 * 能够优雅且自动地处理：
 * 1. 替换串长度 > 模式串长度（如 "abc" -> "ccccc"，自动扩容并向后搬移字符）
 * 2. 替换串长度 < 模式串长度（如 "abc" -> "c"，自动向前搬移并收缩尺寸）
 * 3. 替换串长度 == 模式串长度（如 "bb" -> "ff"，原地覆写）
 */
bool replaceFirstKMP(std::string &text,
                     const std::string &pattern,
                     const std::string &replacement)
{
    // 1. 预处理模式串，生成 next 数组
    std::vector<int> next;
    getNext(pattern, next);

    // 2. 使用 KMP 算法查找匹配位置
    std::string::size_type pos = kmpFind(text, pattern, next);

    // 3. 如果找到，调用 STL 的 replace 算法进行变长替换
    if (pos != std::string::npos)
    {
        text.replace(pos, pattern.size(), replacement);
        return true;
    }

    return false;
}

int main()
{
    // 提高标准 I/O 效率
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t))
    {
        return 0;
    }

    while (t--)
    {
        std::string text;
        std::string pattern;
        std::string replacement;

        std::cin >> text >> pattern >> replacement;

        // 第一行：输出原始主串
        std::cout << text << '\n';

        // 备份一份主串用于修改（体现原数据保护与 STL 值语义）
        std::string modifiedText = text;

        // 执行单处替换操作
        replaceFirstKMP(modifiedText, pattern, replacement);

        // 第二行：输出替换后的结果（未发生替换则原样输出）
        std::cout << modifiedText << '\n';
    }

    return 0;
}
