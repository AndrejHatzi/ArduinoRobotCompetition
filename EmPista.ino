/* .........................................................................................*/

/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | (7)a_sair_de_pista_virar_esq | (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais | (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir | (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/


// ..................................proporcional a leitura sensores inferiores.................ou..............


  // /********************************************************************************/
  // /******    se fosse utilizado DC_Motor_Esq ou DC_Motor_Dir até 1023    **********/
  // /****************************************************  teria que fazer-se  ******/
  // /******    DC_Motor_Esq=DC_Motor_Esq>>2;  /**************************************/
  // /******    DC_Motor_Dir=DC_Motor_Dir>>2;  /**************************************/
  // /********************************************************************************/
  // /******            ou:                    /**************************************/
  // /********************************************************************************/
  // /******    analogWrite(Motor_Esq, DC_Motor_Esq / 4);                  /**********/
  // /******    analogWrite(Motor_Dir, DC_Motor_Dir / 4);                  /**********/
  // *********************************************************************************/

// ***************************************************************
void LoadMotorEsqDirPwm(void)
{
  analogWrite( Motor_Esq, DC_Motor_Esq );
  analogWrite( Motor_Dir, DC_Motor_Dir );
}

/*
ForaDaPistaVirarEsq = 0;
ForaDaPistaVirarDir = 0;
*/
// ***************************************************************

void em_pista_virar_esq_90(void)
{
  ForaDaPistaVirarEsq = 1;
  ForaDaPistaVirarDir = 0;
  EmFrenteRed();
  delay(50);
  Leitura4_EE();
  if (FOTO4_EE < FOTO4_EE_black)
  {
    EmFrenteRed();    
    do
    {
      Leitura4_EE();
    }while(FOTO4_EE < FOTO4_EE_black);
    delay(50);
    //paragem();  // TESTE, para apagar    
    rodar_1_4_esq();
//    paragem();  // TESTE, para apagar    
    //saida_de_90();
    //delay(100);
    Em_Pista();
//    paragem();  // TESTE, para apagar
  }
}
// ***********************************************************************
void em_pista_virar_dir_90(void)
{ // cmps10 .. introduzir
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 1;
  EmFrenteRed();
  delay(50);
  Leitura0_DD();
  if (FOTO0_DD < FOTO0_DD_black)
  {
    EmFrenteRed();
    do
    {
      Leitura0_DD();
    }while(FOTO0_DD < FOTO0_DD_black);
    delay(50);
    rodar_1_4_dir();
//    paragem();    // TESTE, para apagar    
    //saida_de_90();
    Em_Pista();   
//   paragem();    // TESTE, para apagar
  }
}
// ***********************************************************************
// .............................................................................
void ContCiclosObstaculos(void)
{
   //cont_ciclos_obstaculos++;    
}
// .............................................................................
void pista_mais(void)  // pista=1,5
{
  ContCiclosObstaculos();
  DC_Motor_Esq=DutyCicleMotorEsqMais;
  DC_Motor_Dir=DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();
  forward();
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 0;
}

/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | (7)a_sair_de_pista_virar_esq | (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais | (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir | (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/

/*                    w3.....wb3....[b3.....b1.....wb1]......w1 */
void a_sair_de_pista_virar_esq(void)  // pista=7
{
  DC_Motor_Esq = map(FOTO1_CD, FOTO1_CD_w_black, FOTO1_CD_black, DutyCicleMotorEsqMin, DutyCicleMotorEsqMais);    // tstd
  DC_Motor_Dir = DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();
  forward();
  ForaDaPistaVirarEsq = 1;
  ForaDaPistaVirarDir = 0;
  ContCiclosObstaculos();
}
/*                    w3.....[wb3....b3.....b1].....wb1......w1                   */
void a_sair_de_pista_virar_dir(void)  // pista=8
{
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = map(FOTO3_CE, FOTO3_CE_w_black, FOTO3_CE_black, DutyCicleMotorDirMin, DutyCicleMotorDirMais);  // tstd  
  LoadMotorEsqDirPwm(); 
  forward();
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 1;
  ContCiclosObstaculos();
}
// .............................................................................
/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | (7)a_sair_de_pista_virar_esq | (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais | (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir | (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/
// .............................................................................
// .............................................................................
void saiu_pista_rodar_esq(void)  // pista=4
{
    ccw_esq();
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();
  digitalWrite(mot_esq_1, LOW);
  digitalWrite(mot_esq_2, HIGH);
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
//  paragem();
}
// .............................................................................


void saiu_pista_rodar_dir(void)  // pista = 6
{
//  cw_dir();
  DC_Motor_Esq=DutyCicleMotorRodarEsq;
  DC_Motor_Dir=DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm(); 
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
  digitalWrite(mot_dir_1, LOW);
  digitalWrite(mot_dir_2, HIGH);
 //   paragem();
}

// .............................................................................
/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | (7)a_sair_de_pista_virar_esq | (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais | (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir | (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/
/*                    w3.....[wb3....b3.....b1.....wb1......w1] */
void pista_mais_virar_esq_propor(void)  // pista=3
{
//  DC_Motor_Esq = map(FOTO3_CE, FOTO3_CE_w_black, FOTO3_CE_black,  DutyCicleMotorDirMin, DutyCicleMotorDirMais); 
  DC_Motor_Esq = map(FOTO3_CE, FOTO3_CE_w_black, FOTO3_CE_black,  DutyCicleMotorDirMais, DutyCicleMotorDirMin); 
  DC_Motor_Dir=DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();
  forward();
  ForaDaPistaVirarEsq = 1;
  ForaDaPistaVirarDir = 0;
}
// .............................................................................
/*                    [w3.....wb3....b3.....b1.....wb1]......w1   */
void pista_mais_virar_dir_propor(void)  // pista=2
{
  DC_Motor_Esq=DutyCicleMotorEsqMais;
//  DC_Motor_Dir = map(FOTO1_CD, FOTO1_CD_w_black, FOTO1_CD_black,  DutyCicleMotorEsqMin, DutyCicleMotorEsqMais);
  DC_Motor_Dir = map(FOTO1_CD, FOTO1_CD_w_black, FOTO1_CD_black,  DutyCicleMotorEsqMais, DutyCicleMotorEsqMin);
  LoadMotorEsqDirPwm();  
  forward();
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 1;
}
/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red |                (7)a_sair_de_pista_virar_esq |    (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais |                 (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir |      (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/
void pista_red(void)  // pista=9
{
  DC_Motor_Esq=DutyCicleMotorEsqReduzido;
  DC_Motor_Dir=DutyCicleMotorDirReduzido;
  LoadMotorEsqDirPwm();
  forward();
}
// .............................................................................
/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | (7)a_sair_de_pista_virar_esq | (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais | (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir | (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/
// .............................................................................
// .............................................................................
/* 
   if (digitalRead(BumperEsq) == 1)
   {
     Parar();
     VirarEsquerda();   delay(100);  Parar();
     Recuar();          delay(200);  Parar();
     VirarDireita();    delay(100);  Parar();
   }
   if (digitalRead(BumperDir) == 1)
   {
     Parar();
     VirarDireita();  delay(100);  Parar();
     Recuar();        delay(200);  Parar();
     VirarEsquerda(); delay(100);  Parar();
   }
*/

/* .........................................................................................*/
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | (7)a_sair_de_pista_virar_esq | (4)saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     (8)a_sair_de_pista_virar_dir | (5) pista_mais | (3)pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     (6)saiu_pista_rodar_dir | (2)pista_mais_virar_dir_propor | (1)pista_mais
/*    ...........w3.....wb3....b3.....b1.....wb1......w1................... */
/* .........................................................................................*/


void Em_Pista(void)
{
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 0;
  
  if((FOTO3_CE > FOTO3_CE_w_black) && (FOTO1_CD > FOTO1_CD_w_black))
  {                                                 
    pista_mais();     //............................................................................................... 1
  }
  else
  {
      if ((FOTO3_CE < FOTO3_CE_black) && (FOTO1_CD < FOTO1_CD_black))
      {                                            
        pista_red();  // ............................................................................................... 9	
      }
      else if ((FOTO3_CE > FOTO3_CE_black) && (FOTO3_CE < FOTO3_CE_w_black))      //.................................... 8,5,3
      { 
        if (FOTO1_CD < FOTO1_CD_black)					                                  {a_sair_de_pista_virar_dir();} //....  8
        else if (FOTO1_CD > FOTO1_CD_w_black)                                     {pista_mais_virar_esq_propor();}      //....  3	
        else if ((FOTO1_CD>FOTO1_CD_black)&&(FOTO1_CD<FOTO1_CD_w_black))          {pista_mais();}               ///....  5
      }
      else if ((FOTO1_CD > FOTO1_CD_black) && (FOTO1_CD < FOTO1_CD_w_black))      // ................................... 7,<5>,2
      { 
        if (FOTO3_CE < FOTO3_CE_black)					                                  {a_sair_de_pista_virar_esq();} //..... 7
        else if (FOTO3_CE > FOTO3_CE_w_black)                                     {pista_mais_virar_dir_propor();} /// ........ 2
      }
      else if ((FOTO3_CE > FOTO3_CE_w_black) || (FOTO1_CD > FOTO1_CD_w_black))
      {
         if ((FOTO3_CE < FOTO3_CE_black) && (FOTO1_CD > FOTO1_CD_w_black))        {saiu_pista_rodar_esq();} // ......... 4		
        else if ((FOTO3_CE > FOTO3_CE_w_black) && (FOTO1_CD < FOTO1_CD_black))    {saiu_pista_rodar_dir();} // ......... 6
      }
      else 									                                                      pista_red();  //  {paragem();}	//
  }
  if (cont_ciclos_obstaculos >= CountEmPistaSonar)
  {
    cont_ciclos_obstaculos=0;
    led_ON();
    Dist_Frnt();
    if (DistFrnt<=15)
    {
      Parar();
      delay(30);
      Dist_Frnt();
      if ((DistFrnt>4) && (DistFrnt<15))
      {
 //       Recuar();
        do
        {
          delay(20);
          Dist_Frnt();
        }while ((DistFrnt>4) && (DistFrnt<15));
        Parar();        
      }
      contornar();
    }
    led_OFF();  
  }
}

