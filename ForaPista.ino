// ......................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ......................................................................

// ......................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
  ForaDaPistaVirarEsq=0;
  ForaDaPistaVirarDir=0;
*/
// ......................................................................
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
#define uscontornar  200
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
void ContornarCurvaPara_a_Esq(void) // 4.3.2.1.0
{
  ForaDaPistaVirarEsq = 1;
  ForaDaPistaVirarDir = 0;
  Rodar_Esq();
  do
  {
    Leitura1_CD();
  } while (FOTO1_CD < FOTO1_CD_black);
  delay(1);
  do
  {
    Leitura1_CD();
  } while (FOTO1_CD < FOTO1_CD_black);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ContornarCurvaPara_a_Dir(void) // 4.3.2.1.0
{
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 1;

  Rodar_Dir();
  do
  {
    Leitura3_CE();
  } while (FOTO3_CE < FOTO3_CE_black);
  delay(1);
  do
  {
    Leitura3_CE();
  } while (FOTO3_CE < FOTO3_CE_black);
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void fora_de_pista(void)
{
  paragem();
  while (0)
  {
    ///   Leitura_Inf();
    if (((FOTO4_EE > FOTO4_EE_w_black) || (FOTO3_CE > FOTO3_CE_w_black) )  && ((FOTO1_CD < FOTO1_CD_black) || (FOTO0_DD < FOTO0_DD_black)))
    {
      ForaDaPistaVirarEsq = 1;
      ForaDaPistaVirarDir = 0;
    }

    else if   (((FOTO4_EE < FOTO4_EE_w_black) || (FOTO3_CE < FOTO3_CE_w_black) )  && ((FOTO1_CD > FOTO1_CD_black) || (FOTO0_DD > FOTO0_DD_black)))
    {
      ForaDaPistaVirarEsq = 0;
      ForaDaPistaVirarDir = 1;
    }
    if ((FOTO4_EE > FOTO4_EE_silver) || (FOTO0_DD > FOTO0_DD_silver ))    paragem();
    if ((ForaDaPistaVirarEsq == 1) && (ForaDaPistaVirarDir == 0))             ContornarCurvaPara_a_Esq();
    else if ((ForaDaPistaVirarEsq == 0) && (ForaDaPistaVirarDir == 1))        ContornarCurvaPara_a_Dir();
    else                                                                paragem();
  }
}
