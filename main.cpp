#include <iostream>
#include <ctime>

using namespace std;

/*
 * Funcion para imprimir el array.
 */
void print(int arrayN[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            cout << arrayN[i] << ", ";
        } else {
            cout << arrayN[i];
        }
    }
    cout << "]" << endl;
}

/*
 * Funcion para intercambiar los elementos a > b.
 */
void swapElement(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/*
 * Funcion Shell -> Ordenamiento.
 */
void shell(int arrayN[], int n) {
    float fact = 0.75;
    int dif = n * fact;
    int limit;

    while(dif > 0) {
        limit = n - dif;
        for(int i = 0; i <= limit; i++) {
            if(arrayN[i] > arrayN[i + dif]) {
                swapElement(&arrayN[i], &arrayN[i + dif]);
            }
        }
        dif *= fact;
    }
}

/*
 * Funcion principal.
 */
int main() {
    srand(time(0));
    int arrayNum[10]; // = {39, 59, 19, 90, 10, 17, 52, 76, 80, 13};
    int length = (sizeof(arrayNum)/sizeof(*arrayNum)); // BYTES del arreglo / BYTES del puntero (Bytes 1 a 8) -> 40 / 4.

    for(int i = 0; i < 10; i++) {
      arrayNum[i] = 1 + rand() % 100;
    }

    cout << "Ordenamiento Shell" << endl;
    cout << "- Arreglo original: ";
    print(arrayNum, length);

    shell(arrayNum, length - 1);

    cout << "- Arreglo ordenado: ";
    print(arrayNum, length);

    return 0;
}
