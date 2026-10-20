#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <algorithm> // std::inplace_merge
#include <iterator>  // std::distance, std::next

// Wersja tablicowa: zakres domkniety [left, right]
template<typename T>
void mergesort(T *ptr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergesort(ptr, left, mid);
    mergesort(ptr, mid + 1, right);
    std::inplace_merge(ptr + left, ptr + mid + 1, ptr + right + 1);
}

// Wersja z iteratorami: zakres polotwarty [first, last)
template<typename Iterator>
void mergesort(Iterator first, Iterator last) {
    auto dist = std::distance(first, last);
    if (dist <= 1) {
        return;
    }
    Iterator mid = std::next(first, dist / 2);
    mergesort(first, mid);
    mergesort(mid, last);
    std::inplace_merge(first, mid, last);
}

#endif // MERGESORT_HPP