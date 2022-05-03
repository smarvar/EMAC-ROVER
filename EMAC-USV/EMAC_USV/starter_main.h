

void Serial_main(){
    Serial.begin(PC_Baud);     // Baud rate PC
    Serial1.begin(Sonar_Baud); // Serial comunication Sonar
    Serial2.begin(GPS_Baud);   // Serial comunication GPS
    Serial.setTimeout(100);
    Serial1.setTimeout(100);
    Serial2.setTimeout(100);
  }

void Activate_sensors(){
    pinMode(Sensors_Pin, OUTPUT);
    digitalWrite(Sensors_Pin, HIGH);
    attachInterrupt(0,Pulse_counter, FALLING);
    digitalWrite(Digital_pin, HIGH); 
  }  

void Activate_gsm(){
    pinMode(GSM_Pin, OUTPUT);
    digitalWrite(GSM_Pin, HIGH);
  }

void Activate_servo(){
    myservo.attach(Servo_pin);  // Pin Servo
  }
  
void Activate_SD(){
    pinMode(SD_pin, OUTPUT);   // Writing pin SD
    digitalWrite(SD_pin, HIGH); // enable SD card
    SD.begin(SD_pin);
    pinMode(led_Pin, OUTPUT);  // LED check
    digitalWrite(led_Pin, HIGH);
    }

//Initialization function, setup and upload data files
void Upload_files_config(bool if_print){
      if(SD.begin(SD_pin)){
          Serial.println();
          Serial.println("--- Uploading files config ---");
          Serial.println();
          Sensors(if_print); //Reading sensors file
      }
      else
          Serial.println(" SD initialization failed!");    
}

void Header_data(){                                      
    Serial.println(F(Header));
}

//Get data time
void Timer_millis(){  
    USV_data.data_millis = millis();
}


void Sampling_time(){
    String timer = Scan_file(Conf_file, "Tmuestreo");     
    switch (timer.toInt()){
          case 0:
            sampling_rate = Second/2;
            break;
          case 1:
            sampling_rate = Second;
            break;
          case 2:
            sampling_rate = 2*Second;
            break;
          case 3:
            sampling_rate = 5*Second;
            break;
          case 4:
             sampling_rate = 10*Second;
             break;
          case 5:
             sampling_rate = Minute;
             break;
          case 6:
             sampling_rate = 2*Minute;
             break;
          case 7:
             sampling_rate = 5*Minute;
             break;
          case 8:
             sampling_rate = 10*Minute;
             break;
          case 9:
             sampling_rate = 15*Minute;
             break;
          case 10:
             sampling_rate = 30*Minute;
             break;
          case 11:
             sampling_rate = 60*Minute;
             break;
          case 12:
             sampling_rate = 90*Minute;
             break;
          case 13:
             sampling_rate = 120*Minute;
             break;
          default:
             sampling_rate = Second;
             break;
        }  
}
