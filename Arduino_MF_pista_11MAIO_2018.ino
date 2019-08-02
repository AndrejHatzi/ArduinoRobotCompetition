
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ..............  Give names to pins/variables  ..............................
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define  StartButton  39    //
#define  StartLed     41    // confirmar
#define  RedLed       41    // confirmar
#define  LedDir       41    // confirmar

#define  GreenLed     43    // confirmar
#define  LedEsq       43    // confirmar


// LedEsq  LedDir
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define  BumperEsq    51    // caso queiram instalar
#define  BumperDir    53    // caso queiram instalar
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

unsigned int  x,y,z;

// .................  /+ sensores inf  */ ................................
//   /*.............byte == unsigned char ...........  */
/* led infra vermelhos: pinos digitais:  38,40,42,44,46 */
/* pinos */
#define  Led_IR_Inf0  38      // LED IR 0 connected to digital pin 38
#define  Led_IR_Inf1  40      // LED IR 1 connected to digital pin 40
#define  Led_IR_Inf2  42      // LED IR 2 connected to digital pin 42
#define  Led_IR_Inf3  44      // LED IR 3 connected to digital pin 44
#define  Led_IR_Inf4  46      // LED IR 4 connected to digital pin 46
// .......................................................................
/* fototransistores: valores analogicos;0,1,2,3,4  */
/* pinos */
#define  FOTO0_DD_Pin  A0
#define  FOTO1_CD_Pin  A1
#define  FOTO2_CC_Pin  A2
#define  FOTO3_CE_Pin  A3
#define  FOTO4_EE_Pin  A4
/* variaveis */

#define numero_de_leituras  10
byte  cont_media_de_leituras=0;
unsigned int media_de_leituras = 0;  // leituras em pista

byte ForaDaPistaVirarEsq = 0;
byte ForaDaPistaVirarDir = 0;

unsigned int FOTO0_DD = 0;
unsigned int FOTO1_CD = 0;
unsigned int FOTO2_CC = 0;
unsigned int FOTO3_CE = 0;
unsigned int FOTO4_EE = 0;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// --------------------------------------------------------------
#define  FOTO0_DD_black   70  // 25 70
#define  FOTO1_CD_black   70  //  5 70
#define  FOTO2_CC_black   50  //  5 50
#define  FOTO3_CE_black   70  //  5 70
#define  FOTO4_EE_black   70  //  5 70
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define  FOTO0_DD_w_black  110
#define  FOTO1_CD_w_black  110
#define  FOTO2_CC_w_black  110
#define  FOTO3_CE_w_black  110
#define  FOTO4_EE_w_black  110
// --------------------------------------------------------------
//unsigned int FOTO0_DD_white = 220;
//unsigned int FOTO1_CD_white = 200;
//unsigned int FOTO2_CC_white = 190;
//unsigned int FOTO3_CE_white = 190;
//unsigned int FOTO4_EE_white = 200;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define  FOTO0_s     250
#define  FOTO0_DD_s  FOTO0_s    // Em Pista
#define  FOTO1_CD_s  FOTO0_s  
#define  FOTO2_CC_s  FOTO0_s  
#define  FOTO3_CE_s  FOTO0_s  
#define  FOTO4_EE_s  FOTO0_s  

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*  pwm  */
#define  Motor_Dir  12  // PWM :: Timer 1B
#define  Motor_Esq  11  // PWM :: Timer 1A

#define  mot_esq_1  23
#define  mot_esq_2  25
 
#define  mot_dir_1  27
#define  mot_dir_2  29

unsigned int  DC_Motor_Esq;
unsigned int  DC_Motor_Dir;


#define DutyCicleMotorEsqMais  250 // 250
#define DutyCicleMotorDirMais  250 // 250

#define DutyCicleMotorEsq  220 // 220
#define DutyCicleMotorDir  220 // 220

#define DutyCicleMotorEsqMenos  150
#define DutyCicleMotorDirMenos  150

#define DutyCicleMotorEsqReduzido  60
#define DutyCicleMotorDirReduzido  60

#define DutyCicleMotorEsqMin  60
#define DutyCicleMotorDirMin  60

// //++++++++++++++++ .. rodar .. +++++++++++++++++++++++++++++
#define DutyCicleMotorRodarEsqRed  150
#define DutyCicleMotorRodarDirRed  150 //160

#define DutyCicleMotorRodarEsq  180
#define DutyCicleMotorRodarDir  180

#define DutyCicleMotorRodarEsq  180
#define DutyCicleMotorRodarDir  180


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ................  /*  sonares  */ .....................................
/* pinos Trigger/echo:  */
#define  TRG_Esq   31
#define  Echo_Esq   33
  
#define  TRG_Frnt  35
#define  Echo_Frnt   37

#define  TRG_Dir   45
#define  Echo_Dir   47

/* variaveis */
unsigned int   DistDir   = 0;
unsigned int   DistFrnt  = 0;
unsigned int   DistEsq   = 0;        
unsigned int   duration  = 0; 
//unsigned int   distance  = 0;
unsigned long time;
unsigned long sizeofpulse;
float distance;
unsigned int cont_ciclos_obstaculos=0;  // contador

#define  CountEmPistaSonar 10
byte  ContornarPelaDirSonarEsq=0;
byte  ContornarPelaEsqSonarDir=0;
byte  em_pista_fim_contornar=0;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// .................. setup() ............Congig pins in/out  .................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup()
{
  pinMode(StartButton,INPUT);
  pinMode(StartLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(LedEsq, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(LedDir, OUTPUT);
  
  pinMode(BumperEsq, INPUT);
  pinMode(BumperDir, INPUT);
  
  pinMode(Led_IR_Inf0, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf1, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf2, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf3, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf4, OUTPUT);   // sets the pin as output  

  pinMode(Motor_Esq,OUTPUT);  //  MOT LEFT (PWM)
  pinMode(Motor_Dir,OUTPUT);  //  MOT LEFT (PWM
  
  pinMode(mot_esq_1, OUTPUT);  //  MOT LEFT (CW/CCW)
  pinMode(mot_esq_2, OUTPUT);  //  MOT LEFT (CW/CCW)
 
  pinMode(mot_dir_1, OUTPUT);  //  MOT RIGHT (CW/CCW)
  pinMode(mot_dir_2, OUTPUT);  //  MOT RIGHT (CW/CCW)
}


/**************************************************************/
/***************** Fundo Negro  ....  Pista Branca ************/
/**************************************************************/   

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ............... loop() .....   main()........................
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void loop()
{
    while(0)
    {
      //teste_START();
      //arranque_preparado();
      //led_ON();
       testes_leitura_movimento();  // < em: Teste_Leit_Mov.ino >
    }
   
    led_OFF();
    StartPosition();
    cont_ciclos_obstaculos=0;
    
    while(1)  //for(;;)  // while(1)
    {
      Leitura_Inf();
      //leituras_inf_teste();
      if(FOTO2_CC < FOTO2_CC_w_black)
      {
          if  ((FOTO4_EE>FOTO4_EE_s)||(FOTO3_CE>FOTO3_CE_s)||
               (FOTO1_CD>FOTO1_CD_s)||(FOTO0_DD>FOTO0_DD_s))                                   {silver_pista();}
          else if  ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_black))              {em_pista_virar_esq_90();}
          else if  ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_black))              {em_pista_virar_dir_90();} 
          else                                                                                 {Em_Pista();}
       }
      else                                                                                     {Sem_Pista();}
    } 
}

