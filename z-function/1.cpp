#include <bits/stdc++.h>
using namespace std;

vector<int> calcular_arreglo_z(string cadena) {
    int n = cadena.length();
    vector<int> z(n, 0);
    int izq = 0, der = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= der) {
            z[i] = min(der - i + 1, z[i - izq]);
        }
        while (i + z[i] < n && cadena[z[i]] == cadena[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > der) {
            izq = i;
            der = i + z[i] - 1;
        }
    }
    return z;
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int tam1 = s1.length();
    int tam2 = s2.length();

    if (s1 + s2 != s2 + s1) {
        cout << 0 << "\n";
        return 0;
    }

    int tam_mcd = gcd(tam1, tam2);
    string candidato = s1.substr(0, tam_mcd);

    vector<int> z = calcular_arreglo_z(candidato);
    
    int divisores_comunes = 0;

    for (int len = 1; len <= tam_mcd; ++len) {
        if (tam_mcd % len == 0) {
            
            if (len == tam_mcd) {
                divisores_comunes++;
            } 
            else if (z[len] == tam_mcd - len) {
                divisores_comunes++;
            }
        }
    }
    cout << divisores_comunes << "\n";

    return 0;
}