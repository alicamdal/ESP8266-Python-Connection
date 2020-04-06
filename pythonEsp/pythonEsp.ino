#include <SoftwareSerial.h>

SoftwareSerial espSerial(3,2);


String fmsg;
String msg;

void setup() 
{
  espSerial.begin(9600);
  Serial.begin(9600);
}

void loop() 
{   
  while(espSerial.available()){
       fmsg += (char)espSerial.read();
       delay(2);
  }

  msg = getString(fmsg);
  
  Serial.println(msg);
  if(msg == "Veri geliyor"){
    Serial.println("Veri Alindi");
    msg.remove(0);
    fmsg.remove(0);
    delay(5000);
    }
   else{
    Serial.println("Veri Bekleniyor");
    delay(250);
    }
}


String getString(String flmsg)
{ 
  int lng = 0;
  String lmsg;
  lng = flmsg.length();  
  for(int i=0;i<lng;i++){
    if(i>32){
      lmsg += flmsg[i];
      }
    }
  return lmsg;
}
