#include <iostream>
#include <iomanip>
#include <cmath> //Para poder elevar al cuadrado
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::setw;
using std::fixed;
using std::pow; //Para poder elevar al cuadrado
using std::fstream;


string UserInput;
string GruposSanguineos[8] = {"A+"," A-", "B+", "B-", "AB+", "AB-", "O+" ,"O-"};

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
        void setNacimiento(string Nacimiento){this-> Nacimiento = Nacimiento; CalcularEdad();}
        void setDiaNacimiento(int DiaNacimiento){this-> DiaNacimiento = DiaNacimiento;CalcularEdad();}
        void setMesNacimiento(int MesNacimiento){this-> MesNacimiento = MesNacimiento;CalcularEdad();}
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
        
        
        //Calculos:
        void CalcularEdad() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int currentYear = 1900 + localTime->tm_year;
        this->Edad = currentYear - this->AñoNacimiento;
        if (localTime->tm_mon + 1 < this->MesNacimiento || 
            (localTime->tm_mon + 1 == this->MesNacimiento && localTime->tm_mday < this->DiaNacimiento)) {
            this->Edad--;
        }
        }
        
        void CalcularIMS(){
            this->IMS = this->Peso / (pow(this->Altura, 2));
        }

        //Otros metodos set no necesarios (solo para depurar)
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
            string getNacimiento(){return this->Nacimiento;}
            int getDiaNacimiento(){return this->DiaNacimiento;}
            int getMesNacimiento(){return this->MesNacimiento;}
            int getAñoNacimiento(){return this->AñoNacimiento;}
            double getIMS(){return this->IMS;}
            int getEdad(){return Edad;}
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

            //PrintPaciente - (solo para depurar)
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


class EXPEDIENTE : public PACIENTE{
    protected:
    int NumeroExpediente;

    public:
    //Constructor:
    EXPEDIENTE(int NumeroExpediente){
        this->NumeroExpediente = NumeroExpediente;
    }

    //Metodo Set:
    void setNumeroExpediente(int NumeroExpediente){
        this-> NumeroExpediente = NumeroExpediente;
    }

    //Metodos Get:
    int getNumeroExpediente(){
        return this->NumeroExpediente;
    }


    //Metodo sin nada.
    EXPEDIENTE(){}

    //Destructor
    ~EXPEDIENTE(){}
};

class MEDICO : public PERSONA{
    protected:
    string Especialidad;
    string NumeroColegiado;
    double Tarifa= 0.00;
    
    public:
    //metodo constructor
    MEDICO(string Especialidad, string NumeroColegiado, double Tarifa){
    
    this-> Especialidad = Especialidad;
    this-> NumeroColegiado = NumeroColegiado;
    this-> Tarifa = Tarifa;

    }
    
    //Metodos Set: 
    void setEspecialidad(string Especialidad){
         this-> Especialidad = Especialidad;


    }

    void setNumeroColegiado (string NumeroColegiado){
        this-> NumeroColegiado = NumeroColegiado;
    }

    void setTarifa(double Tarifa){
       this->Tarifa = Tarifa;
    }

    // Metodos Get:
    string getEspecialidad(){
        return this-> Especialidad;
    }
    string getNumeroColegiado(){
        return this-> NumeroColegiado;
    }
    double getTarifa(){
        return this->Tarifa;
    }




    //Metodo sin nada.
    MEDICO(){}
    
    //Destructor
    ~MEDICO(){}

};




// -Despliega las opciones del menu.
void DisplayMainMenu(){
    std::cout << "- Crear Usuario: New, Nuevo, 0000." << std::endl;
    std::cout << "- Buscar Usuario: <Numero Identidad>" << std::endl;
    std::cout << "- Salir/Exit" << std::endl;
}


