
#define discharge 10
#define delay_IR_led 2
// +++++++++++++++++ fuction IR reading ++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++ fuction IR reading ++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++ fuction IR reading ++++++++++++++++++++++++++++++++++++++
void Leitura0_DD(void)
{
  digitalWrite(Led_IR_Inf0, HIGH);                // sets the LED on
  FOTO0_DD = analogRead(FOTO0_DD_Pin) / 4;        // read the input pin from 0 to 1023 //  analogRead(FOTO0_DD_Pin)>>2
  digitalWrite(Led_IR_Inf0, LOW);                 // sets the LED off
  delayMicroseconds(discharge);
}

void Leitura1_CD(void)
{
  digitalWrite(Led_IR_Inf1, HIGH);                // sets the LED on
  FOTO1_CD = analogRead(FOTO1_CD_Pin) / 4;        // read the input pin from 0 to 1023 // analogRead(FOTO1_CD_Pin)>>2
  digitalWrite(Led_IR_Inf1, LOW);                 // sets the LED off
  delayMicroseconds(discharge);
}

void Leitura2_CC(void)
{
  digitalWrite(Led_IR_Inf2, HIGH);                // sets the LED on
  FOTO2_CC = analogRead(FOTO2_CC_Pin) / 4;        // read the input pin from 0 to 1023 // analogRead(FOTO2_CC_Pin)>>2
  digitalWrite(Led_IR_Inf2, LOW);                 // sets the LED off
  delayMicroseconds(discharge);
}

void Leitura3_CE(void)
{
  digitalWrite(Led_IR_Inf3, HIGH);                // sets the LED on
  FOTO3_CE = analogRead(FOTO3_CE_Pin) / 4;        // read the input pin from 0 to 1023 // analogRead(FOTO3_CE_Pin)>>2
  digitalWrite(Led_IR_Inf3, LOW);                 // sets the LED off
  delayMicroseconds(discharge);
}


void Leitura4_EE(void)
{
  digitalWrite(Led_IR_Inf4, HIGH);                // sets the LED on 
  FOTO4_EE = analogRead(FOTO4_EE_Pin) / 4;        // read the input pin from 0 to 1023 //  analogRead(FOTO4_EE_Pin)>>2
  digitalWrite(Led_IR_Inf4, LOW);                 // sets the LED off
  delayMicroseconds(discharge);
}

void Leitura6_GND(void)
{
  analogRead(A6);                                 // read the input pin from 0 to 1023
}


#define xxx 5
void Leitura_Inf(void)
{
  
  Leitura2_CC();  Leitura6_GND();  
  Leitura4_EE();  Leitura6_GND();  
  Leitura0_DD();  Leitura6_GND();  
  Leitura3_CE();  Leitura6_GND();  
  Leitura1_CD();  Leitura6_GND();
}

void _Leitura_Inf(void)
{
  Leitura2_CC();
  Leitura4_EE();
  Leitura0_DD();
  Leitura3_CE();
  Leitura1_CD();
}

