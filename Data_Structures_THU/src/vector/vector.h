#ifndef _VECTOR_H
#define _VECTOR_H

#define DEFAULT_CAPACITY 3
typedef int Rank;   //寻秩访问


template <class T> 
class Vector {
private:
    Rank _size;
    int _capacity;
    T* _elem;

protected:

public:
    Vector(int c = DEFAULT_CAPACITY) {
        _elem = new T[_capacity = c];
        _size = 0;
    }

    Vector(int c=DEFAULT_CAPACITY , int s = 0 , T v = 0){
        _elem = new T[_capacity=c];
        for(_size=0;_size<s;_elem[_size++]=v);
    }

    Vector(Rank const * A, Rank lo, Rank hi) {
        
    }
    
};

#endif