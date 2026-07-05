#include <bits/stdc++.h>


using namespace std;

int main() {

    int cantidad_programas;
    cin >> cantidad_programas;

    map<int, int> Ltiempo;

    for (int i = 0; i < cantidad_programas; ++i) {
        int inicio, fin;
        cin >> inicio >> fin;

        Ltiempo[inicio]++;

        Ltiempo[fin + 1]--;
    }

    int televisores_actuales = 0;
    bool es_posible = true;
    
    for (auto const& [tiempo, cambio] : Ltiempo) {
 
        televisores_actuales += cambio;

         if (televisores_actuales > 2) {
            es_posible = false;
            break;
        }
    }


    if (es_posible == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}