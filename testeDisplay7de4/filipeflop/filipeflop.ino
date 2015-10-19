#include <SevSeg.h>
int fim1 = 1;
int seg = 120;

//Create an instance of the object.
SevSeg display7seg; 
void setup()
{
  
  //Selecao tipo de display anodo comum
  int displayType = COMMON_ANODE;
     
  //Definicao dos pinos dos digitos
  int digit1 = 10; //Pino Digito1 do display
  int digit2 = 11; //Pino Digito2 do display
  int digit3 = 12; //Pino Digito3 do display
  int digit4 = 13; //Pino Digito4 do display
 
  //Pinos ligados aos segmentos A - H
  int segA = 2; //Pino segmento A 
  int segB = 3; //Pino segmento B
  int segC = 4; //Pino segmento C
  int segD = 5; //Pino segmento D
  int segE = 6; //Pino segmento E
  int segF = 7; //Pino segmento F
  int segG = 8; //Pino segmento G
  int segDP= 9; //Pino segmento H
   
  //Define o numero de digitos do display
  int numberOfDigits = 4;
 


  //Inicializa o display
   display7seg.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
   
  //Nivel de brilho do display
  display7seg.SetBrightness(50);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
}
  int a1 = 1;
  int a2 = 1;
  int btn = 0;
  int count = 0;
  char tempString[10] = "1-SA"; //Used for sprintf
  int et2 = 0;
  int et3 = 0;
 
void loop()
{ 
  if(et2 == 0){// Etapa 1
    if(btn == 0){
      if(digitalRead(30) == 1){
       if(a1 < 2){ a1++;  sprintf(tempString, "%s", "2-CA"); }
       btn = 1;
       count=20;
      }
      if(digitalRead(31) == 1){
       if(a1 >1){ a1--; sprintf(tempString, "%s", "1-SA"); }
       btn = 1;
       count = 20;
      }
    }
    
    //sprintf(tempString, "00%02d", a1);
    //strcat(tempString,a1);
    display7seg.DisplayString(tempString, 3);
    if(count > 0){
     count--; 
    }else{
       if(count == 0 && btn == 1){
         btn = 0;
       } 
    }
    if(digitalRead(32) ==1){
       et2 = 1; 
       btn = 0;
       count = 0;
       if(a1 == 1){sprintf(tempString, "%s", "0003");}else{sprintf(tempString, "%s", "0003");}
       display7seg.DisplayString(tempString, 3);
    }
  }else{ // Fim etapa 1
    if(et3 == 0){// Etapa 2
      if(a1 == 1){
          
        if(btn == 0){
          if(digitalRead(30) == 1){
           if(a2 < 8){ 
             a2++;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0005"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0010"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 5:  
                  sprintf(tempString, "%s", "0020"); 
                  break;
                case 6:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 7:  
                  sprintf(tempString, "%s", "0200"); 
                  break;
                case 8:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count=20;
          }
          if(digitalRead(31) == 1){
           if(a2 > 1){ 
          
             a2--;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0005"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0010"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 5:  
                  sprintf(tempString, "%s", "0020"); 
                  break;
                case 6:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 7:  
                  sprintf(tempString, "%s", "0200"); 
                  break;
                case 8:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count = 20;
          }
        }
        
        //sprintf(tempString, "00%02d", a1);
        //strcat(tempString,a1);
        display7seg.DisplayString(tempString, 3);
        if(count > 0){
         count--; 
        }else{
           if(count == 0 && btn == 1){
             btn = 0;
           } 
        }
      }else{
          
        if(btn == 0){
          if(digitalRead(30) == 1){
           if(a2 < 8){ 
             a2++;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count=20;
          }
          if(digitalRead(31) == 1){
           if(a2 > 1){ 
          
             a2--;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count = 20;
          }
        }
        
        //sprintf(tempString, "00%02d", a1);
        //strcat(tempString,a1);
        display7seg.DisplayString(tempString, 3);
        if(count > 0){
         count--; 
        }else{
           if(count == 0 && btn == 1){
             btn = 0;
           } 
        }
      }
      if(digitalRead(32) == 1){
         et3 = 1; 
         btn = 0;
         count = 0;
      }
    }else{// fim etapa 3
        strcat(tempString,"Cert");
        display7seg.DisplayString(tempString, 3);
    }
  }
}
