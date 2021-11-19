// Código basado en:
// https://lastminuteengineers.com/stepper-motor-l293d-arduino-tutorial/



/* CARGAR UNA LIBRERIA "Stepper.h" PARA CONTROLAR EL STEPPER */

// Leer más al respecto en:
// https://www.arduino.cc/reference/en/libraries/stepper/
#include <Stepper.h>



/* DEFINIR VARIABLES DEL PROGRAMA */

// Número de pasos por revolución:
const int pasosPorRev = 4;
const int velocidadRPM = 16;

// Pins para la primera bobina del stepper: A
int coilA1 = 9;
int coilA2 = 10;
// Pins para la segunda bobina del stepper: B
int coilB1 = 11;
int coilB2 = 12;

// La librería Stepper provee una forma abstracta (simple) de controlar
// motores paso a paso. La siguiente crea un "objeto" que en abstracto
// representa al microservo dentro del programa.
// y nos permite controlarlo más fácilmente.
// Para crearlo, solamente tenemos que decirle en que pins
// conectamos cada cable, de cada bobina del stepper:
Stepper myStepper(pasosPorRev, coilA1, coilA2, coilB1, coilB2);



/* CONFIGURAR EL ARDUINO */

void setup()
{
  // Configuramos el stepper para que gire a cierta velocidad
  // En RPMs:
  myStepper.setSpeed(velocidadRPM);

  // Configurar mensajes que el arduino nos enviará
  // a traves del "serial monitor":
  Serial.begin(9600);
}



/* PROGRAMAR EL CONTROL */

void loop()
{
	// Dar una vuelta en dirección de las agujas del reloj.
    // Sabemos que es una vuelta, porque le estamos diciendo
    // que haga una cantidad de pasos igual a la que
    // hay en una vuelta completa:
	myStepper.step(pasosPorRev);
    Serial.println("Sentido horario");
	delay(1000*30);

	// Lo mismo que antes, pero en el otro sentido
    // cambiándole el signo a la cantidad de pasos:
	myStepper.step(-pasosPorRev);
    Serial.println("Sentido anti-horario");
	delay(1000*30);
}
