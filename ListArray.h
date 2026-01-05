
#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

#include "List.h"
#include <stdexcept>
#include <ostream>

template <typename U>
class ListArray;

template <typename U>
std::ostream& operator<<(std::ostream& out, const ListArray<U>& list);

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* na = new T[new_size];
        for (int i = 0; i < n; ++i) na[i] = arr[i];
        delete[] arr;
        arr = na;
        max = new_size;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}
    ~ListArray() override { delete[] arr; }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida!");
        return arr[pos];
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición inválida!");
        if (n == max) resize(max * 2);
        for (int i = n; i > pos; --i) arr[i] = arr[i - 1];
        arr[pos] = e;
        ++n;
    }

    void append(T e) override { insert(n, e); }
    void prepend(T e) override { insert(0, e); }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida!");
        T r = arr[pos];
        for (int i = pos + 1; i < n; ++i) arr[i - 1] = arr[i];
        --n;
        return r;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida!");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; ++i) if (arr[i] == e) return i;
        return -1;
    }

    bool empty() override { return n == 0; }
    int size() override { return n; }

    friend std::ostream& operator<< <T>(std::ostream& out, const ListArray<T>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
    out << "List => [\n";
    for (int i = 0; i < list.n; ++i) out << "  " << list.arr[i] << "\n";
    out << "]\n";
    return out;
}

#endif
