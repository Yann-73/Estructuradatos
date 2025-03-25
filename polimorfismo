#include <iostream>
using namespace std;

class Animal {
  protected:
    string nombre;

  public:
    Animal(string _nombre = "Sin nombre") : nombre(_nombre) {}

    virtual ~Animal() {}

    void comer()
    {
        cout << nombre << " esta comiendo" << endl;
    }

    virtual void hacerSonido()
    {
        cout << nombre << " hace un sonido" << endl;
    }
};

class Perro : public Animal {
  public:
    Perro(string _nombre) : Animal(_nombre) {}

    void hacerSonido() override
    {
        cout << nombre << ": guau guau" << endl;
    }
};

class Gato : public Animal {
  public:
    Gato(string _nombre) : Animal(_nombre) {}

    void hacerSonido() override
    {
        cout << nombre << ": miau miau" << endl;
    }
};

class Persona : public Animal {
  private:
    string ocupacion;

  public:
    Persona(string _nombre, string _ocupacion) : Animal(_nombre), ocupacion(_ocupacion) {}

    void hacerSonido() override
    {
        cout << nombre << ": Buenas, me llamo " << nombre << " y soy " << ocupacion << endl;
    }
};

int main()
{
    // Polimorfismo: Misma instruccion, distinto comportamiento segun el objeto

    // Sin polimorfismo: Objetos en memoria estatica
    Perro perro("Luna");
    Gato gato("Michi");
    Persona persona("Juan", "Doctor");

    Animal animales[3];
    animales[0] = perro;
    animales[1] = gato;
    animales[2] = persona;
    for (int i = 0; i < 3; i++)
    {
        animales[i].hacerSonido(); // Animal hace un sonido
    }
    cout << endl;

    // Con polimorfismo:
    // Opcion 1: Punteros a objetos en memoria estatica (stack)
    Animal *animales1[3] = {&perro, &gato, &persona};
    for (int i = 0; i < 3; i++)
    {
        animales1[i]->hacerSonido(); // Polimorfismo: Cada Animal hace su propio sonido
    }
    cout << endl;

    // Opcion 2: Objetos en memoria dinamica (heap)
    Animal *animales2[3] = {new Perro("Nico"), new Gato("Max"), new Persona("Pedro", "Electrico")};
    for (int i = 0; i < 3; i++)
    {
        animales2[i]->hacerSonido();
    }
    cout << endl;
    // Liberacion de memoria de los objetos creados
    for (int i = 0; i < 3; i++)
    {
        delete animales2[i];
    }

    // Opcion 3: Arreglo dinamico de objetos en memoria dinamica
    Animal **animales3 = new Animal *[3];
    animales3[0] = new Perro("Roco");
    animales3[1] = new Gato("Simba");
    animales3[2] = new Persona("Victor", "Comerciante");
    for (int i = 0; i < 3; i++)
    {
        animales3[i]->hacerSonido();
    }
    cout << endl;
    // Liberacion de memoria de los objetos creados
    for (int i = 0; i < 3; i++)
    {
        delete animales3[i];
    }
    // Liberación de la memoria del arreglo dinamico
    delete[] animales3;

    return 0;
}
