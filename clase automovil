#include <iostream>

using namespace std;

class Motor {};

class Rueda {
  private:
    string marca;
    int diametro;

  public:
    Rueda(string _marca = "Generica", int _diametro = 15)
    {
        marca = _marca;
        diametro = _diametro;
    }

    void mostrarInfo()
    {
        cout << "Rueda marca: " << marca << ", diametro: " << diametro << endl;
    }

    // getters y setters
};

class Automovil {
  private:
    string marca;
    string modelo;
    Rueda ruedas[4];
    Motor motor;

  public:
    Automovil(string _marca, string _modelo, string _marcaRuedas, int _diametroRuedas)
    {
        marca = _marca;
        modelo = _modelo;

        for (int i = 0; i < 4; i++)
        {
            ruedas[i] = Rueda(_marcaRuedas, _diametroRuedas);
        }
    }

    void mostrarInfo()
    {
        cout << "Automovil marca: " << marca << ", modelo: " << modelo << endl;
        for (int i = 0; i < 4; i++)
        {
            ruedas[i].mostrarInfo();
        }
        cout << endl;
    }
};

int main()
{
    Automovil automovil("Toyota", "Corolla", "Michelin", 10);

    automovil.mostrarInfo();

    return 0;
}
