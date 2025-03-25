#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Caja {
  private:
    T valor;

  public:
    // constructor
    Caja(T _valor)
    {
        valor = _valor;
    }

    // setter
    setValor(T _valor)
    {
        valor = _valor;
    }

    // getter
    T getValor()
    {
        return valor;
    }
};

int main()
{
    Caja<int> caja1(10);        // Caja con entero
    Caja<double> caja2(3.14);   // Caja con doble
    Caja<string> caja3("Hola"); // Caja con string

    cout << caja1.getValor() << endl; // 10
    cout << caja2.getValor() << endl; // 3.14
    cout << caja3.getValor() << endl; // Hola
    return 0;
}

//Otro ejemplo
/*#include <iostream>
using namespace std;

class Vector {
  private:
    int *items;
    int size;
    int capacity;

  public:
    Vector(int _capacity = 10)
    {
        size = 0;
        capacity = _capacity;
        items = new int[capacity];
    }

    ~Vector()
    {
        delete[] items;
    }

    void pushBack(int value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        items[size] = value;
        size++;
    }

    int at(int index)
    {
        if (index >= 0 && index < size)
        {
            return items[index];
        }
        return -1;
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    void resize(int newCapacity)
    {
        if (newCapacity <= capacity)
        {
            return;
        }

        int *newItems = new int[newCapacity];
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
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Vector v;
    Vector v(2);

    v.pushBack(10);
    v.pushBack(20);
    v.pushBack(30);
    v.pushBack(40);

    v.print();

    return 0;
}*/
