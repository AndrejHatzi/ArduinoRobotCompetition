
// +++++++++++++++++++++++++++++++++++++++++++++++++++
// ...................................................
//  ForaDaPistaVirarEsq = 0;
//  ForaDaPistaVirarDir = 0;
// +++++++++++++++++++++++++++++++++++++++++++++++++++


void ForaPistaEsqVirarDir(void)  // *******************  // robot esq pista
{
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 1;
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorDirMin ;
  forward();
  LoadMotorEsqDirPwm();
  do 
  {
    Leitura2_CC();
    delay(1);
  }while (FOTO2_CC > FOTO2_CC_black);
  Parar();
  saida_de_90();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++
// ...................................................
//  ForaDaPistaVirarEsq = 0;
//  ForaDaPistaVirarDir = 0;
// +++++++++++++++++++++++++++++++++++++++++++++++++++

void ForaPistaDirVirarEsq(void)
{
  ForaDaPistaVirarEsq = 1;
  ForaDaPistaVirarDir = 0;
  DC_Motor_Esq=DutyCicleMotorEsqMin;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  forward();
  LoadMotorEsqDirPwm();
  
  do 
  {
    Leitura2_CC();
    delay(1);
  }while (FOTO2_CC > FOTO2_CC_black);

   Parar();
   saida_de_90();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++
// ...................................................
//  ForaDaPistaVirarEsq = 0;
//  ForaDaPistaVirarDir = 0;
// +++++++++++++++++++++++++++++++++++++++++++++++++++

void Sem_Pista(void)
{
    Leitura_Inf();
    if (FOTO2_CC > FOTO2_CC_black)	// --- " > " ---- fora de pista  // ?????????????????????????????????
    {
        if ((FOTO4_EE < FOTO4_EE_black)||(FOTO3_CE < FOTO3_CE_black)) 		        {ForaPistaDirVirarEsq();}
        else if ((FOTO1_CD < FOTO1_CD_black)||(FOTO0_DD < FOTO0_DD_black)) 	      {ForaPistaEsqVirarDir();}
        else
        {
            if (ForaDaPistaVirarEsq == 1)                   { ForaPistaDirVirarEsq();}
            else if(ForaDaPistaVirarDir == 1)               { ForaPistaEsqVirarDir();}
        }
    }
}
//  ForaDaPistaVirarEsq = 0;
//  ForaDaPistaVirarDir = 0;
