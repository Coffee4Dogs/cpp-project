#include <iostream>
#include <iomanip>
#include <cmath>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::setw;
using std::fixed;
using std::pow;



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

class PACIENTE : public PERSONA{
    protected:
        string Nacimiento;
        int DiaNacimiento;
        int MesNacimiento; //Diciembre or diciembre or 12
        int AñoNacimiento;
        int Edad;
        double IMS = -1;         //(Índice de Masa Corporal)
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
        PACIENTE(string Nacimiento, int DiaNacimiento, int MesNacimiento, int AñoNacimiento, int Edad,  double Altura, double Peso, string TipoSangre, string Cita, int DiaCita, int HoraCita, int MinutoCita, string Antecedentes, string EnfermedadActual, string Direccion){
            this-> Nacimiento = Nacimiento;
            this-> DiaNacimiento = DiaNacimiento;
            this-> MesNacimiento = MesNacimiento;
            this-> AñoNacimiento = AñoNacimiento;
            this-> Edad = Edad;
            // this-> IMS = IMS; // Existe this->IMS, pero no IMS porque no es necesaria.
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

        

        

        // Metodos Set:
            // Atributos
            void setNacimiento(string Nacimiento){this-> Nacimiento = Nacimiento;}
            void setDiaNacimiento(int DiaNacimiento){this-> DiaNacimiento = DiaNacimiento;}
            void setMesNacimiento(int MesNacimiento){this-> MesNacimiento = MesNacimiento;}
            void setAñoNacimiento(int AñoNacimiento){this->AñoNacimiento = AñoNacimiento;}
            void setEdad(int Edad){this-> Edad = Edad;}
            void setAltura(double Altura){
                this->Altura = Altura;
                CalcularIMS(); //Al establecer una Altura (Metros) luego se calcula el IMS.
            }
            void setPeso(double Peso){
                this->Peso = Peso;
                CalcularIMS();  //Al establecer un Peso(KG) luego se calcula el IMS.
            }
            void setTipoSangre(string TipoSangre){this->TipoSangre = TipoSangre;}
            void setCita(string Cita){this-> Cita = Cita;}
            void setDiaCita(int DiaCita){this-> DiaCita = DiaCita;}
            void setHoraCita(int HoraCita){this-> HoraCita = HoraCita;}
            void setMinutoCita(int MinutoCita){this-> MinutoCita = MinutoCita;}
            void setAntecedentes(string Antecedentes){this->Antecedentes = Antecedentes;}
            void setEnfermedadActual(string EnfermedadActual){this-> EnfermedadActual = EnfermedadActual;}
            void setDireccion(string Direccion){this-> Direccion = Direccion;}

            //Calculos y Otros Metodos:
            void CalcularIMS(){
                this->IMS = this->Peso / (pow(this->Altura, 2));
            }

            //Set todos atributos 
            void setPaciente(string Nacimiento, int DiaNacimiento, int MesNacimiento, int AñoNacimiento, int Edad, double IMS, double Altura, double Peso, string TipoSangre, string Cita, int DiaCita, int HoraCita, int MinutoCita, string Antecedentes, string EnfermedadActual, string Direccion){
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

        // Metodos Get:
            // Atributos
            string getNacimiento(){return this->Nacimiento;}
            int getDiaNacimiento(){return this->DiaNacimiento;}
            int getMesNacimiento(){return this->MesNacimiento;}
            int getAñoNacimiento(){return this->AñoNacimiento;}
            int getEdad(){return this-> Edad;}
            double getIMS(){return this->IMS;}
            double getAltura(){return this->Altura;}
            double getPeso(){return this->Peso;}
            string getTipoSangre(){return this->TipoSangre;}
            string getCita(){return this-> Cita;}
            int getDiaCita(){return this-> DiaCita;}
            int getHoraCita(){return this-> HoraCita;}
            int getMinutoCita(){return this-> MinutoCita;}
            string getAntecedentes(){return this->Antecedentes;}
            string getEnfermedadActual(){return this-> EnfermedadActual;}
            string getDireccion(){return this-> Direccion;}

            //PrintPaciente - Imprime todos los atributos del paciente para depurar el codigo.
            void PrintPaciente(){

                std::cout << "Nacimiento: " <<Nacimiento << '\n';
                std::cout << "DiaNacimiento: " <<DiaNacimiento << '\n';
                std::cout << "MesNacimiento: " <<MesNacimiento << '\n';
                std::cout << "AnoNacimiento: " <<AñoNacimiento << '\n';
                std::cout << "Edad: " <<Edad << '\n';
                std::cout << "IMS: " <<IMS << '\n';
                std::cout << "Altura: " <<Altura << '\n';
                std::cout << "Peso: " <<Peso << '\n';
                std::cout << "TipoSangre: " <<TipoSangre << '\n';
                std::cout << "Cita: " <<Cita << '\n';
                std::cout << "DiaCita: " <<DiaCita << '\n';
                std::cout << "HoraCita: " <<HoraCita << '\n';
                std::cout << "MinutoCita: " <<MinutoCita << '\n';
                std::cout << "Antecedentes: " <<Antecedentes << '\n';
                std::cout << "EnfermedadActual: " <<EnfermedadActual << '\n';
                std::cout << "Direccion: " <<Direccion << std::endl;
            }
            
            






        // Metodo Vacio
        PACIENTE(){}

        // Destructor
        ~PACIENTE(){}
};



int main() {
    cout << fixed << setprecision(2) << setw(10); //Ajustar la precision de la salida que se muestra en pantalla.
    PERSONA UnaPersona;
    PACIENTE UnPaciente;
    
    
    UnPaciente.setAltura(1.83);
    UnPaciente.setPeso(80);


    std::cout << "Altura: " << UnPaciente.getAltura() << '\n';
    std::cout << "Peso: "<< UnPaciente.getPeso() << '\n';
    std::cout <<  "El indice de Masa Corporal (IMS): " << UnPaciente.getIMS() << '\n';
    

    return 0;
}