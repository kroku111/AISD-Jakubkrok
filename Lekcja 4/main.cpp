#include <iostream>
#include <cassert>
#include "singlelist.hpp"

void test_basic_operations() {
    SingleList<int> list;
    
    assert(list.empty());
    assert(list.size() == 0);
    
    list.push_back(10);
    assert(!list.empty());
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);
    
    list.push_front(5);
    assert(list.size() == 2);
    assert(list.front() == 5);
    assert(list.back() == 10);
    
    list.push_back(15);
    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list.back() == 15);
}

void test_popping() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 2);
    
    list.pop_back();
    assert(list.size() == 1);
    assert(list.back() == 2);
    
    list.pop_back();
    assert(list.empty());
    assert(list.size() == 0);
}

void test_copy_and_assignment() {
    SingleList<int> list1;
    list1.push_back(100);
    list1.push_back(200);
    
    SingleList<int> list2(list1);
    assert(list2.size() == 2);
    assert(list2.front() == 100);
    assert(list2.back() == 200);
    
    SingleList<int> list3;
    list3.push_back(999);
    list3 = list1;
    
    assert(list3.size() == 2);
    assert(list3.front() == 100);
    assert(list3.back() == 200);
    
    list1.pop_back();
    assert(list1.size() == 1);
    assert(list2.size() == 2); 
    assert(list3.size() == 2); 
}

void test_clear() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);
}

int main() {
    test_basic_operations();
    test_popping();
    test_copy_and_assignment();
    test_clear();
    
    std::cout << "Wszystkie testy SingleList zakonczone powodzeniem!\n";
    return 0;
}