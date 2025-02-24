#include <iostream>
#include <string>

using namespace std;
struct Point {
    int x = 0;
    int y = 0;

    void display() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }

    void mod(int z, int n) {
        if (z == 0) x = n;
        else y = n;
    }
};

class Person {
private:
    string name;
    int age;

public:
    Person(string p1, int p2) : name(p1), age(p2) {}

    void introduce() const {
        std::cout << "Hi, I'm " << name << ", " << age << " years old." << std::endl;
    }
};

class Taehee {
private:
    int id, num;
    string cre;
public:
    Taehee(int id, int num, string cre) : id(id), num(num), cre(cre) {}

    void pri() const {
        cout << id << " " << num << " " << cre << '\n';
    }
};

int main() {
//    Point p;
//    p.display();
//    p.x = 20;
//    p.display();
//    p.mod(0, 0);
//    p.display();
//    p.mod(1, 100);
//    p.display();
//
//    Point q;
//    q.mod(0, 100);
//    q.display();
//
//    Point z;
//    z.display();

    //Person person("Alice", 25);
    //person.introduce();

    Taehee taehee(1001, 3, "A+");
    taehee.pri();
    return 0;
}
