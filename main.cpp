#include <iostream>
#include <cstdio>
using namespace std;

int n;

class Stu {
private:
    string name, cre;
    int id;
public:
    Stu(string name, int id, string cre) : name(name), id(id), cre(cre) {};

    void reset() {
        name = "None";
        id = 0;
        cre = "B0";
    }

    void pri() {
        cout << name << " " << "id: " << id << " " << cre << '\n';
    }
};

int main()
{
    Stu z1("seonkyu", 20220487, "A+");
    z1.pri();
    z1.reset();
    z1.pri();

    return 0;
}
