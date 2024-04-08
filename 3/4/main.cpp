#include <iostream>
#include <cmath>


using namespace std;

struct worker {
    string last_name;
    string initials;
    string position;
    int year_of_employment;
    double salary;

    int experience() {
        return 2023 - year_of_employment;
    }

    double salary_after_tax() {
        return salary * 0.67;
    }
};

int main() {
    const int n = 3;
    worker workers[n];

    for (int i = 0; i < n; i++) {
        cout << "Введіть прізвище працівника " << i + 1 << ": ";
        cin >> workers[i].last_name;
        cout << "Введіть ініціали працівника " << i + 1 << ": ";
        cin >> workers[i].initials;
        cout << "Введіть посаду працівника " << i + 1 << ": ";
        cin >> workers[i].position;
        cout << "Введіть рік вступу на роботу працівника " << i + 1 << ": ";
        cin >> workers[i].year_of_employment;
        cout << "Введіть зарплату працівника " << i + 1 << ": ";
        cin >> workers[i].salary;
    }


    cout << "\nІнформація про працівників:\n";
    for (int i = 0; i < n; i++) {
        cout << "Прізвище: " << workers[i].last_name << endl;
        cout << "Ініціали: " << workers[i].initials << endl;
        cout << "Посада: " << workers[i].position << endl;
        cout << "Рік вступу на роботу: " << workers[i].year_of_employment << endl;
        cout << "Зарплата: " << workers[i].salary << endl;
        cout << "Стаж роботи: " << workers[i].experience() << " років" << endl;
        cout << "Зарплата після оподаткування: " << workers[i].salary_after_tax() << endl;
        cout << endl;
    }

    return 0;
}
