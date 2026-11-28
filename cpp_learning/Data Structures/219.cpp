// CSP202509A 蒙特卡洛
#include <iostream>

using namespace std;
double a;
int n;
int main()
{
    cin >> n >> a;

    int sum = 0;
    int nn = n;
    while (nn--)
    {
        double x, y;
        cin >> x >> y;

        double len = x * x + y * y;
        if (len <= (a * a))
        {
            sum++;
        }
    }
    double result = 4.0 * sum / n;
    cout << result << '\n';
}