int data;
int dioda=23;

String odczyt;
char znak;

void setup() 
{
 pinMode(dioda,OUTPUT);
 Serial1.begin(9600);
}

void loop()
{
  while(Serial1.available())
  {
  delay(3);
  znak=Serial1.read();
  odczyt+=znak;
  }
  if(odczyt.length()>0)
  {
    Serial1.print(odczyt);
  }

  if(odczyt=="LEDON")
  {
    digitalWrite(dioda,HIGH);
    delay(5000);
  }
  else
  {
    digitalWrite(dioda,LOW);
  }
   odczyt="";
}