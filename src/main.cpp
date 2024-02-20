#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;


class PERSONA{
    protected:
        string Identidad;
        int Telefono;
        string Nombre;
        string ApellidoA;
        string ApellidoB;

    public:
    // Constructor
    PERSONA(string Identidad, int Telefono, string Nombre, string ApellidoA, string ApellidoB){
        this->Identidad = Identidad;
        this->Telefono = Telefono;
        this->Nombre = Nombre;
        this->ApellidoA = ApellidoA;
        this->ApellidoB = ApellidoB;
    }

    //Metodos Set
    void setIdentidad(string Identidad){
        this->Identidad = Identidad;
    }


    // Metodos Get
    string getIdentidad(){
        return this->Identidad;
    }



    // Metodo vacio
    PERSONA(){}
    
    // Destructor
    ~PERSONA(){}

}; //Fin de la clase PERSONA


int main() {
    PERSONA BobEsponja;
    //setIdentidad:
    BobEsponja.setIdentidad("0801-1997-1234");

    // getIdentidad:
    std::cout << BobEsponja.getIdentidad() << '\n';
    
    return 0;
}