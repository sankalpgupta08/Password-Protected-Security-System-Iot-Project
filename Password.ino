#include <Keypad.h>

const byte row=4;
const byte col=4;
const int greenled=10;
const int redled=11;
const int piezo=12;

char numpad[row][col]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};

byte rowpin[row]={9,8,7,6};
byte colpin[col]={5,4,3,2};

String password="6556";
String vstup="";

Keypad cKeypad=Keypad(makeKeypad(numpad),rowpin,colpin,row,col);

void setup{
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(redled,OUTPUT);
  digitalWrite(redled,HIGH);
  Serial.begin(9600);
  Serial.print("Enter Password : ");
}

void loop{
  char ckey=cKeypad.getKey();
  if(ckey){
    if(vstup.length()<4){
      	Serial.print("*")
    	vstup+=ckey;
    }
  }
  if(vstup.length()==4){
  	delay(1500);
    if(vstup==password){
      Serial.print("Correct Password");
      digitalWrite(greenled,HIGH);
      digitalWrite(redled,LOW);
      tone(piezo,500);
      delay(500);
      notone(piezo);
    }
    else{
      Seriel.print("Wrong Password");
      digitalWrite(redled,HIGH);
      digitalWrite(greenled,LOW);
      tone(piezo,1000);
      delay(800);
      tone(piezo,1000);
      delay(800);
      notone(piezo);
    }
    delay(5000);
    vstup="";
    Serial.print("Enter Password");
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
  }  
}