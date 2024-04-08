#include <iostream>
#include <cmath>


using namespace std;

struct abiturient {
    string last_name;
    string first_name;
    string address;
    int marks[3];
};

double calculate_average_zno_score(abiturient abiturient) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += abiturient.marks[i];
    }
    return sum / 3;
}

int main() {
    const int n = 3;
    abiturient abiturients[n];

    for (int i = 0; i < n; i++) {
        cout << "Введіть прізвище абітурієнта " << i + 1 << ": ";
        cin >> abiturients[i].last_name;
        cout << "Введіть ім'я абітурієнта " << i + 1 << ": ";
        cin >> abiturients[i].first_name;
        cout << "Введіть адресу абітурієнта " << i + 1 << ": ";
        cin.ignore();
        getline(cin, abiturients[i].address);
        cout << "Введіть оцінки абітурієнта " << i + 1 << " з трьох предметів ЗНО: ";
        for (int j = 0; j < 3; j++) {
            cin >> abiturients[i].marks[j];
        }
    }

    int passing_score = 170;

    cout << "\nАбітурієнти, які пройшли прохідний бал:\n";
    for (int i = 0; i < n; i++) {
        double average_score = calculate_average_zno_score(abiturients[i]);
        if (average_score >= passing_score) {
            cout << "Прізвище: " << abiturients[i].last_name << endl;
            cout << "Ім'я: " << abiturients[i].first_name << endl;
            cout << "Адреса: " << abiturients[i].address << endl;
            cout << "Середній бал ЗНО: " << average_score << endl;
        }
    }

    return 0;
}