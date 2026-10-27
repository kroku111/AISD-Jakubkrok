#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
class ArrayList {
private:
    T* tab;
    int m_size;
    int m_capacity;
    static const int MIN_CAPACITY = 4;

    void resize(int new_capacity) {
        T* new_tab = new T[new_capacity];
        std::copy(tab, tab + m_size, new_tab);
        delete[] tab;
        tab = new_tab;
        m_capacity = new_capacity;
    }

    void check_expand() {
        if (m_size == m_capacity) {
            resize(m_capacity * 2);
        }
    }

    void check_shrink() {
        if (m_size <= m_capacity / 4 && (m_capacity / 2) >= MIN_CAPACITY) {
            resize(m_capacity / 2);
        }
    }

public:
    ArrayList() : m_size(0), m_capacity(MIN_CAPACITY) {
        tab = new T[m_capacity];
    }

    ~ArrayList() {
        delete[] tab;
    }

    ArrayList(const ArrayList& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
        tab = new T[m_capacity];
        std::copy(other.tab, other.tab + m_size, tab);
    }

    ArrayList& operator=(const ArrayList& other) {
        if (this != &other) {
            delete[] tab;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            tab = new T[m_capacity];
            std::copy(other.tab, other.tab + m_size, tab);
        }
        return *this;
    }

    bool empty() const {
        return m_size == 0;
    }

    int size() const {
        return m_size;
    }

    int max_size() const {
        return m_capacity;
    }

    void push_front(const T& item) {
        check_expand();
        std::copy_backward(tab, tab + m_size, tab + m_size + 1);
        tab[0] = item;
        ++m_size;
    }

    void push_back(const T& item) {
        check_expand();
        tab[m_size] = item;
        ++m_size;
    }

    T& front() {
        if (empty()) throw std::out_of_range("Lista jest pusta");
        return tab[0];
    }

    T& back() {
        if (empty()) throw std::out_of_range("Lista jest pusta");
        return tab[m_size - 1];
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("Lista jest pusta");
        std::copy(tab + 1, tab + m_size, tab);
        --m_size;
        check_shrink();
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("Lista jest pusta");
        --m_size;
        check_shrink();
    }

    void clear() {
        m_size = 0;
        if (m_capacity > MIN_CAPACITY) {
            resize(MIN_CAPACITY);
        }
    }

    T& operator[](int pos) {
        return tab[pos];
    }

    void insert(int pos, const T& item) {
        if (pos < 0 || pos > m_size) throw std::out_of_range("Nieprawidlowy indeks");
        check_expand();
        std::copy_backward(tab + pos, tab + m_size, tab + m_size + 1);
        tab[pos] = item;
        ++m_size;
    }

    void erase(int pos) {
        if (pos < 0 || pos >= m_size) throw std::out_of_range("Nieprawidlowy indeks");
        std::copy(tab + pos + 1, tab + m_size, tab + pos);
        --m_size;
        check_shrink();
    }

    void sort() {
        std::sort(tab, tab + m_size);
    }

    void merge(ArrayList& other) {
        if (this == &other) return;
        
        int new_capacity = m_size + other.m_size;
        if (new_capacity < MIN_CAPACITY) {
            new_capacity = MIN_CAPACITY;
        }
        
        T* new_tab = new T[new_capacity];
        std::merge(tab, tab + m_size, other.tab, other.tab + other.m_size, new_tab);
        
        delete[] tab;
        tab = new_tab;
        m_size += other.m_size;
        m_capacity = new_capacity;
        
        other.clear();
    }
};

#endif