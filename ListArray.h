#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray;

template <typename T>
std::ostream& operator<<(std::ostream &out, ListArray<T> &list);

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE;
    public:
        // miembros públicos, incluidos los heredados de List<T>
	ListArray();
	~ListArray() override;
	T operator[](int pos);
    	
	friend std::ostream& operator<< <T>(std::ostream &out, ListArray<T> &list);

};

	template <typename T>
	std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
    return out;
}

#endif
