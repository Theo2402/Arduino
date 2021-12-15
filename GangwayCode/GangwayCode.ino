#include <SoftwareSerial.h>

#define RxD 11 // This is the pin that the Bluetooth (BT_TX) 
              // will transmit to the Arduino (RxD)
#define TxD 10 // This is the pin that the Bluetooth (BT_RX) 
              // will receive from the Arduino (TxD)

SoftwareSerial bluetoothSerial(RxD,TxD);
int RELAY1 = A0;
int RELAY2 = A1;
int RELAY3 = A2;
int RELAY4 = A3;
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;

int delayValue = 200;

void setup() { 
  pinMode(RELAY1, OUTPUT);
  pinMode(LED1, OUTPUT);
  
  pinMode(RELAY2, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  pinMode(RELAY3, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  pinMode(RELAY4, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  // Allow Serial communication via USB cable to computer
  pinMode(RxD, INPUT);
  // Set up the Arduino to receive INPUT from the HC-05 on Digital Pin 7
  pinMode(TxD, OUTPUT);
  // Set up the Arduino to send OUTPUT to the HC-05 on Digital Pin 8
}

void loop() { 
 
  char recvChar;
  //while(1) {
    if(bluetoothSerial.available()) {
      recvChar = bluetoothSerial.read();
      Serial.print("Read character: ");
      Serial.println(recvChar);
      if (recvChar == 'N') {
          Serial.print("north");
          digitalWrite(RELAY1, LOW);
         digitalWrite(LED1, HIGH);
         Serial.println("RELAY1 ON");
         delay(delayValue);
 
         digitalWrite(RELAY1, HIGH);
         digitalWrite(LED1, LOW);
         Serial.println("RELAY1 OFF");
    }
    else if (recvChar == 'E') {
          Serial.print("north");
          digitalWrite(RELAY2, LOW);
         digitalWrite(LED2, HIGH);
         Serial.println("RELAY2 ON");
         delay(delayValue);
 
         digitalWrite(RELAY2, HIGH);
         digitalWrite(LED2, LOW);
         Serial.println("RELAY2 OFF");
    }

    else if (recvChar == 'W') {
          Serial.print("north");
          digitalWrite(RELAY3, LOW);
         digitalWrite(LED3, HIGH);
         Serial.println("RELAY3 ON");
         delay(delayValue);
 
         digitalWrite(RELAY3, HIGH);
         digitalWrite(LED3, LOW);
         Serial.println("RELAY3 OFF");
    }

    else if (recvChar == 'S') {
          Serial.print("north");
          digitalWrite(RELAY4, LOW);
         digitalWrite(LED4, HIGH);
         Serial.println("RELAY4 ON");
         delay(delayValue);
 
         digitalWrite(RELAY4, HIGH);
         digitalWrite(LED4, LOW);
         Serial.println("RELAY4 OFF");
    }

    
      // Print the character received to the Serial Monitor
    //}
  }
}
