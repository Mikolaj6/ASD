#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <assert.h>
#include <time.h>
#include <chrono>

using namespace std;

struct set_cmp {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
        if(p1.first < p2.first){
            return true;
        }else{
            return false;
        }
    }
};


int white_number = 0;
set<pair<int, int>, set_cmp> positions = set<pair<int, int>, set_cmp>();
int N;
int queries;

bool find_finishing(int val, pair<int, int> const& p){
    return val < p.first;
}


bool find_starting(int val, pair<int, int> const& p){
    return val <= p.second;
}


void change_set(pair<int, int> przed, bool to_white) {
    int left = przed.first;
    int right = przed.second;

    int new_left = left;
    int new_right = right;

    auto setval = positions;

    auto starting_it = upper_bound(positions.begin(), positions.end(), left, find_starting);
    auto ending_it = upper_bound(positions.begin(), positions.end(), right, find_finishing);

    bool ending = false;
    if(ending_it == positions.end())
        ending = true;

    if(starting_it == positions.end() || starting_it->first > right) {
        if(to_white) {
            positions.insert(przed);
            white_number += right - left + 1;
        }
        return;
    }

    int positions_removed = 0;

    auto curr_it = starting_it;
    while(curr_it != ending_it){
        if(curr_it->first < left)
            new_left = curr_it->first;
        if(curr_it->second > right)
            new_right = curr_it->second;

        positions_removed += curr_it->second - curr_it->first + 1;
        auto saved = curr_it;
        curr_it++;
        positions.erase(saved);
    }

    if(to_white){
        positions.insert(make_pair(new_left, new_right));
        white_number += new_right - new_left + 1 - positions_removed;
    } else {
        if(new_left != left){
            positions.insert(make_pair(new_left, left - 1));
            positions_removed -= (left - new_left);
        }
        if(new_right != right){
            positions.insert(make_pair(right + 1, new_right));
            positions_removed -= (new_right - right);
        }

        white_number -= positions_removed;
    }
    int x = 0;
}


set<int> test;
void change_set_test(pair<int, int> przed, bool to_white){

    if(to_white){
        for(int i=przed.first; i<=przed.second; i++){
            test.insert(i);
        }
    } else{
        for(int i=przed.first; i<=przed.second; i++){
            auto it = test.find(i);
            if(it != test.end())
                test.erase(it);
        }
    }
}

int main() {

    /*
    set<pair<int, int>> positions2 = set<pair<int, int>>({{7, 7}, {2, 4}, {10, 10}});
    auto starting_it = upper_bound(positions2.begin(), positions2.end(), 7, find_starting);
    auto curr_it = starting_it;

    while (curr_it != positions2.end()){
        cout<< curr_it->first;
        curr_it++;
    }
    */

    cin >> N >> queries;
    auto begin_t = chrono::high_resolution_clock::now();
    int int_begin, int_end;
    char type;
    vector<pair<pair<int, int>, char>> saved;
    int i = 0;

    for(; i<queries; i++){
        cin >> int_begin >> int_end >> type;

        if(type =='B') {
            saved.emplace_back(make_pair(make_pair(int_begin, int_end), 'B'));
            change_set(make_pair(int_begin, int_end), true);
            cout << white_number << endl;
            //change_set_test(make_pair(int_begin, int_end), true);
            //cout << test.size() << endl;
        } else {

            saved.emplace_back(make_pair(make_pair(int_begin, int_end), 'C'));
            change_set(make_pair(int_begin, int_end), false);
            cout << white_number << endl;
            //change_set_test(make_pair(int_begin, int_end), false);
            //cout << test.size() << endl;
        }

        if(std::chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - begin_t).count() > 300){
            i++;
            break;
        }
        /**/
    }
    if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - begin_t).count() > 299){
        for(auto elem: saved){
            if(elem.second =='B') {
                change_set_test(make_pair(elem.first.first, elem.first.second), true);
            } else {
                change_set_test(make_pair(elem.first.first, elem.first.second), false);
            }
        }
        for(; i<queries; i++){
            cin >> int_begin >> int_end >> type;

            if(type =='B') {
                change_set_test(make_pair(int_begin, int_end), true);
                cout << test.size() << endl;
            } else {
                change_set_test(make_pair(int_begin, int_end), false);
                cout << test.size() << endl;
            }
        }

    }


    return 0;
}
/*
13
4
7 7 B
2 4 B
10 10 B
7 13 C

 */