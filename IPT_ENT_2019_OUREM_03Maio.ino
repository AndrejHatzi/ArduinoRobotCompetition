
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ..............  Give names to pins/variables  ..............................
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define  StartButton  35     // V
#define  StartLed  37       // V

byte  x,y,z;

byte ForaDaPistaVirarEsq=0; 
byte ForaDaPistaVirarDir=0;


// .................  /+ sensores inf  */ ................................
/* led infra vermelhos: pinos digitais:  38,40,42,44,46 */
/* pinos */
#define    Led_IR_Inf0  38      // LED IR 0 connected to digital pin 38
#define    Led_IR_Inf1  40      // LED IR 1 connected to digital pin 40
#define    Led_IR_Inf2  42      // LED IR 2 connected to digital pin 42
#define    Led_IR_Inf3  44      // LED IR 3 connected to digital pin 44
#define    Led_IR_Inf4  46      // LED IR 4 connected to digital pin 46
// .......................................................................
/* fototransistores: valores analogicos;0,1,2,3,4  */
/* pinos */
#define    FOTO0_DD_Pin  A0
#define    FOTO1_CD_Pin  A1
#define    FOTO2_CC_Pin  A2
#define    FOTO3_CE_Pin  A3
#define    FOTO4_EE_Pin  A4
/* variaveis */


unsigned int FOTO0_DD = 0;  // leituras em pista
unsigned int FOTO1_CD = 0;  // leituras em pista
unsigned int FOTO2_CC = 0;  // leituras em pista
unsigned int FOTO3_CE = 0;  // leituras em pista
unsigned int FOTO4_EE = 0;  // leituras em pista


//++++++++++++++++++++++++  black < w_black < white  ++++++++++++++++++++++++++++++++++++++
////**** A DETERMINAR POR LEITURA EM PISTA:
#define  FOTO0_DD_black  100 //0 
#define  FOTO1_CD_black  100 //0 
#define  FOTO2_CC_black  100 //2
#define  FOTO3_CE_black  100 //0 
#define  FOTO4_EE_black  100 //0
// ++++   black < w_black < white  ++++++++++++++++++++++++++++++++++++++
#define  FOTO0_DD_w_black  170
#define  FOTO1_CD_w_black  170
#define  FOTO2_CC_w_black  175
#define  FOTO3_CE_w_black  175
#define  FOTO4_EE_w_black  175
// ++++   black < w_black < white  ++++++++++++++++++++++++++++++++++++++
#define  FOTO0_DD_white   244
#define  FOTO1_CD_white   244
#define  FOTO2_CC_white   244
#define  FOTO3_CE_white   244
#define  FOTO4_EE_white   244
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
////**** A DETERMINAR POR LEITURA EM PISTA:
#define  FOTO0_DD_silver  250
#define  FOTO1_CD_silver  250
#define  FOTO2_CC_silver  250
#define  FOTO3_CE_silver  250
#define  FOTO4_EE_silver  250
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*  pwm  */
#define  mot_esq_1  24
#define  mot_esq_2  26

#define  Motor_Esq  11  //  (12) old  (6) new - pinos
#define  Motor_Dir  12  //  (11) old  (7) new - pinos
 
#define  mot_dir_1  30
#define  mot_dir_2  28

byte  DC_Motor_Esq; // load -> Motor_Esq
byte  DC_Motor_Dir; // load -> Motor_Dir


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
// ................  /*  sonares  */ .....................................
/* pinos Trigger/echo*/
#define    TRG_Esq   23
#define    ECH_Esq   25

#define    TRG_Frnt  35
#define    ECH_Frnt  33

#define    TRG_Dir   53
#define    ECH_Dir   51

/* pinos Echo: 



/* variaveis */
unsigned int   DistDir   = 0;
unsigned int   DistFrnt  = 0;
unsigned int   DistEsq   = 0;        

unsigned long time_trg=0;
unsigned long time_ech=0;
unsigned long time_pulse=0;
unsigned long duration=0;
float distance=0; 
//unsigned long distance=0; 
unsigned int state=0;


unsigned int cont_ciclos_obstaculos=0;  // contador
#define  CountEmPistaSonar 50

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// .................. setup() ............Congig pins in/out  .................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define DutyCicleMotorEsqMais  255
#define DutyCicleMotorDirMais  255

#define DutyCicleMotorEsq  200
#define DutyCicleMotorDir  200

#define DutyCicleMotorEsqMenos  180
#define DutyCicleMotorDirMenos  180

#define DutyCicleMotorEsqRed 160
#define DutyCicleMotorDirRed 160


#define DutyCicleMotorEsqMin 160
#define DutyCicleMotorDirMin 160
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define DutyCicleMotorRodarEsq  200
#define DutyCicleMotorRodarDir  200
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void setup()
{
  pinMode(StartButton,INPUT);
  pinMode (StartLed, OUTPUT);
    
  pinMode(Led_IR_Inf0, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf1, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf2, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf3, OUTPUT);   // sets the pin as output
  pinMode(Led_IR_Inf4, OUTPUT);   // sets the pin as output  
  
  pinMode(TRG_Dir, OUTPUT);   // sets the pin as output  
  pinMode(TRG_Frnt, OUTPUT);   // sets the pin as output  
  pinMode(TRG_Esq, OUTPUT);   // sets the pin as output  

  pinMode(ECH_Dir, INPUT);   // sets the pin as INPUT  
  pinMode(ECH_Frnt,INPUT);   // sets the pin as INPUT    
  pinMode(ECH_Esq, INPUT);   // sets the pin as INPUT   
 
  pinMode(Motor_Esq,OUTPUT);  //  MOT LEFT (PWM)
  pinMode(Motor_Dir,OUTPUT);  //  MOT LEFT (PWM
  
  pinMode (mot_esq_1, OUTPUT);  //  MOT LEFT (CW/CCW)
  pinMode (mot_esq_2, OUTPUT);  //  MOT LEFT (CW/CCW)
 
  pinMode (mot_dir_1, OUTPUT);  //  MOT RIGHT (CW/CCW)
  pinMode (mot_dir_2, OUTPUT);  //  MOT RIGHT (CW/CCW)

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ............... loop() .....   main().......................................
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loop()
{
    while(0)
    {
       testes_leitura_movimento();  // < em: Teste_Leit_Mov.ino >
       //teste_START();
       //foto40bwhite();
       //RodarEsqRed(); delay(1000);
       paragem();
    }
   

//    StartPosition();      // ou ..."  StartButtonPosition() " definida em  "start_position_do_while.ino " .. 
    cont_ciclos_obstaculos=0;
  
   for(;;)  //while(1) ou  for(;;)    //  ...Fundo Negro..||..Pista Branca..||...Fundo Negro ...
    {
      Leitura_Inf();
      if ((FOTO4_EE < FOTO4_EE_black) && (FOTO0_DD > FOTO0_DD_black)){
        //virar 90 graus esq
        PistaViraEsq();
      }
      else if ((FOTO4_EE > FOTO4_EE_black) && (FOTO0_DD < FOTO0_DD_black)){
         //virar 90 graus dir
         PistaViraDir();
      }
      else{
        em_pista();
      }
      }
      /*        
     if ((FOTO4_EE > FOTO4_EE_silver)||(FOTO0_DD > FOTO0_DD_silver ))    silver();
      if (FOTO2_CC  > FOTO2_CC_w_black)                                   em_pista();
      else*/	                                                              fora_de_pista();// 	 ((FOTO2_CC  <= FOTO2_CC_w_black) 
}

