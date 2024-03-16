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
//Crear Vectores y algoritmos
    #include <vector>
    #include <algorithm>
//INVESTIGAR UNA LIBRERIA.
    #include <cstdlib> 

    #include <ctime> 
// Nos permite usar comandos de la consola de windows. 
// En este caso la vamos a usar para limpiar pantalla cuando querramos.
// system("cls"); <- (hace el comando del cmd clear screen).
    
//Version Actual:
std::string vrs = "4.0.3";

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

int index = -1;


//Entrada de tipo string usada input de usuario.
string UserInput;
string BuscarIdentidad;

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
    
    //Metodos Set
    //Encriptados:
    void setIdentidad(string Identidad){
        this->Identidad = CCipher(1, Identidad);
    }

    void setNombre(string Nombre){
        this->Nombre = CCipher(1, Nombre);
    }

    void setApellidoA(string ApellidoA){
        this->ApellidoA = CCipher(1, ApellidoA);
    }

    void setApellidoB(string ApellidoB){
        this->ApellidoB = CCipher(1, ApellidoB);
    }

    
    //No Encriptados   
    void setTelefono(int Telefono){
        this->Telefono = Telefono;
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
        void setNacimiento(string Nacimiento){this-> Nacimiento = Nacimiento;}
        void setDiaNacimiento(int DiaNacimiento){this-> DiaNacimiento = DiaNacimiento;}
        void setMesNacimiento(int MesNacimiento){this-> MesNacimiento = MesNacimiento;}
        void setAñoNacimiento(int AñoNacimiento){this->AñoNacimiento = AñoNacimiento;}
        void setEdad(int Edad){this->Edad = Edad;}
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

        // Metodos Get:
            string getNacimiento(){return this->Nacimiento;}
            int getDiaNacimiento(){return this->DiaNacimiento;}
            int getMesNacimiento(){return this->MesNacimiento;}
            int getAñoNacimiento(){return this->AñoNacimiento;}
            double getIMS(){return this->IMS;}
            int getEdad(){return this->Edad;}
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


        // Metodo Vacio
        PACIENTE(){}

        // Destructor
        ~PACIENTE(){}
};

class EXPEDIENTE : public PACIENTE{
    protected:
    int NumeroHistoria;
    string Tratamiento;
    string EnfermedadActual1;

    public:
    //Constructor:
    EXPEDIENTE(int NumeroHistoria, string Tratamiento, string EnfermedadActual1){
        this->NumeroHistoria = NumeroHistoria;
        this->Tratamiento = Tratamiento;
   //     this->EnfermedadActual = EnfermedadActual;
    }

    //Metodos Set:
    void setNumeroHistoria(int NumeroHistoria){this-> NumeroHistoria = NumeroHistoria;}
    void setTratamiento(string Tratamiento){this-> Tratamiento = Tratamiento;}
    void setEnfermedadActual1(string EnfermedadActual1){this->EnfermedadActual1 = EnfermedadActual1;}

    //Metodos Get:
    int getNumeroHistoria(){return this->NumeroHistoria;}
  

    std::string getTratamientoCompleto() {
       return this->Tratamiento;
    }

        std::string getTratamiento() const {
        return Tratamiento;
    }

            std::string getEnfermedadActual1() const {
        return EnfermedadActual1;
    }
   // string getEnfermedadActual(){return this->EnfermedadActual;}

    //Metodo sin nada.
    EXPEDIENTE(){}

    //Destructor
    ~EXPEDIENTE(){}
};

void buscarExpediente(){
    fstream file;
    string address = "Datos_Expedientes.txt";
    file.open(address, fstream::in);
    string Nombre, Apellido, Identidad, gruposanguieno, Antencedentes;
   int Numerobuscar;
   std::cout << "Numero:" << '\n';
   std::cin >> Numerobuscar ;
    int numero, Altura, Peso, IMS;
    file >>numero>> Nombre >> Apellido >> Identidad >> Altura >> Peso >> IMS >> gruposanguieno >>  Antencedentes;
    while (!file.eof()) {
        if (Numerobuscar == numero) {
            
            std::cout << "encontrado" << '\n';
        } else {
            std::cout << "no encontrado" << '\n';
        }
        file >>numero>> Nombre >> Apellido >> Identidad >> Altura >> Peso >> IMS >> gruposanguieno >>  Antencedentes;
    } 

}

