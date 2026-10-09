#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray;

template <typename T>
std::ostream& operator<<(std::ostream& out, ListArray<T>& list);

template <typename T>
class ListArray : public List<T> {

private:
    T* arr;
    int max;
    int n;

    static const int MINSIZE;

    void resize(int new_size);

public:
    ListArray();
    ~ListArray() override;

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;

    T operator[](int pos);

    friend std::ostream& operator<< <T>(
        std::ostream& out, ListArray<T>& list
    );
};


// Tamaño mínimo
template <typename T>
const int ListArray<T>::MINSIZE = 2;


// Constructor
template <typename T>
ListArray<T>::ListArray()
    : arr(new T[MINSIZE]), max(MINSIZE), n(0) {
}


// Destructor
template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}


// Redimensionar el array
template <typename T>
void ListArray<T>::resize(int new_size) {
    T* nuevo = new T[new_size];

    for (int i = 0; i < n; i++) {
        nuevo[i] = arr[i];
    }

    delete[] arr;
    arr = nuevo;
    max = new_size;
}


// Insertar en una posición
template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Posicion no valida");
    }

    if (n == max) {
        resize(max * 2);
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = e;
    n++;
}


// Añadir al final
template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}


// Añadir al principio
template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}


// Eliminar y devolver un elemento
template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posicion no valida");
    }

    T eliminado = arr[pos];

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    if (max > MINSIZE && n <= max / 4) {
        int nuevo_max = max / 2;

        if (nuevo_max < MINSIZE) {
            nuevo_max = MINSIZE;
        }

        resize(nuevo_max);
    }

    return eliminado;
}


// Obtener un elemento
template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posicion no valida");
    }

    return arr[pos];
}


// Buscar un elemento
template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i;
        }
    }

    return -1;
}


// Comprobar si esta vacia
template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}


// Obtener el numero de elementos
template <typename T>
int ListArray<T>::size() {
    return n;
}


// Operador []
template <typename T>
T ListArray<T>::operator[](int pos) {
    return get(pos);
}


// Operador de impresion <<
template <typename T>
std::ostream& operator<<(std::ostream& out, ListArray<T>& list) {
    out << "[";

    for (int i = 0; i < list.n; i++) {
        if (i > 0) {
            out << ", ";
        }

        out << list.arr[i];
    }

    out << "]";
    return out;
}

#endif
