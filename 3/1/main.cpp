#include <iostream>
#include <math.h>


using namespace std;

struct students {
    string last_name;
    string first_name;
    int scholarship;
    int hours_absent;
};

int main() {
    const int n = 3;
    students student_array[n];

    for (int i = 0; i < n; i++) {
        cout << "Введіть прізвище студента " << i + 1 << ": ";
        getline(cin, student_array[i].last_name);
        cout << "Введіть ім'я студента " << i + 1 << ": ";
        getline(cin, student_array[i].first_name);
        cout << "Введіть розмір стипендії студента " << i + 1 << ": ";
        cin >> student_array[i].scholarship;
        cout << "Введіть кількість годин відсутності студента " << i + 1 << ": ";
        cin >> student_array[i].hours_absent;
        cin.ignore();
    }

    cout << "\nСтуденти, які отримують стипендію та не пропустили більше 2 годин:\n";
    int total_hours_absent = 0;
    for (int i = 0; i < n; i++) {
        if (student_array[i].scholarship > 0 && student_array[i].hours_absent <= 2) {
            cout << "Прізвище: " << student_array[i].last_name << endl;
            cout << "Ім'я: " << student_array[i].first_name << endl;
            cout << "Стипендія: " << student_array[i].scholarship << endl;
            cout << "Годин відсутності: " << student_array[i].hours_absent << endl;
            total_hours_absent += student_array[i].hours_absent;
        }
    }

    cout << "\nЗагальна кількість годин відсутності всіма студентами: " << total_hours_absent << endl;

    return 0;
}