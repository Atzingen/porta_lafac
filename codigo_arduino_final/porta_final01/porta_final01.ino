/* Versão 1.0 Controle da porta do LAFAC
 
 Gustavo Voltani von Atzingen	15/01/2014
 
 
 */
#include <EEPROM.h>
#include <Keypad.h>

// ********************************** notas musicais ***************************************************************************
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int melody[] = 
{
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 
  /*
  NOTE_G6, NOTE_E7, NOTE_G7, 
   NOTE_A7, 0, NOTE_F7, NOTE_G7, 
   0, NOTE_E7, 0,NOTE_C7, 
   NOTE_D7, NOTE_B6, 0, 0,
   
   NOTE_C7, 0, 0, NOTE_G6, 
   0, 0, NOTE_E6, 0, 
   0, NOTE_A6, 0, NOTE_B6, 
   0, NOTE_AS6, NOTE_A6, 0, 
   
   NOTE_G6, NOTE_E7, NOTE_G7, 
   NOTE_A7, 0, NOTE_F7, NOTE_G7, 
   0, NOTE_E7, 0,NOTE_C7, 
   NOTE_D7, NOTE_B6, 0, 0
   */
};
int tempoS[] = 
{
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 
};
int underworld_tempo[] = 
{
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  /*12, 12, 12, 12, 
   12, 12, 6,
   3,
   12, 12, 12, 12, 
   12, 12, 6,
   6, 18, 18, 18,
   6, 6,
   6, 6,
   6, 6,
   18, 18, 18,18, 18, 18,
   10, 10, 10,
   10, 10, 10,
   3, 3, 3
   */
};
int underworld_melody[] = 
{
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  /*NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
   NOTE_DS3, NOTE_DS4, 0,
   0,
   NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
   NOTE_DS3, NOTE_DS4, 0,
   0, NOTE_DS4, NOTE_CS4, NOTE_D4,
   NOTE_CS4, NOTE_DS4, 
   NOTE_DS4, NOTE_GS3,
   NOTE_G3, NOTE_CS4,
   NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
   NOTE_GS4, NOTE_DS4, NOTE_B3,
   NOTE_AS3, NOTE_A3, NOTE_GS3,
   0, 0, 0
   */
};

// ************************ notas para os tons **********************************************************

// Variáveis globais:
const int abre  = 11;			// pino que controla a ponte H para o motor
const int fecha = 12;			// pino que controla a ponte H para o motor
const int som   = 13;			// som
const int speakerPin = 13;	
boolean add_senha    = false;
boolean rem_senha    = false;
boolean sensor       = false;
volatile boolean sensor_porta = false;
int contador = 0;
unsigned long n=0, senha = 0, senha2 = 0, tempo_atual=0, tempo_anterior=0;

// Teclado:
const byte ROWS = 4; // 4 linhas
const byte COLS = 3; // 3 colunas
char keys[ROWS][COLS] = 
{
  {
    '1','2','3'  }
  ,
  {
    '4','5','6'  }
  ,
  {
    '7','8','9'  }
  ,
  {
    '*','0','#'  }
};
byte rowPins[ROWS] = {
  4, 5, 6, 7};  			// Define os pinos do arduino conectados as linhas
byte colPins[COLS] = {
  8, 9, 10};     			// Define os pinos do arduino conectados as colunas
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup()
{	
  //attachInterrupt(0, sensorporta, FALLING);
  Serial.begin(9600);
  pinMode(abre, OUTPUT);						// Pino que liga o motor (fecha a porta)
  pinMode(fecha, OUTPUT);						// Pino que liga o motor (abre a porta)
  pinMode(som, OUTPUT);						// buzzer						// Pino do sensor de fechamento da porta
  Serial.println(" Iniciando o programa ");
}

