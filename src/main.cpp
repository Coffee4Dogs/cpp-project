#include <iostream>
#include <ctime>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;





class PERSONA{
    protected:
        string Identidad = "-1";
        int Telefono = -1;
        string Nombre = "-1";
        string ApellidoA = "-1";
        string ApellidoB = "-1";

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
        // Set Atributos:
        void setIdentidad(string Identidad){
            this->Identidad = Identidad;
        }

        void setTelefono(int Telefono){
            this->Telefono = Telefono;
        }

        void setNombre(string Nombre){
            this->Nombre = Nombre;
        }

        void setApellidoA(string ApellidoA){
            this->ApellidoA = ApellidoA;
        }

        void setApellidoB(string ApellidoB){
            this->ApellidoB = ApellidoB;
        }

        //Otros Set:
        void setPersona(string Identidad, int Telefono, string Nombre, string ApellidoA, string ApellidoB){
            this->Identidad = Identidad;
            this->Telefono = Telefono;
            this->Nombre = Nombre;
            this->ApellidoA = ApellidoA;
            this->ApellidoB = ApellidoB;
        }



    // Metodos Get
        //Atributos:
        string getIdentidad(){
            return this->Identidad;
        }

        int getTelefono(){
            return this->Telefono;
        }

        string getNombre(){
            return this->Nombre;
        }

        string getApellidoA(){
            return this->ApellidoA;
        }

        string getApellidoB(){
            return this->ApellidoB;
        }

    //Imprimir Atributos Pantalla en void (util para depurar):
    void PrintPersona(){
        std::cout <<"Identidad: " <<this->Identidad << '\n';
        std::cout <<"Telefono: " <<this->Telefono << '\n';
        std::cout <<"Nombre: " <<this->Nombre << '\n';
        std::cout <<"ApellidoA: " <<this->ApellidoA << '\n';
        std::cout <<"ApellidoB: " <<this->ApellidoB << std::endl;


    }



    // Metodo vacio
    PERSONA(){}
    
    // Destructor
    ~PERSONA(){}

}; //Fin de la clase PERSONA

// DiaNacimiento, MesNacimiento, AñoNacimiento, Edad Altura(m), 
// Peso (KG), IMS (Índice de Masa Corporal), TipoSangre, 
// DiaCita, HoraCita, Antecedentes, Enfermedad Actual (Motivo Consulta), Direccion

class PACIENTE : public PERSONA{
    public:
        string Nacimiento;
            int DiaNacimiento = -1;
            int MesNacimiento = -1; //Diciembre or diciembre or 12
            int AñoNacimiento = -1;

        int Edad = -1;

        double IMS = -1.0;         //(Índice de Masa Corporal)
            double Altura = -1.0;  //Edad Altura(m)
            double Peso = -1.0;    //(KG)
        
        
        string TipoSangre = "-1"; // A+, A-, B, AB, O, etc...
        
        string Cita = "-1";        //Una cita contiene dia, hora y minuto:
            int DiaCita = -1;
            int HoraCita = -1;
            int MinutoCita = -1;

        string Antecedentes = "-1";            //Total de enfermedades.
            string EnfermedadActual = "-1";    //La ultima enfermedad.
        
        string Direccion = "-1";   //Direccion del paciente.


    public:
        // Constructor
        PACIENTE(string Nacimiento, int DiaNacimiento, int MesNacimiento, int AñoNacimiento, int Edad,
                double IMS, double Altura, double Peso, string TipoSangre, 
                string Cita, int DiaCita, int HoraCita, int MinutoCita,
                string Antecedentes, string EnfermedadActual, string Direccion){
            // Logica del Constructor
            this-> Nacimiento = Nacimiento;
            this-> DiaNacimiento = DiaNacimiento;
            this-> MesNacimiento = MesNacimiento;
            this-> AñoNacimiento = AñoNacimiento;
            this-> Edad = Edad;
            // this-> IMS = IMS;
            CalcularIndiceMasaCorporal(Altura, Peso);
            this-> Altura = Altura;
            this-> Peso = Peso;
            this-> TipoSangre = TipoSangre;
            this-> Cita = Cita;
            this-> DiaCita = DiaCita;
            this-> HoraCita = HoraCita;
            this-> MinutoCita = MinutoCita;
            this-> Antecedentes = Antecedentes;
            this-> EnfermedadActual = EnfermedadActual;
            this-> Direccion = Direccion;
        }

        void CalcularIndiceMasaCorporal(double Altura, double Peso){
            Altura = Altura * Altura;
            this->IMS = Peso / Altura;
        }

      
        // Metodo Vacio
        PACIENTE(){}

        // Destructor
        ~PACIENTE(){}
};

int main() {
    PACIENTE Arenita;
    Arenita.Peso(70.0);//kg
    Arenita.Altura(180.0); //peso cm
    std::cout << Arenita.IMS() << '\n';



    return 0;
}