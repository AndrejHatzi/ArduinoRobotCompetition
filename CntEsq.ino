
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  sonar dir
//	      contornar esq   com  sonar dir
// sonar dir
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void retomar_pista_a_esquerda(void)
{
  EmFrente();
  do
  {
    Leitura_Inf();
  }while((FOTO4_EE > FOTO4_EE_w_black) || (FOTO2_CC > FOTO2_CC_w_black) || (FOTO0_DD > FOTO0_DD_w_black)) ;
  Parar();
  delay(500);
  
  Rodar_Esq();
  do
  {
    Leitura0_DD();
  }while(FOTO0_DD > FOTO0_DD_black);

  Parar();
  entrada_em_pista();
//  paragem();
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ..........................com sonar dir
void em_frente_5cm_obst_cont_esq_sonar_dir(void)  // contornar pela esquerda
{	// ao rodar, o obstaculo ficou fora do sensor ESQ??
  EmFrente();
  //////  delay(400);  // (+/-) 15 cm: construir 
  Dist_Dir();
  if (DistDir<40)
  {
    EmFrente();
    do	//segue com o obstaculo frente ao sensor DIR
    {
      delay(20);	
      Dist_Dir();
    }while (DistDir<40);
  
    delay(10);
    EmFrente();
    
    do	//segue com o obstaculo frente ao sensor DIR // Repete 
    {
      delay(20);	
      Dist_Dir();
    }   while (DistDir<40);
  }
  
// Passou o obstaculo
              
  EmFrente();
  delay(150);  //  em_frente_20cm();
  Parar();
  delay(500);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// sonar dir
void em_frente_30cm_obst_cont_esq_sonar_dir(void) // contornar pela esquerda
{
  Dist_Dir();
  EmFrente();  
  if (DistDir > 40) // ainda antes do obstaculo
  { 
    do
    {
      delay(20);	
      Dist_Dir();
    }while (DistDir > 40);
  
    do  // Repete
    {
      delay(20);	
      Dist_Dir();
    }while (DistDir > 40);
  }

// frente ao obstaculo sensor dir

  do
  {
    delay(20);	
    Dist_Dir();
  }while (DistDir < 40);

  do
  {
    delay(20);	
    Dist_Dir();
  }while (DistDir < 40);
    
  EmFrente();
  
  delay(150);  //  //.... JA PASSOU 20 cm
  Parar();
  delay(500);  
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++// sonar dir

void contornar_pela_esq_sonar_dir(void) 
{
  Parar();
  delay(500);
  
  rodar_1_4_esq();
//  paragem();

  em_frente_5cm_obst_cont_esq_sonar_dir();
  // paragem();

  rodar_1_4_dir();
  // Paragem();
 
  em_frente_30cm_obst_cont_esq_sonar_dir();  //  1 vez
  // Paragem();  
  rodar_1_4_dir();
  // Paragem();
    
  retomar_pista_a_direita();
//  paragem();
}