void loop()
{
  /*if ( sensor_porta )
   	{  
   delay(200);
   		sensor_porta = false;
   fecha_porta();
   	}*/
  char key = keypad.getKey(); 				// Recebe o valor keypad
  if ( Serial.available() > 0 )				// Intra no if caso receba algum comando serial
  {
    char s = Serial.read();
    switch (s) 
    {
    case 'r':							// Le todos os valores da EEPROM e mostra na serial
      mostra_senhas();
      senha2 = 0;
      break;
    case 'w':							// escreve (write)
      Serial.print(" gravando ...");
      Serial.println(senha2);
      adiciona_senha(senha2);
      senha2 = 0;
      break;
    case 'd':
      Serial.print(" deletando ...");
      Serial.println(senha2);
      remove_senha(senha2);
      senha2 = 0;
    case '0'...'9':
      senha2 = 10*senha2 + ( s - '0' );
      break;
    case 'a':
      senha2 = 0;
      abre_porta();		
      break;
    case 'F':
      senha2 = 0;
      fecha_porta();
      break;
    case 'x':
      if ( autoriza(senha2) )
      {
        abre_porta();
      }
      else
      {
        delay(300);
        tone(som, 800, 200);        // Som de problema
        delay(250);
        tone(som, 800, 200);        // Som de problema
        delay(250);
        tone(som, 800, 200);        // Som de problema
        delay(250);
      }
      senha2 = 0;
      break;
    case '#':
      senha2 = 0;
      march();
      break;
    case '?':
      Serial.println();
      Serial.println();
      Serial.println(" 'r': Mostra as senhas gravadas ");
      Serial.println(" '123456w': 6 digitos e 'w' -> insere uma senha nova");
      Serial.println(" '123456d': 6 digitos e 'd' -> deleta uma senha gravada");
      Serial.println(" 'A': Abre a Porta ");
      Serial.println(" 'F': Fecha a Porta ");
      Serial.println(" '#': Toca a campainha ");
      Serial.println();
      Serial.println();
      Serial.println(" Teclado: ");
      Serial.println(" '#' Campaiha");
      Serial.println(" '*' Fecha a porta");
      Serial.println(" Adicionar senha: 368711 ");
      Serial.println(" Remover senha  : 117863 ");
      break;
    }
  }
  if ( key )								// Entra no if quando uma tecla é pressionada
  {
    Serial.println(key);
    tone(som, 400, 200);
    delay(150);							// Fim da inserção da senha ( hora de checar o valor)
    //***************************************************************************************
    if ( key >=48 && key <= 58 )		// Checa se o valor apertado é um número
    {
      if ( contador > 0 )             // Checa se esta no meio da digitacao
      {
        tempo_atual = millis();
        if ( tempo_atual - tempo_anterior > 2000 )   // tempo maior que 2 segundos para resposta
        {
          contador = 0;
          senha = 0;
          tempo_anterior = tempo_atual; 
          delay(300);
          tone(som, 800, 200);        // Som de problema
          delay(250);
          tone(som, 800, 200);        // Som de problema
          delay(250);
          tone(som, 800, 200);        // Som de problema
          delay(250);
        }
        else
        {
          senha = 10*senha + ( key - 48 );    // incrementa n
          contador = contador + 1;
          tempo_anterior = millis();
        }
      }
      else
      {
        senha = 10*senha + ( key - 48 );    // incrementa n
        contador = contador + 1;
        tempo_anterior = millis();
      }

    }
    else if ( key == '*' )				// Valor para fechar a porta - caracter '*'
    {
      fecha_porta();
      add_senha = false;				// zera o marcador de adicionar senha
      rem_senha = false;				// zera o marcador de remover senha
    }
    else if ( key == '#' )  			// Quando apertarem a tecla '#'  -> toca a campainha
    {
      march();
    }
    //*************************************************************************************
    if( contador > 5 )
    {
      contador = 0;
      if ( senha == 368711 )				// Valor para Adicionar Senha
      {	
        add_senha = true;				// seta o marcador de adicionar senha
        rem_senha = false;				// zera o marcador de remover senha
      }
      else if ( senha == 117863 )			// Valor par remover uma senha
      {
        add_senha = false;				// zera o marcador de adicionar senha
        rem_senha = true;				// seta o marcador de remover senha
      }
      else if ( add_senha )				// Entra caso o marcador de add senha esteja ligado e a senha 
      {									// tenha sido digitada
        add_senha = false;
        if ( senha > 0 )
        {
          adiciona_senha(senha);
        }
      }
      else if ( rem_senha )				// Idem para o caso de remover senha
      {
        rem_senha = false;
        if ( senha > 0 && senha < 999999 )
        {
          remove_senha(senha);
        }
      }
      else 												// Quando o número é maior que 100000 e
      {													// não é um dos números reservados acima - checa a senha
        boolean resposta = autoriza(senha);
        if ( resposta )
        {
          abre_porta();
        }
        else
        {
          delay(300);
          tone(som, 800, 200);        // Som de problema
          delay(250);
          tone(som, 800, 200);        // Som de problema
          delay(250);
          tone(som, 800, 200);        // Som de problema
          delay(250);
        }
      }
      // Zera os valores de senha e n			
      senha = 0;
    }
    delay(50);
  }
}


