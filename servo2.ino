#define EnaPin 2

#define StepPin_x1 3
#define DipPin_x1 4

#define StepPin_x2 10
#define DipPin_x2 9

#define StepPin_y 6
#define DipPin_y 5

#define StepPin_z 8
#define DipPin_z 7

int i=0;

bool b=true;
void setup()
{
  Serial.begin(9600);
  pinMode (EnaPin,OUTPUT);
  
  pinMode (StepPin_x1,OUTPUT);
  pinMode (DipPin_x1,OUTPUT);

  pinMode (StepPin_x2,OUTPUT);
  pinMode (DipPin_x2,OUTPUT);
 
  pinMode (StepPin_y,OUTPUT);
  pinMode (DipPin_y,OUTPUT);
 
  pinMode (StepPin_z,OUTPUT);
  pinMode (DipPin_z,OUTPUT);
}

void loop()
{
  if(b==true)
  {
  move(0,10000,0);
  }
}
////////////////////////////////////////////////////////////////////////
void move(int steps_x,int steps_y,int steps_z) //os x
{
  digitalWrite(EnaPin,LOW); // 2 na LOW to w "prawo"
  digitalWrite(DipPin_x1,LOW);// DIP high "lewo"

  digitalWrite(EnaPin,LOW); // 2 na LOW to w "prawo"
  digitalWrite(DipPin_x2,HIGH); // DIP high "lewo"

  digitalWrite(EnaPin,LOW); // 2 na LOW to w "prawo"
  digitalWrite(DipPin_y,HIGH); // DIP high "lewo"

  digitalWrite(EnaPin,LOW); // 2 na LOW to w "prawo"
  digitalWrite(DipPin_z,LOW); // DIP high "lewo"

     if(i < steps_y)
      {
       i++;
       digitalWrite(StepPin_y,!digitalRead(StepPin_y));
       digitalWrite(StepPin_y,!digitalRead(StepPin_y));
       delay(1);
      }
      else
      {
       digitalWrite(StepPin_y,LOW);
       digitalWrite(StepPin_y,LOW);
      }
//      for(int i=0; i<steps_y;i++)
//      {
//      digitalWrite(StepPin_y,!digitalRead(StepPin_y));
//      }
//        for(int i=0; i<steps_z;i++)
//        {
//          digitalWrite(StepPin_z,!digitalRead(StepPin_z));
//        }
//      delay(1);
      
}
////////////////////////////////////////////////////////////////////////
