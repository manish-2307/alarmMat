int x = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);    
 pinMode(A0,INPUT);
 pinMode(8,OUTPUT);
 pinMode(10,INPUT);                                                            
}
void loop() {
  for(int i = 0; i <7000;i++){
    x = analogRead(A0);
    if(x > 0){
      break;
      }
    }
    if(x>0){
      Serial.println("ON");
      digitalWrite(8,HIGH);
      boolean ok = false;
      for(int i = 0; i<10; i++){ 
      if(digitalRead(10) == LOW){
        digitalWrite(8,HIGH);
        ok = true;
        break;
      }
      ok = false;
      delay(500);
      }
      if(!ok){
        digitalWrite(8,LOW);
        Serial.println("END");
        delay(10000);
      }
      
    }else{
      Serial.println("OFF");
      digitalWrite(8,LOW);
    }

}
