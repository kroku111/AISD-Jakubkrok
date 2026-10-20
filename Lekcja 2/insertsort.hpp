#ifndef INSERTSORT_HPP
#define INSERTSORT_HPP

#include <iterator> // std::iterator_traits, std::prev
#include <utility>  // std::move

// Wersja tablicowa: zakres domkniety [left, right]
template<typename T>
void insertsort(T *ptr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T key = std::move(ptr[i]);
        int j = i - 1;
        while (j >= left && key < ptr[j]) {
            ptr[j + 1] = std::move(ptr[j]);
            --j;
        }
        ptr[j + 1] = std::move(key);
    }
}

// Wersja z iteratorami: zakres polotwarty [first, last)
template<typename Iterator>
void insertsort(Iterator first, Iterator last) {
    if (first == last) return;

    for (Iterator i = first + 1; i != last; ++i) {
        typename std::iterator_traits<Iterator>::value_type key = std::move(*i);
        Iterator j = i;
        while (j != first && key < *std::prev(j)) {
            *j = std::move(*std::prev(j));
            --j;
        }
        *j = std::move(key);
    }
}

#endif // INSERTSORT_HPP