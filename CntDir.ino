// cont_ dir _sonar_ esq
void em_pista_virar_dir_h_obst(void) 		// 432"10"  
{// com (FOTO2CC<FOTO2_CC_w_black) LED2CC já no negro
  digitalWrite(StartLed,LOW);
  delay(100);
  rodar_1_4_dir();

  Parar();

  delay(15);
  digitalWrite(StartLed,HIGH);
  saida_de_90();
}


void retomar_pista_a_direita(void)
{
  delay(20);
  do
  {

    Leitura_Inf();
    if ((FOTO4_EE>FOTO4_EE_w_black) || (FOTO0_DD>FOTO0_DD_w_black))
    {
      recuar_2cm();
      em_pista_virar_dir_h_obst();
      break;
    }
    Leitura_Inf();
  }while (FOTO2_CC>FOTO2_CC_w_black);
}


void em_frente_5cm_obst_cont_dir_sonar_esq(void) // contornar pela direita
{	//:: ao rodar, o obstaculo ficou fora do sensor DIR??
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  EmFrente();
  do		// segue ainda sem o obstaculo.				
  {

    delay(30);	
    Dist_Esq();
  } while (DistEsq>30);
  delay(100);
  EmFrente();	// segue ainda sem  o obstaculo ?
  do	
  {

    delay(30);	
    Dist_Esq();
  }while (DistEsq>30);
  delay(10);
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  EmFrente();
  do	//segue com o obstaculo ja frente ao sensor ESQ
  {

    delay(30);	
    Dist_Esq();
  }while (DistEsq<30);
  delay(50);
  EmFrente();	//verificar se o obstaculo frente ao sensor ESQ ainda esta presente
  do
  {

    delay(30);    
    Dist_Esq();
  }while (DistEsq<30);
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //.... JA PASSOU ??
  em_frente_5cm(); 
  Parar();
  delay(100);
}



void em_frente_30cm_obst_cont_dir_sonar_esq(void)
{ 	// contornar pela direita
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  em_frente_5cm();
  if (em_pista_fim_contornar==0)  
  {	// ** PISTA EM FRENTE/ANTES DO OBSTACULO ???? ** 
    EmFrente ();
    do
    {
      Leitura2_CC();
      if (FOTO2_CC < FOTO2_CC_black) 
      {
        delay(1);	
        Leitura2_CC();
        if (FOTO2_CC < FOTO2_CC_black) 
        {
          em_pista_virar_dir_h_obst();
          em_pista_fim_contornar=1;	// obstaculo colocado em L
          break;
        }
      }

      delay(30);	Dist_Esq();
    }while (DistEsq >20);
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  delay(100);  // .............. obstaculo a esquerda

  if (em_pista_fim_contornar==0)
  {
    do
    {
      Leitura2_CC();
      if (FOTO2_CC < FOTO2_CC_black) 
      {
        delay(1);
        Leitura2_CC();
        if (FOTO2_CC < FOTO2_CC_black) 
        {
          em_pista_virar_dir_h_obst();
          em_pista_fim_contornar=1;	// obstaculo colocado em L
          break;
        }
      }

      delay(30);	Dist_Esq();
    }while (DistEsq <30);
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++

  if (em_pista_fim_contornar==0)  // verificar se obstaculo ainda a esquerda
  {
    do
    {
      Leitura2_CC();
      if (FOTO2_CC < FOTO2_CC_black) 
      {
        delay(1);
        Leitura2_CC();
        if (FOTO2_CC < FOTO2_CC_black) 
        {
          em_pista_virar_dir_h_obst();
          em_pista_fim_contornar=1;	// obstaculo colocado em L
          break;
        }
      }

      delay(30);	Dist_Esq();
    }while (DistEsq <30);
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Parar();
  delay(100);
  Recuar();  // verificar apos teste se necessario
  do
  {
    delay(30);	Dist_Esq();
  }   while (DistEsq > 20);
  delay(200);
  // +++++++++++++// ja passou o obstaculo	
  //	teste_passagem();
}
void contornar_pela_dir_sonar_esq(void)
{
  em_pista_fim_contornar=0;
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  rodar_1_4_dir();
  //paragem();
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  em_frente_5cm_obst_cont_dir_sonar_esq();
  // em_frente_5cm(); ????
  //paragem();
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  rodar_1_4_esq();

/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  em_frente_30cm_obst_cont_dir_sonar_esq();
  //  em_frente_5cm(); ????
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  if (em_pista_fim_contornar==0)
  {
    rodar_1_4_esq();

    /*  ><><><><><><><><><><><><><><><><><><><><><>< */  
    em_frente_30cm_obst_cont_dir_sonar_esq();
    /*  ><><><><><><><><><><><><><><><><><><><><><>< */
    if (em_pista_fim_contornar == 0)  //+V+V+V
    {
      em_frente_30cm_obst_cont_dir_sonar_esq();
//      rodar_1_4_esq();
    }
  }  
  digitalWrite(StartLed,LOW);
//  retomar_pista_a_direita();
}

