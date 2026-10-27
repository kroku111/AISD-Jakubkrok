#include <iostream>
#include <cassert>
#include "arraylist.hpp"

void test_basic_operations() {
    ArrayList<int> list;
    assert(list.empty());
    assert(list.size() == 0);
    assert(list.max_size() == 4);

    list.push_back(10);
    list.push_front(20);
    assert(list.size() == 2);
    assert(list.front() == 20);
    assert(list.back() == 10);
}

void test_dynamic_resizing() {
    ArrayList<int> list;
    
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    assert(list.size() == 5);
    assert(list.max_size() == 8); 

    for (int i = 0; i < 4; ++i) {
        list.push_back(i);
    }
    assert(list.size() == 9);
    assert(list.max_size() == 16); 

    for (int i = 0; i < 7; ++i) {
        list.pop_back();
    }
    
    assert(list.size() == 2);
    assert(list.max_size() == 4);
}

void test_insert_erase_clear() {
    ArrayList<int> list;
    list.push_back(1);
    list.push_back(3);
    
    list.insert(1, 2); 
    assert(list[1] == 2);
    assert(list.size() == 3);
    
    list.erase(0);
    assert(list.front() == 2);
    assert(list.size() == 2);
    
    list.clear();
    assert(list.empty());
    assert(list.max_size() == 4);
}

void test_sort_and_merge() {
    ArrayList<int> list1;
    list1.push_back(5);
    list1.push_back(1);
    list1.push_back(3);
    list1.sort();
    assert(list1[0] == 1 && list1[1] == 3 && list1[2] == 5);

    ArrayList<int> list2;
    list2.push_back(4);
    list2.push_back(2);
    list2.push_back(6);
    list2.sort();

    list1.merge(list2);
    
    assert(list1.size() == 6);
    assert(list2.empty());
    
    for (int i = 0; i < 6; ++i) {
        assert(list1[i] == i + 1);
    }
}

int main() {
    test_basic_operations();
    test_dynamic_resizing();
    test_insert_erase_clear();
    test_sort_and_merge();

    std::cout << "Wszystkie testy ArrayList zakonczone powodzeniem!" << std::endl;
    return 0;
}