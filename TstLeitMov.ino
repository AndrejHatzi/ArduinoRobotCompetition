
void teste_pwm_min(void)
{
  DC_Motor_Esq = 60;
  DC_Motor_Dir = 60;
  LoadMotorEsqDirPwm();

  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);

  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);

  delay(2000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}

void teste_curva(void)
{
  DC_Motor_Esq = 0;
  DC_Motor_Dir = DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);

  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  delay(2000);  // wait 2000 m(s)

  while (1)
  {
    digitalWrite(mot_esq_1, LOW);
    digitalWrite(mot_esq_2, LOW);

    digitalWrite(mot_dir_1, LOW);
    digitalWrite(mot_dir_2, LOW);
  }
}


void teste_em_frente_sonar(void)
{
  while (1)
  {
    EmFrente();
    if (DistFrnt <= 8)  //  >>>>::  (DistFrnt<=3)  and backward 8 cm :::: <<<<
    {
      Parar();
    }
  }
}

// +++++++++++++++++++
void teste_rodar_90(void)
{
  delay(2000);  // wait 2000 m(s)
  rodar_1_4_dir();
  delay(3000);  // wait 2000 m(s)
  rodar_1_4_esq();
  delay(3000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}



void teste_em_frente_max(void)
{
  EmFrenteMax();
  delay(2000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}

void teste_em_frente_parar_mot_esq(void)
{
  EmFrenteMax();
  delay(1000);  // wait 2000 m(s)

  DC_Motor_Esq = 0;
  DC_Motor_Dir = DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();

  delay(3000);  // wait 2000 m(s)
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, HIGH);

  digitalWrite(mot_dir_1, LOW);  //digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);

  while (1)
  {
    digitalWrite(mot_esq_1, LOW);
    digitalWrite(mot_esq_2, LOW);

    digitalWrite(mot_dir_1, LOW);
    digitalWrite(mot_dir_2, LOW);

  }
}


void teste_em_frente_esq(void)
{
  EmFrente_esq();
  delay(1000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}


void teste_em_frente_dir(void)
{
  EmFrente_dir();
  delay(1000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}


void teste_em_frente(void)
{
  Em_Frente();
  delay(2000);
  while (1)
  {
    paragem();
  }
}

void teste_em_frente_red(void)
{
  EmFrenteRed();
  delay(1000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}


void teste_RodarDirRed(void)
{
  Rodar_Dir();
  delay(1000);  // wait 2000 m(s)
  Parar();
  while (1)
  {
    Parar();
  }
}


void teste_RodarEsqRed(void)
{
  Rodar_Esq();
  delay(1000);  // wait 2000 m(s)
  Parar();
  while (1)
  {
    Parar();
  }
}


void teste_em_frente_recuar_rodar(void)
{
  EmFrente();
  delay(1000);  // wait 1000 m(s)
  Parar();
  delay(1000);  // wait 1000 m(s)
  Recuar();
  delay(1000);  // wait 1000 m(s)
  Parar();
  delay(2000);  // wait 1000 m(s)
  Rodar_Esq();
  delay(1000);  // wait 2000 m(s)
  Parar();
  delay(2000);  // wait 1000 m(s)
  Rodar_Dir();
  delay(1000);  // wait 2000 m(s)
  while (1)
  {
    Parar();
  }
}

void teste_rodar(void)
{
  rodar_1_4_dir();
  delay(1000);
  rodar_1_4_esq();
  delay(2000);
  rodar_1_4_dir();
  delay(2000);
  rodar_1_4_esq();
  delay(1000);
  while (1)
  {
    Parar();
  }
}

void teste_leit_inf(void)
{
  while (1)
  {
    Leitura_Inf();
    Serial.print("FOTO_4_EE");        // prints a label
    Serial.print("  FOTO_3_CE");        // prints a label
    Serial.print("  FOTO_2_CC");        // prints a label
    Serial.print("  FOTO_1_CD");        // prints a label
    Serial.print("  FOTO_0_DD");

    Serial.println("");                 // prints another carriage return

    Serial.print(FOTO4_EE);       // print as an ASCII-encoded decimal
    Serial.print("\t   ");                 // prints a tab
    Serial.print(FOTO3_CE);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(FOTO2_CC);       // print as an ASCII-encoded decimal
    Serial.print("\t  ");                 // prints a tab
    Serial.print(FOTO1_CD);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(FOTO0_DD);       // print as an ASCII-encoded decimal

    Serial.println("");                 // prints another carriage return
    Serial.println("");                 // prints another carriage return
    delay(500);  // wait 500 m(s) so as not to send massive amounts of data
  }
}

void teste_leit_inf_4_2_0(void)
{
  while (1)
  {
    _Leitura_Inf();
    Serial.print("FOTO_4_EE\t");        // prints a label
    Serial.print("FOTO_2_CC\t");        // prints a label
    Serial.print("FOTO_0_DD\t");

    Serial.println("");                 // prints another carriage return

    Serial.print(FOTO4_EE);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(FOTO2_CC);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(FOTO0_DD);       // print as an ASCII-encoded decimal

    Serial.println("");                 // prints another carriage return
    Serial.println("");                 // prints another carriage return
    delay(1000);  // wait 500 m(s) so as not to send massive amounts of data
  }
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void teste_sonar(void)
{
  while (1)
  {
    delay(30);  // wait 30 m(s)
//    Dist_Dir();
    delay(30);  // wait 30 m(s)
    Dist_Frnt();
    delay(30);  // wait 30 m(s)
//    Dist_Esq();
    Serial.print("DIST_ESQ\t");        // prints a label
    Serial.print("DIST_FRENTE\t");        // prints a label
    Serial.print("DIST_DIR\t");        // prints a label

    Serial.println("");                 // prints another carriage return

    Serial.print(DistEsq);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(DistFrnt);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(DistDir);       // print as an ASCII-encoded decimal

    Serial.println("");                 // prints another carriage return
    Serial.println("");                 // prints another carriage return

    delay(250);  // wait 500 m(s) so as not to send massive amounts of data
  }
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void teste_sonar_mm(void)
{
  Serial.begin(9600);      // open the serial port at 9600 bps:
  while (1)
  {
    delay(30);  // wait 30 m(s)
    Dist_Dir_mm();
    delay(30);  // wait 30 m(s)
    Dist_Frnt_mm();
    delay(30);  // wait 30 m(s)
    Dist_Esq_mm();
    Serial.print("DIST_ESQ\t");        // prints a label
    Serial.print("DIST_DIR\t");        // prints a label
    Serial.println("");                 // prints another carriage return

    Serial.print(DistEsq);       // print as an ASCII-encoded decimal
    Serial.print("\t\t");                 // prints a tab
    Serial.print(DistDir);       // print as an ASCII-encoded decimal

    Serial.println("");                 // prints another carriage return
    Serial.println("");                 // prints another carriage return

    delay(250);  // wait 500 m(s) so as not to send massive amounts of data
  }
}


void testes_leitura_movimento(void)
{
  while (0)  teste_curva();
  while (0)  teste_em_frente_sonar();
  while (0)  teste_rodar_90();
  while (0)  teste_em_frente_esq();
  while (0)  teste_em_frente_dir();
  while (0)  teste_em_frente();
  while (0)  teste_em_frente_max();
  while (0)  teste_em_frente_parar_mot_esq();
  while (0)  teste_em_frente_red();
  while (0)  teste_RodarDirRed();
  while (0)  teste_RodarEsqRed();
  while (0)  teste_em_frente_recuar_rodar();
  while (0)  teste_rodar();
  Serial.begin(9600);      // open the serial port at 9600 bps:
  while (1)  teste_leit_inf();
  while (0)  teste_leit_inf_4_2_0();
  while (0)  teste_sonar();
  while (0)  EmPista();
}
