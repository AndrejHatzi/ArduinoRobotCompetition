
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | [7]a_sair_de_pista_virar_esq | [4]saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     [8]a_sair_de_pista_virar_dir | (5) pista_mais | [3]pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     [6]saiu_pista_rodar_dir | [2]pista_mais_virar_dir_propor | (1)pista_mais
void leituras_inf_teste(void)
{
  FOTO0_DD = FOTO0_DD_black+1;
  FOTO4_EE = FOTO4_EE_black+1;
  FOTO2_CC = FOTO2_CC_black-1;
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | [7]a_sair_de_pista_virar_esq | [4]saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     [8]a_sair_de_pista_virar_dir | (5) pista_mais | [3]pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     [6]saiu_pista_rodar_dir | [2]pista_mais_virar_dir_propor | (1)pista_mais  
  if(0) {FOTO3_CE = FOTO3_CE_black-1;      FOTO1_CD = FOTO1_CD_black-1;}     // 9
  if(0) {FOTO3_CE = FOTO3_CE_black-1;      FOTO1_CD = FOTO1_CD_black+1; }    // 7 
    if(0) {FOTO3_CE = FOTO3_CE_black-1;      FOTO1_CD = FOTO1_CD_w_black-1; }    // 7 
  if(0) {FOTO3_CE = FOTO3_CE_black-1;      FOTO1_CD = FOTO1_CD_w_black+1;}   // 4    
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | [7]a_sair_de_pista_virar_esq | [4]saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     [8]a_sair_de_pista_virar_dir | (5) pista_mais | [3]pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     [6]saiu_pista_rodar_dir | [2]pista_mais_virar_dir_propor | (1)pista_mais  
  if(0) {FOTO3_CE = FOTO3_CE_w_black-1;      FOTO1_CD = FOTO1_CD_black-1;}     //  8
    if(0) {FOTO3_CE = FOTO3_CE_black+1;      FOTO1_CD = FOTO1_CD_black-1;}     //  8  
  if(0) {FOTO3_CE = FOTO3_CE_black+1;      FOTO1_CD = FOTO1_CD_black+1;}    // 5
  if(0) {FOTO3_CE = FOTO3_CE_black+1;      FOTO1_CD = FOTO1_CD_w_black+1;}   //  3 
    if(0) {FOTO3_CE = FOTO3_CE_w_black-1;      FOTO1_CD = FOTO1_CD_w_black+1;}   //  3 
//                 led1_black     led1_w_black    
//            9        |     7       |      4     (9)pista_red | [7]a_sair_de_pista_virar_esq | [4]saiu_pista_rodar_esq
// led3_black          -             -      
//            8        |     5       |      3     [8]a_sair_de_pista_virar_dir | (5) pista_mais | [3]pista_mais_virar_esq_propor
// led3_w_black        -             -                
//            6        |     2       |      1     [6]saiu_pista_rodar_dir | [2]pista_mais_virar_dir_propor | (1)pista_mais    
  if(0) {FOTO3_CE = FOTO3_CE_w_black+1;    FOTO1_CD = FOTO1_CD_black-1;}  //   6
  if(0) {FOTO3_CE = FOTO3_CE_w_black+1;    FOTO1_CD = FOTO1_CD_black+1;}   //   2
    if(0) {FOTO3_CE = FOTO3_CE_w_black+1;    FOTO1_CD = FOTO1_CD_w_black-1;}   //   2
  if(1) {FOTO3_CE = FOTO3_CE_w_black+1;    FOTO1_CD = FOTO1_CD_w_black+1;}   // 1  
}

// +++++++++++++++++++

void teste_pwm_min(void)
{
  DC_Motor_Esq=0;
  DC_Motor_Dir=100;
  LoadMotorEsqDirPwm();
  
  digitalWrite(mot_esq_1, HIGH);
  digitalWrite(mot_esq_2, LOW);
 
  digitalWrite(mot_dir_1, HIGH);
  digitalWrite(mot_dir_2, LOW);
  
  delay(2000);  // wait 2000 m(s)
  Parar();
  while(1)
  {
    Parar();
  }    
}

