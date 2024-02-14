#include <iostream>
#include <string>

using std::string;

int main() {

    int Hex;
    int TotalHex;
    char resultado; 
    string palabra = "Hola Jack";
    std::cout << palabra << '\n';
    std::cout << "Contiene: " << palabra.size() << " letras." << '\n';
    
    for(int i = 0; i < palabra.size(); i++){
        std::cout << " - Letra: " << palabra.at(i) << " Hex: ";
        Hex = static_cast<int>(palabra.at(i)); //<- Obtener Numero Hexadecimal de algo
        std::cout << Hex << '\n';

        Hex = Hex + 1; //Probemos sumar un 1 en decimal.
        std::cout << "HEX+1" << Hex << '\n';
        resultado = static_cast<char>(Hex); // Obtener de nuevo el char.
        std::cout << "Resultado: "<< resultado << '\n';
    }

    

    
    
    return 0;
}