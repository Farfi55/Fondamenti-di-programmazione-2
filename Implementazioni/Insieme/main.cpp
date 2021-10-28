#include <iostream>

#include "Insieme.h"
using namespace std;

int main() {
    insieme<int> set;

    if (set.empty()) cout << "vuoto" << endl;

    cout << set;
    set.add(1);
    set.add(2);
    set.add(2);
    set.add(3);
    cout << set;

    if (set.remove(1)) cout << "rimosso 1\n";
    if (!set.remove(1)) cout << "1 non c'e' piu'\n";
    if (set.isIn(2)) cout << "trovato 2\n";

    insieme<int> set2;
    set2.add(3);
    set2.add(4);

    auto set3 = set.unionTo(set2);

    cout << "Union of " << set << "and " << set2 << "is " << set3 << endl;
	
	set3 = set.intersectTo(set2);
    cout << "Intersect of " << set << "and " << set2 << "is " << set3 << endl;

	set3 = set.differenceWith(set2);
    cout << "Difference of " << set << "with " << set2 << "is " << set3 << endl;

	// exclusive or
	set3 = set.simmetricDifferenceWith(set2);
    cout << "Simmetric difference of " << set << "and " << set2 << "is " << set3 << endl;


}
