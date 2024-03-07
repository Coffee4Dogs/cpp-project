/* ***************************************
    
    Nombre: Jack Hollmann Lagos Mejia
    Numero Registro: 32011727

    Nombre: Josue Eliezer Castillo Soto
    Numero Registro:  32151059

//Repository: //https://github.com/Coffee4Dogs/cpp-project
***************************************** */
//cout, cin, endl, etc...
    #include <iostream>
//Prec de variables double (setprecision()) y lim caracteres (setw()).
    #include <iomanip>
//Elevar al cuadrado
    #include <cmath> 
//Manipular archivos
    #include <fstream>
//Crear Vectores
    #include <vector>
//INVESTIGAR UNA LIBRERIA.
    #include <cstdlib> 
// Nos permite usar comandos de la consola de windows. 
// En este caso la vamos a usar para limpiar pantalla cuando querramos.
// system("cls"); <- (hace el comando del cmd clear screen).
    

//Version Actual:
std::string vrs = "3.0.2";

using std::string; 
using std::cout; 
using std::cin; 
using std::endl;
using std::setprecision; 
using std::setw; 
using std::fixed;
using std::pow; 
using std::fstream;
using std::vector;

//Vectores:
vector<int> VRegistro;
vector<string> VNombre;
vector<string> VApellidoA; 
vector<string> VApellidoB;
vector<string> VIdentidad;
vector<int> VTelefono;
vector<int> VDiaNacimiento;
vector<int> VMesNacimiento;
vector<int> VAñoNacimiento;
vector<int> VEdad;
vector<double> VAltura;
vector<double> VPeso;
vector<double> VIMS;
vector<string> VGrupoSanguineo;
vector<string> VAntecedentes;

//Entrada de tipo string usada input de usuario.
string UserInput;

//Variables de Registro (como el ID en una base de datos):
int IDPacientes;
int IDExpediente; 

//Solo hay 8 "Tipos de Sangre":
const std::string GruposSanguineos[8] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};


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

//Ordena un arreglo (De mayor a menor). Parametros: array, el tamaño en numero entero.
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

// cuand -help muestra un texto con instrucciones al usuario.
void DisplayHelp(){
    system("cls"); std::cout << "\n";
    
    std::cout << "VERSION \n\t -version  --version" << std::endl;
    std::cout << "CLEAR SCREEN \n\t cls, clear" << std::endl;
    std::cout << "NUEVO PACIENTE \n\t -new, -nuevo, -new patient, -nuevo paciente (Crear un nuevo usuario)." << std::endl;
    std::cout << "TODOS LOS PACIENTES \n\t -all, -todos (Muestra la lista de todos los pacientes)." << std::endl;
    std::cout << "SALIR/EXIT \n\t -exit, -salir, exit(), exit, salir" << std::endl;
}

//Trae un archivo de decoracion de un gato como presentacion.
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

//Encripta un string si le damos un shift. Ejem la a -> b con shift +1.
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

//Dar total de registros. Si no hay retorna -1.
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

//Asignar ID cuando esta en modo escritura.
int AsignarID(){
    int totalregistros;
    totalregistros = ContarRegistros("Datos_Pacientes.txt");
    if(totalregistros > 0){
        totalregistros ++;
    }
    else{
        totalregistros = 1;
        // totalregistros ++;
    }
    return totalregistros; 
}

