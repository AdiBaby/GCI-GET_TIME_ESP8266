/*
 * GOOGLE CODE IN PROJECT.
 * LINK TO PROJECT : https://codein.withgoogle.com/dashboard/task-instances/4997569559134208/
 * LIKE TO REPO ON GITHUB : https://github.com/AdiBaby/Arduino_GCI_2018_CONTROL_FROM_SERIAL_MONITOR/blob/master/GCI-READFROMCONSOLE.ino
 * (C) ADITYA PREREPA 11/19/18
*/
int ledPin = 7;
// Pin 7 is the pin the LED is connected to, so the one for it to light up.
int incomingByte;   
//declare variable incomingByte.

void setup() {
        // setup() runs once, so all the introduction messages are printed
        // here.
        Serial.begin(57600);
        //Begin Serial at 57600 baud rate
        Serial.println("Welcome to the arduino LED interfacer.");
        Serial.println("Enter 0 to turn LED off, or 1 to turn LED on.");
}

void loop() {
        // loop() runs forever.
        //Check if Serial Monitor is active and things are being entered.
        if (Serial.available() > 0) {
                //Save value entered to variable incomingByte
                incomingByte = Serial.read();
                switch (incomingByte) {
                  // 48 is the key code for 0, so if the computer interpreted value is 48,
                  // they entered 0.
                  case 48 : 
                    Serial.println("You Entered : 0");
                    Serial.println("Turning LED off...");
                    digitalWrite(ledPin, LOW);
                    break;
                  // 49 is the key code for 1, so if the computer interpreted value is 49,
                  // they entered 1.
                  case 49 : 
                    Serial.println("You Entered : 1");
                    Serial.println("Turning LED on..."); 
                    digitalWrite(ledPin, HIGH);
                    break;
                  // If the value was not 48 or 49, or the value entered was not 0 or 1,
                  // print out error message. (All other cases).
                  default :  
                    Serial.print("You entered : ");
                    Serial.println(incomingByte - 48);
                    Serial.println("Please enter either 0 or 1. Try again please.");
                    break;
                }
        }
}
