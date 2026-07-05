#include <bits/stdc++.h>
using namespace std;

void resolver() {
    int n;
    cin >> n;

    map<int, int> frecuencias;
    int f_max = 0;

    for (int i = 0; i < n; ++i) {
        int numero;
        cin >> numero;
        frecuencias[numero]++;

        f_max = max(f_max, frecuencias[numero]);
    }

    if (f_max > n - f_max) {
        cout << 2 * f_max - n << "\n";
    } 
    else {
        cout << n % 2 << "\n";
    }
}

int main() {
    int casos;
    if (cin >> casos) {
        while (casos--) {
            resolver();
        }
    }
    return 0;
}