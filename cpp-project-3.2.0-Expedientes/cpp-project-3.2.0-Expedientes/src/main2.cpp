#include <iostream>
#include <fstream>

class Consulta {
private:
    std::string motivoConsulta;

public:
    // Método setter para guardar toda la línea de texto
    void setMotivoConsulta(const std::string& MotivoConsulta) {
        motivoConsulta = MotivoConsulta;
    }

    // Método getter para obtener la línea de texto completa
    std::string getMotivoConsulta() const {
        return motivoConsulta;
    }

    // Método para guardar la línea de texto en un archivo
    void guardarEnArchivo(const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            archivo << motivoConsulta << std::endl;
            archivo.close();
            std::cout << "Línea de texto guardada en el archivo: " << nombreArchivo << std::endl;
        } else {
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        }
    }

    // Método para cargar la línea de texto desde un archivo
    void cargarDesdeArchivo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            std::getline(archivo, motivoConsulta);
            archivo.close();
            std::cout << "Línea de texto cargada desde el archivo: " << nombreArchivo << std::endl;
        } else {
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        }
    }
};

int main() {
    Consulta consulta;

    // Ejemplo de uso
    consulta.setMotivoConsulta("Hola como estas");
    std::cout << "Motivo de consulta: " << consulta.getMotivoConsulta() << std::endl;

    // Guardar la línea de texto en un archivo
    consulta.guardarEnArchivo("consulta.txt");

    // Cargar la línea de texto desde un archivo
    consulta.cargarDesdeArchivo("consulta.txt");
    std::cout << "Motivo de consulta cargado desde el archivo: " << consulta.getMotivoConsulta() << std::endl;

    return 0;
}