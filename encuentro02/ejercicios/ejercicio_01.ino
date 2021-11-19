/* DEFINIR VARIABLES */

// Esta variable guarda el numero de pin donde esta conectado el potenciometro.
int potPin = A0;
// Esta variable guarda el numero de pin donde esta conectado el motor.
int motorPin = 9;

// Estas dos variables sirven para guardar valores utiles
// por ejemplo, el valor de la señal del potenciometro,
// o el valor de señal que querremos mandar al motor.
int sensorValue;
int outputValue;



/* CONFIGURAR ARDUINO */

void setup()
{
  // Configuramos el pin conectado al potenciómetro como "input".
  // Ver más en: https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
  pinMode(potPin, INPUT);

  // Configuramos el pin conectado al potenciómetro como "output".
  pinMode(motorPin, OUTPUT);

  // Configurar mensajes que el arduino nos enviará
  // a traves del "serial monitor":
  Serial.begin(9600);

  // Enviar un mensaje de prueba al serial monitor:
  Serial.println("Señal de entrada (potenciometro), Señal de salida (angulo)");
}



/* PROGRAMAR EL CONTROL */

void loop()
{
  // Leer la señal del potenciómetro.
  // Este valor es un número entero entre 0 y 1023.
  // Ver más en: https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
  sensorValue = analogRead(potPin);

  // Convertir la señal del potenciometro (de 0 a 1023)
  // al rango de pulsos PWM que generar el Arduino (de 0 a 255).
  // Ver más en: https://www.arduino.cc/reference/en/language/functions/math/map/
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // Configurar el PWM en el pin del motor
  // con el nuevo ancho de pulso.
  // Ver más en: https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
  analogWrite(motorPin, outputValue);

  // Mandar mensajes al serial monitor, con informaicón sobre
  // las señales de entrada y de salida:
  Serial.print("Señal de entrada (potenciometro) = ");
  Serial.print(sensorValue);
  Serial.print("     Señal de salida (PWM) = ");
  Serial.println(outputValue);

  // Esperemos a que el motor se estabilice un poco
  // antes de volver a empezar.
  delay(50);
}
