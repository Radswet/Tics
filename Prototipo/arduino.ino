#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorSalida 8

int Rojo_Frec = 0;
int Verde_Frec = 0;
int Azul_Frec = 0;

void setup() {
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorSalida, INPUT);    
                            // Configura la escala de Frecuencia en 20%
    digitalWrite(S0,HIGH);
    digitalWrite(S1,LOW);
    
    Serial.begin(9600);
}

void loop() {
                          // Configura el filtor ROJO para tomar lectura
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    delay(100);
    Rojo_Frec= pulseIn(sensorSalida, LOW);
    Serial.print(" R= "); Serial.print(Rojo_Frec);
    delay(100);
                                // Configura el filtor VERDE para tomar lectura
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    delay(100);
    Verde_Frec = pulseIn(sensorSalida, LOW);
    Serial.print(" V= "); Serial.print(Verde_Frec);
    delay(100);
                            // Configura el filtor AZUL para tomar lectura
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    delay(100);
    Azul_Frec = pulseIn(sensorSalida, LOW);
    Serial.print(" A= "); Serial.print(Azul_Frec);
    delay(100);

                  //Valores obtenidos en la calibracion del sensor, son propios de cada usuario 
                  
    if (Rojo_Frec < 35 && Verde_Frec < 35 && Azul_Frec < 35)  Serial.print(" . *** BLANCO **");
    else Serial.print(" . *** COLOR **");

    Serial.println("*");
    delay(200);
}