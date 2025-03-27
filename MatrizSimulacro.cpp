// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using namespace std;

template <typename T, int ROWS, int COLS>
class Matrix {
  protected:
    T m[ROWS][COLS];

  public:
    Matrix()
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                m[i][j] = T();
            }
        }
    }

    T at(int row, int col) const
    {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            throw out_of_range("Índice fuera de rango");
        }
        return m[row][col];
    }

    void set(int row, int col, T value)
    {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            throw out_of_range("Índice fuera de rango");
        }
        m[row][col] = value;
    }

    int numRows() const
    {
        return ROWS;
    }
    int numCols() const
    {
        return COLS;
    }

    void print() const
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif // MATRIX_H

// ejMatrix.cpp

class Asiento {
  private:
    string nombre;
    bool reservado;

 public:
    string getNombre() {
        return nombre;
    }

    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    bool getReservado() {
        return reservado;
    }

    void setReservado(bool _reservado) {
        reservado = _reservado;
    }
};

class Reserva {
  private:
    Matrix<Asiento, 5, 5> asientos;

  public:
    void mostrarAsientos()
    {
        for (int i = 0; i < asientos.numRows(); i++)
        {
            for (int j = 0; j < asientos.numCols(); j++)
            {
                Asiento asiento = asientos.at(i, j);
                cout << "[" << asiento.getNombre() << "]" << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void reservarAsiento(int fila, int col, string nombre)
    {
        Asiento asiento = asientos.at(fila, col);
        if (!asiento.getReservado())
        {
            asiento.setReservado(true);
            asiento.setNombre(nombre);
            asientos.set(fila, col, asiento);
        }
    }

    void cancelarReserva(int fila, int col)
    {
        Asiento asiento = asientos.at(fila, col);
        if (asiento.getReservado())
        {
            asiento.setReservado(false);
            asiento.setNombre("");
            asientos.set(fila, col, asiento);
        }
    }

    int asientosDisponibles()
    {
        int cont = 0;
        for (int i = 0; i < asientos.numRows(); i++)
        {
            for (int j = 0; j < asientos.numCols(); j++)
            {
                Asiento asiento = asientos.at(i, j);
                if (!asiento.getReservado())
                {
                    cont++;
                }
            }
        }
        return cont;
    }

    int asientosReservados()
    {
        int cont = 0;
        for (int i = 0; i < asientos.numRows(); i++)
        {
            for (int j = 0; j < asientos.numCols(); j++)
            {
                Asiento asiento = asientos.at(i, j);
                if (asiento.getReservado())
                {
                    cont++;
                }
            }
        }
        return cont;
    }
};

int main()
{
    Reserva reserva;
    reserva.mostrarAsientos();

    reserva.reservarAsiento(1, 1, "Jose");
    reserva.mostrarAsientos();
    cout << "reservados: " << reserva.asientosReservados() << endl;
    cout << "disponibles: " << reserva.asientosDisponibles() << endl;
    cout << endl;

    reserva.cancelarReserva(1, 1);
    reserva.mostrarAsientos();
    cout << "reservados: " << reserva.asientosReservados() << endl;
    cout << "disponibles: " << reserva.asientosDisponibles() << endl;
    cout << endl;
}
