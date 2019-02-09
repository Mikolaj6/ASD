#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ile, diff, count = 0, elem, typ;
    cin >> ile >> diff;

    set<int> elements;

    for(int i=0; i<ile; i++) {
        cin >> typ >> elem;

        if(typ == 1) {
            elements.insert(elem);

            if (elements.find(elem - diff) != elements.end())
                count++;
            if (elements.find(elem + diff) != elements.end())
                count++;
            cout << (count ? "TAK" : "NIE") << endl;
        }

        if(typ == -1) {
            elements.erase(elem);

            if (elements.find(elem - diff) != elements.end())
                count--;
            if (elements.find(elem + diff) != elements.end())
                count--;
            cout << (count ? "TAK" : "NIE") << endl;
        }
    }

    return 0;
}