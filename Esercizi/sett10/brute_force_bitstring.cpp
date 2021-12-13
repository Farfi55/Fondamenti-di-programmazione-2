#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

typedef vector<bool> vectorBool;
list<vectorBool> genera(int n);
void genera_ric(int n, vector<bool>& v, list<vectorBool>& l);

vectorBool gen_first(int n);
void gen_next(vectorBool& prev);



class Gen {
private:
    const int n;
    vectorBool current;
    int iter;

public:
    Gen(int _n) : n(_n), current(n, false), iter(0) {}

    vectorBool& next() {
        if(iter++ == 0) return current;

        bool carry = true;
        for(int i = n - 1; carry && i >= 0; --i) {
            if(!current[i]) carry = false;
            current[i] = !current[i];
        }
        return current;
    }

    vectorBool getCurrent() const { return current; }
    void setCurrent(const vectorBool& _current) { current = _current; }

    int getIteration() const { return iter; }
};


int main(int argc, char const* argv[])
{
    int n;
    cin >> n;


    Gen gen(n);
    while(cin.ignore())
        for(bool digit : gen.next())
            cout << digit;



    // vectorBool vbool = gen_first(n);
    // do {
    //     gen_next(vbool);
    //     for(int i = 0; i < vbool.size(); ++i) {
    //         cout << vbool[i];
    //     }
    // } while(cin.get());


    // auto l = genera(n);
    // int x = 0;
    // for(vectorBool combinazione : l) {
    //     cout << x++ << '\t';

    //     // print in reverse
    //     for(int i = combinazione.size() - 1; i >= 0; --i) {
    //     // for(int i = 0; i < combinazione.size(); ++i) {
    //         cout << combinazione[i];
    //     }
    //     cout << '\n';
    // }

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
        v[n - 1] = false;
        genera_ric(n - 1, v, l);
        v[n - 1] = true;
        genera_ric(n - 1, v, l);
    }

}

// USANDO UN GENERATORE

vectorBool gen_first(int n) {
    return vectorBool(n, false);
}


// non ha nessun controllo

// genera il prossimo 
void gen_next(vectorBool& prev) {
    bool carry = true;
    for(int i = prev.size() - 1; carry && i >= 0; --i) {
        if(!prev[i]) carry = false;
        prev[i] = !prev[i];
    }
    return;
}

// o in meno righe
/*
void gen_next(vectorBool& prev) {
    for(int i = prev.size() - 1; i >= 0; --i) {
        prev[i] = !prev[i];
        if(prev[i]) return;
    }
    return;
}
*/


// USANDO UNA CLASSE GENERATRICE



