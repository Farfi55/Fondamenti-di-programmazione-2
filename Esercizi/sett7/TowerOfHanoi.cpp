#include <iostream>
#include <string>
#include <stack>

using namespace std;

void print_stack(stack<int> s, char c);

void print_rods_in_order(stack<int> from, stack<int> to, stack<int> aux, char f, char t, char a);
void print_rods_in_order(stack<int> from, stack<int> to, stack<int> aux);


void towerOfHanoi(int n, stack<int>& from, stack<int>& to, stack<int>& aux,
    char f, char t, char a);

void towerOfHanoi(int n, stack<int>& from, stack<int>& to, stack<int>& aux,
    stack<int>& const_from, stack<int>& const_to, stack<int>& const_aux);



int main() {
    stack<int> from;
    stack<int> to;
    stack<int> aux;

    cout << "Inserisci numero dischi: ";
    int n;
    cin >> n;

    for(int i = n; i > 0; --i) {
        from.push(i);
    }

    print_stack(from, 'A');
    cout << "------------------------------" << endl;

    towerOfHanoi(n, from, to, aux, from, to, aux);

    return 0;
}


// implementazioni

/*
void print_rods_in_order(stack<int> from, stack<int> to, stack<int> aux,
    char f, char t, char a) {

    if(f == 'A') print_stack(from, 'F');
    else if(t == 'A') print_stack(to, 'T');
    else if(a == 'A') print_stack(aux, 'A');

    if(f == 'B') print_stack(from, 'F');
    else if(t == 'B') print_stack(to, 'T');
    else if(a == 'B') print_stack(aux, 'A');

    if(f == 'C') print_stack(from, 'F');
    else if(t == 'C') print_stack(to, 'T');
    else if(a == 'C') print_stack(aux, 'A');
}
*/

void print_stack(stack<int> s, char c) {
    if(!s.empty()) {
        cout << c << ":";
        do {
            int x = s.top();
            s.pop();
            cout << "\t" << x << " " << string(x, '_') << endl;
        } while(!s.empty());
    }
}

/*
void towerOfHanoi(int n, stack<int>& from, stack<int>& to, stack<int>& aux,
    char f, char t, char a) {
    if(n == 1) {
        to.push(from.top());
        from.pop();
        print_stack(from, f);
        print_stack(to, t);
        print_stack(aux, a);
        return;
    }

    // spostiamo n-1 dischi sullo stack aux, usando il to come aux
    towerOfHanoi(n - 1, from, aux, to, f, a, t);

    to.push(from.top());
    from.pop();

    // spostiamo sempre n-1 dischi dall'aux al to, usando il from come aux
    towerOfHanoi(n - 1, aux, to, from, a, t, f);

}
*/



void towerOfHanoi(int n, stack<int>& from, stack<int>& to, stack<int>& aux,
    stack<int>& const_from, stack<int>& const_to, stack<int>& const_aux) {
    if(n == 1) {
        to.push(from.top());
        from.pop();
        print_stack(const_from, 'A');
        print_stack(const_aux, 'B');
        print_stack(const_to, 'C');
        cout << "------------------------------" << endl;
        return;
    }

    // spostiamo n-1 dischi sullo stack aux, usando il to come aux
    towerOfHanoi(n - 1, from, aux, to, const_from, const_to, const_aux);

    to.push(from.top());
    from.pop();

    print_stack(const_from, 'A');
    print_stack(const_aux, 'B');
    print_stack(const_to, 'C');
    cout << "------------------------------" << endl;


    // spostiamo sempre n-1 dischi dall'aux al to, usando il from come aux
    towerOfHanoi(n - 1, aux, to, from, const_from, const_to, const_aux);
}
