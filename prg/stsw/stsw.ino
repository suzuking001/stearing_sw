
#include <BleKeyboard.h>
BleKeyboard bleKeyboard;
int sensorPin1 = A0;    // select the input pin for the potentiometer
int sensorPin2 = A3;
int sensorPin3 = A6;
int ledPin = 12;      // select the pin for the LED
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int sensorValue3 = 0;
int pitch = 200;
int count = 0;
int setValue= 0;
int startFlg = 0 ;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {

  sensorValue3 = analogRead(sensorPin3);
  Serial.print(" sensorValue3:");
  Serial.println(sensorValue3);
  if(sensorValue3<3000){
    digitalWrite(ledPin, HIGH);
    //delay(50);
    sensorValue1=2640;
    Serial.println("3V3 Low");
  }
    
   
  if(bleKeyboard.isConnected()) {
    sensorValue1 = analogRead(sensorPin1);
    Serial.print(" sensorValue1:");
    Serial.println(sensorValue1);

    sensorValue2 = analogRead(sensorPin2);
    Serial.print(" sensorValue2:");
    Serial.println(sensorValue2);
    
    if(startFlg==0){
      delay(1500);
      sensorValue1 =1605;
      startFlg=startFlg+1;
    }

    //VOLUME_UP
    setValue=1080;
    if((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'VOLUME_UP'");
      bleKeyboard.press(KEY_MEDIA_VOLUME_UP);
      delay(10);
      bleKeyboard.release(KEY_MEDIA_VOLUME_UP);
      delay(100);
    }
    
    //VOLUME_DOWN
    setValue=1605;
    if((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'VOLUME_DOWN'");
      bleKeyboard.press(KEY_MEDIA_VOLUME_DOWN);
      delay(10);
      bleKeyboard.release(KEY_MEDIA_VOLUME_DOWN);
      delay(50);
    }

    //ログイン
    setValue=1605;
    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'passWord'");
      for (int i = 0; i < 6; i++)
      {
          bleKeyboard.write(KEY_BACKSPACE);
          delay(50);
      }
      bleKeyboard.print("249666");
      delay(500);
    }

    //CangeApp
    setValue=570;
    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'CangeApp'");
      bleKeyboard.press(KEY_LEFT_GUI);
      delay(10);
      bleKeyboard.press(KEY_TAB);
      while((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
        sensorValue1 = analogRead(sensorPin1);
        delay(10);
      }
      bleKeyboard.release(KEY_TAB);
      delay(50);
      bleKeyboard.press(KEY_TAB);
      delay(50);
      bleKeyboard.release(KEY_TAB);
      delay(50);
      bleKeyboard.release(KEY_LEFT_GUI);
      delay(50);
    }








//    setValue=1200;
//    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//      digitalWrite(ledPin, HIGH);
//      Serial.println("Sending 'press cmd'");
//      while((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//        bleKeyboard.press(KEY_LEFT_GUI);
//        sensorValue1 = analogRead(sensorPin1);
//        delay(10);
//      }
//      bleKeyboard.release(KEY_LEFT_GUI);
//      delay(50);
//    }
    
    
//    
//    setValue=1400;
//    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//      digitalWrite(ledPin, HIGH);
//      Serial.println("Sending 'press ctrl'");
//      while((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//        bleKeyboard.press(KEY_LEFT_GUI);
//        sensorValue1 = analogRead(sensorPin1);
//        delay(10);
//      }
//      bleKeyboard.release(KEY_LEFT_GUI);
//      delay(50);
//    }

    //NEXT_TRACK
    setValue=2645;
    if((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'NEXT_TRACK'");
      bleKeyboard.press(KEY_MEDIA_NEXT_TRACK);
      delay(10);
      bleKeyboard.release(KEY_MEDIA_NEXT_TRACK);
      delay(50);
    }
    
    //PREVIOUS_TRACK
    setValue=3235;
    if((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'PREVIOUS_TRACK'");
      bleKeyboard.press(KEY_MEDIA_PREVIOUS_TRACK);
      delay(10);
      bleKeyboard.release(KEY_MEDIA_PREVIOUS_TRACK);
      delay(50);
    }

    //HOME
    setValue=2128;
    if((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'HOME'");
      bleKeyboard.press(KEY_MEDIA_WWW_HOME);
      while((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
        sensorValue2 = analogRead(sensorPin2);
        delay(10);
      }
      delay(10);
      bleKeyboard.release(KEY_MEDIA_WWW_HOME);
      delay(50);
    }


    //MONITER_LOCK Command+Ctrl+q
    setValue=2640;
    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'MONITER_LOCK'");
      bleKeyboard.press(KEY_LEFT_GUI);
      delay(10);
      bleKeyboard.press(KEY_LEFT_CTRL);
      delay(10);
      bleKeyboard.print("q");
      while((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
        sensorValue1 = analogRead(sensorPin1);
        delay(10);
      }
      bleKeyboard.release(KEY_LEFT_CTRL);
      delay(10);
      bleKeyboard.release(KEY_LEFT_GUI);
      delay(50);
    }
//
//    //Command-Option-D  Dockの切り替え
//    setValue=2800;
//    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//      digitalWrite(ledPin, HIGH);
//      Serial.println("Sending 'changeDock'");
//
//      
//      bleKeyboard.press(KEY_LEFT_GUI);
//      delay(10);
//      for (int i = 0; i < 3; i++)
//      {
//          bleKeyboard.press( KEY_LEFT_ARROW);
//          delay(100);
//          bleKeyboard.release(KEY_LEFT_ARROW);
//          delay(100);
//      }
//      bleKeyboard.release(KEY_LEFT_GUI);
//      delay(10);
//      bleKeyboard.press(KEY_LEFT_GUI);
//      delay(10);
//      bleKeyboard.press(KEY_LEFT_ALT);
//      delay(10);
//      bleKeyboard.print("d");
//      bleKeyboard.release(KEY_LEFT_ALT);
//      delay(10);
//      bleKeyboard.release(KEY_LEFT_GUI);
//      delay(10);
//      for (int i = 0; i < 10; i++)
//      {
//          bleKeyboard.press( KEY_LEFT_ARROW);
//          delay(10);
//          bleKeyboard.release(KEY_LEFT_ARROW);
//          delay(10);
//      }
//      
//      delay(10);
//      for (int i = 0; i < count; i++){
//        Serial.println("Sending 'change'");
//        bleKeyboard.press(KEY_RIGHT_ARROW);
//        delay(10);
//        bleKeyboard.release(KEY_RIGHT_ARROW);
//        delay(10);
//      }
//      count=count+1;
//      if(count>2){
//        count=0;
//      }
//      
//      bleKeyboard.press(KEY_RETURN );
//      delay(10);
//      bleKeyboard.release(KEY_RETURN);
//      delay(500);
//    }

    //PLAY_PAUSE
    setValue=575;
    if((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
      digitalWrite(ledPin, HIGH);
      Serial.println("Sending 'PLAY_PAUSE'");
      bleKeyboard.press(KEY_MEDIA_PLAY_PAUSE);
      while((sensorValue2>(setValue-pitch))&&(sensorValue2<(setValue+pitch))){
        sensorValue2 = analogRead(sensorPin2);
        delay(10);
      }
      bleKeyboard.release(KEY_MEDIA_PLAY_PAUSE);
      delay(50);
    }




//    setValue=3000;
//    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//      digitalWrite(ledPin, HIGH);
//      Serial.println("Sending 'KEY_RIGHT_ARROW'");
//      bleKeyboard.press(KEY_RIGHT_ARROW);
//      while((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//        sensorValue1 = analogRead(sensorPin1);
//        delay(10);
//      }
//      bleKeyboard.release(KEY_RIGHT_ARROW);
//      delay(50);
//    }

//    setValue=3200;
//    if((sensorValue1>(setValue-pitch))&&(sensorValue1<(setValue+pitch))){
//      digitalWrite(ledPin, HIGH);
//      Serial.println("Sending 'googleMap'");
//      // ->home (Cmd + h)
//      bleKeyboard.press(KEY_LEFT_GUI);
//      delay(10);
//      bleKeyboard.print("h"); //文字を送信
//      delay(10);
//      bleKeyboard.release(KEY_LEFT_GUI);
//      delay(50);
//      // ->command (Cmd + Space)
//      bleKeyboard.press(KEY_LEFT_GUI);
//      delay(50);
//      bleKeyboard.print(" "); // space
//      delay(50);
//      bleKeyboard.release(KEY_LEFT_GUI);
//      delay(50);
//      // Erase the string with backspace
//      for (int i = 0; i < 10; i++)
//      {
//          bleKeyboard.write(KEY_BACKSPACE);
//          delay(50);
//      }
//      bleKeyboard.press(KEY_CAPS_LOCK);
//      delay(50);
//      bleKeyboard.release(KEY_CAPS_LOCK);
//      // input - "googleMap"
//      delay(500);
//      bleKeyboard.print("googlemap");
//      delay(50);
//      // input - "enter"
//      bleKeyboard.write(KEY_RETURN);
//      delay(50);
//    }



    
    digitalWrite(ledPin, LOW);
    delay(100);


  }


  
}
