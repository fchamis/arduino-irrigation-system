
//http://blog.webtronico.com/?p=88
int pinWater = 11;
//pouca agua = LOW
int pinBuzzer = 12;
float seno;
int frequencia;

void setup(){
  Serial.begin(9600);
  pinMode(pinWater,INPUT);
  pinMode(pinBuzzer,OUTPUT);
  noTone(pinBuzzer);
}
void loop(){
  /*
  if(digitalRead(pinWater)==HIGH){
    Serial.println("HIGH");
  }else{
    Serial.println("LOW");
    buzzer();
  }
  */
  //delay(200);
  //buzzer();
   for(int x=0;x<180;x++){
    //converte graus para radiando e depois obtém o valor do seno
    seno=(sin(x*3.1416/180));
    //gera uma frequência a partir do valor do seno
    frequencia = 2000+(int(seno*1000));
    tone(pinBuzzer,frequencia);
    delay(2);
   }

}

void buzzer() {
  for(int x=0;x<180;x++){
    //converte graus para radiando e depois obtém o valor do seno
    seno=(sin(x*3.1416/180));
    //gera uma frequência a partir do valor do seno
    frequencia = 2000+(int(seno*1000));
    tone(pinBuzzer,frequencia);
    delay(2);
  }
}
