#include "tvector.h"

using namespace std;

template <typename T>
tvector<T> ::tvector() :data(nullptr),used(0),cap(1){
    data=new T[cap];
}

template <typename T>
tvector<T> ::tvector(const tvector<T> &other) :used(other.used),cap(other.cap){
    data=new T[other.cap];
    for(int i=0;i<other.cap;i++) {
        data[i]=other[i];
    }
}

template <typename T>
const tvector<T>& tvector<T> ::operator=(const tvector<T> &other) {
    if(this==&other) {

    }
    else {
        used=other.used;
        cap=other.cap;
        data=nullptr;
        data=new T[other.cap];
        for(int i=0;i<other.cap;i++) {
            data[i]=other[i];
        }
        
    }
    return *this;
}

template <typename T>
tvector<T> ::~tvector() {
    delete[] data;
}

template <typename T>
int tvector<T> ::size() const{
    return used;
}

template <typename T>
int tvector<T> ::capacity() const{
    return cap;
}

template <typename T>
void tvector<T> ::push_back(const T& value) {
    if(used>=cap) {
        reallocate();
    }
    data[used++]=value;
}

template <typename T>
void tvector<T> ::reallocate() {
    int i;
    T*temp=nullptr;
    temp=new T[cap*2];
    for(i=0;i<cap;i++) {
        temp[i]=data[i];
    }
    delete[] data;
    data=new T[cap*2];
    for(int i=0;i<cap;i++) {
        data[i]=temp[i];
    }
    cap*=2;
    delete[] temp;
}

template <typename T>
T tvector<T> ::at(const int& index) const {
    if(index<0 || index>=cap) {
        throw "Index out of bounds";
    }
    return data[index];
}

template <typename T>
bool tvector<T> ::empty() const{
    return used==0;
}

template <typename T>
T tvector<T> ::operator[](const int &index) const {
    if(index<0 || index>=cap) {
        throw "Index out of bounds";
    }
    return data[index];
}

template <typename T>
T tvector<T> ::front() const {
    if(empty()) {
        throw "Empty vector";
    }
    return data[0];
}
template <typename T>
T tvector<T> ::back() const {
    if(empty()) {
        throw "Empty vector";
    }
    return data[used-1];
}

template <typename T>
void tvector<T> ::pop_back() {
    if(empty()) {
        throw "Empty vector";
    }
    used-=1;
}