// -MENU: Funcion que pregunta al usuario que opcion quiere.
void PreguntarUsuario(){
    int c = 0;
    while(c < 1){
        // -Crear Usuario
        DisplayMainMenu();
        std::getline(std::cin, UserInput);
        if(
                (UserInput.at(0) == '0') && (UserInput.at(1) == '0') && (UserInput.at(2) == '0') && (UserInput.at(3) == '0') ||
                ((UserInput.at(0) == 'n') || (UserInput.at(0) == 'N')) && ((UserInput.at(1) == 'e') || (UserInput.at(1) == 'E')) && ((UserInput.at(2) == 'w') || (UserInput.at(2) == 'W')) ||
                ((UserInput.at(0) == 'n') || (UserInput.at(0) == 'N')) && ((UserInput.at(1) == 'u') || (UserInput.at(1) == 'U')) && ((UserInput.at(2) == 'e') || (UserInput.at(2) == 'E')) && ((UserInput.at(3) == 'v') || (UserInput.at(3) == 'V')) && ((UserInput.at(4) == 'o') || (UserInput.at(4) == 'O'))
            ){
            std::cout << "Seleccionaste la opcion Crear Usuario." << '\n';
            
        }

        //Exit, Salir 
        else if(
                ((UserInput.at(0) == 'E') || (UserInput.at(0) == 'e')) && ((UserInput.at(1) == 'x') || (UserInput.at(1) == 'X')) && ((UserInput.at(2) == 'i') || (UserInput.at(2) == 'I')) && ((UserInput.at(3) == 't') || (UserInput.at(3) == 'T')) ||
                ((UserInput.at(0) == 's') || (UserInput.at(0) == 'S')) && ((UserInput.at(1) == 'a') || (UserInput.at(1) == 'A')) && ((UserInput.at(2) == 'l') || (UserInput.at(2) == 'L')) && ((UserInput.at(3) == 'i') || (UserInput.at(3) == 'I')) && ((UserInput.at(4) == 'r') || (UserInput.at(4) == 'R'))
            ){
            std::cout << "Seleccionaste la opcion Salir." << '\n';
        }
        else{
            std::cout << "Buscando usuario: " << UserInput << '\n'; 
        }
    }
}





int main() {
    
    cout << fixed << setprecision(2) << setw(10); // -Ajustar la precision de la salida que se muestra en pantalla.
    
    ////------------------/////
    
    //Variables
    fstream file; 
    string address = "Datos_Pacientes.txt"; 

    //Variables temporales:
        string stemp = "";      //Variale stemporal para guardar cualquier string.
        int itemp = 0;         //variable stemporal para guardar cualquier int.
        double dtemp = 0.0;     //Variable temporal para guardar cualquier double.

    int count = 0;
    
    //Instancias
    PACIENTE P1;
    
    
    
    
    file.open(address, fstream::app);
    if(file.is_open()){

        //Nombre
            std::cout << "Ingrese el nombre del paciente: " << '\n';
            std::cin >> stemp; P1.setNombre(stemp);
            file << P1.getNombre() << '\n';
        //ApellidoA
            std::cout << "Ingrese su primer apellido: " << '\n';
            std::cin >> stemp; P1.setApellidoA(stemp);
            file << P1.getApellidoA() << '\n';
            //---------NO TESTEADO ------------------
        //ApellidoB
            std::cout << "Ingrese su segundo apellido: " << '\n';
            std::cin >> stemp; P1.setApellidoB(stemp);
            file << P1.getApellidoB() << '\n';
        //IDENTIDAD
            std::cout << "Ingrese su numero de IDENTIDAD: " << '\n';
            std::cin >> stemp; P1.setIdentidad(stemp);
            file << P1.getIdentidad() << '\n';

            
        //Altura
            std::cout << "Ingrese la altura en Metros (Sistema Internacional): " << '\n';
            std::cin >> dtemp; P1.setAltura(dtemp);
            file << P1.getAltura() << '\n';

        //Altura
            std::cout << "Ingrese el peso en Kilogramos (Sistema Internacional): " << '\n';
            std::cin >> dtemp; P1.setPeso(dtemp);
            file << P1.getPeso() << '\n';
        
        //IMS
            file << P1.getIMS() << '\n';


        //HoraCita
            count = 0;
            while(count < 1){
                std::cout << "Ingrese la hora de la Cita en formato de 24 hrs." << '\n';    
                std::cin >> itemp; 
                ((itemp >= 0) && (itemp <= 23)) ? count = 1 : count = -1;

                P1.setHoraCita(itemp);
                
                file << P1.getHoraCita() << '\n';
            }

        //MinutoCita
            count = 0;
            while(count < 1){
                std::cout << "Ingrese los minutos de la cita (0 - 59)" << '\n';    
                std::cin >> itemp;
                  

                (itemp >= 0) && (itemp <= 59) ? count = 1 : count = -1;
                //El usuario puso una hora entre 0 a 59?
                P1.setMinutoCita(itemp);
                file << P1.getMinutoCita() << '\n';
            }

        //Grupo Sanguineo
            count = 0;
            while(count < 1){
                std::cout << "Seleccione un grupo sanguineo:" << '\n';
                std::cout << "Opciones: ";
                for(string i : GruposSanguineos){
                    std::cout << i << ", ";
                }
                std::cin >> stemp;
                if(stemp == "A+" || stemp == "A-" || stemp == "B+" || stemp == "B-" || stemp == "AB+" || stemp == "AB-" || stemp == "O+" || stemp == "O-"){
                    count = 1;
                }
                else{
                    count = -1;
                }
            }
            P1.setTipoSangre(stemp);
            file << P1.getTipoSangre() << '\n';
        file.close();
    }
   
    



    

    
    
    
    


    return 0;
}
