//ByteOperators

unsigned long valor = 13259; // 258 in hexadecimal notation is 0x102

int byte1 = 0, byte2 = 0, byte3 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if ( valor <= 999999 )
  {
  	int n1 = valor/100000;
  	int n2 = (valor-n1*100000)/10000;
  	int byte3 = 10*n1 + n2;
  	unsigned long rem1 = valor - long(byte3)*10000;
  	int n3 = rem1 /1000;
  	int n4 = (rem1 - n3*1000)/100;
  	int byte2 = 10*n3 + n4; 
  	int byte1 = rem1 - byte2*100;

  	Serial.println(byte3);
  	Serial.println(byte2);
  	Serial.println(byte1);
  	//Serial.println(byte2);
  	//Serial.println(byte3);
  }

  /*

  int loWord,hiWord;
  byte loByte, hiByte;

  hiByte = highByte(intValue);
  loByte = lowByte(intValue);

  Serial.println(intValue,DEC);
  Serial.println(loByte,DEC);
  Serial.println(hiByte,DEC);
  Serial.println(hiByte*256 + loByte);
  */
  Serial.println();
  delay(10000); // wait a very long time
}
