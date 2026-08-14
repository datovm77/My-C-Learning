#include <cstring>
#include <iostream>

using namespace std;

class CN; // 提前声明
class EN; // 提前声明

// 抽象类
class Weight
{
protected:
    char kind[20]; // 计重类型
    int gram;      // 克

public:
    Weight(const char tk[] = "no name", int tg = 0)
    {
        strcpy(kind, tk);
        gram = tg;
    }
    virtual void print(ostream &out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
    int jin;
    int liang;
    int qian;

public:
    CN(int tjin = 0, int tliang = 0, int tqian = 0, int tgram = 0, const char tk[] = "no name")
        : Weight(tk, tgram), jin(tjin), liang(tliang), qian(tqian)
    {
    }

    void Convert(int totalGram)
    {
        jin = totalGram / 500;
        totalGram %= 500;
        liang = totalGram / 50;
        totalGram %= 50;
        qian = totalGram / 5;
        gram = totalGram % 5;
    }

    void print(ostream &out) override
    {
        out << kind << ':' << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << '\n';
    }
};

// 英国计重
class EN : public Weight
{
    int pound;
    int ounce;
    int drachm;

public:
    EN(int tpound = 0, int tounce = 0, int tdrachm = 0, int tgram = 0, const char tk[] = "no name")
        : Weight(tk, tgram), pound(tpound), ounce(tounce), drachm(tdrachm)
    {
    }

    void Convert(int totalGram)
    {
        pound = totalGram / 512;
        totalGram %= 512;
        ounce = totalGram / 32;
        totalGram %= 32;
        drachm = totalGram / 2;
        gram = totalGram % 2;
    }

    operator CN() const
    {
        int totalGram = pound * 512 + ounce * 32 + drachm * 2 + gram;
        CN result(0, 0, 0, 0, "中国计重");
        result.Convert(totalGram);
        return result;
    }

    void print(ostream &out) override
    {
        out << kind << ':' << pound << "磅" << ounce << "盎司" << drachm << "打兰" << gram << "克" << '\n';
    }
};

// 以全局函数方式重载输出运算符
ostream &operator<<(ostream &out, Weight &weight)
{
    weight.print(out);
    return out;
}

// 主函数
int main()
{
    int tw;
    // 创建一个中国计重类对象cn
    // 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
    CN cn(0, 0, 0, 0, "中国计重");
    cin >> tw;
    cn.Convert(tw); // 把输入的克数转成中国计重
    cout << cn;

    // 创建英国计重类对象en
    // 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
    EN en(0, 0, 0, 0, "英国计重");
    cin >> tw;
    en.Convert(tw); // 把输入的克数转成英国计重
    cout << en;
    cn = en; // 把英国计重转成中国计重
    cout << cn;
    return 0;
}
