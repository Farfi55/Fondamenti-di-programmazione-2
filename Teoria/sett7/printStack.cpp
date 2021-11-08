#include <stack>
#include <iostream>

using namespace std;


void printStack(stack<int>& s) {
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    printStack(s);
    cout << x << " ";
    s.push(x);
}


int main() {
    stack<int> s;
    s.push(15);
    s.push(3);
    s.push(72);
    s.push(8);

    printStack(s);

    cout << "seconda chiamata\n\n";
    printStack(s);

}