//Crea un usuario cada vez que se le llama.
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

        //Registro
            file << AsignarID() << ' ';

        //Nombre-string
            std::cout << "Ingrese el nombre del paciente: " << '\n';
            std::cin >> stemp; P1.setNombre(stemp);
            file << P1.getNombre() << ' ';

        //ApellidoA-string
            std::cout << "Ingrese su primer apellido: " << ' ';
            std::cin >> stemp; P1.setApellidoA(stemp);
            file << P1.getApellidoA() << ' ';
            
        //ApellidoB-string
            std::cout << "Ingrese su segundo apellido: " << '\n';
            std::cin >> stemp; P1.setApellidoB(stemp);
            file <<  P1.getApellidoB() << ' ';
        //IDENTIDAD-string
            std::cout << "Ingrese su numero de IDENTIDAD: " << '\n';
            std::cin >> stemp; P1.setIdentidad(stemp);
            file <<  P1.getIdentidad() << ' ';

        //Telefono
            std::cout << "Ingrese el telefono: " << '\n';
            std::cin >> itemp; P1.setTelefono(itemp);
            file << P1.getTelefono() << ' ';

        
        //DiaNacimiento
            std::cout << "Dia de Nacimiento  (Numero)" << '\n';
            std::cin >> itemp; P1.setDiaNacimiento(itemp);
            file << P1.getDiaNacimiento() << ' ';

        //MesNacimiento
            std::cout << "Mes de Nacimiento (Numero) " << '\n';
            std::cin >> itemp; P1.setMesNacimiento(itemp);
            file << P1.getMesNacimiento() << ' ';
        
        //AñoNacimiento
            std::cout << "Ano de Nacimiento  (Numero)" << '\n';
            std::cin >> itemp; P1.setAñoNacimiento(itemp);
            file << P1.getAñoNacimiento() << ' ';
        
        //Edad
            std::cout << "Se genero la edad del paciente: " << P1.getEdad() << '\n';
            file << P1.getEdad() << ' ';
            
        //Altura
            std::cout << "Ingrese la altura en Metros (Sistema Internacional): " << '\n';
            std::cin >> dtemp; P1.setAltura(dtemp);
            file << P1.getAltura() << ' ';

        //Peso
            std::cout << "Ingrese el peso en Kilogramos (Sistema Internacional): " << '\n';
            std::cin >> dtemp; P1.setPeso(dtemp);
            file << P1.getPeso() << ' ';
        
        //IMS
            std::cout << "Generado Indice de Masa Corporal (IMS)" << P1.getIMS() << '\n';
            file << P1.getIMS() << ' ';

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
        
        //Antecedentes
            std::cout << "Escriba los antecedentes (enfermedades previas) separado por el siguiente simbolo: \n ->  /  <-" << '\n';
            std::cout << "Ejemplo: Hipertension/Diabetes" << '\n';
            std::cout << "Si la persona NO TIENE enfermedades previas, ingrese un punto -> . <-" << std::endl;
            std::cin >> stemp; 
            P1.setAntecedentes(stemp);
            file << P1.getAntecedentes() << ' ';

        //Quizas esto deberia de ir en expediente...
        // //HoraCita
        //     count = 0;
        //     while(count < 1){
        //         std::cout << "Ingrese la hora de la Cita en formato de 24 hrs." << '\n';    
        //         std::cin >> itemp; 
        //         ((itemp >= 0) && (itemp <= 23)) ? count = 1 : count = -1;

        //         P1.setHoraCita(itemp);
                
        //         file << P1.getHoraCita() << ' ';
        //     }

        // //MinutoCita
        //     count = 0;
        //     while(count < 1){
        //         std::cout << "Ingrese los minutos de la cita (0 - 59)" << '\n';    
        //         std::cin >> itemp;
                  

        //         (itemp >= 0) && (itemp <= 59) ? count = 1 : count = -1;
        //         //El usuario puso una hora entre 0 a 59?
        //         P1.setMinutoCita(itemp);
        //         file << P1.getMinutoCita() << ' ';
        //     }

        //Direccion ha sido eliminado.


            //Fin de Crear Usuario.
            file << '\n';
        file.close();
    }
   
   
   
}

// int size = ContarRegistros("Datos_Pacientes.txt")
// for(int i = 0; i < size; i++){
//     file >> ID >> Identidad >> Telefono >> Nombre >> ApellidoA >> ApellidoB >> Identidad >> Altura >> Peso >> HoraCita >> MinutoCita >> GrupoSanguineo;
//     std::cout << "El usuario es: " << Nombre << "y su edad es: " <<  << '\n';

// }

