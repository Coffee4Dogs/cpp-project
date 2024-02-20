#include <iostream>

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
    protected:
        string Nacimiento;
            int DiaNacimiento;
            string MesNacimiento; //Diciembre or diciembre or 12
            int AñoNacimiento;

        int Edad;

        double IMS;         //(Índice de Masa Corporal)
            double Altura;  //Edad Altura(m)
            double Peso;    //(KG)
        
        
        string TipoSangre; // A+, A-, B, AB, O, etc...
        
        string Cita;        //Una cita contiene dia, hora y minuto:
            int DiaCita;
            int HoraCita;
            int MinutoCita;

        string Antecedentes;            //Total de enfermedades.
            string EnfermedadActual;    //La ultima enfermedad.
        
        string Direccion;   //Direccion del paciente.


    public:
        // Constructor
        PACIENTE(string Nacimiento, int DiaNacimiento, string MesNacimiento, int AñoNacimiento, int Edad,
                double IMS, double Altura, double Peso, string TipoSangre, 
                string Cita, int DiaCita, int HoraCita, int MinutoCita,
                string Antecedentes, string EnfermedadActual, string Direccion){
            this-> Nacimiento = Nacimiento;
            this-> DiaNacimiento = DiaNacimiento;
            this-> MesNacimiento = MesNacimiento;
            this-> AñoNacimiento = AñoNacimiento;
            this-> Edad = Edad;
            this-> IMS = IMS;
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

        // Metodo Vacio
        PACIENTE(){}

        // Destructor
        ~PACIENTE(){}
};

int main() {
    PERSONA BobEsponja;
    
    BobEsponja.setPersona(  "0801-1997-12345",  //Identidad
                            123456789,          //Telefono
                            "Bob",              //Nombre
                            "Esponja",          //ApellidoA
                            "Gaaar");           //ApellidoB
    //Imprimir en pantalla los datos de Bob:
    BobEsponja.PrintPersona();



    return 0;
}