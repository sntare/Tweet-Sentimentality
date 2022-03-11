//
// Created by Steve Ntare on 6/11/2021.
//

#ifndef INC_21SU_PA02_TEMPLATE_DSVECTOR_H
#define INC_21SU_PA02_TEMPLATE_DSVECTOR_H
#include <iostream>
#include <functional>
using namespace std;

template <class T>

class DSVector {
private:
    T* ranVec;
    int nextUp;
    int capacity;
    int size;
public:
    DSVector(int initial_capacity = 10);
    DSVector(const DSVector<T>&);
    ~DSVector();

    int getNextUp() const;
    int getSize() const;
    void setNextUp(int);
    void setSize(int);

    DSVector& operator= (const DSVector&);
    T& operator[](const int);
    T& operator[](const int) const;
    void insert(const int, const T&);
    void pop_back();
    void grow(int);
    int find(T);
    bool isFound(T);
    //sorts a vector alphabetically
//    void sort();
    //adds values to vector
    void push_back(const T&);
    void push_front(const T&);
    void clear();
    int partition(const DSVector<T>&, int, int );
    void swap(T*, T*);
    void quickSort(const DSVector<T>&, int, int);

};

template<class T>
DSVector<T>::DSVector(int initial_capacity) {
    ranVec = new T[initial_capacity];
    nextUp = 0;
    capacity = initial_capacity;
    size = 0;

}

template<class T>
DSVector<T>::DSVector(const DSVector<T>& vec) {
    ranVec = new T[vec.getSize()];
    nextUp = vec.getNextUp();
    size = vec.getSize();
    capacity = vec.capacity;

    for(int i = 0; i < vec.getSize(); i++){
        ranVec[i] = vec.ranVec[i];
    }
}
template<class T>
DSVector<T>::~DSVector() {
    delete [] ranVec;
}

template<class T>
int DSVector<T>::getNextUp() const {
    return nextUp;
}

template<class T>
int DSVector<T>::getSize() const {
    return size;
}

template<class T>
void DSVector<T>::setNextUp(int v) {
    nextUp = v;
}

template<class T>
void DSVector<T>::setSize(int v) {
    size = v;
}

template<class T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& vec) {
    if (this == &vec)
        return *this;

    delete[] ranVec;
    size = vec.getSize();
    nextUp = vec.getNextUp();
    capacity = vec.capacity;
    ranVec = new T [capacity];


    for (int i = 0; i < vec.getSize(); i++)
        ranVec[i] = vec[i];

    return *this;

}

template<class T>
T& DSVector<T>::operator[](const int led) {
    return ranVec[led];
}

template<class T>
T &DSVector<T>::operator[](const int led) const {
    return ranVec[led];
}

template<class T>
void DSVector<T>::insert(const int location, const T& thing) {
    if (capacity == location){
        push_back(thing);
    }else{
        if(size == capacity){
            grow(size*=2);
        }
        for (int i = size; i >= location + 1; i--) {
            ranVec[i] = ranVec[i - 1];
        }
        ranVec[location] = thing;
        size++;
    }
}

template<class T>
void DSVector<T>::pop_back() {
    if(size == 0){
        cout << "Nothing in array!" << endl;

    }
    size--;
}

template<class T>
void DSVector<T>::grow(int newCapacity) {
    T* temp = new T[newCapacity];

    for (int i = 0; i<size; i++)
        temp[i] = ranVec[i];

    delete [] ranVec;
    ranVec = temp;
    capacity = newCapacity;
    ranVec = temp;
}

template<class T>
int DSVector<T>::find(T thing) {
    for (int i = 0; i<capacity; i++){
        if (thing == ranVec[i]){
            return i;
        }
    }
    return -1;
}

template<class T>
bool DSVector<T>::isFound(T thing) {
    for (int i = 0; i<size; i++){
        if(ranVec[i] == thing){
            return true;
        }
    }
    return false;
}

//template<class T>
//void DSVector<T>::sort() {
//    int j;
//    T value_key;
//    for (int i = 1; i < size; i++)
//    {
//        value_key = ranVec[i];
//        j = i - 1;
//
//        /* Move elements of arr[0..i-1], that are
//        greater than key, to one position ahead
//        of their current position */
//        while (j >= 0 && ranVec[j] > value_key)
//        {
//            ranVec[j + 1] = ranVec[j];
//
//            j = j - 1;
//        }
//        ranVec[j + 1] = value_key;
//
//
//    }
//
//}

template<class T>
void DSVector<T>::push_back(const T&  thing) {
    if(size == capacity){
        grow(capacity*2);
    }
    ranVec[size] = thing;
    size++;
}

template<class T>
void DSVector<T>::push_front(const T& thing) {
    if(size == capacity){
        grow(capacity+= 15);
    }
    for(int i = size; i > 0; i--){
        ranVec[i] = ranVec[i-1];
    }
    ranVec[0] = thing;
    size++;
}

template<class T>
void DSVector<T>::clear() {
    delete [] ranVec;
    size = 0;
    capacity = 10;
    ranVec = new T[10];
}
template <class T>
void DSVector<T>::swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}
template <class T>
int DSVector<T>::partition(const DSVector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
template <class T>
void DSVector<T>::quickSort(const DSVector<T>& arr, int low, int high) {
    if(low<high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}





#endif //INC_21SU_PA02_TEMPLATE_DSVECTOR_H