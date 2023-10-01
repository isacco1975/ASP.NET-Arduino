/*
 **********************************************************************
 * Name:                                                              *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *
 * Created: 09.03.2023 10:01:49                                       *
 * Author:  Isaac Garcia Peveri                                       *
 *          isacco1975gp@gmail.com                                    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *
 **********************************************************************
*/

#pragma region "Working-Storage"
const int GREEN_LED = 2;
const int YELLOW_LED = 3;
const int RED_LED = 4;
String incomingMessage;
#pragma endregion

void setup()
{  
   Serial.begin(1200);
}

void loop()
{ 
   if (Serial.available()) 
   {
      incomingMessage = Serial.readString();
      Serial.println(incomingMessage);
      Serial.println(incomingMessage.indexOf("ON1"));
      Serial.println(incomingMessage.indexOf("ON2"));
      Serial.println(incomingMessage.indexOf("ON3"));
      Serial.println(incomingMessage.indexOf("OFF1"));
      Serial.println(incomingMessage.indexOf("OFF2"));
      Serial.println(incomingMessage.indexOf("OFF3"));
     
      if (incomingMessage.indexOf("ON1") > 0)
      {
         digitalWrite(GREEN_LED, HIGH);
      } 
      if (incomingMessage.indexOf("ON2") > 0)
      {
         digitalWrite(YELLOW_LED, HIGH);        
      } 
      if (incomingMessage.indexOf("ON3") > 0)
      {
         digitalWrite(RED_LED, HIGH);        
      } 
      if (incomingMessage.indexOf("OFF1") > 0)
      {
         digitalWrite(GREEN_LED, LOW);        
      } 
      if (incomingMessage.indexOf("OFF2") > 0)
      {
         digitalWrite(YELLOW_LED, LOW);                
      } 
      if (incomingMessage.indexOf("OFF3") > 0)
      {
         digitalWrite(RED_LED, LOW);                
      }                  

      Serial.flush();
   }

   //delay(500);

}
