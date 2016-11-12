
int luminosity;
int state = 0;
float invert(float x){
  x = x - 1000;
  return x * (-1);
}
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6, INPUT);
}
void loop() {
  int button;
  button = digitalRead(6);
  delay(100);
  if(button == 1){
    state = !state;
  }
  digitalWrite(5, LOW );
  digitalWrite(4, LOW );
  digitalWrite(3, LOW );
  digitalWrite(2, LOW );
  delay(100);
  while(state == 1){
    button = digitalRead(6);
    delay(100);
    float pino = invert(analogRead(A1));
    //float pino2 = invert(analogRead(A0));
    luminosity = digitalRead(7);
    //float voltage = (pino * 5.0)/1024; // calculo da voltagem
    //float temperatureC = ((voltage - 0.5) * 10) + 11; // transformacao para celsius
    Serial.print(button);
    //Serial.println(pino2);
   // Serial.print("Temperatura : ");
  //  Serial.println(temperatureC);
    delay(500); 
    // put your main code here, to run repeatedly:
    if(pino > 550){
      digitalWrite(2, HIGH);
      digitalWrite(5, LOW );
      digitalWrite(4, LOW );
      digitalWrite(3, LOW );
    }
    if(pino > 380 && pino < 550){
      digitalWrite(3, HIGH );
      digitalWrite(5, LOW );
      digitalWrite(4, LOW );
      digitalWrite(2, LOW );
    }
    if(pino > 200 && pino < 380){
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW );
      digitalWrite(3, LOW );
      digitalWrite(2, LOW );
    }
    if(pino > 0 && pino < 200){
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW );
      digitalWrite(3, LOW );
      digitalWrite(2, LOW );
    }
  }
}
