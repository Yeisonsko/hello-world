int contacto = 2;                     //pin del reed switch
int led = 13;                         //pin del led

void setup() {
  pinMode(contacto, INPUT);           //reed switch entrada
  pinMode(led, OUTPUT);               //led salida
}

void loop() {
  if(digitalRead(contacto) == HIGH){  //Si deja de detectar el imán inicia secuencia
    for(int i = 0; i < 10; i++){      //Secuencia para que:
      digitalWrite(led, HIGH);        //el led parpadee 10 veces y tenga pausas de 200
      tone(3,440,1000);               //buzzer suena 10 veces y tenga pausas de 200
      delay(200);                     //el buzzer y el led comparten el mismo pin
      digitalWrite(led, LOW);
      delay(200);
  }
  }else{
    digitalWrite(led, LOW);           //condición contraria se detiene secuencia
      tone(3,0,0);
  }
}

