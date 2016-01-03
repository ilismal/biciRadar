int trigger=7;
int echo=6;
long duracion=0;
long distancia=0;

void setup() {
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = (duracion/2) / 29.1;
  if (distancia >= 500 || distancia <= 0){
    Serial.println("Error de medicion");
  }
  else{
    Serial.print(distancia);
    Serial.println(" cm");
    if (distancia > 125){
      digitalWrite(8, HIGH); 
      digitalWrite(9, LOW); 
      digitalWrite(10, LOW); 
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);   
    }
    else if (distancia <= 125 && distancia > 100){
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10, LOW); 
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);   
    }
    else if (distancia <= 100 && distancia > 75){
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10, HIGH); 
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);   
    }
    else if (distancia <= 75 && distancia > 50){
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);   
    }
    else if (distancia <= 50 && distancia > 25){
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);   
    }
    else if (distancia <= 25){
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);   
    }
  }
  delay(500);
}
