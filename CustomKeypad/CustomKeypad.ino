#include <Keypad.h>

#define password_lenght 8
char data[password_lenght];
char password[password_lenght]="4655568";

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
byte data_count=0;
char custom_key;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {52, 50, 48, 46}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {44, 42, 40, 38}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(22, OUTPUT);
}
  
void loop()
{
  char customKey = customKeypad.getKey();
  
  if (customKey)
  {
    Serial.println(customKey);
    data[data_count]=customKey;
    data_count++;
  }

  if(!strcmp(data,password))
  {
    digitalWrite(22,HIGH);
    delay(100);
    digitalWrite(22,LOW);
    delay(100);
  }
     
}
