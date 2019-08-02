

// para robot movel ""em pista"" e para eliminar tempos mortos de leitura(Sistema cego em pista).
// introduzir a funcao "sonar_frente()" apenas em "pista mais" e de 20 em 20 ciclos. 
// ... para eliminar possiveis ecos.

//#define TrigPin  3
//#define EchoPin  2
//unsigned long time_trg=0;
//unsigned long time_ech=0;
//unsigned long time_pulse=0;
//unsigned long duration=0;
//float distance;  //unsigned long distance=0; 
//unsigned int state=0;


// *******************************************************
// ..........................................................................
void _Dist_Frnt_(void)  // HC-SR04 // US_015
{
  digitalWrite(TRG_Frnt, LOW);
  delayMicroseconds(2);
  digitalWrite(TRG_Frnt, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Frnt, LOW);
  
  while(digitalRead(ECH_Frnt)==0)
  {
  };
  time_trg = micros();
  
  while(digitalRead(ECH_Frnt)==1)
  {
  };
  time_ech = micros();
  
  if (time_ech <= time_trg){distance=0;}
  else 
  {
    time_pulse = time_ech - time_trg;
    //  distance = (duration/2) / 29.1; 
    distance = time_pulse / 58;
  }
  Serial.print("distance = "); 
  Serial.print(distance); 
  Serial.println();      
}

