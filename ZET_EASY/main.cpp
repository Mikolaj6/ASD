#include <iostream>
#include <set>
#include <vector>

#define MAX 1000001

using namespace std;

bool fncomp (long long lhs, long long rhs) {return lhs > rhs;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<long long, bool(*)(long long, long long)> elements(fncomp);
    long long howMany[MAX];
    for (int i = 0; i < MAX; i++)
        howMany[i] = 0;

    int ile, elem;
    cin >> ile;
    for (int i = 0; i < ile; i++) {
        cin >> elem;
        auto p = elements.insert(elem);
        howMany[elem]++;
    }

    long long queriesNum, query;
    cin >> queriesNum;

    long long element, count, toDo, val1, val2;

    for (int i = 0; i < queriesNum; i++) {
        cin >> query;

        while (query > 0) {
            element = *elements.begin();
            count = howMany[element];
            toDo = min(query, count);
            query -= toDo;

            howMany[element] -= toDo;
            if(howMany[element] == 0)
                elements.erase(elements.begin());

            val1 = element/2;
            val2 = element - val1;

            elements.insert(val1);
            elements.insert(val2);
            howMany[val1] += toDo;
            howMany[val2] += toDo;
        }
        cout << elements.size() << endl;
    }
    return 0;
}
