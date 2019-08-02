
// +++++++++++++++++ IR reading ++++++++++++++++++++++++++++++++++++++

#define delaymicrosegundos 2

void Leitura0_DD(void)
{
  digitalWrite(Led_IR_Inf0, HIGH);     // sets the LED on
  delayMicroseconds(delaymicrosegundos+1);                            // waits for a second
  FOTO0_DD = analogRead(FOTO0_DD_Pin)/4;   // read the input pin from 0 to 1023
  digitalWrite(Led_IR_Inf0, LOW);   // sets the LED off
}
void Leitura1_CD(void)
{
  digitalWrite(Led_IR_Inf1, HIGH);   // sets the LED on
  delayMicroseconds(delaymicrosegundos);                  // waits for a 5(us)
  FOTO1_CD = analogRead(FOTO1_CD_Pin)/4;   // read the input pin from 0 to 1023
  digitalWrite(Led_IR_Inf1, LOW);   // sets the LED off
}
void Leitura2_CC(void)
{
  digitalWrite(Led_IR_Inf2, HIGH);     // sets the LED on
  delayMicroseconds(delaymicrosegundos+1);                            // waits for a 5(us)
  FOTO2_CC = analogRead(FOTO2_CC_Pin)/4;   // read the input pin from 0 to 1023
  digitalWrite(Led_IR_Inf2, LOW);   // sets the LED off
}
void Leitura3_CE(void)
{
  digitalWrite(Led_IR_Inf3, HIGH);     // sets the LED on
  delayMicroseconds(delaymicrosegundos+2);                            // waits for a 5(us)
  FOTO3_CE = analogRead(FOTO3_CE_Pin)/4;   // read the input pin from 0 to 1023
  digitalWrite(Led_IR_Inf3, LOW);   // sets the LED off
}
void Leitura4_EE(void)
{
  digitalWrite(Led_IR_Inf4, HIGH);     // sets the LED on
  delayMicroseconds(delaymicrosegundos);                            // waits for a second
  FOTO4_EE = analogRead(FOTO4_EE_Pin)/4;   // read the input pin from 0 to 1023
  digitalWrite(Led_IR_Inf4, LOW);   // sets the LED off
}


void Leitura_Inf(void)
{
  Leitura2_CC();
  Leitura1_CD();
  Leitura3_CE();  
  Leitura0_DD();
  Leitura4_EE();
}

// +++++++++++++++++ SONAR reading ++++++++++++++++++++++++++++++++++++++

/***********************************************************************/

/***********************************************************************/
// ++++++++++++++++++++  function sonar readings +++++++++++++++++++++++++++++
void Dist_Esq(void)
{
  digitalWrite(TRG_Esq, LOW); // <<<<< IMP
  delayMicroseconds(20); // << IMP << IMP << IMP
  
  digitalWrite(TRG_Esq, HIGH); 
  delayMicroseconds(10);
  
  digitalWrite(TRG_Esq, LOW); 
  duration = pulseIn(Echo_Esq, HIGH); 
  
  distance = (duration/2) / 29.1; 
  DistEsq = distance;
}

void Dist_Frnt(void)  // HC-SR04
{
  digitalWrite(TRG_Frnt, LOW);  // <<<<< IMP
  delayMicroseconds(2); // << IMP << IMP << IMP

  digitalWrite(TRG_Frnt, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Frnt, LOW); 
  
  duration = pulseIn(Echo_Frnt, HIGH); 
   
  distance = (duration/2) / 29.1; 
  DistFrnt = distance;
}

void Dist_Dir(void)
{
  digitalWrite(TRG_Dir, LOW);  // <<<<< IMP
  delayMicroseconds(2); // << IMP << IMP << IMP

  digitalWrite(TRG_Dir, HIGH); 
  delayMicroseconds(10);
  
  digitalWrite(TRG_Dir, LOW); 
  duration = pulseIn(Echo_Dir, HIGH); 
   
  distance = (duration/2) / 29.1; 
  DistDir = distance;
}

void leitura_sonares(void)
{
  delay(15);
  Dist_Esq();
  delay(15);
  Dist_Frnt();
  delay(15);
  Dist_Dir();
}

