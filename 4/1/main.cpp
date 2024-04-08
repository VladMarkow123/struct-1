#include <iostream>
#include <string>

using namespace std;

struct SCHOOL {
    string NAME;
    int KLAS;
    int SUBJECT[5];
};

void input_students(SCHOOL students[], int n) {
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "Введіть ім'я студента: ";
        getline(cin, students[i].NAME);
        cout << "Введіть номер класу студента: ";
        cin >> students[i].KLAS;
        cout << "Введіть оцінки з п'яти предметів: ";
        for (int j = 0; j < 5; ++j) {
            cin >> students[i].SUBJECT[j];
        }
        cin.ignore();
    }
}

void print_excellent_students(const SCHOOL students[], int n) {
    cout << "Відмінники:\n";
    for (int i = 0; i < n; ++i) {
        if (students[i].KLAS >= 11 && students[i].SUBJECT[0] == 5 && students[i].SUBJECT[1] == 5 && students[i].SUBJECT[2] == 5 && students[i].SUBJECT[3] == 5 && students[i].SUBJECT[4] == 5) {
            cout << students[i].NAME << " " << students[i].KLAS << endl;
        }
    }
}

void print_students_with_bad_grades(const SCHOOL students[], int n) {
    cout << "Студенти з поганими оцінками:\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (students[i].SUBJECT[j] == 2) {
                cout << students[i].NAME << " " << students[i].KLAS << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Немає студентів з поганими оцінками" << endl;
    }
}

void sort_students_by_class(SCHOOL students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].KLAS < students[j + 1].KLAS) {
                SCHOOL temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void print_students(const SCHOOL students[], int n) {
    cout << "Студенти:\n";
    for (int i = 0; i < n; ++i) {
        cout << students[i].NAME << " " << students[i].KLAS << " ";
        for (int j = 0; j < 5; ++j) {
            cout << students[i].SUBJECT[j] << " ";
        }
        cout << endl;
    }
}

void delete_students_from_class(SCHOOL students[], int& n) {
    int class_number;
    cout << "Введіть номер класу для видалення: ";
    cin >> class_number;
    for (int i = 0; i < n; ++i) {
        if (students[i].KLAS == class_number) {
            for (int j = i; j < n - 1; ++j) {
                students[j] = students[j + 1];
            }
            --n;
            --i;
        }
    }
}

int main() {
    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;

    SCHOOL *students = new SCHOOL[n];

    input_students(students, n);

    print_excellent_students(students, n);
    print_students_with_bad_grades(students, n);
    sort_students_by_class(students, n);
    print_students(students, n);
    delete_students_from_class(students, n);
    print_students(students, n);

    delete[] students;

    return 0;
}
