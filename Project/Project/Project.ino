/*
 * NEED:
 * ALARM(sound speaker of somesort)
 * LIGHTS
 * READ DATE, TIME,WEATHER
 * SMOKE/FIRE DETECTION
 * ALERT ON PHONE
 */





int pushButton = 8; //switch digital input pin
int ButtonState =0; //will start 0 when not pressed
int LightState = 0; // initialize

void setup() {
  pinMode(13, OUTPUT);//light
 
  pinMode(pushButton, INPUT); //switch

  Serial.begin(9600);// show states
}


void loop(){
  int ButtonState = digitalRead(pushButton);
  
  if(ButtonState == HIGH){
  // the button is pressed
  LightState = digitalRead(13);
  Serial.println(LightState);
    if (LightState==0){// the light is off
      
      digitalWrite(13, HIGH); //when light is off, turn it on

    }
    else{// the light is on
      
      // when light is on, turn it off
      digitalWrite(13, LOW);

   
    }
    delay(500);// wait half a second to keep from constant reading... if you hold the button for over half a second it will read the input again!

  }

  /*
   * delay(my timer); will hold time to wait
   *  if (LightState==0){// the light is off
      
      digitalWrite(13, HIGH); //when light is off, turn it on

    }
   * 
   */
 



}
