// Version: 0.0.1

//Librerias:
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Using & Typedef
using std::string;
using std::fstream;
using std::vector;

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

    void setUserData(string Identidad, string User, string Password){
        this->Identidad = Identidad;
        this->User = User;
        this->Password = Password;
    }

    //Metodo Vacio
    DOCTOR(){}

    //Destructor
    ~DOCTOR(){} 
};



int main() {

    DOCTOR doctorcito;
    fstream File; //Archivo
    string Line; //Linea del documento.
    std::vector<string> ListaDoctores;
    

    //Asignar un usuario con setUserData()
    doctorcito.setUserData("080119981234" ,"doctorcito", "1234");
    

    //Crear archivo con usuario y contraseña
        // File.open("user.dat", fstream::out);
        // if(File.is_open()){
        //     File << "User" << '\n';
        //     File << doctorcito.User << '\n';
        //     File << "Password" << '\n';
        //     File << doctorcito.Password << '\n';
        //     File.close();
        // }

    string UserInput, PasswordInput;
    std::cout << "Ingresar Usuario: " << '\n';
    
    //Leer archivo user.txt
    File.open("user.dat", fstream::in);
    if(File.is_open()){
        std::cout << "~ Leer base de datos" << '\n';
        while(getline(File, Line)){
            

            //Si encontramos un Usuario
            if("User" == Line){
                std::cout << "User found" << '\n';
                getline(File, Line); //Pasar a la siguiente linea
                ListaDoctores.push_back(Line);

                getline(File, Line); //Pasar a la siguiente linea
                ListaDoctores.push_back(Line);

                getline(File, Line); //Pasar a la siguiente linea
                ListaDoctores.push_back(Line);
                

            
            }
            
        }

        std::cout << ListaDoctores[0] << '\n';
        std::cout << ListaDoctores[1] << '\n';
        std::cout << ListaDoctores[2] << '\n';

        std::cout << doctorcito.Identidad << '\n';

        File.close(); //Cerrar el archivo user.txt
    }
    
    


    std::cout << "Fin del programa" << '\n';
    return 0;
}