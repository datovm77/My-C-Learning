#include <iostream>
#include <string>
using namespace std;

class CPeople
{
protected:
    string name;
    string sex;
    int age;

public:
    CPeople(string n, string s, int a) : name(n), sex(s), age(a) {}
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
    }
};

class CStudent : virtual public CPeople
{
protected:
    string no;
    double score;

public:
    CStudent(string n, string s, int a, string no_, double sc)
        : CPeople(n, s, a), no(no_), score(sc) {}
    void print()
    {
        CPeople::print();
        cout << "No.: " << no << endl;
        cout << "Score: " << score << endl;
    }
};

class CTeacher : virtual public CPeople
{
protected:
    string position;
    string department;

public:
    CTeacher(string n, string s, int a, string pos, string dept)
        : CPeople(n, s, a), position(pos), department(dept) {}
    void print()
    {
        CPeople::print();
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
    }
};

class CGradOnWork : public CStudent, public CTeacher
{
protected:
    string direction;
    string tutor;

public:
    CGradOnWork(string n, string s, int a, string no_, double sc,
                string pos, string dept, string dir, string tut)
        : CPeople(n, s, a), CStudent(n, s, a, no_, sc), CTeacher(n, s, a, pos, dept),
          direction(dir), tutor(tut) {}
    void print()
    {
        CPeople::print();
        cout << "No.: " << no << endl;
        cout << "Score: " << score << endl;
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
        cout << "Direction: " << direction << endl;
        cout << "Tutor: " << tutor << endl;
    }
};

int main()
{
    string name, sex, no, pos, dept, dir, tut;
    int age;
    double sc;
    cin >> name >> sex >> age;
    cin >> no >> sc;
    cin >> pos >> dept;
    cin >> dir >> tut;
    CPeople p(name, sex, age);
    CStudent s(name, sex, age, no, sc);
    CTeacher t(name, sex, age, pos, dept);
    CGradOnWork g(name, sex, age, no, sc, pos, dept, dir, tut);
    cout << "People:" << endl;
    p.print();
    cout << endl;
    cout << "Student:" << endl;
    s.print();
    cout << endl;
    cout << "Teacher:" << endl;
    t.print();
    cout << endl;
    cout << "GradOnWork:" << endl;
    g.print();
    return 0;
}
