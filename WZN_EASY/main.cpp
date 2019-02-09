#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    cout<< sizeof(int) << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ile, edges;
    cin >> ile;

    vector<multiset<int>> edgesFromVertice;

    for(int i=0; i <= ile; i++) {
        edgesFromVertice.emplace_back(multiset<int>());
    }

    cin >> edges;

    int from, to, val;
    for(int i=0; i<edges; i++) {
        cin >> from >> to >> val;
        edgesFromVertice.at(from).insert(val);
        edgesFromVertice.at(to).insert(val);
    }

    long long counter = 0;

    for(int i=1; i <= ile; i++) {
        auto sizeOfI = edgesFromVertice.at(i).size();

        long long last = -1;
        long long elementsOfVal = 0;
        long long before = 0;
        for(auto value: edgesFromVertice.at(i)) {
            if(value != last) {
                last = value;
                counter += elementsOfVal*(sizeOfI - elementsOfVal - before);
                before += elementsOfVal;
                elementsOfVal = 1;
            } else {
                elementsOfVal++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}
