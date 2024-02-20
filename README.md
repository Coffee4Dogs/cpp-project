# Proyecto C++
## ![c++](https://github.com/Coffee4Dogs/cpp-project/assets/59121551/d9c9e5c2-343d-4cc6-9cb0-9b24905a62f0) Listado de pacientes a atender por un médico.

## Diagrama CRC
![Diagrama CRC](https://github.com/Coffee4Dogs/cpp-project/assets/59121551/3d18620a-88a7-4620-b898-e6c31adce207)

## Atributos:
CLASE PERSONA: Identidad, Teléfono, Nombre, ApellidoA, ApellidoB
CLASE PACIENTE: DiaNacimiento, MesNacimiento, AñoNacimiento, Edad Altura(m), Peso (KG), IMS (Índice de Masa Corporal), TipoSangre, DiaCita, HoraCita, Antecedentes, Enfermedad Actual (Motivo Consulta), Direccion
CLASE ACOMPAÑANTE: RelacionPaciente, Autorizacion
CLASE MÉDICO: Especialidad, numeroColegiado, tarifa
CLASE EXPEDIENTE: IDExpediente
CLASE PRECIO_CITA:  TotalCita
Nota: PRECIO_CITA será agregada opcionalmente según la complejidad del programa


## Descripción de las clases: 
CLASE PERSONA: Define lo que es una Persona en la vida real. En la vida real podemos encontrar varios tipos de personas. El médico, El paciente, El acompañante del paciente, etc. 
CLASE PACIENTE: La clase PACIENTE puede verse como el “Perfil”del paciente. Contiene toda la información del paciente, sus enfermedades, su edad, su Índice de Masa Corporal, Su Nombre, Apellidos, Identidad, Contactos, Dirección, y se relaciona con los Expedientes.
CLASE ACOMPAÑANTE: Consideramos que la clase ACOMPAÑANTE podría ser una buena propuesta para reducir código. La razón por la que se tomó esta decisión es porque todo PACIENTE podría tener un acompañante. En algunos casos es importante tener un número de emergencia para contactar a alguien en caso de emergencia aparte del paciente. Por eso el acompañante ya hereda el Número, Nombre, y Apellidos. La forma en cómo se va a enlazar es con la Identidad. En caso de ser necesario podríamos crear otros atributos o lógica para que se conecten.
CLASE MÉDICO: Mantiene un sistema de registro para los médicos con usuarios (User), contraseñas (Password) y muestra la lista de pacientes que tiene que atender cada Médico al día según su hora de cita.  
CLASE EXPEDIENTE: Esta clase agrega expedientes con un nuevo número de Registro de Expediente que el doctor/médico agrega cuando el paciente se presente con una nueva enfermedad cada vez que se presente en la consulta.


## Métodos:
# CLASE PACIENTE:
-CalcularEdad() Este método tiene la función de calcular la edad con los atributos DiaNacimiento, MesNacimiento, AñoNacimiento.
-CalcularIMC() Este método toma los metros, los convierte a metros cuadrados, y luego divide los Kilogramos / los Metros Cuadrados para sacar el Índice de Masa Corporal (IMC).
-AgregarAntecedentes(EnfermedadActual) Una vez creado el expediente, tomara del expediente el valor que está en EnfermedadActual, y lo agregara en Antecedentes. Antecedentes nos dará un total de todas las enfermedades que tiene el paciente.
-EnfermedadActual() Aquí se actualiza la enfermedad actual basada en el último número de expediente.

# CLASE ACOMPAÑANTE: 
-SetAcompañante()  Establecer los datos del acompañante.

# CLASE MÉDICO:
 -BuscarPacientesNombre() Mostrar la lista de Pacientes (Perfiles) según un parámetro (Nombre).
-BuscarPacientesIdentidad() Mostrar la lista de Pacientes (Perfiles) según un parámetro (Nombre).
-OrdenarPacientesCita() Ordenar los pacientes que tienen cita el día de “hoy” (hipotéticamente hablando) según su hora de cita. El método toma como atributo el Día y Hora de la Cita.

# CLASE EXPEDIENTE: 
	-SetEnfermedadActual() Establece la Enfermedad Actual del paciente en el paciente.
# CLASE PRECIO_CITA:
    • CalcularPrecioCita() Hipotéticamente llamará el atributo del médico: tarifa y calculará el total de la cita.



## Descripción de problemas a resolver 

    • Ordenar pacientes según su hora de cita programada: Tenemos definido los atributos día y hora de la cita en nuestra lista de pacientes, entonces nuestro problema seria el como ordenar los datos, para ello tendremos que realizar un algoritmo que pueda ordenar la hora y así poder saber el orden de llegada de los pacientes, lo que nos lleva al segundo problema:

    • Registro de pacientes que no llegaron a la cita programada: Al no llegar un paciente tendríamos que reasignar una cita para dicho paciente, para ello no eliminaremos la cita si no que reasignaremos al paciente para un dia diferente o una hora que tengamos disponible, para ello, implementaremos una librería que sea consciente de la hora o día así podríamos saber por medio de la hora que paciente esta siendo atendido por el médico, luego haremos un espacio entre citas o reasignaremos a una hora totalmente distinta o día totalmente distinto.





