#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int arbol[4 * MAXN];
int respuesta[MAXN];

void actualizar(int nodo, int inicio, int fin, int l, int r, int ganador) {
    if (inicio > r || fin < l) {
        return;
    }

    if (l <= inicio && fin <= r) {
        arbol[nodo] = ganador; 
        return;
    }

    if (arbol[nodo] != 0) {
        arbol[2 * nodo] = arbol[nodo];
        arbol[2 * nodo + 1] = arbol[nodo];
        arbol[nodo] = 0;
    }

    int medio = inicio + (fin - inicio) / 2;
    actualizar(2 * nodo, inicio, medio, l, r, ganador);
    actualizar(2 * nodo + 1, medio + 1, fin, l, r, ganador);
}


void empujar_todo(int nodo, int inicio, int fin) {
    if (inicio == fin) {

        respuesta[inicio] = arbol[nodo];
        return;
    }

    if (arbol[nodo] != 0) {
        arbol[2 * nodo] = arbol[nodo];
        arbol[2 * nodo + 1] = arbol[nodo];
    }

    int medio = inicio + (fin - inicio) / 2;
    empujar_todo(2 * nodo, inicio, medio);
    empujar_todo(2 * nodo + 1, medio + 1, fin);
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> L(m), R(m), X(m);
    for (int i = 0; i < m; ++i) {
        cin >> L[i] >> R[i] >> X[i];
    }

    for (int i = m - 1; i >= 0; --i) {

        if (L[i] < X[i]) {
            actualizar(1, 1, n, L[i], X[i] - 1, X[i]);
        }
        if (X[i] < R[i]) {
            actualizar(1, 1, n, X[i] + 1, R[i], X[i]);
        }
    }

    empujar_todo(1, 1, n);

    for (int i = 1; i <= n; ++i) {
        cout << respuesta[i] << (i == n ? "" : " ");
    }

    return 0;
}