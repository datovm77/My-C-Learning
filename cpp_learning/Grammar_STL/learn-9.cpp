#include<iostream>
#include<string>

class Solution {
public:
    int lengthOfLastWord(std::string s) 
    {
        int length = 0;
        int sum = s.size();
        while(sum >=0 && s[sum] == ' ')
        {
            sum--;
        }
        while(sum >= 0&& s[sum] != ' ')
        {
            length++;
            sum--;
        }
        return length;

    }
};

int main()
{
    Solution s1;
    s1.lengthOfLastWord("   fly me   to   the moon  ");

    return 0;
}