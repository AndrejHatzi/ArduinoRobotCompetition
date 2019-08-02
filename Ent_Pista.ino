

void entrada_em_pista(void)
{
  Para();
  delay(250);
  Leitura_Inf();
  EmFrenteRed();
  if ((FOTO4_EE < FOTO4_EE_black) || (FOTO0_DD < FOTO0_DD_black))
  {
    do
    {
      do
      {
        Leitura_Inf();
        if ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_black))
        {
          ccw();
          do 
          {
            //Leitura6_GND; Leitura0_DD();
            Leitura_Inf();
          }while(FOTO0_DD < FOTO0_DD_black);
        }
        else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_black))
        {
          cw();
          do 
          {
            //Leitura6_GND; Leitura4_EE();
            Leitura_Inf();
          }while(FOTO4_EE < FOTO4_EE_black);
        }
        EmFrenteRed();  //EmFrenteRed();
        delay(10);
        Leitura_Inf();
      }while(((FOTO4_EE < FOTO4_EE_black) || (FOTO0_DD < FOTO0_DD_black))&&(FOTO2_CC < FOTO2_CC_black)); // (FOTO2_CC < FOTO2_CC_black)->pista
      EmFrenteRed();
      delay(5);
      Leitura_Inf();
    }while(((FOTO4_EE < FOTO4_EE_black) || (FOTO0_DD < FOTO0_DD_black))&&(FOTO2_CC < FOTO2_CC_black)); // (FOTO2_CC < FOTO2_CC_black)->pista
  }
  paragem();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

