#include <iostream>

class CVehicle
{
protected:
    int max_speed;
    int speed;
    int weight;

public:
    CVehicle(int m_s, int s, int w) : max_speed(m_s), speed(s), weight(w) {}

    virtual void display()
    {
        std::cout << "Vehicle:" << '\n';
        std::cout << "max_speed:" << max_speed << '\n';
        std::cout << "speed:" << speed << '\n';
        std::cout << "weight:" << weight << '\n';
        std::cout << '\n';
    }
};

class CBicycle : virtual public CVehicle
{
protected:
    int height;

public:
    CBicycle(int m_s, int s, int w, int h) : CVehicle(m_s, s, w), height(h) {}
    void display()
    {
        std::cout << "Bicycle:" << '\n';
        std::cout << "max_speed:" << max_speed << '\n';
        std::cout << "speed:" << speed << '\n';
        std::cout << "weight:" << weight << '\n';
        std::cout << "height:" << height << '\n';
        std::cout << '\n';
    }
};

class CMotocar : virtual public CVehicle
{
protected:
    int seat;

public:
    CMotocar(int m_s, int s, int w, int seat) : CVehicle(m_s, s, w), seat(seat) {}
    void display()
    {
        std::cout << "Motocar:" << '\n';
        std::cout << "max_speed:" << max_speed << '\n';
        std::cout << "speed:" << speed << '\n';
        std::cout << "weight:" << weight << '\n';
        std::cout << "seat_num:" << seat << '\n';
        std::cout << '\n';
    }
};
class CMotocycle : public CBicycle, public CMotocar
{
public:
    CMotocycle(int m_s, int s, int w, int h, int seat)
        : CVehicle(m_s, s, w), CBicycle(m_s, s, w, h), CMotocar(m_s, s, w, seat) {}

    void display()
    {
        std::cout << "Motocycle:" << '\n';
        std::cout << "max_speed:" << max_speed << '\n';
        std::cout << "speed:" << speed << '\n';
        std::cout << "weight:" << weight << '\n';
        std::cout << "height:" << height << '\n';
        std::cout << "seat_num:" << seat << '\n';
        std::cout << '\n';
    }
};

int main()
{
    int max_speed, speed, weight, height, seat;
    std::cin >> max_speed >> speed >> weight;
    std::cin >> height;
    std::cin >> seat;

    CVehicle v(max_speed, speed, weight);
    v.display();

    CBicycle b(max_speed, speed, weight, height);
    b.display();

    CMotocar c(max_speed, speed, weight, seat);
    c.display();

    CMotocycle m(max_speed, speed, weight, height, seat);
    m.display();

    return 0;
}
