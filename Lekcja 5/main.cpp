#include <iostream>
#include <cassert>
#include "doublelist.hpp"

int main() {
    DoubleList<int> list;

    // Test podstawowych operacji
    assert(list.empty());
    assert(list.size() == 0);

    list.push_back(10);
    list.push_front(5);
    list.push_back(15);
    
    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list.back() == 15);

    // Test dostępu indeksowanego i wyszukiwania
    assert(list[1] == 10);
    assert(list.index(15) == 2);
    assert(list.index(99) == -1);

    // Test usuwania (pop)
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 10);

    list.pop_back();
    assert(list.size() == 1);
    assert(list.back() == 10);

    // Test metod insert oraz erase
    list.insert(0, 5); 
    list.insert(2, 15); 
    assert(list.size() == 3);
    assert(list[0] == 5 && list[1] == 10 && list[2] == 15);

    list.erase(1); 
    assert(list.size() == 2);
    assert(list[0] == 5 && list[1] == 15);

    // Test czyszczenia
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);

    std::cout << "Wszystkie testy DoubleList zakonczone sukcesem!\n";
    return 0;
}