void adiciona_senha(unsigned long senha)
{
  //Serial.println( senha );
  int n1 = senha/100000;								  	//   Bloco que separa a senha em 3 bytes
  int n2 = (senha-n1*100000)/10000;
  int byte3 = 10*n1 + n2;
  unsigned long rem1 = senha - long(byte3)*10000;
  int n3 = rem1 /1000;
  int n4 = (rem1 - n3*1000)/100;
  int byte2 = 10*n3 + n4; 
  int byte1 = rem1 - byte2*100;							// ****************************************************************
  int i = 0;
  while ( i < 510)						// Loop que anda nas posições de memória da eeprom
  {
    if ( EEPROM.read(i) == 0 )			// checa se a posição esta vazia
    {
      if ( EEPROM.read(i+1) == 0 && EEPROM.read(i+2) == 0 )
      {
        EEPROM.write(i,byte3);
        EEPROM.write(i+1,byte2);
        EEPROM.write(i+2,byte1);
        Serial.print("Adicionando - posicao: ");
        Serial.print((i+1)/3);
        Serial.print(" senha: ");
        Serial.println(senha);
        break;	
      }
    }
    i = i + 3;
  }
  if ( i > 509 )
  {
    Serial.println( " Memoria cheia ! ");
  }
}

void remove_senha(unsigned long senha)
{
  //Serial.println( senha );
  //*************************************************************************************************************************
  int n1 = senha/100000;								  	//   Bloco que separa a senha em 3 bytes
  int n2 = (senha-n1*100000)/10000;
  int byte3 = 10*n1 + n2;
  unsigned long rem1 = senha - long(byte3)*10000;
  int n3 = rem1 /1000;
  int n4 = (rem1 - n3*1000)/100;
  int byte2 = 10*n3 + n4; 
  int byte1 = rem1 - byte2*100;							// ****************************************************************
  //*************************************************************************************************************************
  int i = 0;
  while ( i < 510)						// Loop que anda nas posições de memória da eeprom
  {
    if ( int(EEPROM.read(i)) == byte3 )			// checa se a posição esta vazia
    {
      if ( int(EEPROM.read(i+1)) == byte2 && int(EEPROM.read(i+2)) == byte1 )
      {
        EEPROM.write(i  ,0);
        EEPROM.write(i+1,0);
        EEPROM.write(i+2,0);
        Serial.print(" Removendo - posicao: ");
        Serial.print((i+1)/3);
        Serial.print(" senha: ");
        Serial.print(senha);
        break;	
      }
    }
    i = i + 3;
  }
  if ( i > 509 )
  {
    Serial.println( " Senha nao encontrada ");
  }
}


boolean autoriza(unsigned long senha)
{	
  Serial.print( " Procurando senha no registro ...");
  Serial.println( senha );
  int n1 = senha/100000;
  int n2 = (senha-n1*100000)/10000;
  int byte3 = 10*n1 + n2;
  unsigned long rem1 = senha - long(byte3)*10000;
  int n3 = rem1 /1000;
  int n4 = (rem1 - n3*1000)/100;
  int byte2 = 10*n3 + n4; 
  int byte1 = rem1 - byte2*100;
  int i=0;
  while ( i < 510 )
  {
    if ( EEPROM.read(i) == byte3 &&  byte3 != 0 )
    {
      if ( EEPROM.read(i+1) == byte2 && EEPROM.read(i+2) == byte1 )
      {
        Serial.print("Senha Confere ! - posição: ");
        Serial.print((i+1)/3);
        Serial.println(senha);
        return true;
        break;
      }
    }
    i = i + 3;
  }
  if ( i >=510 )
  {
    Serial.println(" Senha não encontrada");
    return false;  		
  }
}

void abre_porta()
{
  Serial.println(" Abrindo Porta ... ");
  digitalWrite(abre, HIGH);
  digitalWrite(fecha, LOW);
  delay(600);
  digitalWrite(abre, LOW);
  sing(1);
  //tone(som, 2000, 1000);
  //delay(1000);
  //noTone(som);
}

void fecha_porta()
{
  Serial.println(" Fechando Porta ... ");
  digitalWrite(fecha, HIGH);
  digitalWrite(abre, LOW );
  delay(600);
  digitalWrite(fecha, LOW);
  sing(2);
  //tone(som, 800, 1000);
  //delay(1000);	
}

void mostra_senhas()
{
  for ( int i=0; i < 510; i = i+3)
  {
    int byte3 = int(EEPROM.read(i));
    int byte2 = int(EEPROM.read(i+1));
    int byte1 = int(EEPROM.read(i+2));
    if ( byte1 != 0 || byte2 != 0 || byte3 != 0  )
    {
      Serial.print(" posicao ");
      Serial.print((i+1)/3);
      Serial.print("\t: ");
      if( byte3 < 9)
      {
        Serial.print("0");
      }
      Serial.print(byte3);
      if( byte2 < 9)
      {
        Serial.print("0");
      }
      Serial.print(byte2);
      if( byte1 < 9)
      {
        Serial.print("0");
      }
      Serial.println(byte1);
      delay(10);
    }

  }
}

