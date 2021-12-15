#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Combinazione {
    vector<bool> v;

public:
    Combinazione(int n) : v(n, false) {}

    vector<bool> first() {
        v.assign(v.size(), false);

    }

    bool last() {
        return (find(v.begin(), v.end(), true) == v.end());
    }


    vector<bool> next() {
        // implementazione prof
        if(v[0] == false) v[0] = true;
        else {
            v[0] = false;
            int i;
            for(i = 1; i < v.size() && v[i]; i++) {
                v[i] = false;
            }
            if(i < v.size()) v[i] = true;

        }

        // implementazione personale
        // bool carry = true;
        // for(int i = n - 1; carry && i >= 0; --i) {
        //     if(!v[i]) carry = false;
        //     v[i] = !v[i];
        // }
        // return v;
    }

};



int main(int argc, char const* argv[])
{
    Combinazione c(5);

    c.first();
    while(!c.last()) {
        c.next();

    }

    return 0;
}
