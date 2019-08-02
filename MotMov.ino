// ++++++++++++++++++++  function mov +++++++++++++++++++++++++++++
void forward(void)
{  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
// ++++++++++++++++++++  function mov +++++++++++++++++++++++++++++
void cw_dir(void)
{  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
}
// ++++++++++++++++++++  function mov +++++++++++++++++++++++++++++
void ccw_esq(void)
{ 
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}

void Recuar(void)
{
  DC_Motor_Esq=DutyCicleMotorEsq;
  DC_Motor_Dir=DutyCicleMotorDir;
  LoadMotorEsqDirPwm();  
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
}

void EmFrenteMax(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqMais;
  DC_Motor_Dir=DutyCicleMotorDirMais;
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
void EmFrente(void)
{
  DC_Motor_Esq=DutyCicleMotorEsq;
  DC_Motor_Dir=DutyCicleMotorDir;
  LoadMotorEsqDirPwm();
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
void EmFrenteRed(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqReduzido;
  DC_Motor_Dir=DutyCicleMotorDirReduzido;
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}

void EmFrenteMin(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqMenos;
  DC_Motor_Dir=DutyCicleMotorDirMenos;

  LoadMotorEsqDirPwm();
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}


void Parar(void)
{
  DC_Motor_Esq=250;
  DC_Motor_Dir=250;
  LoadMotorEsqDirPwm();
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, HIGH);
  delay(20);
}

void paragem(void)
{
  Parar();
  while(1)
  {
    	led_ON();
	delay(100);
	led_OFF();
	delay(100);
      //  Parar();
  }

}

void travado(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqMais;
  DC_Motor_Dir=DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, HIGH);
}

void EmFrenteDCRed(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqReduzido;
  DC_Motor_Dir=DutyCicleMotorDirReduzido;
  LoadMotorEsqDirPwm();  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
// .............................................................
void em_frente_5cm(void)
{
  DC_Motor_Esq=700;
  DC_Motor_Dir=700;  
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();    
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  delay(280);
  Parar();
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void VirarEsquerda(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqReduzido;  // ou menos :: teste andamento com valor minimo
  DC_Motor_Dir=DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);  // ou HIGH
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}

void VirarDireita(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqMais;
  DC_Motor_Dir=DutyCicleMotorDirReduzido;  // ou menos :: teste andamento com valor minimo
  LoadMotorEsqDirPwm();  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);  // ou HIGH
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RodarDir(void)
{
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();    
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);  
}
void RodarEsq(void)
{
  DC_Motor_Esq=DutyCicleMotorEsq;
  DC_Motor_Dir=DutyCicleMotorDir;
  LoadMotorEsqDirPwm();   
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RodarDirRed(void)
{
  DC_Motor_Esq=DutyCicleMotorRodarEsqRed;
  DC_Motor_Dir=DutyCicleMotorRodarDirRed;
  LoadMotorEsqDirPwm();    
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);  
}

void RodarEsqRed(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqReduzido;
  DC_Motor_Dir=DutyCicleMotorDirReduzido;
  LoadMotorEsqDirPwm();   
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// .............................................................................
# define delay_rot_90_esq  700  // ..............
# define delay_rot_90_dir  700  // ..............
// ..............................................
// ..............................................

void rodar_1_4_dir(void)
{
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();   
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
  
  delay(delay_rot_90_dir);
  Parar();
}

void rodar_1_4_esq(void)
{
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();    
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  
  delay(delay_rot_90_esq);
  Parar();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void em_frente_10cm(void)
{
  DC_Motor_Esq=700;
  DC_Motor_Dir=700;  
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();   
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  delay(510);
    Parar();
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void recuar_10cm(void)
{
  DC_Motor_Esq=700;
  DC_Motor_Dir=700;  
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();    
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
  delay(510);
    Parar();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ...................
void recuar_5cm(void)
{
  DC_Motor_Esq=700;
  DC_Motor_Dir=700;  
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();   
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
  delay(280);
}
// ...................
void recuar_2cm(void)
{
  DC_Motor_Esq=700;
  DC_Motor_Dir=700;  
//  analogWrite(Motor_Esq, DC_Motor_Esq / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
//  analogWrite(Motor_Dir, DC_Motor_Dir / 4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  LoadMotorEsqDirPwm();   
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
 
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
  delay(50);
}
// ++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++ 
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

