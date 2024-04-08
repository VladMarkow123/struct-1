#include <iostream>
#include <cmath>


using namespace std;

struct triangle {
    double side1;
    double side2;
    double side3;

    double area() {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    triangle triangle1;
    triangle triangle2;

    cout << "Введіть довжини сторін першого трикутника: ";
    cin >> triangle1.side1 >> triangle1.side2 >> triangle1.side3;

    cout << "Введіть довжини сторін другого трикутника: ";
    cin >> triangle2.side1 >> triangle2.side2 >> triangle2.side3;

    double area1 = triangle1.area();

    double area2 = triangle2.area();

    double totalArea = area1 + area2;

    cout << "Сума площ двох трикутників: " << totalArea << endl;

    return 0;
}