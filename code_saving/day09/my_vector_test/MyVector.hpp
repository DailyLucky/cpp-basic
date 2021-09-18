#pragma once

#include <iostream>

using namespace std;

template <class T>
class MyVector;

template <class T>
ostream& operator<<(ostream &out, const MyVector<T> &v);

template <class T>
class MyVector {
public:
    MyVector();
    MyVector(int _len);
    MyVector(const MyVector &v);
    ~MyVector();

    int length();

    T& operator[](int index);
    MyVector& operator=(const MyVector &v);
    friend ostream& operator<<<T>(ostream &out, const MyVector &v);
private:
    int len;
    T *space;
};


template <class T>
MyVector<T>::MyVector() {
    len = 0;
    space = NULL;
}

template <class T>
MyVector<T>::MyVector(int _len) {
    if (_len > 0) {
        len = _len;
        space = new T[len];
    } else {
        len = 0;
        space = NULL;    
    }
}

template <class T>
MyVector<T>::MyVector(const MyVector &v) {
    if (v.space != NULL) {
        len = v.len;
        space = new T[len];
        for (int i=0; i<len; i++) {
            space[i] = v.space[i];
        }
    } else {
        len = 0;
        space = NULL;
    }
}

template <class T>
MyVector<T>::~MyVector() {
    if (space != NULL) {
        delete []space;
        space = NULL;
        len = 0;
    }
}

template <class T>
int MyVector<T>::length() {
    return len;
}

template <class T>
T& MyVector<T>::operator[](int index) {
    return space[index];
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &v) {
    // 1. 先清理掉原来的内存空间
    if (space != NULL) {
        delete []space;
    }
    // 2. 根据传入的对象，重新分配空间，再进行数据的拷贝
    if (v.space != NULL) {
        len = v.len;
        space = new T[len];
        for (int i=0; i<len; i++) {
            space[i] = v.space[i];
        }
    } else {
        len = 0;
        space = NULL;
    }
    return *this;
}

template <class T>
ostream& operator<<(ostream &out, const MyVector<T> &v) {
    for (int i=0; i<v.len; i++) {
        out << v.space[i] << "  ";
    }
    out << endl;
    return out;
}