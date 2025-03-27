#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include "Vector.h"


using namespace std;

template <typename T> class Vector {
protected:
    T* items;
    int size;
    int capacity;

public:
    Vector(int _capacity = 10) : size(0), capacity(_capacity)
    {
        items = new T[capacity];
    }

    ~Vector()
    {
        delete[] items;
    }

    void pushBack(const T& value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        items[size++] = value;
    }

    T at(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    void set(int index, T value)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Índice fuera de rango");
        }
        items[index] = value;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void resize(int newCapacity)
    {
        if (newCapacity <= capacity)
            return;

        T* newItems = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << items[i] << " | ";
        }
        cout << endl;
    }
};

#endif // VECTOR_H

// ej.1
Vector<float> promedioVecinos(const Vector<int>& v)
{
    Vector<float> resultado;
    int n = v.getSize();
    for (int i = 0; i < n; i++) {
        float promedio = 0;
        if (i == 0) {
            promedio = (float)(v.at(i) + v.at(i + 1)) / 2.0;
        }
        else if (i == n - 1) {
            promedio = (float)(v.at(i - 1) + v.at(i)) / 2.0;
        }
        else {
            promedio = (float)(v.at(i - 1) + v.at(i) + v.at(i + 1)) / 3.0;
        }
        resultado.pushBack(promedio);
    }
    return resultado;
}


int main()
{
    Vector<int> input;
    input.pushBack(10);
    input.pushBack(20);
    input.pushBack(30);
    input.pushBack(40);
    input.pushBack(51);

    Vector<float> output = promedioVecinos(input);
    output.print();

    return 0;
    
}
