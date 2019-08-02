// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ...........................................................................
void ContCiclosObstaculos(void)
{
  //cont_ciclos_obstaculos++;  // primeira e sem obstaculos
}
// ...........................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ...........................................................................
void LoadMotorEsqDirPwm(void)
{
  analogWrite(Motor_Esq, DC_Motor_Esq);   //  byte  DC_Motor_Esq; // load -> Motor_Esq
  analogWrite(Motor_Dir, DC_Motor_Dir);   //  byte  DC_Motor_Dir; // load -> Motor_Dir
}
// ...........................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
  if   ((FOTO4_EE > FOTO4_EE_w_black) && (FOTO0_DD > FOTO0_DD_w_black ))          EmPista(); // (9) (W)(W)  EmPistaRed (curva, pista larga, cruzamento)
  else if   ((FOTO4_EE > FOTO4_EE_black) && (FOTO4_EE < FOTO4_EE_w_black) &&
             (FOTO0_DD < FOTO0_DD_w_black) && (FOTO0_DD > FOTO0_DD_black ))       EmPista();    // (5) (wb)(wb) EmPista
  else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_black ))           EmPista();    // (1) (b)(b) pista_mais  (pista estreita)
*/
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void pista_mais(void)                //(1) pista_mais();  // (1) (b)(b) pista_mais
{
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = DutyCicleMotorDirMais;
  Forward();
  LoadMotorEsqDirPwm();
  // ++++++++++++++++++++
  ContCiclosObstaculos();
  // ++++++++++++++++++++
}
// .............................................................................
void EmPista(void)                // (5)EmPista();  // (5) (wb)(wb) EmPista
{
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = DutyCicleMotorDirMais;
  Forward();
  LoadMotorEsqDirPwm();
  // ++++++++++++++++++++
  ContCiclosObstaculos();
  // ++++++++++++++++++++
}
// .............................................................................
void EmPistaRed(void)               // (9)  // (9) (W)(W)  EmPistaRed
{
  DC_Motor_Esq = DutyCicleMotorEsq;
  DC_Motor_Dir = DutyCicleMotorDir;
  Forward();
  LoadMotorEsqDirPwm();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
  else if ((FOTO4_EE< FOTO4_EE_black) && ((FOTO0_DD> FOTO0_DD_black )&& (FOTO0_DD< FOTO0_DD_w_black )))  pista_virar_dir_p0();
*/
void pista_virar_dir_p0(void) // (2) (b)(wb)
{
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = map(FOTO0_DD, FOTO0_DD_black, FOTO0_DD_w_black, DutyCicleMotorDirRed, DutyCicleMotorDirMais );
  Forward();
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
  // ++++++++++++++++++++
  ContCiclosObstaculos();  // primeira e sem sem obstaculos
  // ++++++++++++++++++++
//  paragem();
}
// ......................................................................
/*
  else if (((FOTO4_EE> FOTO4_EE_black) && (FOTO4_EE< FOTO4_EE_w_black))&& (FOTO0_DD< FOTO0_DD_black ))    pista_virar_esq_p4();
*/
void pista_virar_esq_p4(void)
{
  DC_Motor_Esq = map(FOTO4_EE, FOTO4_EE_black, FOTO4_EE_w_black , DutyCicleMotorEsqRed, DutyCicleMotorEsqMais);
  DC_Motor_Dir = DutyCicleMotorDirMais; //FRW
  Forward();
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
  // ++++++++++++++++++++
  ContCiclosObstaculos();  // primeira e sem sem obstaculos
  // ++++++++++++++++++++
//    paragem();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_w_black))  // Com3 – rodar ou virar
    if (FOTO3_CE > FOTO3_CE_w_black)                                                    PistaViraDir();
*/
void PistaViraDir(void) // (6) (wb)(W) PistaViraDir // introduzir prporcional ????
{
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = DutyCicleMotorEsqRed;
  Forward();
  LoadMotorEsqDirPwm();
  // ++++++++++++++++++++
  ContCiclosObstaculos();  // primeira e sem sem obstaculos
  // ++++++++++++++++++++
//    paragem();
}
/*
  else if ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_w_black))  // Com1– rodar ou virar
       if (FOTO1_CD > FOTO1_CD_w_black)                                                    PistaViraEsq();
*/
void PistaViraEsq(void)
{
  DC_Motor_Esq = DutyCicleMotorEsqRed; //0??
  DC_Motor_Dir = DutyCicleMotorDirMais;
  Forward();
  LoadMotorEsqDirPwm();
  // ++++++++++++++++++++
  ContCiclosObstaculos();  // primeira e sem sem obstaculos
  // ++++++++++++++++++++
  //  paragem();
}
// ......................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_w_black))  // Com3 – rodar ou virar
     else if ((FOTO3_CE > FOTO3_CE_black) && (FOTO3_CE < FOTO3_CE_w_black))              PistaViraDirMais();
*/
void PistaViraDirMais(void) // (6) (wb)(W) PistaViraDir
{
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = DutyCicleMotorEsqMin; // 0 (???)
  Forward();
  LoadMotorEsqDirPwm();
  // ++++++++++++++++++++
  ContCiclosObstaculos();  // primeira e sem sem obstaculos
  // ++++++++++++++++++++
//  paragem();
}

/*
  else if ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_w_black))  // Com1– rodar ou virar
      else if ((FOTO1_CD > FOTO1_CD_black) && (FOTO1_CD < FOTO1_CD_w_black))              PistaViraEsqMais();
*/
void PistaViraEsqMais(void)
{
  DC_Motor_Esq = DutyCicleMotorDirMin; //0??
  DC_Motor_Dir = DutyCicleMotorDirMais;
  Forward();
  LoadMotorEsqDirPwm();
  // ++++++++++++++++++++
  ContCiclosObstaculos();  // primeira e sem sem obstaculos
  // ++++++++++++++++++++
//  paragem();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ......................................................................
/*
 else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_w_black))  // Com3 – rodar ou virar
     else if (FOTO3_CE < FOTO3_CE_black)                                                 saiu_pista43_rodar_dir();
  // Com3 – rodar ou virar
*/
void saiu_pista43_rodar_dir(void)   // // (3) (b)(W) saiu_pista43_rodar_dir // Com3 – rodar ou virar
{
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 1;
  cw();
  DC_Motor_Esq = DutyCicleMotorEsqMais;
  DC_Motor_Dir = DutyCicleMotorDirMais;
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
  do
  {
    Leitura6_GND();
    Leitura3_CE();
  }while(FOTO3_CE < FOTO3_CE_black);
  ccw();
  delay(10);
  entrada_em_pista();
  paragem();
}
/////.........
/*
  else if ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_w_black))  // Com1– rodar ou virar
      else if(FOTO1_CD < FOTO1_CD_w_black)                                                saiu_pista01_rodar_esq();
*/
void saiu_pista01_rodar_esq(void)  //// (7) (W)(b) saiu_pista01_rodar_esq  // Com1– rodar ou virar
{
  ForaDaPistaVirarEsq = 1;
  ForaDaPistaVirarDir = 0;
  ccw();                              //   ccw(); DutyCicleMotorEsqRed
  DC_Motor_Esq = DutyCicleMotorRodarEsq;
  DC_Motor_Dir = DutyCicleMotorRodarDir;
  LoadMotorEsqDirPwm();   // < EmPista.ino > com DutyCicleMotorEsq .. DutyCicleMotorDir <=255
  do
  {
    Leitura6_GND();
    Leitura1_CD();
  } while (FOTO1_CD < FOTO1_CD_black);
  cw();
  delay(10);
  entrada_em_pista();
  paragem();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ......................................................................
// ......................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ......................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void em_pista(void)
{
  ForaDaPistaVirarEsq = 0;
  ForaDaPistaVirarDir = 0;

  //                                   Fundo Negro(0) ... Pista Branca(255) ... Fundo Negro(0)
  // ................................................................Branco(255)....Negro (0) ..sensores(4.3.2.1.0)

  if   ((FOTO4_EE > FOTO4_EE_w_black) && (FOTO0_DD > FOTO0_DD_w_black ))          EmPista();
  else if   ((FOTO4_EE > FOTO4_EE_black) && (FOTO4_EE < FOTO4_EE_w_black) &&
             (FOTO0_DD < FOTO0_DD_w_black) && (FOTO0_DD > FOTO0_DD_black ))       EmPista();
  else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_black ))           EmPista();

  // ...............................................................................................................................

  else if ((FOTO4_EE < FOTO4_EE_black) && ((FOTO0_DD > FOTO0_DD_black ) && (FOTO0_DD < FOTO0_DD_w_black )))  pista_virar_dir_p0();
  else if (((FOTO4_EE > FOTO4_EE_black) && (FOTO4_EE < FOTO4_EE_w_black)) && (FOTO0_DD < FOTO0_DD_black ))    pista_virar_esq_p4();

  // ...............................................................................................................................



  else if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_w_black))  // Com3 – rodar ou virar
  {
    if (FOTO3_CE > FOTO3_CE_w_black)                                                    PistaViraDir();
    else if ((FOTO3_CE > FOTO3_CE_black) && (FOTO3_CE < FOTO3_CE_w_black))              PistaViraDirMais();
    else if (FOTO3_CE < FOTO3_CE_black)                                                 saiu_pista43_rodar_dir();
  }

  else if ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_w_black))  // Com1– rodar ou virar
  {
    if (FOTO1_CD > FOTO1_CD_w_black)                                                    PistaViraEsq();
    else if ((FOTO1_CD > FOTO1_CD_black) && (FOTO1_CD < FOTO1_CD_w_black))              PistaViraEsqMais();
    else if(FOTO1_CD < FOTO1_CD_w_black)                                                saiu_pista01_rodar_esq();
  }
  // ...............................................................................................................................
  else                                                                            EmPistaRed();
  // ...............................................................................................................................
  // ...............................................................................................................................
  if (cont_ciclos_obstaculos >= CountEmPistaSonar)
  {
    cont_ciclos_obstaculos = 0; // ... local correcto
    EmFrenteMin();
    delay(20);
    Dist_Frnt();
    if ((DistFrnt < 15))
    {
      Parar();
      delay(500);
      //     paragem();
      contornar();
    }
  }
}
//......................................................................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
