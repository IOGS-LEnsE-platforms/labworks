void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT); //Ports utilisés pour piloter les 3 LEDS
  pinMode(11,OUTPUT);
  pinMode(9,OUTPUT);
  
  pinMode(5,OUTPUT);//Broche de commande de LED blanche de référence
  pinMode(6,OUTPUT);//Broche de commande de deuxième LED blanche de référence
//analogWrite(5,255);
}

void loop() {
  
  while (Serial.available() > 0) {
    int r = Serial.parseInt();
    int v = Serial.parseInt();
    int b = Serial.parseInt();
    int Led1 = Serial.parseInt(); // LED1 24000K
    int Led2 = Serial.parseInt(); // LED2 6900K
    
    if (Serial.read() == '\n') {
      analogWrite(9, r);
      analogWrite(10, v);
      analogWrite(11, b);
      analogWrite(5,Led1);
      
      analogWrite(6,Led2);
      Serial.print("Rouge = "); Serial.println(r);
      Serial.print("Vert = "); Serial.println(v);
      Serial.print("Bleu = ");Serial.println(b);   
      Serial.print("LED1 = ");Serial.println(Led1);
      Serial.print("LED2 = ");Serial.println(Led2);    
    }
  }
}
