#include <iostream>

class PERSONA {
private:
    int instancia;

public:
    PERSONA() : instancia(1) {}

    int CrearPersona() {
        return instancia++;
    }
};

int main() {
    PERSONA persona;

    // Generar e imprimir instancias
    for (int i = 0; i < 5; ++i) {
        int instancia = persona.CrearPersona();
        std::cout << "Persona generada: " << instancia << std::endl;
    }
    
    return 0;
}
