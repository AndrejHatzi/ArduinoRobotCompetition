// cont_esq_sonar_dir

void em_pista_virar_esq_h_obst(void) 		// 432"10"  
{	// com (FOTO2CC<FOTO2_CC_w_black)  	LED2CC já no negro
  digitalWrite(StartLed,LOW);
  delay(100);
  rodar_1_4_esq();

  Parar();

  delay(15);
  digitalWrite(StartLed,HIGH);
  saida_de_90();
}


void retomar_pista_a_esquerda(void)
{
  delay(20);
  do
  {

    Leitura_Inf();
    if ((FOTO4_EE>FOTO4_EE_w_black) || (FOTO0_DD>FOTO0_DD_w_black))
    {
      recuar_2cm();
      em_pista_virar_esq_h_obst();
      break;
    }
    Leitura_Inf();
  }while (FOTO2_CC>FOTO2_CC_w_black);	
}


void em_frente_5cm_obst_cont_esq_sonar_dir(void)  // contornar pela esquerda
{	// ao rodar, o obstaculo ficou fora do sensor ESQ??
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  EmFrente();
  do  // segue ainda sem o obstaculo.
  {	

    delay(30);	
    Dist_Dir();
  }while (DistDir>30);
  delay(100);	// segue já com o obstaculo?.
  EmFrente();
  do
  {
    
    delay(30);	
    Dist_Dir();
  }while (DistDir>30);
  delay(10);
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  EmFrente();
  do	//segue com o obstaculo frente ao sensor DIR
  {

    delay(30);	
    Dist_Dir();
  }while (DistDir<30);
  delay(50);
  EmFrente();
  do
  {

    delay(30);	
    Dist_Dir();
  }while (DistDir<30);
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //.... JA PASSOU ??
  em_frente_5cm();
  Parar();
  delay(100);
}



void em_frente_30cm_obst_cont_esq_sonar_dir(void)
{ 	// contornar pela esquerda
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  em_frente_5cm();
  if (em_pista_fim_contornar==0)
  {// ** PISTA EM FRENTE/ANTES DO OBSTACULO ???? **
    EmFrente();
    do
    { 
      Leitura2_CC();
      if (FOTO2_CC< FOTO2_CC_black) 
      {
        delay(1);	
        Leitura2_CC();
        if (FOTO2_CC<FOTO2_CC_black) 
        {
          em_pista_virar_esq_h_obst();
          em_pista_fim_contornar=1;	// obstaculo colocado em L
          break;
        }
      }

      delay(30);	Dist_Esq();
    } while (DistEsq >20);
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  delay(100);

  if (em_pista_fim_contornar==0)
  {
    do
    {
      Leitura2_CC();
      if (FOTO2_CC<FOTO2_CC_black) 
      {
        delay(1);
        Leitura2_CC();
        if (FOTO2_CC<FOTO2_CC_black) 
        {
          em_pista_virar_esq_h_obst();
          em_pista_fim_contornar=1;	// obstaculo colocado em L
          break;
        }
      }

      delay(30);	Dist_Esq();
    } while (DistEsq <30);
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++

  if (em_pista_fim_contornar==0)
  {
    do
    {
      Leitura2_CC();
      if (FOTO2_CC<FOTO2_CC_black) 
      {
        delay(1);
        Leitura2_CC();
        if (FOTO2_CC<FOTO2_CC_black) 
        {
          em_pista_virar_esq_h_obst();
          em_pista_fim_contornar=1;	// obstaculo colocado em L
          break;
        }
      }

      delay(30);	 Dist_Esq();
    } while (DistEsq <30);
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Parar();
  delay(100);
  Recuar();
  do
  {
    delay(30);	  Dist_Esq();
  }   while (DistEsq >20);
  delay(200);
  // +++++++++++++// ja passou o obstaculo	
  //	teste_passagem();
}
void contornar_pela_esq_sonar_dir(void) 
{
  em_pista_fim_contornar=0;
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  rodar_1_4_esq();
//  rotate_TO_angulo(cmps10_contornar_5cm_esq);

  paragem();
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  em_frente_5cm_obst_cont_esq_sonar_dir();
  //  	em_frente_5cm();
  //		paragem();
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  rodar_1_4_dir();
//  rotate_TO_angulo(cmps10_contornar_30cm);  // == cmps10_contornar
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  em_frente_30cm_obst_cont_esq_sonar_dir();  //  1 vez
  //    em_frente_5cm();   
/*  ><><><><><><><><><><><><><><><><><><><><><><><>< */
  if (em_pista_fim_contornar==0)
  {
    rodar_1_4_dir();
//    rotate_TO_angulo(cmps10_contornar_30cm_2_esq);
    /*  ><><><><><><><><><><><><><><><><><><><><><>< */
    em_frente_30cm_obst_cont_esq_sonar_dir();  //+V+V+V
    /*  ><><><><><><><><><><><><><><><><><><><><><>< */
    if (em_pista_fim_contornar == 0)
    {
      em_frente_30cm_obst_cont_esq_sonar_dir();
      rodar_1_4_dir();
    }
  }	
  digitalWrite(StartLed,LOW);
  retomar_pista_a_esquerda();
}

