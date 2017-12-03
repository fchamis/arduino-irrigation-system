
//http://blog.webtronico.com/?p=88
//pouca agua = LOW


//config variables:
int pinWater = 11;
int pinBuzzer = 12;
int pinPump = 7;
int pinSensor = A0;
int pinPot = A2;
//how many seconds should we turn on the pump
int pumpTime = 5000;
//how many times should we check the water level whe the pump is turned on
int pumpCheckTime = 5;

//variables
int sensorValue = 0;
int potValue = 0;
int pumpDelayTime = 0;
float seno;
int frequencia;

void setup(){
  
  Serial.begin(9600);
  pinMode(pinWater, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinSensor, INPUT);
  pinMode(pinPot, INPUT);
  pinMode(pinPump, OUTPUT);
  
}

void loop(){
  
  if(digitalRead(pinWater)==LOW){
    
    //we don't have water, let's call someone to bring us more :)
    Serial.println("water is LOW");
    //buzzer();
    
  }else{
    
    //we do have water, now we need to check the soil condition and compare with the pot minimum value
    Serial.println("water is HIGH");
    
    sensorValue = analogRead(pinSensor);  
    Serial.print("sensorValue: ");
    Serial.println(sensorValue);
    
    potValue = analogRead(pinPot);
    Serial.print("potValue: ");
    Serial.println(potValue);

    if (sensorValue <= potValue) {
      
      //the soil is dry, turn on the pump for some seconds and turn it off
      digitalWrite(pinPump, HIGH);
      Serial.println("pump is HIGH");
      
      //we need to verify if the water ends while we pump is on
      pumpDelayTime = long(pumpTime/pumpCheckTime);
      for (int i = 0; i < pumpCheckTime; i++){
        
        delay(pumpDelayTime);

        //check the water level again to see if it's necessary to turn it off in the middle
        if(digitalRead(pinWater)==LOW){
          Serial.println("water is LOW, so we need to send pump to LOW");
          digitalWrite(pinPump, LOW);
          break;
        }
        
      }

      //turn the pump off at the end
      digitalWrite(pinPump, LOW);
      Serial.println("pump is LOW");
    }

  }
  
  delay(2000);

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
