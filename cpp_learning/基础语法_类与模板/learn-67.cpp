#include <iostream>
#include <string>

class appliance
{
protected:
    int power;
    int number;

public:
    appliance(int power, int number) : power(power), number(number) {}
};

class fan : virtual public appliance
{
protected:
    int wind_arr;
    int wind_power;

public:
    fan(int power, int number, int wind_arr, int wind_power) : appliance(power, number), wind_arr(wind_arr), wind_power(wind_power) {}

    void control_wind_arr(int wind_arr)
    {
        this->wind_arr = wind_arr;
    }

    void control_wind_power(int wind_power)
    {
        this->wind_power = wind_power;
    }

    std::string get_wind_arr() const
    {
        if (wind_arr == 0)
        {
            return "定向吹风";
        }
        else
        {
            return "旋转吹风";
        }
    }

    int get_wind_power() const
    {
        return wind_power;
    }
};

class jiashi : virtual public appliance
{
protected:
    double real_water;
    double max_water;

public:
    jiashi(int power, int number, double real_water, double max_water) : appliance(power, number), real_water(real_water), max_water(max_water) {}

    int alarm() const
    {
        if (real_water >= max_water * 5 / 10)
        {
            return 1;
        }
        // 旧写法：real_water >= max_water * 0.1 && real_water < 0.5
        // 0.5 是固定水量，必须改为最大容量的 50%。
        else if (real_water >= max_water * 0.1 && real_water < max_water * 0.5)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
};

class jiashi_fan : public jiashi, public fan
{
protected:
    int level;

public:
    jiashi_fan(int power, int number, int wind_arr, int wind_power, double real_water, double max_water, int level)
        // 旧写法：fan(...) 位于 jiashi(...) 前，会触发 -Wreorder 警告。
        : appliance(power, number), jiashi(power, number, real_water, max_water), fan(power, number, wind_arr, wind_power), level(level) {}

    void set_level(int set_level)
    {
        // 旧写法：level = set_level;  会让非法档位覆盖当前状态。
        if (set_level < 0 || set_level > 3)
        {
            return;
        }

        level = set_level;
        if (level == 1)
        {
            control_wind_arr(0);   // 旧写法：wind_arr = 0;
            control_wind_power(1); // 旧写法：wind_power = 1;
        }
        else if (level == 2)
        {
            control_wind_arr(1);   // 旧写法：wind_arr = 1;
            control_wind_power(2); // 旧写法：wind_power = 2;
        }
        else if (level == 3)
        {
            control_wind_arr(1);   // 旧写法：wind_arr = 1;
            control_wind_power(3); // 旧写法：wind_power = 3;
        }
    }
    int get_level() const
    {
        return level;
    }

    int get_number() const
    {
        return number;
    }

    int get_power() const
    {
        return power;
    }

    double get_realwater() const
    {
        return real_water;
    }

    std::string get_alarm() const
    {
        int num = alarm();
        if (num == 1)
        {
            return "水量正常";
        }
        else if (num == 2)
        {
            return "水量偏低";
        }
        else if (num == 3)
        {
            return "水量不足";
        }
        return "";
    }
};

std::ostream &operator<<(std::ostream &os, const jiashi_fan &f)
{
    // 旧写法：按档位分支，并将内容直接写到 std::cout。
    // 统一使用对象当前属性和传入流，避免固定文案与实际状态脱节。
    os << "加湿风扇--档位" << f.get_level() << '\n';
    os << "编号" << f.get_number() << "--功率" << f.get_power() << "W" << '\n';
    os << f.get_wind_arr() << "--风力" << f.get_wind_power() << "级" << '\n';
    os << "实际水容量" << f.get_realwater() << "升--" << f.get_alarm() << '\n';
    return os;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int number, power, wind_arr, wind_power, level;
        double real_water, max_water;
        std::cin >> number >> power >> wind_arr >> wind_power >> real_water >> max_water >> level;

        jiashi_fan f1 = jiashi_fan(power, number, wind_arr, wind_power, real_water, max_water, level);

        int set_level;
        std::cin >> set_level;
        f1.set_level(set_level);

        std::cout << f1;
    }
}
