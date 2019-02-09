#include <iostream>
#include <vector>
#include <set>
#include <sys/param.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ile, x1, x2;
    cin >> ile;

    set<pair<int, int>> elements;
    int min_ = INT_MAX;

    for(int i=0; i<ile; i++) {
        cin >> x1 >> x2;
        auto insertion = elements.insert(make_pair(x1, x2));
        auto it = insertion.first;

        int diff1 = INT_MAX;
        if(it != elements.begin()) {
            diff1 = max(0, x1 - prev(it)->second);
        }

        int diff2 = INT_MAX;
        if(next(it) != elements.end()) {
            diff2 = max(0, next(it)->first - x2);
        }
        int diff = min(diff1, diff2);

        if(diff == 0){
            cout << 0 << endl;
            return 0;
        }
        min_ = min(min_, diff);
    }

    cout << min_ << endl;

    return 0;
}