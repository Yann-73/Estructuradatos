#include <iostream>

using namespace std;

class Animal {
  protected:
    string nombre;

  public:
    Animal(string _nombre) : nombre(_nombre) {}

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
    Persona(string _nombre, string _ocupacion) : Animal(_nombre)
    {
        ocupacion = _ocupacion;
    }

    void hacerSonido() override
    {
        cout << "Hola, me llamo " << nombre << " y soy " << ocupacion << endl;
    }
};

int main()
{
    Perro perro("Luna");
    perro.hacerSonido(); // guau
    perro.comer();

    Gato gato("Michi");
    gato.hacerSonido(); // miau
    gato.comer();

    Persona persona("Juan", "Doctor");
    persona.hacerSonido(); // saludo
    persona.comer();

    return 0;
}
