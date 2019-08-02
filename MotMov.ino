// ++++++++++++++++++++  function mov +++++++++++++++++++++++++++++
void Forward(void)
{
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
void backward(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
}
void ccw(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}
void cw(void)
{
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
}


void Rodar_Esq(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=DutyCicleMotorRodarEsq;  //;DutyCicleMotorEsqMenos  ???????
  DC_Motor_Dir=DutyCicleMotorRodarDir;  //;DutyCicleMotorDirMais
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255 
}
void Rodar_Dir(void)
{
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
  DC_Motor_Esq=DutyCicleMotorRodarEsq;  //;DutyCicleMotorEsqMenos  ???????
  DC_Motor_Dir=DutyCicleMotorRodarDir;  //;DutyCicleMotorDirMais
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255 
}

void Em_Frente(void)
{
  DC_Motor_Esq=255; //DutyCicleMotorEsq;  //;DutyCicleMotorEsqMenos  ???????
  DC_Motor_Dir=255; //DutyCicleMotorDir;  //;DutyCicleMotorDirMais
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255 
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void EmFrente_esq(void)
{
  DC_Motor_Esq = DutyCicleMotorEsq;
  DC_Motor_Dir = 0;

  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}

void EmFrente_dir(void)
{
  DC_Motor_Esq = 0;
  DC_Motor_Dir = DutyCicleMotorDir;

  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
}

void EmFrente(void)
{
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq = DutyCicleMotorEsq;
  DC_Motor_Dir = DutyCicleMotorDir;
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
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
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=DutyCicleMotorEsqMais;
  DC_Motor_Dir=DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();
}

void EmFrenteRed(void)
{
  DC_Motor_Esq=DutyCicleMotorEsqRed;
  DC_Motor_Dir=DutyCicleMotorDirRed;
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
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=0;
  DC_Motor_Dir=0;
  LoadMotorEsqDirPwm();
}

void Para(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=0;
  DC_Motor_Dir=0;
  LoadMotorEsqDirPwm();
}

void parar(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=0;
  DC_Motor_Dir=0;
  LoadMotorEsqDirPwm();
}
void para(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=0;
  DC_Motor_Dir=0;
  LoadMotorEsqDirPwm();
}

void paragem(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=0;
  DC_Motor_Dir=0;
  LoadMotorEsqDirPwm();
  while(1)
  {
    Parar();
  }

}

// .............................................................
void em_frente_5cm(void)
{
  DC_Motor_Esq=200;
  DC_Motor_Dir=200;  
  LoadMotorEsqDirPwm();    
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  delay(160);
  Parar();
    delay(500);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

# define delay_rot_90_esq  465  // ..............
# define delay_rot_90_dir  465 // ..............
// ..............................................
// ..............................................
// ..............................................
# define delay_rot_45_esq  delay_rot_90_esq/2  // ..............
# define delay_rot_45_dir  delay_rot_90_dir/2  // ..............
// ..............................................

void rodar_1_4_dir(void)
{
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();   
  delay(delay_rot_90_dir);
  Parar();
  delay(500);
}
void rodar_1_4_esq(void)
{
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();    
  delay(delay_rot_90_esq);
  Parar();
    delay(500);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void em_frente_10cm(void)
{
  DC_Motor_Esq=200;
  DC_Motor_Dir=200;  
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
// ++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++ 
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

