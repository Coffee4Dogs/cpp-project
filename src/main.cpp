#include <iostream>
#include <iomanip>
#include <cmath> //Para poder elevar al cuadrado
#include <fstream>
#include <cstdlib> //La vamos a usar solamente para limpiar la consola system("cls") <- (clear screen).


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::setw;
using std::fixed;
using std::pow; //Para poder elevar al cuadrado
using std::fstream;

string vrs = "2.2.4 - (Aurora) "; //Current Patch/Version


string UserInput;
int IDPacientes;
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


//De mayor a menor.
void BubbleSort(int array[], int size){
    int temp;
    for(int i = 0; i<size-1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j]<array[j+1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            } 
        }
    }
}

// -Despliega las opciones cuando se llama -help
void DisplayHelp(){
    system("cls"); std::cout << "\n";
    
    std::cout << "VERSION \t\t -version  --version (Ultima version)." << std::endl;
    std::cout << "NUEVO PACIENTE \t\t -new (Crear un nuevo usuario)." << std::endl;
    std::cout << "LISTA PACIENTES \t -list (Lista de todos los pacientes)." << std::endl;
    std::cout << "EXIT \t\t\t -exit (Salir del programa)." << std::endl;
}

void DisplayWelcome(){
    system("cls"); std::cout << "\n";
    fstream file; string line;
    file.open("welcome.txt", fstream::in);
    if(file.is_open()){
        while(getline(file, line)){
            std::cout << line << '\n';
        }
        file.close();
    }
}



string CCipher(int shift, string line){
    // ----------  Caesar Cipher Encryption  -----------
        //-Shift: Abecedario estandar: A, B, C...  | Ejemplo: shift +1: B, C, D...
        //-Line: El texto que se quiere encriptar.
    string NewLine = "";
    int size = line.size();
    char temp;

    for(int i = 0; i < size; i++){
        temp = line.at(i);
        temp = temp + shift;
        NewLine = NewLine + temp;
    }
    return NewLine;
}

int ContarRegistros(string address){
    fstream file;
    file.open(address, fstream::in);
    string line;
    int TotalRegistros=0;
    if(file.is_open()){
        while(getline(file, line)){
            TotalRegistros++;    
        }
        file.close();
    }
    if(TotalRegistros >= 1){
        return TotalRegistros;
    }
    else{
        return -1;
    }
}

void CrearUsuario(){
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

        //Nombre-string
            std::cout << "Ingrese el nombre del paciente: " << '\n';
            std::cin >> stemp; P1.setNombre(stemp);
            file << P1.getNombre() << ' ';
        //ApellidoA-string
            std::cout << "Ingrese su primer apellido: " << ' ';
            std::cin >> stemp; P1.setApellidoA(stemp);
            file << P1.getApellidoA() << ' ';
            //---------NO TESTEADO ------------------
        //ApellidoB-string
            std::cout << "Ingrese su segundo apellido: " << '\n';
            std::cin >> stemp; P1.setApellidoB(stemp);
            file <<  P1.getApellidoB() << ' ';
        //IDENTIDAD-string
            std::cout << "Ingrese su numero de IDENTIDAD: " << '\n';
            std::cin >> stemp; P1.setIdentidad(stemp);
            file <<  P1.getIdentidad() << ' ';
            
        //Altura
            std::cout << "Ingrese la altura en Metros (Sistema Internacional): " << '\n';
            std::cin >> dtemp; P1.setAltura(dtemp);
            file << P1.getAltura() << ' ';

        //Peso
            std::cout << "Ingrese el peso en Kilogramos (Sistema Internacional): " << '\n';
            std::cin >> dtemp; P1.setPeso(dtemp);
            file << P1.getPeso() << ' ';
        
        //IMS
            file << P1.getIMS() << ' ';


        //HoraCita
            count = 0;
            while(count < 1){
                std::cout << "Ingrese la hora de la Cita en formato de 24 hrs." << '\n';    
                std::cin >> itemp; 
                ((itemp >= 0) && (itemp <= 23)) ? count = 1 : count = -1;

                P1.setHoraCita(itemp);
                
                file << P1.getHoraCita() << ' ';
            }

        //MinutoCita
            count = 0;
            while(count < 1){
                std::cout << "Ingrese los minutos de la cita (0 - 59)" << '\n';    
                std::cin >> itemp;
                  

                (itemp >= 0) && (itemp <= 59) ? count = 1 : count = -1;
                //El usuario puso una hora entre 0 a 59?
                P1.setMinutoCita(itemp);
                file << P1.getMinutoCita() << ' ';
            }

        //Grupo Sanguineo 
            count = 0;
            while(count < 1){
                
                std::cout << "Seleccione un grupo sanguineo:" << '\n';
                std::cout << "Opciones: "<< std::endl;
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
            file << P1.getTipoSangre() << ' ';

            //Fin de Crear Usuario.
            file << '\n';
        file.close();
    }
   
    
}