//Recorre 
void LeerUsuario() {
    fstream file; string address = "Datos_Pacientes.txt"; string line;
    file.open(address, fstream::in);
    if(file.is_open()){
        while(getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
    }
}  

//Vectores:
// vector<int> VRegistro;
// vector<string> VNombre;
// vector<string> VApellidoA; 
// vector<string> VApellidoB;
// vector<string> VIDENTIDAD;
// vector<int> VTelefono;
// vector<int> VDiaNacimiento;
// vector<int> VMesNacimiento;
// vector<int> VAñoNacimiento;
// vector<int> VEdad;
// vector<double> VAltura;
// vector<double> VPeso;
// vector<double> VIMS;
// vector<string> VGrupoSanguineo;
// vector<string> VAntecedentes;

void EscanearPaciente(){
    fstream file; string address;
    address = "Datos_Pacientes.txt";
    file.open(address, fstream::in);
    if(file.is_open()){
        int Registro; string Nombre; string ApellidoA; string ApellidoB; string Identidad; int Telefono; 
        int DiaNacimiento; int MesNacimiento; int AñoNacimiento; int Edad; double Altura; double Peso; double IMS; string GrupoSanguineo; string Antecedentes;
        
        //1 Bob Esponja Pantalones 1234-5678 7777777 23 6 1999 2023 3.3 4.4 0.40404 A+ .

        while(file >> Registro >> Nombre >> ApellidoA >> ApellidoB >> Identidad >> Telefono >> DiaNacimiento >> MesNacimiento >> AñoNacimiento >> Edad >> Altura >> Peso >> IMS >> GrupoSanguineo >> Antecedentes){
            VRegistro.push_back(Registro);
            VNombre.push_back(Nombre);
            VApellidoA.push_back(ApellidoA);
            VApellidoB.push_back(ApellidoB);
            VIdentidad.push_back(Identidad);
            VTelefono.push_back(Telefono);
            VDiaNacimiento.push_back(DiaNacimiento);
            VMesNacimiento.push_back(MesNacimiento);
            VAñoNacimiento.push_back(AñoNacimiento);
            VEdad.push_back(Edad);
            VAltura.push_back(Altura);
            VPeso.push_back(Peso);
            VIMS.push_back(IMS);
            VGrupoSanguineo.push_back(GrupoSanguineo);
            VAntecedentes.push_back(Antecedentes);

        }
        std::cout << "Archivo pacientes escaneado." << '\n';

        
        file.close();
    }
}

int main() {
    int itemp; string stemp;
    DisplayWelcome();
    cout << fixed << setprecision(2) << setw(10); // -Ajustar la precision de la salida que se muestra en pantalla.
   
    ////------------------/////
    

    //--Menu--
    
    bool MantenerBucle = true; 
    while (MantenerBucle == true){
        std::cout << " - $ ";
        cin >> UserInput;
        if(UserInput == "-new" || UserInput=="-nuevo" || UserInput == "-new patient" || UserInput=="-nuevo paciente" || UserInput == "new" || UserInput == "nuevo"){
            CrearUsuario();
            MantenerBucle = true;
        }
        //Leer todos los pacientes
        else if(UserInput == "-all" || UserInput=="-todos" || UserInput == "all" || UserInput == "todos"){
            std::cout << "Mostrando todos los pacientes:" << '\n';
            LeerUsuario();
            MantenerBucle = true;
        }

        else if(UserInput=="-help" || UserInput=="--help" || UserInput=="help"){
            DisplayHelp();
            MantenerBucle = true;
        }
        else if(UserInput=="-exit" || UserInput=="-salir" || UserInput=="exit()" || UserInput=="exit" || UserInput=="salir"){   
            MantenerBucle = false;
        }
        else if(UserInput=="-version" || UserInput=="--version"){
            std::cout << "Version " << vrs << '\n';
            MantenerBucle = true;
        }

        else if(UserInput=="-search"){
            std::cout << "Leyendo el archivo... " << '\n';
            EscanearPaciente();
            std::cout << "ID:" << VRegistro[2] << " con nombre " << VNombre[2] << " y numero de telefono: " << VTelefono [2] << '\n';
            MantenerBucle = true;
        }

        else if(UserInput=="-search"){ 
            
            std::cout << "Seleccione una opcion de busqueda:" << '\n';
            std::cout << "1. Identidad" << '\n';
            std::cout << "2. Numero de Telefono" << '\n';
            itemp == 0; cin >> itemp;
            if(itemp == 1){
                std::cout << "Buscar por Identidad. Ingrese la identidad:" << '\n';
                cin >> stemp;
                std::cout << "Buscando: " << stemp << '\n';

            }
            if(itemp == 2){
                std::cout << "Buscar por Telefono" << '\n';
                cin >> itemp;
                std::cout << "Buscando: " << itemp << '\n';
            }
            MantenerBucle = true;
        }
        
        else if(UserInput=="clear" || UserInput=="cls"){
            system("cls");
            MantenerBucle = true;
        }

        else{
            std::cout << "El comando " << UserInput << "no es un comando reconocido. \nUtilice -help o --help para mostrar todos los comandos disponibles." << '\n';
            MantenerBucle = true;

        }

    }
    
    

    //Fin del Codigo
    return 0;
}