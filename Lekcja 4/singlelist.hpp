#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <utility> // std::swap

// Szablon dla pojedynczego wezla listy.
template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() = default;
};

// Szablon dla listy powiazanej pojedynczo.
template <typename T>
class SingleList {
    SingleNode<T> *head;
    SingleNode<T> *tail;
    
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    
    ~SingleList() {
        clear();
    }
    
    SingleList(const SingleList& other) : head(nullptr), tail(nullptr) {
        SingleNode<T>* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    
    SingleList(SingleList&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }
    
    SingleList& operator=(const SingleList& other) {
        if (this != &other) {
            clear();
            SingleNode<T>* current = other.head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }
    
    SingleList& operator=(SingleList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }
    
    bool empty() const {
        return head == nullptr;
    }
    
    bool full() const {
        return false; // lista dynamiczna
    }
    
    std::size_t size() const {
        std::size_t count = 0;
        SingleNode<T>* current = head;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }
    
    void push_front(const T& item) {
        SingleNode<T>* newNode = new SingleNode<T>(item, head);
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }
    
    void push_back(const T& item) {
        SingleNode<T>* newNode = new SingleNode<T>(item, nullptr);
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    T& front() {
        assert(!empty());
        return head->value;
    }
    
    const T& front() const {
        assert(!empty());
        return head->value;
    }
    
    T& back() {
        assert(!empty());
        return tail->value;
    }
    
    const T& back() const {
        assert(!empty());
        return tail->value;
    }
    
    void pop_front() {
        assert(!empty());
        SingleNode<T>* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    
    void pop_back() {
        assert(!empty());
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            SingleNode<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
    }
    
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
    
    void display() const {
        SingleNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // SINGLELIST_HPP