#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm> // std::is_sorted
#include <cassert>   // assert

#include "insertsort.hpp"
#include "mergesort.hpp"

void test_insertsort() {
    int arr[] = { 9, 4, 7, 3, 6, 8, 2, 1, 5, 0 };
    int n = sizeof(arr) / sizeof(*arr);
    insertsort(arr, 0, n - 1);
    assert(std::is_sorted(arr, arr + n));

    std::vector<int> vec = { 9, 4, 7, 3, 6, 8, 2, 1, 5, 0 };
    insertsort(vec.begin(), vec.end());
    assert(std::is_sorted(vec.begin(), vec.end()));

    std::array<double, 5> arr_d = { 3.14, 1.41, 2.71, -1.0, 0.0 };
    insertsort(arr_d.begin(), arr_d.end());
    assert(std::is_sorted(arr_d.begin(), arr_d.end()));

    std::vector<std::string> words = { "z", "a", "m", "b", "k" };
    insertsort(words.begin(), words.end());
    assert(std::is_sorted(words.begin(), words.end()));

    std::vector<int> empty_vec;
    insertsort(empty_vec.begin(), empty_vec.end());
    assert(std::is_sorted(empty_vec.begin(), empty_vec.end()));
}

void test_mergesort() {
    int arr[] = { 9, 4, 7, 3, 6, 8, 2, 1, 5, 0 };
    int n = sizeof(arr) / sizeof(*arr);
    mergesort(arr, 0, n - 1);
    assert(std::is_sorted(arr, arr + n));

    std::vector<int> vec = { 9, 4, 7, 3, 6, 8, 2, 1, 5, 0 };
    mergesort(vec.begin(), vec.end());
    assert(std::is_sorted(vec.begin(), vec.end()));

    std::array<double, 5> arr_d = { 3.14, 1.41, 2.71, -1.0, 0.0 };
    mergesort(arr_d.begin(), arr_d.end());
    assert(std::is_sorted(arr_d.begin(), arr_d.end()));

    std::vector<std::string> words = { "z", "a", "m", "b", "k" };
    mergesort(words.begin(), words.end());
    assert(std::is_sorted(words.begin(), words.end()));

    std::vector<int> empty_vec;
    mergesort(empty_vec.begin(), empty_vec.end());
    assert(std::is_sorted(empty_vec.begin(), empty_vec.end()));
}

int main() {
    test_insertsort();
    test_mergesort();

    std::cout << "Wszystkie testy (insertsort, mergesort) zakonczone powodzeniem!\n";
    return 0;
}