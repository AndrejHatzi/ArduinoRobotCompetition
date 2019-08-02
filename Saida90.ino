

void saida_de_90(void)
{
  EmFrenteRed();
  delay(50);
//******************************************  
//*******************************************
  Leitura_Inf();
  do
  {   
    do
    {
      Leitura1_CD();
      Leitura3_CE();
      if ((FOTO3_CE > FOTO3_CE_black)&&(FOTO1_CD < FOTO1_CD_black))
      {
        RodarDirRed();
        do 
        { 
          Leitura1_CD();
          //Leitura3_CE();
        }while  ((FOTO1_CD < FOTO1_CD_black));  // (FOTO3_CE > FOTO3_CE_w_black)&&
      }
      else if ((FOTO3_CE < FOTO3_CE_black)&&(FOTO1_CD > FOTO1_CD_black))
      {
        RodarEsqRed();
        do 
        {
          //Leitura3_CE();
          Leitura1_CD();
        }while  ((FOTO3_CE < FOTO3_CE_black));  //&&(FOTO1_CD > FOTO1_CD_w_black));
      }
      EmFrenteRed();      
      delay(250); // 50
      Leitura_Inf();
    }while ((FOTO3_CE<FOTO3_CE_black) || (FOTO1_CD<FOTO1_CD_black));  //((FOTO3_CE>FOTO3_CE_white) || (FOTO1_CD>FOTO1_CD_white));  /// 

    EmFrenteRed();
    Leitura3_CE();  
    Leitura4_EE();
    delay(250); //10
  }while(( FOTO4_EE < FOTO4_EE_black)||(FOTO0_DD < FOTO0_DD_black));
//  EmFrenteRed();
}

