#include <iostream>
#include <random>

#include "OrderedList.h"

int main() {
    srand(time(0));

    OrderedList<int> ol;

    for (int i = 0; i < 20; i++) {
        int x = rand() % 100;
        ol.insert(x);
        std::cout << ol << std::endl;
    }
}
