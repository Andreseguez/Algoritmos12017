#include <iostream>
#include <string>

using namespace std;

#define MAX 20


struct tipo_vector {
    string vector;
};

void cargar(tipo_vector matriz[MAX][MAX], int n, int m, int N, string frase);
void mostrar(tipo_vector matriz[MAX][MAX], int n, int m, int N);

int main()
{
    int n, m, N;
    string frase;

    tipo_vector matriz[MAX][MAX];

    cout << "ingerse el numero de elementos de las filas de la matriz interna: ";
    cin >> n;

    cout << "ingrese el numero de elmentos de la fila de la matriz interna: ";
    cin >> m;

    cout << "ingrese el numero de elementos del vector ";
    cin >> N;

    cout << "ingrese su frase: ";

    cin.ignore();
    getline(cin, frase);

    frase = frase + " ";

    cargar(matriz, n, m, N, frase);
    mostrar(matriz, n, m, N);

    return 0;
}

void cargar(tipo_vector matriz[MAX][MAX], int n, int m, int N, string frase)
{
    int fptr = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matriz[i][j].vector.resize(N, ' ');

            for (int k = 0; k < N; ++k)
            {
                matriz[i][j].vector[k] = frase[fptr++];
                fptr = (fptr % frase.size());
            }
        }
    }
}


void mostrar(tipo_vector matriz[MAX][MAX], int n, int m, int N)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {   
            cout << matriz[i][j].vector << "     ";
        }
        cout << endl;
    }
}