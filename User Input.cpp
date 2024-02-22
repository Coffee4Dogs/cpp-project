#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class PERSONA {
private:
    int instancia;

public:
    PERSONA() : instancia(1) {}

    int CrearPersona() {
        return instancia++;
    }
};

void DisplayMainMenu(){
    std::cout << "Presione 0000 para crear un nuevo perfil." << std::endl;
    std::cout << "Ingrese la Identidad que desea buscar." << std::endl;
}


int main() {
    PERSONA persona;
    std::string UserInput;
    // Generar e imprimir instancias
    // for (int i = 1; i < 5; ++i) {
    //     int instancia = persona.CrearPersona();
    //     std::cout << "Persona generada: " << instancia << std::endl;
    // }

    int c = 0;
    
    while(1 < 2){
        cin>> UserInput;

        std::cout << UserInput << '\n';

        if((UserInput.at(0) == '0') && (UserInput.at(1) == '0') && (UserInput.at(2) == '0') && (UserInput.at(3) == '0')){
            std::cout << "You created a new user!" << '\n';
        }

        //Exit, Compara el indice 0, luego el 1, 
        else if(((UserInput.at(0) == 'E') || (UserInput.at(0) == 'e')) && ((UserInput.at(1) == 'x') || (UserInput.at(1) == 'X')) && ((UserInput.at(2) == 'i') || (UserInput.at(2) == 'I')) && ((UserInput.at(3) == 't') || (UserInput.at(3) == 'T'))){
            std::cout << "You just Exit!" << '\n';
        }

    }






    return 1;
}
