#include <iostream>

using namespace std;

class Circle {
    double radius;

   public:
    Circle(double r) { radius = r; }
    double circum() { return 2 * radius * 3.14; }
    double area() { return radius * radius * 3.14; }
};

class Cylinder {
    Circle base;
    double height;

   public:
    Cylinder(double r, double h) : base(r), height(h) {}
    double volume() { return base.area() * height; }
};

int main() {
    double r, h;
    cin >> r >> h;
    Cylinder cyl(r, h);
    cout << cyl.volume();
    return 0;
}
