  int ROJO_A = 2;                 //Declaracion de pines
  int AMARILLO_A = 3;
  int VERDE_A = 4;
  int VERDE_P = 5;
  int ROJO_P = 8;
  int PULS = 9;
  long VALOR;
  
void setup() {
  Serial.begin(9600);             //Inicializar entradas y salidas
  pinMode(ROJO_A, OUTPUT);
  pinMode(AMARILLO_A, OUTPUT);
  pinMode(VERDE_A, OUTPUT);
  pinMode(VERDE_P, OUTPUT);
  pinMode(ROJO_P, OUTPUT);
  pinMode(PULS, INPUT);
}

void loop() {
  VALOR = analogRead(A0);         //  Leemos el pin A0 valor
  SecuenciaNor();                 //  Metodo de secuencia normal de semaforo  
}

void SecuenciaNor(){
  digitalWrite(VERDE_A, HIGH);    //  Prende verde de autos y rojo de peatones
  digitalWrite(ROJO_P, HIGH);     //  para permitir paso de autos.
  if(digitalRead(PULS)){          //  Secuencia en la cual al pulsar el boton
    SecuenciaIn();                //  se interrumpe la secuencia normal para
  }                               //  darle paso al peaton.
  delay(VALOR);
  digitalWrite(VERDE_A, HIGH);    //  Parpadeo de la luz verde.
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_A, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_A, HIGH);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_A, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_A, HIGH);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_A, LOW);
  digitalWrite(ROJO_P, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(VALOR);
  digitalWrite(AMARILLO_A, HIGH); // Prende un tiempo la luz amarillo para
  if(digitalRead(PULS)){          // para que bajen la velocidad los carros.
    SecuenciaIn();
  }
  delay(VALOR+300);
  digitalWrite(AMARILLO_A, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(VALOR+300);
  digitalWrite(ROJO_A, HIGH);     //  Prende luz verde de peaton y luz roja
  digitalWrite(VERDE_P, HIGH);    //  de autos para que puedan pasar los
  if(digitalRead(PULS)){          //  peatones
    SecuenciaIn();
  }
  delay(VALOR);
  digitalWrite(VERDE_P, HIGH);    //  Parpadeo de luz verde de peatones
  if(digitalRead(PULS)){          //  para avisar que cambiara a rojo.
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_P, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_P, HIGH);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_P, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(VERDE_P, HIGH);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(200);
  digitalWrite(ROJO_A, LOW);
  digitalWrite(VERDE_P, LOW);
  if(digitalRead(PULS)){
    SecuenciaIn();
  }
  delay(VALOR);
}

void SecuenciaIn(){               //  Metodo de secuencia en la cual al presionar
  digitalWrite(ROJO_P, LOW);      //  el boton cambiara las luces para 
  digitalWrite(VERDE_A, LOW);     //  que el peaton tenga prioridad
  digitalWrite(AMARILLO_A, LOW);  //  (prender verde de peaton y prender 
  digitalWrite(VERDE_P, HIGH);    //  rojo de autos) con un tiempo de 
  digitalWrite(ROJO_A, HIGH);     //  espera para que puedan pasar.
  delay(VALOR);
  SecuenciaNor();
}