class MEDICO : public PERSONA{
    protected:
    string Especialidad;
    string NumeroColegiado;
    double Tarifa= 0.00;
    string Constraseña;
    
    
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

    void setConstraseña(string Constraseña){
        this->Constraseña = Constraseña;
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
        string getConstraseña(){
        return this->Constraseña = Constraseña;
    }

    bool login(const std::string& username, const std::string& password) {
        // Verificar las credenciales del usuario
        return (username == "Monica" && password == "xl23");
    }

    //Metodo sin nada.
    MEDICO(){}
    
    //Destructor
    ~MEDICO(){}

     void ListaMedicos(){
         fstream file; 
         string address = "ListaMedicos.txt"; 
       
        MEDICO doctor1("Endocrinologo", "41048-4", 600.0);
        doctor1.setNombre("Monica");
        doctor1.setTelefono(1234567);
        doctor1.setApellidoA("Lopez");
        doctor1.setIdentidad("0801-1972-9897");
        doctor1.setTarifa(600);
    

        MEDICO doctor2("Gastroenterologo", "56945-6", 1500.0);
        doctor2.setNombre("Arturo");
        doctor2.setTelefono(1234567);
        doctor2.setApellidoA("Diaz");
        doctor2.setIdentidad("0801-1989-5697");
        doctor2.setNumeroColegiado("56945-6");
        doctor2.setTarifa(1500);
        doctor2.setEspecialidad("Gastroenterologo");

        file.open(address, fstream::out);
        if(file.is_open()){

        //APERTURA

        file << "Nombre    Apellido   Identidad         Telefono    NumeroColegiado   Tarifa   Especialidad" << std::endl;

        //Nombre
            file << doctor1.getNombre() << '\t'<< "  ";
        //ApellidoA
            file << doctor1.getApellidoA() << '\t'<< "     ";
        //IDENTIDAD
            file <<  doctor1.getIdentidad() << '\t'<< "";
        //TELEFONO
            file <<  doctor1.getTelefono() << '\t'<< "      ";
        //NumeroColegiado
            file <<  doctor1.getNumeroColegiado() << '\t'<< "      ";
        //Tarifa  
            file <<  doctor1.getTarifa() << "     ";
        //Especialidad
            file <<  doctor1.getEspecialidad() << '\t'<< endl;  
        //DOCTOR 2  
        //Nombre 
           file << doctor2.getNombre() << '\t'<< "  ";
        //ApellidoA
           file << doctor2.getApellidoA() << '\t'<< "     ";
        //IDENTIDAD
            file <<  doctor2.getIdentidad() << '\t'<< ""; 
        //TELEFONO
           file <<  doctor2.getTelefono() << '\t'<< "      ";
        //NumeroColegiado
          file <<  doctor2.getNumeroColegiado() << '\t'<< "      ";
        //Tarifa 
          file <<  doctor2.getTarifa() << "    ";
        //Especialidad
         file <<  doctor2.getEspecialidad() << '\t'<< endl;
            file.close();  
        }    
}


void displayListMedicos() {
    fstream file;
    string address = "ListaMedicos.txt";

    file.open(address, fstream::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } 
    }

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
    std::cout << "NUEVO PACIENTE \n\t -new, -nuevo, -new patient, -nuevo paciente" << std::endl;
    std::cout << "VER TODOS LOS PACIENTES \n\t -all, -todos" << std::endl;
    std::cout << "SELECCIONAR PACIENTE \n\t -select (Selecciona un paciente)." << std::endl;
    std::cout << "DELETE \n\t -delete Elimina un paciente. (primero seleccione un paciente)." << '\n';
    std::cout << "EDIT \n\t -edit Edita un paciente. (primero seleccione un paciente)." << '\n';
    std::cout << "\t Puede buscar pacientes por: Identidad, Nombre y Apellido(s), Telefono." << std::endl;
    std::cout << "LISTA DE MEDICOS \n\t -Listmedico, -listmedico (Muestra la lista de medicos)." << std::endl;
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

int ContarRegistrosNuevos(string address){
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
    totalregistros = ContarRegistrosNuevos("Datos_Pacientes.txt");
    if(totalregistros > 0){
        totalregistros ++;
    }
    else{
        totalregistros = 1;
        // totalregistros ++;
    }
    return totalregistros; 
}

int AsignarIDNuevos(){
    int totalregistros;
    totalregistros = ContarRegistros("Datos_Pacientestemp.txt");
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
            P1.CalcularEdad();
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

            file << '\n';
        file.close();
    }
}

//Leer el archivo, Y luego Imprimir en Pantalla
void ImprimirPaciente() {  
    fstream file; string address = "Datos_Pacientes.txt"; string line;
    file.open(address, fstream::in);
    if(file.is_open()){
        while(getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
    }
}  

//1.Vacia los Vectores. 2. Mete datos de Datos_Paciente.txt a los Vectores correspondientes.
void EscanearPaciente(){
    //Vaciar Vectores
    VRegistro.clear(); VNombre.clear(); VApellidoA.clear(); VApellidoB.clear(); VIdentidad.clear(); VTelefono.clear(); VDiaNacimiento.clear(); VMesNacimiento.clear(); VAñoNacimiento.clear(); VEdad.clear(); VAltura.clear(); VPeso.clear(); VIMS.clear(); VGrupoSanguineo.clear(); VAntecedentes.clear();

    fstream file; string address;
    address = "Datos_Pacientes.txt";
    file.open(address, fstream::in);
    if(file.is_open()){
        int Registro; string Nombre; string ApellidoA; string ApellidoB; string Identidad; int Telefono; 
        int DiaNacimiento; int MesNacimiento; int AñoNacimiento; int Edad; double Altura; double Peso; double IMS; string GrupoSanguineo; string Antecedentes;
        
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

void CopiarDatos_Pacientes(){
    EscanearPaciente();
    int size = VNombre.size();
    std::cout << size << '\n';

    fstream file; string address = "Datos_Expedientes.txt";

    file.open(address, fstream::out);
    if(file.is_open()){
        for(int i = 0; i < size; i++){
            file << VRegistro[i] << ' ' << VNombre[i] << ' ' << VApellidoA[i] << ' ' << VApellidoB[i] << ' ' << VIdentidad[i] << ' ' << VTelefono[i] << ' ' << VDiaNacimiento[i] << ' ' << VMesNacimiento[i] << ' ' << VAñoNacimiento[i] << ' ' << VEdad[i] << ' ' << VAltura[i] << ' ' << VPeso[i] << ' ' << VIMS[i] << ' ' << VGrupoSanguineo[i] << ' ' << VAntecedentes[i] << std::endl;
        }
        file.close();
    }
}

//Opcion 1 de -select:
void Buscar_Por_Identidad(string buscar){
    for(int i = 0; i < VIdentidad.size(); i ++){
        if(buscar == VIdentidad[i]){
            index = i;
            break;
        }   
    }
    if(index != -1){
        //Found User! :)
            std::cout << " - $ Se encontro al paciente: ";
            std::cout << VIdentidad[index] << " -> " << VNombre[index] << ' ' << VApellidoA[index] << ' ' << VApellidoB[index] << " Tel. "  << VTelefono[index] << '\n';
    
    }
    else{
        //Not Found :(
            std::cout << "- $ No se encontro a: " << buscar << '\n';
    }
}

//Opcion 2 de -select:
void Buscar_Por_Nombre(string buscar, string buscarA, string buscarB){
    for(int i = 0; i < VNombre.size(); i ++){
        if((buscar == VNombre[i]) && (buscarA == VApellidoA[i]) && (buscarB == VApellidoB[i])){
            index = i;
            
        }   
    }
    if(index != -1){
        //Found User! :)
            std::cout << " - $ Se encontro al paciente: ";
            std::cout << VIdentidad[index] << " -> " << VNombre[index] << ' ' << VApellidoA[index] << ' ' << VApellidoB[index] << " Tel. "  << VTelefono[index] << '\n';
    }
    else{
        //Not Found :(
            std::cout << "- $ No se encontro a: " << buscar << ' ' << buscarA <<  ' ' << buscarB << '\n';
    }
}

//Opcion 3 de -select:
void Buscar_Por_Nombre(string buscar, string buscarA){
    for(int i = 0; i < VNombre.size(); i ++){
        if((buscar == VNombre[i]) && (buscarA == VApellidoA[i])){
            index = i;
            
        }   
    }
    if(index != -1){
        //Found User! :)
            std::cout << " - $ Se encontro al paciente: ";
            std::cout << VIdentidad[index] << " -> " << VNombre[index] << ' ' << VApellidoA[index] << ' ' << VApellidoB[index] << " Tel. " << VTelefono[index] << '\n';
    
    }
    else{
        //Not Found :(
            std::cout << "- $ No se encontro a: " << buscar << ' ' << buscarA <<  ' ' << '\n';
    }
}

//Opcion 4 de -select:
void Buscar_Por_Telefono(int ibuscar){
    for(int i = 0; i < VTelefono.size(); i ++){
        if((ibuscar == VTelefono[i])){
            index = i;
            break;
        }   
    }
    if(index != -1){
        //Found User! :)
            std::cout << " - $ Se encontro al paciente: ";
            std::cout << VIdentidad[index] << " -> " << VNombre[index] << ' ' << VApellidoA[index] << ' ' << VApellidoB[index] << " Tel. " << VTelefono[index] << '\n';
    
    }
    else{
        //Not Found :(
            std::cout << "- $ No se encontro a: " << ibuscar << '\n';
    }
}
int ObtenerHoraActual() {
  
    time_t tiempoActual = time(0);

 
    tm* tiempoLocal = localtime(&tiempoActual);

   
    int hora = tiempoLocal->tm_hour;

    // Retornar la hora actual
    return hora;
}
int ObtenerMinutosActuales() {
    
    time_t tiempoActual = time(0);

   
    tm* tiempoLocal = localtime(&tiempoActual);

    
    int minutos = tiempoLocal->tm_min;

   
    return minutos;
}


void CrearHistoriaClinica(){

    //Variables/Instancias/Objetos
    EXPEDIENTE Historia; int NumeroHistoria = 8; string stemp;
    fstream file; string address = "Datos_Expediente.txt";
    
    Historia.setNumeroHistoria(NumeroHistoria);
    

    
    file.open(address, fstream::app);
    if(file.is_open()){
        
        //hora de la proxima cita
        std::cout << "La cita finalizo a las "<< ObtenerHoraActual() <<":"<< ObtenerMinutosActuales() <<  '\n';
        

        //Enfermedad Actual:
        std::cout << " - $ Enfermedad Actual: " <<  '\n';
        cin >> stemp; 
        Historia.setEnfermedadActual1(stemp);
        
        //Tratamiento:
        std::cout << " - $ Tratamiento: " <<  '\n';
        cin >> stemp; 
        Historia.setTratamiento(stemp);


        


        //Guardar todo en el archivo.
        file<< VRegistro[index] << ' '<< VNombre[index] << ' ' << VApellidoA[index] << ' ' << VApellidoB[index] << ' ' << VIdentidad[index] << ' ' << VTelefono[index] << ' ' << VDiaNacimiento[index] << ' ' << VMesNacimiento[index] << ' ' << VAñoNacimiento[index] << ' ' << VEdad[index] << ' ' << VAltura[index] << ' ' << VPeso[index] << ' ' << VIMS[index] << ' ' << VGrupoSanguineo[index] << ' ' << VAntecedentes[index] << ' ' << Historia.getEnfermedadActual1()<< ' ' <<Historia.getTratamiento()<< ' '<< ObtenerHoraActual()<<":"<<ObtenerMinutosActuales()<< '\n';
        
        //Cerrar archivo
        system("cls"); //(Limpiar pantalla)
        std::cout << " > Expediente agregado exitosamente!" << '\n';
        file.close(); 
    }
}

void VerHistoriaClinica(){
    std::cout << "Esta funcion esta vacia." << '\n';
}




// Transferir de un archivo a otro.
void Transfer(string addressA, string addressB){
    fstream fileA, fileB;
    string line;
    fileA.open(addressA, fstream::in);
    fileB.open(addressB, fstream::out);
    
    if(fileA.is_open() && fileB.is_open()){
        
        while(std::getline(fileA, line)){
            fileB << line << '\n';
        }

        fileA.close(); fileB.close();
    }


}
     

//Eliminar Pacientes
void EliminarPacientes(){
    fstream file; fstream ftemp;
    string address = "Datos_Pacientes.txt";
    string address_temp = "Datos_Pacientestemp.txt";

    char respuesta; bool del=false;
    cout << "Esta seguro de que desea eliminar este usuario? (S/N): " << endl; cin >> respuesta;
    (respuesta == 'S' || respuesta == 's') ? del=true: del=false;

    //Sacar de los vectores.
    if(del==true){
        VRegistro.erase(VRegistro.begin()+index);
        VNombre.erase(VNombre.begin()+index);
        VApellidoA.erase(VApellidoA.begin()+index);
        VApellidoB.erase(VApellidoB.begin()+index);
        VIdentidad.erase(VIdentidad.begin()+index);
        VTelefono.erase(VTelefono.begin()+index);
        VDiaNacimiento.erase(VDiaNacimiento.begin()+index);
        VMesNacimiento.erase(VMesNacimiento.begin()+index);
        VAñoNacimiento.erase(VAñoNacimiento.begin()+index);
        VEdad.erase(VEdad.begin()+index);
        VAltura.erase(VAltura.begin()+index);
        VPeso.erase(VPeso.begin()+index);
        VIMS.erase(VIMS.begin()+index);
        VGrupoSanguineo.erase(VGrupoSanguineo.begin()+index);
        VAntecedentes.erase(VAntecedentes.begin()+index);

        //Guardar en archivo temporal.
        ftemp.open(address_temp, fstream::out);
        if(ftemp.is_open()){  
            for (int i = 0; i < VRegistro.size(); ++i) {
                ftemp << VRegistro[i] << ' ';
                ftemp << VNombre[i] << ' ';
                ftemp << VApellidoA[i] << ' ';
                ftemp << VApellidoB[i] << ' ';
                ftemp << VIdentidad[i] << ' ';
                ftemp << VTelefono[i] << ' ';
                ftemp << VDiaNacimiento[i] << ' ';
                ftemp << VMesNacimiento[i] << ' ';
                ftemp << VAñoNacimiento[i] << ' ';
                ftemp << VEdad[i] << ' ';
                ftemp << VAltura[i] << ' ';
                ftemp << VPeso[i] << ' ';
                ftemp << VIMS[i] << ' ';
                ftemp << VGrupoSanguineo[i] << ' ';
                ftemp << VAntecedentes[i] << std::endl;
            }
            Transfer("Datos_Pacientestemp.txt", "Datos_Pacientes.txt");
            file.close();
        }
    }
    else{
        std::cout << "No se eliminaron pacientes." << '\n';
    }

}
             
                   
void EditarPacientes(){
    fstream file; fstream ftemp;
    string address = "Datos_Pacientes.txt";
    string address_temp = "Datos_Pacientestemp.txt";
    PACIENTE P1;
     
    //Editar Instancias/
    int itemp; string stemp; double dtemp;
    std::cout << "Editar Nombre de " << VNombre[index] << '\n';
    cin >> stemp;   VNombre[index] = stemp;
    std::cout << "Editar Primer Apellido " << VApellidoA[index] << '\n';
    cin >> stemp;   VApellidoA[index] = stemp;
    std::cout << "Editar Segundo Apellido " << VApellidoB[index] << '\n';
    cin >> stemp;   VApellidoB[index] = stemp;
    std::cout << "Editar Identidad: "<< VIdentidad[index] << '\n';
    cin >> stemp;   VIdentidad[index] = stemp;
    std::cout << "Editar Telefono: "<< VTelefono[index] << '\n';
    cin >> itemp; VTelefono[index];
    std::cout << "Editar Altura: "<< VAltura[index] << '\n';
    cin >> dtemp;   P1.setAltura(dtemp);    VAltura[index] = dtemp;
    std::cout << "Editar Peso: "<< VPeso[index] << '\n';
    cin >> dtemp;   P1.setPeso(dtemp);  VPeso[index] = dtemp; 
    dtemp = VIMS[index];
    VIMS[index] = P1.getIMS();       
    std::cout << "Se recalculo el indice de masa corporal. Paso de "<< dtemp << " a " << VIMS[index] << "."<< '\n';
    std::cout << "Editar Grupo Sanguineo: "<< VGrupoSanguineo[index] << '\n';
    cin >> stemp; VGrupoSanguineo[index] = stemp;
    std::cout << "Editar Antecedentes: "<< VAntecedentes[index] << '\n';
    cin >> stemp;   VAntecedentes[index] = stemp;




    //Guardar en archivo temporal.
    ftemp.open(address_temp, fstream::out);
    if(ftemp.is_open()){  
        for (int i = 0; i < VRegistro.size(); ++i) {
            ftemp << VRegistro[i] << ' ';
            ftemp << VNombre[i] << ' ';
            ftemp << VApellidoA[i] << ' ';
            ftemp << VApellidoB[i] << ' ';
            ftemp << VIdentidad[i] << ' ';
            ftemp << VTelefono[i] << ' ';
            ftemp << VDiaNacimiento[i] << ' ';
            ftemp << VMesNacimiento[i] << ' ';
            ftemp << VAñoNacimiento[i] << ' ';
            ftemp << VEdad[i] << ' ';
            ftemp << VAltura[i] << ' ';
            ftemp << VPeso[i] << ' ';
            ftemp << VIMS[i] << ' ';
            ftemp << VGrupoSanguineo[i] << ' ';
            ftemp << VAntecedentes[i] << std::endl;
        }
        Transfer("Datos_Pacientestemp.txt", "Datos_Pacientes.txt");
        file.close();
        }
    
    else{
        std::cout << "No se eliminaron pacientes." << '\n';
    }


}



void MedicoLogin(){





    fstream file;   vector<string> users;   vector<string> passwords;   MEDICO doctor1;
    string stemp;   string USER; string PASSWORD;   bool login = false; bool MantenerLoop = true;


    while(MantenerLoop == true){
        std::cout << "Nombre usuario" << '\n';
        cin >> stemp;
        doctor1.setNombre(stemp);
        std::cout << "Password: " << '\n';
        cin >> stemp;
        doctor1.setConstraseña(stemp);



            file.open("credenciales.txt", fstream::in);
            if(file.is_open()){
                file >> USER >> PASSWORD;
                users.push_back(USER);
                passwords.push_back(PASSWORD);
                file.close();
            }



   for(auto i = users.begin(); i != users.end(); ++i)
    if((*i == doctor1.getNombre()) && (passwords[i - users.begin()] == doctor1.getConstraseña())){
        MantenerLoop = false;
    }
    else{
        MantenerLoop = true;
    }
    }
       MantenerLoop = false;
}


void MedicoLogin(){

    fstream file;   vector<string> users;   vector<string> passwords;   MEDICO doctor1;
    string stemp;   string USER; string PASSWORD;    bool MantenerLoop = true;


    while(MantenerLoop == true){
        std::cout << "Nombre usuario" << '\n';
        cin >> stemp;
        doctor1.setNombre(stemp);
        std::cout << "Password: " << '\n';
        cin >> stemp;
        doctor1.setConstraseña(stemp);


        //Recorrer Archivo
        file.open("credenciales.txt", fstream::in);
        if(file.is_open()){
            file >> USER >> PASSWORD;
            users.push_back(USER);
            passwords.push_back(PASSWORD);
            file.close();
        }

        //Comparar Vectores
        for(auto i = users.begin(); i != users.end(); ++i)
            if((users == doctor1.getNombre()) && (passwords == doctor1.getConstraseña())){
                MantenerLoop = false;
            }
            else{
                MantenerLoop = true;
            }

        }
}


           
        

int main() {
    
    MEDICO Instancia;
    Instancia.ListaMedicos();
    
     
    // Variables temporales reutilizables: itemp->var temporales de tipo int | stemp -> var temporales tipo string.
    int itemp; string stemp;

    //Despliega una pantalla de bienvenida de un medicamento y un gatito.
    DisplayWelcome();
    
    //Ajustar la precision de la salida que se muestra en las variables double.
    cout << fixed << setprecision(2) << setw(10); 
   
    //El usuario puede buscar por identidad, nombre, apellido y telefono. Aqui se guarda ese valor.
    string buscar, buscarA, buscarB; int ibuscar;
        std::string username, password;

    bool loginExitoso = false;
    /*
    
    // Solicitar al usuario que inicie sesión hasta que las credenciales sean válidas
    while (!loginExitoso) {
        std::cout << "Ingrese su nombre de usuario: ";
        std::cin >> username;
        std::cout << "Ingrese su contrasena: ";
        std::cin >> password;

        // Intentar iniciar sesión utilizando las credenciales ingresadas
        if (Instancia.login(username, password)) {
            loginExitoso = true;
            system("cls");
            std::cout << "Inicio de sesion exitoso. Bienvenida, " << username << "!" << std::endl;
        } else {
            std::cout << "Credenciales incorrectas. Por favor, intente nuevamente." << std::endl;
        }
    }
*/
    

    MedicoLogin();


    //Menu
    bool MantenerBucle = true; 
    while (MantenerBucle == true){
        std::cout << " - $ ";
        cin >> UserInput;
        
        //-new -> Crear un nuevo Paciente 
        if(UserInput == "-new" || UserInput=="-nuevo" || UserInput == "-new patient" || UserInput=="-nuevo paciente" || UserInput == "new" || UserInput == "nuevo"){
            CrearUsuario();
            MantenerBucle = true;
        }
        
        //-all -> Desplegar todos los pacientes 
        else if(UserInput == "-all" || UserInput=="-todos" || UserInput == "all" || UserInput == "todos"){
            std::cout << "Mostrando todos los pacientes:" << '\n';
            ImprimirPaciente();
            MantenerBucle = true;
        }

        //-help -> Desplegar ayuda 
        else if(UserInput=="-help" || UserInput=="--help" || UserInput=="help"){
            DisplayHelp();
            MantenerBucle = true;
        }

        //-exit -> Salir del programa
        else if(UserInput=="-exit" || UserInput=="-salir" || UserInput=="exit()" || UserInput=="exit" || UserInput=="salir"){   
            MantenerBucle = false;
        }

        // -version -> Mostrar Version
        else if(UserInput=="-version" || UserInput=="--version"){
            std::cout << "Version " << vrs << '\n';
            MantenerBucle = true;
        }

        // -listmedico -> Mostrar lista de medicos
        else if(UserInput=="-listmedico" || UserInput=="-Listmedico"){
            Instancia.displayListMedicos();
            MantenerBucle = true;
        }

        //-clear -> Limpiar la pantalla
        else if(UserInput=="clear" || UserInput=="cls"){
            system("cls");
            MantenerBucle = true;
        }

        // -select -> Buscar un paciente
        else if(UserInput=="-select" || UserInput=="-seleccionar" || UserInput=="-search" || UserInput=="-buscar"){     
            std::cout << "Seleccione un metodo de busqueda:" << '\n';
            std::cout << "1. Identidad" << '\n';
            std::cout << "2. Nombre ApellidoA ApellidoB" << '\n';
            std::cout << "3. Nombre ApellidoA" << '\n';
            std::cout << "4. Telefono" << '\n';
            itemp = 0; cin >> itemp;
            
            //Formas de buscar un paciente:
            //Opcion 1. Identidad:
            if(itemp==1){
                EscanearPaciente();
                std::cout << "Ingrese la identidad del paciente: " << std::endl;
                cin>>buscar;
                Buscar_Por_Identidad(buscar);
            }
            //Opcion 2. Nombre ApellidoA ApellidoB:
            else if(itemp==2){
                EscanearPaciente();
                std::cout << "Ingrese el Nombre ApellidoA ApellidoB del paciente a buscar (separado de un espacio): " << std::endl;
                cin>>buscar >> buscarA >> buscarB;
                Buscar_Por_Nombre(buscar, buscarA, buscarB);
            }
            //Opcion 3. Nombre ApellidoA:
            else if(itemp==3){
                EscanearPaciente();
                std::cout << "Ingrese el Nombre ApellidoA del paciente a buscar (separado de un espacio): " << std::endl;
                cin>>buscar >> buscarA;
                Buscar_Por_Nombre(buscar, buscarA);
            }
            //Opcion 4. Telefono:
            else if(itemp==4){
                EscanearPaciente();
                std::cout << "Ingrese el Telefono: " << std::endl;
                cin>> ibuscar;
                Buscar_Por_Telefono(ibuscar);
            }

            //Buscar un paciente -search o -select
            std::cout << "Ahora puede hacer lo siguiente:"<< '\n'; 
             std::cout << "\t -newh (Nueva historia clinica.)" <<std::endl;
            // std::cout << "\t -verh (Ver historias clinicas de un paciente.)" <<std::endl;
            std::cout << "\t -delete (Eliminar el paciente seleccionado)" << '\n';
            std::cout << "\t -edit (Edita el paciente seleccionado)" << std::endl;                          
            MantenerBucle = true;
        }

        

                // Una vez seleccionado el paciente:
                //-newh -> Nueva historia clinica
                else if(UserInput=="-newh"){
                    std::cout << " - $ Crear Historia clinica." << '\n';
                    CrearHistoriaClinica();
                    MantenerBucle = true;
                }

                //-verh -> Ver Historias Clinicas del paciente
                else if(UserInput=="-verh"){
                    std::cout << " - $ Ver Historia Clinica" << '\n';
                    VerHistoriaClinica();
                    MantenerBucle = true;
                }

                // EliminarPacientes
                else if(UserInput=="-delete"){
                    std::cout << " - $ Eliminar Paciente" << '\n';
                    EliminarPacientes();
                    MantenerBucle = true;
                }
                
                // Editar Pacientes
                else if(UserInput=="-editar" || UserInput=="-edit"){
                    std::cout << " - $ Editar Paciente" << '\n';
                    EditarPacientes();
                    MantenerBucle = true;
                }


        
        
        
            //Error, comando no reconocido.
            else{
                std::cout << "El comando " << UserInput << "no es un comando reconocido. \nUtilice -help o --help para mostrar todos los comandos disponibles." << '\n';
                MantenerBucle = true;
            }
    }
    
    
    //Fin del Codigo
    return 0;
}
