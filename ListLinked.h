
#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked;

template <typename T>
std::ostream& operator<<(std::ostream& out, ListLinked<T>& list);

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked();
    ~ListLinked() override;

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
        std::ostream& out, ListLinked<T>& list
    );
};

// Constructor
template <typename T>
ListLinked<T>::ListLinked() : first(nullptr), n(0) {}

// Destructor
template <typename T>
ListLinked<T>::~ListLinked() {
    Node<T>* aux;

    while (first != nullptr) {
        aux = first->next;
        delete first;
        first = aux;
    }
}

// Insertar en una posición
template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Posicion no valida");
    }

    if (pos == 0) {
        first = new Node<T>(e, first);
    } else {
        Node<T>* aux = first;

        for (int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }

        aux->next = new Node<T>(e, aux->next);
    }

    n++;
}

// Añadir al final
template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e);
}

// Añadir al principio
template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}

// Eliminar y devolver el elemento de una posición
template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posicion no valida");
    }

    Node<T>* eliminado;
    T dato;

    if (pos == 0) {
        eliminado = first;
        first = first->next;
    } else {
        Node<T>* aux = first;

        for (int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }

        eliminado = aux->next;
        aux->next = eliminado->next;
    }

    dato = eliminado->data;
    delete eliminado;
    n--;

    return dato;
}

// Obtener el elemento de una posición
template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posicion no valida");
    }

    Node<T>* aux = first;

    for (int i = 0; i < pos; i++) {
        aux = aux->next;
    }

    return aux->data;
}

// Buscar un elemento
template <typename T>
int ListLinked<T>::search(T e) {
    Node<T>* aux = first;
    int pos = 0;

    while (aux != nullptr) {
        if (aux->data == e) {
            return pos;
        }

        aux = aux->next;
        pos++;
    }

    return -1;
}

// Comprobar si está vacía
template <typename T>
bool ListLinked<T>::empty() {
    return n == 0;
}

// Devolver el número de elementos
template <typename T>
int ListLinked<T>::size() {
    return n;
}

// Operador []
template <typename T>
T ListLinked<T>::operator[](int pos) {
    return get(pos);
}

// Operador <<
template <typename T>
std::ostream& operator<<(std::ostream& out, ListLinked<T>& list) {
    out << "[";

    Node<T>* aux = list.first;

    while (aux != nullptr) {
        if (aux != list.first) {
            out << ", ";
        }

        out << aux->data;
        aux = aux->next;
    }

    out << "]";
    return out;
}

#endif

