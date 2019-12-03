/*
   NEED:
   LIGHTS MUST TURN ON AND OFF ACCORDING TO ALARM DELAY AND BUTTON PRESS

*/





int pushButton = 8; //switch digital input pin
int ButtonState = 0; //will start 0 when not pressed
int LightState = 0; // initialize light detection

String alarm = ""; //will hold alarm value
int alarmDelay = 5000; //user alarm time as an int, used for delay. will be 5 seconds as default
bool alarmSet = false; // FLAG hold if alarm is set, asume false for now


void setup() {
  pinMode(13, OUTPUT);//light

  pinMode(pushButton, INPUT); //switch

  Serial.begin(9600);// for input delay time and test light state
  Serial.write("Power On\n");
  delay(2000);
  //Serial.println("Set your alarm: ");

  //setAlarm();
}


void loop() {
  int ButtonState = digitalRead(pushButton);


  /* USE THIS BLOCK FOR TESTING THE BUTTON*/
//    if (ButtonState == HIGH) {
//      // the button is pressed
//      LightState = digitalRead(13);
//      //Serial.println(LightState);
//      if (LightState == 0) { // the light is off
//  
//        digitalWrite(13, HIGH); //when light is off, turn it on
//        Serial.println("I'll turn on!");
//  
//      }
//      else { // the light is on
//  
//        // when light is on, turn it off
//        digitalWrite(13, LOW);
//        Serial.println("I'll turn off!");
//  
//  
//      }
//      delay(500);// wait half a second to keep from constant reading... if you hold the button for over half a second it will read the input again!
//  
//    }


  //Check alarmSet settings; comment this out when testing button
  //  Flag for setting alarm if improper input
  if (alarmSet == false) {
    Serial.println("Set your alarm: ");
    //alarmSet = true; //reset flag
    while (!Serial.available() ) {
      //do nothing and wait until user input

    }
  }



  if (LightState == 1) { // the light is on(alarm is on)
    Serial.println("Turn off the alarm!");
    while (digitalRead(pushButton) == LOW) {//button not pressed
      //wait until high
//      if (ButtonState == HIGH) {
//        Serial.println("Alarm turned off");
//        digitalWrite(13, LOW);
//        LightState = digitalRead(13);
//        alarmSet = false;
//        return;
//      }
    }
        if ((digitalRead(pushButton) == HIGH)) {
          Serial.println("Alarm turned off");
          digitalWrite(13, LOW);
          LightState = digitalRead(13);
          alarmSet = false;
          
        }
  }
  //Serial.println("Alarm turned off");
  //alarmSet=false;

  if (alarmSet == true) {
    Serial.println("We are now waiting for your alarm..");
    delay(alarmDelay);
    if (LightState == 0) { // the light is off

      digitalWrite(13, HIGH); //turn on
      LightState = digitalRead(13);
      Serial.println("Alarm is complete!");
    }
  }




  //get user input
  if (Serial.available() > 0) {
    alarm = Serial.readStringUntil('\n');

    Serial.print("Your alarm: ");
    Serial.println(alarm);

    if (isNumber(alarm)) {
      setAlarm(alarm);
      alarmSet = true;
    }
    else {
      Serial.println("alarm is unset");
      alarmSet = false;
    }


  }


}


// the following will be used with serial communicate to set the alarm
bool setAlarm(String str) {

  if (isNumber(str)) {

    //convert alarm string to int here

    alarmDelay = alarm.toInt();

    Serial.println("All set!");
    alarmSet = true;
    return true;
  }
  else {
    Serial.println("Not a number!");
    return false;
  }

}

boolean isNumber(String str) {
  for (byte i = 0; i < str.length(); i++)
  {
    //Serial.println(str.charAt(i));
    if (isDigit(str.charAt(i)) == false) {
      Serial.println("Not a number!");
      return false;
    }
  }
  return true;

}
