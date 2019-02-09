#include <iostream>
#include <vector>

#define MAX 500001

using namespace std;


int p[MAX];
int l[MAX];
int r[MAX];


int find(int x) {
    int y = x;
    while (p[y] != y)
        y = p[y];
    while(p[x] != y) {
        int z = p[x];
        p[x] = y;
        x = z;
    }
    return y;
}

void unionAB(int a, int b) {
    p[b] = a;
    r[a] = r[b];
    if(a != 0)
        l[r[b]] = a;
    else
        l[r[b]] = -1;
}

int main() {

    int ile;
    cin >> ile;

    for(int i=0; i<=ile; i++) {
        p[i] = i;
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[ile] = -1;
    l[1] = -1;

    int query, toJoin;
    for(int i=0; i<ile; i++) {
        cin >> query;
        toJoin = find(query - 1);
        cout << l[query] << " " << r[query] << endl;
        unionAB(toJoin, query);
    }
    int x = 0;


    return 0;
}