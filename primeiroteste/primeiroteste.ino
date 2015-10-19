int tempo = 1010;// 1000 = 100s
int ten = 0;
int av1 = 0;
int av2 = 0;


void setup(){
 pinMode(7, OUTPUT); 
 pinMode(9, INPUT); 
 Serial.begin(9600);
}

void loop(){
 int botao = digitalRead(9);
 if(av1 == 0){
  Serial.println("aguardando ");
  av1 = 1;
 }
 if(botao == 1){
  if(av2 == 0){
   Serial.print("tempo iniciado ");
   Serial.println((tempo/10)-1);
   av2 = 1;
  }
  int wh = 1;
  while(wh == 1){
   if(tempo > 10){
    tempo = tempo - 10;
    delay(1000); 
    //Serial.println(tempo/10);
   }else{
    if(ten == 0){
      tempo = tempo - 10;
      delay(1000); 
      Serial.println(tempo);
      digitalWrite(7, HIGH); 
      ten = 1;
    }
   } 
  }
 }
 delay(100);
}
