// Version: 0.0.1

//Librerias:
#include <iostream>
#include <fstream>

// Using & Typedef
using std::string;
using std::fstream;

//Clase Base
class PERSONA{
    //Atributos
    public:
        string Identidad;
        string Nombre;
        string ApellidoA;
        string ApellidoB;
        int Telefono;
        string NombreCompleto;

    public:
    //Constructor
    PERSONA(string Identidad, string Nombre, string ApellidoA,string ApellidoB,int Telefono){
        this-> Identidad = Identidad;
        this-> Nombre = Nombre;
        this-> ApellidoA = ApellidoA;
        this-> ApellidoB = ApellidoB;
        this-> Telefono = Telefono;
    }
    
    //Metodo Vacio
    PERSONA(){}
    
    //Destructor
    ~PERSONA(){}


};

// Clase Derivada
class DOCTOR : public PERSONA {
    //Atributos:
    public:
        string User;
        string Password;
        // Hora de Entrada
        int HoraEntrada;
        int MinutosEntrada;
        // Hora de Salida
        int HoraSalida;
        int MinutosSalida;

    public:
    //Constructor:
    DOCTOR(string User,string Password,int HoraEntrada,int MinutosEntrada,int HoraSalida,int MinutosSalida){
        this-> User = User;
        this-> Password = Password;
        this-> HoraEntrada = HoraEntrada;
        this-> MinutosEntrada = MinutosEntrada;
        this-> HoraSalida = HoraSalida;
        this-> MinutosSalida = MinutosSalida;    
    }

    void setUserAndPassword(string User, string Password){
        this->User = User;
        this->Password = Password;
    }

    //Metodo Vacio
    DOCTOR(){}

    //Destructor
    ~DOCTOR(){}
   
};



int main() {

    fstream File;
    DOCTOR doctorcito;
    
    

    //Probando setUserAndPassword()
        doctorcito.setUserAndPassword("doctorcito", "1234");
        std::cout << "Usuario asignado: " << doctorcito.User << '\n';
        std::cout << "Password asignado: " << doctorcito.Password << '\n';


    

    File.open("user.txt", fstream::in);
    string Line;
    if(File.is_open()){
        while(getline(File, Line)){

            // Verificar User & Password
            if(doctorcito.User == Line){
                std::cout << "Encontramos Usuario: " << doctorcito.User << ". El usuario es correcto" << '\n';
            }
            if(doctorcito.Password == Line){
                std::cout << "Encontramos Password de "<< doctorcito.User << ". El password es correcto" << '\n';
            }
            
            // Leer el documento:
                // std::cout << "Linea del texto: "<< Line << '\n';
        }
    }




    std::cout << "Fin del programa" << '\n';
    return 0;
}