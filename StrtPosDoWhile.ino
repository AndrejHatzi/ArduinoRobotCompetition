//
// **********************************************************************
byte  StartReady = 0;
/*
void arranque_preparado(void)
{
    led_ON();
    delay(250);
    
    led_OFF();
    delay(100);	
    
    led_ON();
    delay(250);
    
    led_OFF();
    delay(50);	
}
*/

void StartButtonPosition(void)
{
  led_OFF();
  travado();
  delay(100);

// StartButton_position:
  while(1)
  {
    do
    {
      Leitura_Inf();
      if (FOTO2_CC<FOTO2_CC_black)
      {
        if ((FOTO1_CD>FOTO1_CD_black) && (FOTO3_CE>FOTO3_CE_black))	// Normal
        {
          arranque_preparado();
          StartReady=1;
        }
        else
        {
          led_OFF();
        }
      }
      // .............................................
      if (StartReady==1) //	(Botao ainda nao premido)
      {
        delay(10);
        if (StartButton==1) 
        {
          delay(100);	// confirmar
          if (StartButton==1) 
          {
            led_OFF();
            break;
          }
        }
       }
    }while((FOTO1_CD<FOTO1_CD_black) || (FOTO3_CE<FOTO3_CE_black));
    // .............................................
    if (StartButton==1)	//	(Botao premido) 
    {
      do
      {
          led_ON();
          delay(100);
          if (StartButton==1)
          {
            delay(200);
            if (StartButton==0) break;
          }
      }while(StartButton==1);	//(liberta botao de arranque)
    }
    else StartReady=0;
    // .............................................
    if (StartReady==1) break;
	
  led_OFF();
  }
}
