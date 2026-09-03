#include <iostream>
using namespace std;

int main()
{
    const char *months[12] = {
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
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        if (num >= 1 && num <= 12)
        {
            cout << months[num - 1] << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    return 0;
}