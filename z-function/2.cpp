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
    int n;
    cin >> n;

    string resultado;
    cin >> resultado;

    for (int i = 1; i < n; ++i) {
        string nueva_palabra;
        cin >> nueva_palabra;

        int tam_resultado = resultado.length();
        int tam_nueva = nueva_palabra.length();

        int letras_a_tomar = min(tam_resultado, tam_nueva);
        string trozo_final = resultado.substr(tam_resultado - letras_a_tomar);

        string combinada = nueva_palabra + "#" + trozo_final;

        vector<int> z = calcular_arreglo_z(combinada);

        int max_solapamiento = 0;
        int tam_comb = combinada.length();

        int inicio_trozo = tam_nueva + 1; 

        for (int j = inicio_trozo; j < tam_comb; ++j) {
            if (j + z[j] == tam_comb) {
                max_solapamiento = z[j];
                break; 
            }
        }

        resultado += nueva_palabra.substr(max_solapamiento);
    }

    cout << resultado;

    return 0;
}