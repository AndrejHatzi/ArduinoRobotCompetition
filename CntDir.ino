
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  sonar esq
//	      contornar dir  com  sonar esq
// sonar esq
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++EmFrenteContornarContornar
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void retomar_pista_a_direita(void)
{
  EmFrente();
  do
  {
    Leitura_Inf();
  }while((FOTO4_EE > FOTO4_EE_w_black) || (FOTO2_CC > FOTO2_CC_w_black) || (FOTO0_DD > FOTO0_DD_w_black)) ;
  Parar();
  delay(500);
  
  Rodar_Dir();
  do
  {
    Leitura4_EE();
  }while(FOTO4_EE > FOTO4_EE_black);

  Parar();
  entrada_em_pista();
//  paragem();
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ..........................com sonar esq
void em_frente_5cm_obst_cont_dir_sonar_esq(void)  // contornar pela direita
{	// ao rodar, o obstaculo ficou fora do sensor ESQ??
  EmFrente();
  delay(400);  // (+/-) 15 cm: construir 
  Dist_Esq();
  if (DistEsq<40)
  {
    EmFrente();  Leitura1_CD();
    do	//segue com o obstaculo frente ao sensor ESQ
    {
      delay(20);	
      Dist_Esq();
    }while (DistEsq<40);
  
    delay(10);
    EmFrente();
    
    do	//segue com o obstaculo frente ao sensor ESQ
    {
      delay(20);	
      Dist_Esq();
    }   while (DistEsq<40);
  }
              
  EmFrente();
  delay(300);  //  em_frente_10cm();
  Parar();
  delay(500);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// sonar esq
void em_frente_30cm_obst_cont_dir_sonar_esq(void) // contornar pela esquerda
{
  Dist_Esq();
  EmFrente();  
  if (DistEsq > 40)
  { 
    do
    {
      delay(20);	
      Dist_Esq();
    }while (DistEsq > 40);
  
    do
    {
      delay(20);	
      Dist_Esq();
    }while (DistEsq > 40);
  }
  
  do
  {
    delay(20);	
    Dist_Esq();
  }while (DistEsq < 40);

  do
  {
    delay(20);	
    Dist_Esq();
  }while (DistEsq < 40);
    
  EmFrente();
  delay(150);  //  //.... JA PASSOU
  Parar();
  delay(500);  
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++// sonar esq

void contornar_pela_dir_sonar_esq(void) 
{
  Parar();
  delay(500);
  
  rodar_1_4_dir();
//  paragem();

  em_frente_5cm_obst_cont_dir_sonar_esq(); 
// paragem();

  rodar_1_4_esq();
// Paragem();
 
  em_frente_30cm_obst_cont_dir_sonar_esq();  //  1 vez
// Paragem();

  rodar_1_4_esq();
// Paragem();

  retomar_pista_a_esquerda();
//  paragem();
}

