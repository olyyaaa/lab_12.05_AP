
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Elem {
    Elem* link;
    int info;
};

int main() {
    Elem* top = nullptr;
    ifstream file("D://input.txt");
    int number;
    while (file >> number) {
        Elem* newElem = new Elem{ top, number };
        top = newElem;
    }
    file.close();

    while (top != nullptr && top->link != nullptr && top->link->link != nullptr) {
        int a = top->info;
        top = top->link;
        int b = top->info;
        top = top->link;
        int c = top->info;
        top = top->link;

        if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
            double radius = (a + b - c) / 2.0;
            cout << "Triangle with sides " << a << ", " << b << ", " << c << " is  right triangle. Radius: " << radius << endl;
        }
        else {
            cout << "Triangle with sides " << a << ", " << b << ", " << c << " is NOT right triangle." << endl;
        }
    }

    return 0;
}