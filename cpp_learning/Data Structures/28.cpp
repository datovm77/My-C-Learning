#include <iostream>
#include <string>
using namespace std;

class CPeople {
protected:
    string name;
    string sex;
    int age;
public:
    CPeople() {}
    CPeople(string n, string s, int a) : name(n), sex(s), age(a) {}
    void print() {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
    }
};

class CStudent : virtual public CPeople {
protected:
    string student_id;
    double score;
public:
    CStudent() {}
    CStudent(string n, string s, int a, string id, double sc)
        : CPeople(n, s, a), student_id(id), score(sc) {}
    void print() {
        CPeople::print();
        cout << "No.: " << student_id << endl;
        cout << "Score: " << score << endl;
    }
};

class CTeacher : virtual public CPeople {
protected:
    string position;
    string department;
public:
    CTeacher() {}
    CTeacher(string n, string s, int a, string pos, string dept)
        : CPeople(n, s, a), position(pos), department(dept) {}
    void print() {
        CPeople::print();
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
    }
};

class CGradOnWork : public CStudent, public CTeacher {
protected:
    string direction;
    string tutor;
public:
    CGradOnWork(string n, string s, int a, string id, double sc,
                string pos, string dept, string dir, string tut)
        : CPeople(n, s, a),
          CStudent(n, s, a, id, sc),
          CTeacher(n, s, a, pos, dept),
          direction(dir), tutor(tut) {}
    void print() {
        CPeople::print();
        cout << "No.: " << student_id << endl;
        cout << "Score: " << score << endl;
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
        cout << "Direction: " << direction << endl;
        cout << "Tutor: " << tutor << endl;
    }
};

int main() {
    string name, sex, student_id, position, department, direction, tutor;
    int age;
    double score;

    cin >> name >> sex >> age;
    cin >> student_id >> score;
    cin >> position >> department;
    cin >> direction >> tutor;

    CPeople p(name, sex, age);
    cout << "People:" << endl;
    p.print();
    cout << endl;

    CStudent s(name, sex, age, student_id, score);
    cout << "Student:" << endl;
    s.print();
    cout << endl;

    CTeacher t(name, sex, age, position, department);
    cout << "Teacher:" << endl;
    t.print();
    cout << endl;

    CGradOnWork g(name, sex, age, student_id, score, position, department, direction, tutor);
    cout << "GradOnWork:" << endl;
    g.print();

    return 0;
}