void sensorporta()
{
  sensor_porta = true;
}


//***************************************** SOM ***********************************************************

void buzz(int targetPin, long frequency, long length) 
{
  long delayValue = 1000000/frequency/2; 
  long numCycles = frequency * length/ 1000; 
  for (long i=0; i < numCycles; i++)
  { 
    digitalWrite(targetPin,HIGH); 
    delayMicroseconds(delayValue); 
    digitalWrite(targetPin,LOW); 
    delayMicroseconds(delayValue); 
  }
}

void sing(int s)
{      
  if(s==2)
  {
    //Serial.println(" Underwolrd ");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) 
    {
      int noteDuration = 1000/underworld_tempo[thisNote];
      buzz(som, underworld_melody[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(som, 0,noteDuration);
    }
  }
  else
  {
    //Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) 
    {
      int noteDuration = 1000/tempoS[thisNote];
      buzz(som, melody[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(som, 0,noteDuration);
    }
  }
}

void march()
{ 	 
  //for the sheet music see:
  //http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
  //this is just a translation of said sheet music to frequencies / time in ms
  //used 500 ms for a quart note

  beep(speakerPin, a, 500); 
  beep(speakerPin, a, 500);     
  beep(speakerPin, a, 500); 
  beep(speakerPin, f, 350); 
  beep(speakerPin, cH, 150);

  beep(speakerPin, a, 500);
  beep(speakerPin, f, 350);
  beep(speakerPin, cH, 150);
  beep(speakerPin, a, 1000);
  //first bit

  beep(speakerPin, eH, 500);
  beep(speakerPin, eH, 500);
  beep(speakerPin, eH, 500);    
  beep(speakerPin, fH, 350); 
  beep(speakerPin, cH, 150);

  beep(speakerPin, gS, 500);
  beep(speakerPin, f, 350);
  beep(speakerPin, cH, 150);
  beep(speakerPin, a, 1000);
  //second bit...
  /*
    beep(speakerPin, aH, 500);
   beep(speakerPin, a, 350); 
   beep(speakerPin, a, 150);
   beep(speakerPin, aH, 500);
   beep(speakerPin, gSH, 250); 
   beep(speakerPin, gH, 250);
   
   beep(speakerPin, fSH, 125);
   beep(speakerPin, fH, 125);    
   beep(speakerPin, fSH, 250);
   delay(250);
   beep(speakerPin, aS, 250);    
   beep(speakerPin, dSH, 500);  
   beep(speakerPin, dH, 250);  
   beep(speakerPin, cSH, 250);  
   //start of the interesting bit
   
   beep(speakerPin, cH, 125);  
   beep(speakerPin, b, 125);  
   beep(speakerPin, cH, 250);      
   delay(250);
   beep(speakerPin, f, 125);  
   beep(speakerPin, gS, 500);  
   beep(speakerPin, f, 375);  
   beep(speakerPin, a, 125); 
   
   beep(speakerPin, cH, 500); 
   beep(speakerPin, a, 375);  
   beep(speakerPin, cH, 125); 
   beep(speakerPin, eH, 1000); 
   //more interesting stuff (this doesn't quite get it right somehow)
   
   beep(speakerPin, aH, 500);
   beep(speakerPin, a, 350); 
   beep(speakerPin, a, 150);
   beep(speakerPin, aH, 500);
   beep(speakerPin, gSH, 250); 
   beep(speakerPin, gH, 250);
   
   beep(speakerPin, fSH, 125);
   beep(speakerPin, fH, 125);    
   beep(speakerPin, fSH, 250);
   delay(250);
   beep(speakerPin, aS, 250);    
   beep(speakerPin, dSH, 500);  
   beep(speakerPin, dH, 250);  
   beep(speakerPin, cSH, 250);  
   //repeat... repeat
   
   beep(speakerPin, cH, 125);  
   beep(speakerPin, b, 125);  
   beep(speakerPin, cH, 250);      
   delay(250);
   beep(speakerPin, f, 250);  
   beep(speakerPin, gS, 500);  
   beep(speakerPin, f, 375);  
   beep(speakerPin, cH, 125); 
   
   beep(speakerPin, a, 500);            
   beep(speakerPin, f, 375);            
   beep(speakerPin, c, 125);            
   beep(speakerPin, a, 1000);       
   //and we're done \ó/    
   */
}

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
  int x; 	 
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++) 	 
  { 	 
    digitalWrite(speakerPin,HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speakerPin,LOW);
    delayMicroseconds(delayAmount);
  } 	 
  delay(20);
} 	

