#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;


long long MAxTab[MAX + 1][4][2];
long long ile;

int main() {

    cin >> ile;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            MAxTab[0][i][j] = 0;
        }
    }

    int elem;
    for (int i = 1; i <= ile; i++) {
        cin >> elem;
        for (int k = 0; k < 4; k++) {
            for (int m = 0; m < 2; m++) {
                long long max_;
                if (k == 0) {
                    max_ = max(MAxTab[i - 1][0][m], MAxTab[i - 1][1][m]);
                    max_ = max(max_, MAxTab[i - 1][2][m]);
                    if (m == 1)
                        max_ = max(max_, MAxTab[i - 1][3][m]);
                }
                if (k == 1 || k == 2) {
                    max_ = MAxTab[i - 1][k - 1][m] + elem;

                }
                if (k == 3) {
                    m = 1;
                    max_ = MAxTab[i - 1][2][0] + elem;
                }
                MAxTab[i][k][m] = max_;
            }
        }
    }

    long long max_val = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            max_val = max(max_val, MAxTab[ile][i][j]);
        }
    }

    cout << max_val << endl;

    return 0;
}