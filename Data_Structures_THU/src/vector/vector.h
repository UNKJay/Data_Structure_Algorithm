#ifndef _VECTOR_H
#define _VECTOR_H

#define DEFAULT_CAPACITY 3
typedef int Rank;   //寻秩访问


template <class T> 
class Vector {
protected:
    Rank _size;
    int _capacity;
    T* _elem;

public:

    Vector(int c=DEFAULT_CAPACITY , int s = 0 , T v = 0){
        _elem = new T[_capacity=c];
        for(_size=0;_size<s;_elem[_size++]=v);
    }

    
};

#endif