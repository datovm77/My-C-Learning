#include<iostream>
#include<string>
#include<vector>
//力扣 14. 最长公共前缀 解法一
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        int length = strs[0].size(); //代表单词的最短长度
        std::string str = "";//代表公共内容
        for(std::string str:strs)
        {
            //std::cout<< str << "\n";
            if(str.size()<length)
            {
                length = str.size();
            }
        }

        for(int i = 0;i<length;++i)
        {
            str += strs[0][i];
            for(int j = 1;j<strs.size();++j)
            {
                if(strs[j].substr(0,i+1)!=str)
                {
                    return strs[j].substr(0,i);
                }
            }
        }
        return str;

    }
};


void test01()
{
    std::vector<std::string> strs {"flower","flow","flight"};
    Solution s1;
    std::string str = s1.longestCommonPrefix(strs);
    std::cout << str <<std::endl;
}

int main()
{
    test01();

    return 0;
}