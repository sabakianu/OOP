#include <iostream>

using namespace std;
template<typename s>

void sortare(s v[], int n)
{
    s aux;//aux nu era templetizat
    for (int i = 0; i < n-1; i++) // i trebuie pana la n-2{
        for (int j = i+1; j < n; j++)// j ul de la i+1 {
            if (v[i] > v[j])// v[i] trebuie > decat v[j]
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for (int i = 0; i < n; i++) //trebuie <n{
        cout << v[i] << ' ';
    }
}

int main()
{
    int v[1001];//vectorul nu e s si trebuie tipul lui
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sortare(v, n);
    return 0;
}