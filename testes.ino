
//  #define  FOTO0_DD_black  30 //6
//  #define  FOTO1_CD_black  30 //7 
//  #define  FOTO2_CC_black  30 //0
//  #define  FOTO3_CE_black  30 //7 
//  #define  FOTO4_EE_black  30 //6
 // FOTO0_DD  FOTO1_CD  FOTO2_CC  FOTO3_CE  FOTO4_EE
 //----------------------------------------------------------
 //----------------------------------------------------------
void testes_pontuais(void)
{
  while (0) // teste de leitura negro
  {
    #define  FOTO0_DD_black  100 //6
    Rodar_Dir();
    do
    {
      Leitura_Inf();
    }while(FOTO0_DD < FOTO0_DD_black);
    paragem();
  }
//----------------------------------------------------------  
  while (1)
  {
    entrada_em_pista();
    paragem();
  }
//----------------------------------------------------------
  while (0) // teste digital, analog com 2 motores. ponte em H
  {
    digitalWrite(mot_esq_1, HIGH);
    digitalWrite(mot_esq_2, LOW);
    analogWrite(Motor_Esq, 255); //  MOT LEFT (PWM) // INTERRUPTOR
    digitalWrite(Motor_Dir, 0); //  MOT LEFT (PWM
    digitalWrite(mot_dir_1, HIGH);  //digitalWrite(mot_dir_1, HIGH);
    digitalWrite(mot_dir_2, LOW);
    delay(1000);
    paragem();
  }
//----------------------------------------------------------  
  while (0)
  {
    digitalWrite(mot_esq_1, LOW);
    digitalWrite(mot_esq_2, LOW);
    digitalWrite(mot_dir_1, LOW);  //digitalWrite(mot_dir_1, HIGH);
    digitalWrite(mot_dir_2, LOW);

    analogWrite(Motor_Esq, 255); //  MOT LEFT (PWM) // INTERRUPTOR
    analogWrite(Motor_Dir, 255); //  MOT LEFT (PWM

    delay(1000);
    digitalWrite(mot_esq_1, HIGH);
    digitalWrite(mot_esq_2, LOW);
    digitalWrite(mot_dir_1, HIGH);  //digitalWrite(mot_dir_1, HIGH);
    digitalWrite(mot_dir_2, LOW);

    delay(1000);
    paragem();
  }
}


