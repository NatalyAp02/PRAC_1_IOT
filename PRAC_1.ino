int DISTANCIA = 0;
int pinEco = 2; // Pin del sensor echo
int pinGatillo = 15; // Pin de trig del sensor
int led1 = 13;
int led2 = 12;
int led3 = 14;
int led4 = 27;

int led6 = 26;

long readUltrasonicDistance(int triggerPin, int echoPin) 
{
    // Configura el pin del sensor de ultrasonidos para enviar señales
    pinMode(triggerPin, OUTPUT);
    // Envía un pulso bajo para asegurarse de que el sensor esté listo
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Envía un pulso alto de 10 microsegundos para activar el sensor
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    // Desactiva el pulso del sensor
    digitalWrite(triggerPin, LOW);
    // Configura el pin del sensor para recibir señales
    pinMode(echoPin, INPUT);
    // Mide la duración del pulso de eco (el tiempo que tarda en regresar la onda ultrasónica)
    return pulseIn(echoPin, HIGH);
}

void setup() 
{
    Serial.begin(115200); // Inicializa la comunicación serial a 115200 bps
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
  //  pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
}

void loop()
{
    DISTANCIA = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
    // Imprime la distancia en el monitor serial
    Serial.print("Distancia: ");
    Serial.print(DISTANCIA);
    Serial.println(" cm");
    
    // Apagar todos los LEDs antes de encender el adecuado
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
   // digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    
    // Encender el LED correspondiente basado en la distancia
    if (DISTANCIA <= 10)
    {
        digitalWrite(led1, HIGH);
    }
    else if (DISTANCIA > 10 && DISTANCIA <= 14)
    {
      digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
    }
    else if (DISTANCIA > 14 && DISTANCIA <= 20)
    {
      digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
    }
    else if (DISTANCIA > 20 && DISTANCIA <= 26)
    {
      digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    }
    
    else if (DISTANCIA > 26 && DISTANCIA <= 35)
    {
      digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led6, HIGH);
    }
    
    delay(1000); // Espera 1 segundo antes de tomar otra medición
}