void teste_rodar_90(void)
{
  rodar_1_4_dir();
  delay(2000);  // wait 2000 m(s)
  rodar_1_4_esq();
  while(1)
  {
    Parar();
  }    
}



void teste_em_frente(void)
{
  EmFrente();
  delay(2000);  // wait 2000 m(s)
  Parar();
  while(1)
  {
    Parar();
  }    
}

void teste_em_frente_recuar_rodar(void)
{
  EmFrente();
  delay(1000);  // wait 1000 m(s)
  Parar();
  delay(1000);  // wait 1000 m(s)
  Recuar();
  delay(1000);  // wait 1000 m(s)
  Parar();   
  RodarEsq();
  delay(2000);  // wait 2000 m(s) 
  Parar();
  RodarDir();
  delay(2000);  // wait 2000 m(s)
  Parar();
  while(1)
  {
   Parar();
  }    
}

void teste_rodar(void)
{
  rodar_1_4_dir();
  delay(100);    
  rodar_1_4_esq();
  delay(2000);
  while(1)
  {
    Parar();
  }
}

void teste_leit_inf(void)
{
  while(1)
  {
    Leitura_Inf();
    Serial.print("FOTO_4_EE  ");        // prints a label
    Serial.print("FOTO_3_CE  ");        // prints a label
    Serial.print("FOTO_2_CC  ");        // prints a label
    Serial.print("FOTO_1_CD  ");        // prints a label 
    Serial.print("FOTO_0_DD  ");  
     
    Serial.println("");                 // prints another carriage return
    
    Serial.print(FOTO4_EE);       // print as an ASCII-encoded decimal
    Serial.print("\t   ");                 // prints a tab
    Serial.print(FOTO3_CE);       // print as an ASCII-encoded decimal
    Serial.print("\t      ");                 // prints a tab
    Serial.print(FOTO2_CC);       // print as an ASCII-encoded decimal
    Serial.print("  \t   ");                 // prints a tab
    Serial.print(FOTO1_CD);       // print as an ASCII-encoded decimal
    Serial.print("  \t");                 // prints a tab
    Serial.print(FOTO0_DD);       // print as an ASCII-encoded decimal
    
    Serial.println("");                 // prints another carriage return 
    Serial.println("");                 // prints another carriage return   
    delay(1000);  // wait 500 m(s) so as not to send massive amounts of data
  }
}

void teste_sonar(void)
{
  while(1)
  {
      delay(30);  // wait 30 m(s) 
      Dist_Dir();
      delay(30);  // wait 30 m(s) 
      Dist_Frnt();
      delay(30);  // wait 30 m(s) 
      Dist_Esq();
      Serial.print("DIST_ESQ\t");        // prints a label
      Serial.print("DIST_FRENTE\t");        // prints a label
      Serial.print("DIST_DIR\t");        // prints a label
      
      Serial.println("");                 // prints another carriage return
      
      Serial.print(DistEsq);       // print as an ASCII-encoded decimal
      Serial.print("\t\t");                 // prints a tab
      Serial.print(DistFrnt);       // print as an ASCII-encoded decimal
      Serial.print("\t\t");                 // prints a tab
      Serial.print(DistDir);       // print as an ASCII-encoded decimal
      
      Serial.println("");                 // prints another carriage return
      Serial.println("");                 // prints another carriage return
      
    //  delay(1000);  // wait a second (1000 m(s)) so as not to send massive amounts of data
      delay(500);  // wait 500 m(s) so as not to send massive amounts of data
  }
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void testes_leitura_movimento(void)
{
  

  while(0)  teste_pwm_min();  
  while(0)  teste_rodar_90();
  while(0)  teste_em_frente();
  while(0)  teste_em_frente_recuar_rodar();
  while(0)  teste_rodar();
  while(0)  Em_Pista();
  Serial.begin(9600);      // open the serial port at 9600 bps:
  while(1)  teste_leit_inf();
  while(0)  teste_sonar();

}
