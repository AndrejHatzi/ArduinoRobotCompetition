

//  pinMode(StartButton,INPUT);
//  pinMode (StartLed, OUTPUT);

void led_ON(void)
{
  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, HIGH);
}

void led_OFF(void)
{
  digitalWrite(RedLed, LOW);
  digitalWrite(GreenLed, LOW);
}
void teste_START(void)
{
	while (1)
	{
		if (digitalRead(StartButton)==1) led_ON();
		delay(10);
		if (digitalRead(StartButton)==0) led_OFF();
		delay(10);
	}
}


void arranque_preparado(void)
{
	led_ON();
	delay(250);
	led_OFF();
	delay(250);
}

void StartPosition(void)
{
  led_ON();
  travado();
  delay(10);

start_position:

  Leitura_Inf();
	if (FOTO2_CC <= FOTO2_CC_w_black)
	{
		if ((FOTO3_CE > FOTO3_CE_w_black) && (FOTO1_CD > FOTO1_CD_w_black))
		{
			led_ON();
			goto preparado_START;	
		}
		else
		{
			led_OFF();
			goto start_position;	
		}					
	}
	else
	{
  	  led_OFF();
	  goto start_position;	
	}
preparado_START:
	delay(10);
	if (digitalRead(StartButton)==0) 
	{
		delay(10);	// debounce
		if (digitalRead(StartButton)==0) 
		{
      delay(100);
			goto start_position;
		}
	}
arranque:
	delay(10);
	if (digitalRead(StartButton)==1)
	{
    led_OFF();
		delay(1);	// debounce
		if (digitalRead(StartButton)==1)
		{
			delay(1);
			goto arranque;
		}
	}
  led_ON();
  delay(250);
  EmFrente();
  delay(5);
}


