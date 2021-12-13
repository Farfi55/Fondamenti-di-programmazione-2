#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


int main(int argc, char const* argv[])
{
    int n;
    cin >> n;




    return 0;
}

/*
void generate(vector<int>& values, int max_depth)return generate(values, max_depth, 0);

void generate(vector<int>&values, int max_depth, int depth) {
    if(depth == max_depth) return;
    else if(depth == 0) {
        values.pop_back(0);
        values.pop_back(1);
    }

    for(int i = 0; i < values.size(); i++) {
        values[i] *= 10;
        values.pop_back(values[i] * 10 + 1);

    }
    generate(values, max_depth, depth++);

}
*/

// 13-12-2021 10:05
// implementazione prof
typedef vector<bool> vectorBool;
list<vectorBool> genera(int n) {
    vector<bool> b(n, false);
    list<vectorBool> l;
    genera_ric(n, b, l);
    return l;
}

void genera_ric(int n, vector<bool>& v, list<vectorBool>& l) {

    // caso base
    if(n == 0) {
        l.push_back(v);
    }
    else {
        v[n - 1] = 0;
        genera_ric(n - 1, v, l);
        v[n - 1] = 1;
        genera_ric(n - 1, v, l);
    }

}


