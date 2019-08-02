

// ++++++++++++++++++++  function sonar readings +++++++++++++++++++++++++++++
void Dist_Frnt(void)  // HC-SR04 // US_015
{
  digitalWrite(TRG_Frnt, LOW);
  delayMicroseconds(2);
  digitalWrite(TRG_Frnt, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Frnt, LOW);

  while(digitalRead(ECH_Frnt)==0)
  {
    time_trg = micros();
  };
  time_trg = micros();
    
  while(digitalRead(ECH_Frnt)==1)
  {
    time_ech = micros();
    if ((time_ech-time_trg)>1200)break;   // 1000...17cm  // 1200..20cm
  };
  time_ech = micros();
  
  if (time_ech <= time_trg){distance=0;}
  else 
  {
    time_pulse = time_ech - time_trg;
    distance = time_pulse / 58;     //  distance = (duration/2) / 29.1; 
  }
    DistFrnt=distance;
}
// .............................................................
void Dist_Esq(void)
{  
  digitalWrite(TRG_Esq, LOW);
  delayMicroseconds(2);
  digitalWrite(TRG_Esq, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Esq, LOW);

  while(digitalRead(ECH_Esq)==0)
  {
    time_trg = micros();
  };
  time_trg = micros();
    
  while(digitalRead(ECH_Esq)==1)
  {
    time_ech = micros();
  };
  time_ech = micros();
  
  if (time_ech <= time_trg){distance=0;}
  else 
  {
    time_pulse = time_ech - time_trg;
    distance = time_pulse / 58;     //  distance = (duration/2) / 29.1; 
  }
}
// .............................................................
void Dist_Dir(void)
{
  digitalWrite(TRG_Dir, LOW);
  delayMicroseconds(2);
  digitalWrite(TRG_Dir, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Dir, LOW);

  while(digitalRead(ECH_Dir)==0)
  {
    time_trg = micros();
  };
  time_trg = micros();
    
  while(digitalRead(ECH_Dir)==1)
  {
    time_ech = micros();
  };
  time_ech = micros();
  
  if (time_ech <= time_trg){distance=0;}
  else 
  {
    time_pulse = time_ech - time_trg;
    distance = time_pulse / 58;     //  distance = (duration/2) / 29.1; 
  }
}
// .............................................................
// .............................................................

void sonar_dist_esq_dir(void)
{
  delay(30);
  Dist_Esq();
  delay(30);
  Dist_Dir();
}


void sonar_dist_frnt(void)
{
  delay(30);
  Dist_Frnt();
}
//++++++++++++++++++++++++++++++++++++++++++++++

/*
  e(m)=v(m/s).t(s)
  e(mm)=v.1000(mm)*t(us)/1000000(us)
  sonar
  e(mm)=340000*t/1000000=t(us)/(1000000/340000)
  e(mm)=t(us)/(100/34)
  e(mm)=t(us)/2.91
*/
////
// ++++++++++++++++++++  function sonar readings mm +++++++++++++++++++++++++++++
void Dist_Esq_mm(void)
{
  digitalWrite(TRG_Esq, LOW); // <<<<< IMP
  delayMicroseconds(5); // << IMP << IMP << IMP
  
  digitalWrite(TRG_Esq, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRG_Esq, LOW);

  duration = pulseIn(ECH_Esq, HIGH); 
  distance = (duration/2) / 2.91;  // mm
  DistEsq = distance;              // mm
  digitalWrite(TRG_Esq, LOW);
}

void Dist_Dir_mm(void)
{
  digitalWrite(TRG_Dir, LOW);  // <<<<< IMP
  delayMicroseconds(5); // << IMP << IMP << IMP
  
  digitalWrite(TRG_Dir, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Dir, LOW);
  
  duration = pulseIn(ECH_Dir, HIGH);   // mm
  distance = (duration/2) / 2.91;  // mm
  DistDir = distance;              // mm
}
void Dist_Frnt_mm(void)
{
  digitalWrite(TRG_Frnt, LOW);  // <<<<< IMP
  delayMicroseconds(5); // << IMP << IMP << IMP
  
  digitalWrite(TRG_Frnt, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRG_Frnt, LOW);
  
  duration = pulseIn(ECH_Frnt, HIGH); 
  distance = (duration/2) / 2.91;   // mm
  DistFrnt = distance;              // mm
}

