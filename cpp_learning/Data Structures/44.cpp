#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> months = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    int t;
    std::cin >> t;
    while (t--)
    {
        int month;
        std::cin >> month;
        if (month <= 12 && month >= 1)
            std::cout << months[month - 1] << '\n';
        else
            std::cout << "error" << '\n';
    }
    return 0;
}