int main() {
    DisplayWelcome();
    ;std::cout << ContarRegistros("Datos_Pacientes.txt") << '\n';
    cout << fixed << setprecision(2) << setw(10); // -Ajustar la precision de la salida que se muestra en pantalla.
    
    ////------------------/////
    



    
    //--------- MENU ---------
    //Inspirado en los LLM Ref. Andrej Karpathy -> https://www.youtube.com/watch?v=zduSFxRajkE
    //Bag of words:
    string Nuevo[] = {"n","e","w" };    // 3 -new new, New
    string Help[] = {"h","e", "l"};     // 1 -Help Command
    string Salir[] = {"x","i","t"};     //exit
    string Version[] = {"s","r","o"};   //version llm
    
    int m = 0; //m = -1 (mantenerse en while, respuestas negativas) | m = 1 (romper/salir de menu while) 
    
    //Existing Layers:
    int N, n1, n2, n3;
    int S, s1, s2, s3;
    int H, h1, h2, h3;
    int V, v1, v2, v3;


    while(m<1){
        std::cout << "   - $ ";
        cin >> UserInput;

        
        //Reset Everything
        N = 0; n1 = 0; n2 = 0; n3 = 0;
        S = 0; s1 = 0; s2 = 0; s3 = 0;
        H = 0; h1 = 0; h2 = 0; h3 = 0;
        V = 0; v1 = 0; v2 = 0; v3 = 0;

        // Pre-Process:
        //Layer N:
        for(int i = 0; i < Nuevo[0].size(); i++){n1 = UserInput.find(Nuevo[0].at(i));}
        for(int i = 0; i < Nuevo[1].size(); i++){n2 = UserInput.find(Nuevo[1].at(i));}
        for(int i = 0; i < Nuevo[2].size(); i++){n3 = UserInput.find(Nuevo[2].at(i));}

        //Layer S:
        for(int i = 0; i < Salir[0].size(); i++){s1 = UserInput.find(Salir[0].at(i));}
        for(int i = 0; i < Salir[1].size(); i++){s2 = UserInput.find(Salir[1].at(i));}
        for(int i = 0; i < Salir[2].size(); i++){s3 = UserInput.find(Salir[2].at(i));}

        //Layer H:
        for(int i = 0; i < Help[0].size(); i++){h1 = UserInput.find(Help[0].at(i));}
        for(int i = 0; i < Help[1].size(); i++){h2 = UserInput.find(Help[1].at(i));}
        for(int i = 0; i < Help[2].size(); i++){h3 = UserInput.find(Help[2].at(i));}

        //Layer V:
        for(int i = 0; i < Version[0].size(); i++){v1 = UserInput.find(Version[0].at(i));}
        for(int i = 0; i < Version[1].size(); i++){v2 = UserInput.find(Version[1].at(i));}
        for(int i = 0; i < Version[2].size(); i++){v3 = UserInput.find(Version[2].at(i));}
            
        //Process:
            N = n1 + n2 + n3; 
            S = s1 + s2 + s3; 
            H = h1 + h2 + h3;
            V = v1 + v2 + v3;

        //Bubble Sort me dira es la mas grande del arreglo, osea cual es la respuesta que acumulo mas puntos.
        //En una red neuronal, la que activo mas neuronas.
            int response[] = {N, S, H, V};
            int size_response = sizeof(response) / sizeof(response[0]);
            BubbleSort(response, size_response);

        // Responses: (Comparamos la respuesta con cada posibilidad)
            // Layer N:
            if(N == response[0]){
                std::cout << "Crear un usuario." << '\n';
                m = -1;
                CrearUsuario();
            }
            //Layer S:
            else if(S == response[0]){
                std::cout << "Seleccionaste Salir." << '\n';
                m = 1;
            }
            //Layer H:
            else if(H == response[0]){
                
                system("cls"); //system sirve para usar comandos del cmd. cls es lo mismo que clear en unix/ubuntu (clear screen).
                DisplayHelp();
                
                m = -1;
            }
            //Layer V:
            else if(V == response[0]){
                std::cout << "Version actual: "<< vrs << '\n';
                m = -1;
            }

            //Error Message:
            else{
                std::cout << "No entendi lo que dijiste..." << '\n';
                m = -1;
            }
    }


    

    
    
    
    


    return 0;
}