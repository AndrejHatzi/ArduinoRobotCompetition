
void silver_pista(void)
{
  led_ON();
  EmFrente();
  Leitura_Inf();
    do
    {
      Leitura_Inf();
    }while (( FOTO4_EE>FOTO4_EE_s)||(FOTO3_CE>FOTO3_CE_s)||(FOTO2_CC>FOTO2_CC_s)||(FOTO1_CD>FOTO1_CD_s)||(FOTO0_DD>FOTO0_DD_s));
  led_OFF();    
  Parar();    
  for (x=0; x<10; x++)
  {
    led_ON();
    delay(250);
    led_OFF();
    delay(150);
  }
  paragem();
}

