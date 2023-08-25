#include <iostream>
#define N 10

using namespace std;

int main() {
    double a[N][N], b[N], constant, term;
    int i, j, k, n;

    cout << "Enter number of unknowns: ";
    cin >> n;

    cout << "Enter the augmented matrix:" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Gauss Jordan elimination
    for (k = 1; k <= n; k++) {
        constant = a[k][k];

        for (j = 1; j <= n + 1; j++) {
            a[k][j] = a[k][j] / constant;
        }

        for (i = 1; i <= n; i++) {
            if (i != k) {
                term = a[i][k];
                for (j = 1; j <= n + 1; j++) {
                    a[i][j] = a[i][j] - term * a[k][j];
                }
            }
        }
    }

    cout << "Solution:" << endl;
    for (i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << a[i][n + 1] << endl;
    }

    return 0;
}
