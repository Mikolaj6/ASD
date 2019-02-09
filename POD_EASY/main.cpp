#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long j,d,t, jd, ile, count, elem;

int main() {

    ios_base::sync_with_stdio(false);

    cin >> ile;
    for(int i=0; i<ile; i++) {
        cin >> elem;
        switch (elem) {
            case 1:
                j++;
                count++;
                break;
            case 2:
                d++;
                jd += j;
                count += 1 + j;
                break;
            default:
                t++;
                count += 1 + j + d + jd;
                break;
        }
    }
    cout << count << endl;


    return 0;
}