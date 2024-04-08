#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int main() {

    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    int a[n];
    cout << "Введіть елементи: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }
    int even[even_count];
    int odd[odd_count];
    int even_index = 0;
    int odd_index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            even[even_index++] = a[i];
        else
            odd[odd_index++] = a[i];
    }

    sort(even, even + even_count);

    sort(odd, odd + odd_count, greater<int>());

    cout << "Результат: ";
    for (int i = 0; i < even_count; i++) {
        cout << even[i] << " ";
    }
    for (int i = 0; i < odd_count; i++) {
        cout << odd[i] << " ";
    }

    return 0;


    }