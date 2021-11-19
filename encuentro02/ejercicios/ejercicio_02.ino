/* CARGAR UNA LIBRERIA "Servo.h" PARA USAR EL SERVO */

// Leer más al respecto en:
// https://www.arduino.cc/reference/en/libraries/servo/
#include <Servo.h>



/* DEFINIR VARIABLES DEL PROGRAMA */

int potPin = 0;    // Equivalente a "A0"
int servoPin = 9;  // Pin (tipo PWM) donde conectamos el servo.
int sensorValue;   // Para guardar la señal del potenciómetro.
int valorAngulo;   // Para guardar el ángulo.
int anguloMaximo = 180;  // Angulo maximo de nuestro servo.

// La librería servo provee una forma abstracta (simple) de controlar
// el servo con código. La siguiente línea "define" una variable llamada "mi_servo"
// que representa al motor dentro del programa de forma abstracta, y nos
// permite controlarlo más sencillamente:
Servo mi_servo;



/* CONFIGURAR EL ARDUINO */

void setup (){
  // Configuramos el pin conectado al potenciómetro como "input".
  // Ver más en: https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
  pinMode(potPin, INPUT);

  // Acá especificamos en qué pin está conectado el servo.
  // Documentación: https://www.arduino.cc/reference/en/libraries/servo/attach/
  mi_servo.attach(servoPin);

  // Configurar mensajes que el arduino nos enviará
  // a traves del "serial monitor":
  Serial.begin(9600);
  // Enviar un mensaje de prueba:
  Serial.println("Señal de entrada (potenciometro), Señal de salida (angulo)");
}



/* PROGRAMAR EL CONTROL */

void loop(){

  // Leer la señal del potenciómetro.
  // Este valor es un número entero entre 0 y 1023.
  sensorValue = analogRead(potPin);

  // Convertir la señal del potenciometro (de 0 a 1023)
  // al rango de ángulos que puede girar el servo (0 1 180).
  valorAngulo = map(sensorValue, 0, 1023, 0, anguloMaximo-1);

  // Enviar señal para posicionar al servo
  // en el ángulo deseado, usando mi_servo.write()
  mi_servo.write(valorAngulo);

  // Esperemos a que el servo se mueva un poco
  // antes de enviarle otra instrucción.
  delay(50);

  // Imprimir señal del potenciómetro
  // y el valor de ángulo correspondiente
  // en el serial monitor (es solo para saber).
  Serial.print(sensorValue);
  Serial.print(", ");
  Serial.println(valorAngulo);
}

