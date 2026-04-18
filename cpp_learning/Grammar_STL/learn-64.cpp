#include <iostream>
#include <string>
#include <cmath>
#include <complex>
#include <iomanip>

class Equation
{
private:
    double a = 1.0;
    double b = 1.0;
    double c = 0.0;

public:
    Equation(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}
    Equation() = default;

    void set(double aa, double bb, double cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }

    void getRoot()
    {
        double sign = b * b - 4.0 * a * c;
        
        if (sign > 0)
        {
            double x1 = (-b + std::sqrt(sign)) / (2.0 * a);
            double x2 = (-b - std::sqrt(sign)) / (2.0 * a);
            std::cout << "x1=" << std::fixed << std::setprecision(2) << x1 
                      << " x2=" << std::fixed << std::setprecision(2) << x2 << '\n';
        }
        else if (sign == 0)
        {
            double x = -b / (2.0 * a);  
            std::cout << "x1=x2=" << std::fixed << std::setprecision(2) << x << '\n';
        }
        else
        {
            std::complex<double> disc(b * b - 4.0 * a * c);
            std::complex<double> x1 = (-b + std::sqrt(disc)) / (2.0 * a);
            std::complex<double> x2 = (-b - std::sqrt(disc)) / (2.0 * a);
            
            std::cout << "x1=" << std::fixed << std::setprecision(2) 
                      << x1.real() << (x1.imag() >= 0 ? "+" : "") << x1.imag() << "i "
                      << "x2=" << std::fixed << std::setprecision(2) 
                      << x2.real() << (x2.imag() >= 0 ? "+" : "") << x2.imag() << "i\n";
        }
    }
};

int main()
{
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; ++i)
    {
        double a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c; 
        Equation e1(a, b, c);
        e1.getRoot();
    }
    return 0;
}