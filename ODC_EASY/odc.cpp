#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct odcinek {
    int x;
    int yLow;
    int yHigh;

    odcinek(int x, int y1, int y2) {
        this->x = x;
        yLow = y1;
        yHigh = y2;
    }

} odcinek;


int main() {
    ios_base::sync_with_stdio(false);

    vector<odcinek> lines;

    int ile, x, ylow, yhigh;
    cin >> ile;
    for (int i = 0; i < ile; i++) {
        cin >> x >> ylow >> yhigh;
        lines.emplace_back(odcinek(x, ylow, yhigh));
    }

    sort(lines.begin(), lines.end(), [](const odcinek &o1, const odcinek &o2) -> bool {
        if (o1.x < o2.x) {
            return true;
        } else if (o1.x > o2.x) {
            return false;
        } else {
            if (o1.yLow < o2.yLow) {
                return true;
            } else if (o1.yLow > o2.yLow) {
                return false;
            } else {
                if (o1.yHigh < o2.yHigh) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    });

    long long counter = 0;

    auto itLeft = lines.begin();
    auto itRight = lines.begin();

    while (itLeft != lines.end()) {
        if (itRight == lines.end() || itRight->x != itLeft->x) {
            while (itLeft != itRight) {
                auto it = upper_bound(itLeft, itRight, *itLeft, [](const odcinek &o1, const odcinek &o2) {
                    if (o1.yHigh < o2.yLow)
                        return true;
                    else
                        return false;
                });
                counter += distance(itLeft, it) - 1;
                ++itLeft;
            }
        } else {
            ++itRight;
        }
    }

    cout << counter << endl;

    return 0;
}