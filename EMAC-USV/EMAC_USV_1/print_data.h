
String GPS_data, Sensors_data, Sonar_data, SD_data;
uint8_t cont_file = 0;

// Function definitions
void Save_data_SD();
void Print_Bluetooth_data();
void Print_PC_Serial_data();
void CreateNewFileName();
void Print_SD();
void Status(String, String, String, String, String, String, uint16_t);


void Save_data_SD(){
    print_SD.print(USV_data.data_millis);
    print_SD.print(",");
    print_SD.print(USV_data.gps_year);
    print_SD.print("/");
    print_SD.print(USV_data.gps_month);
    print_SD.print("/");
    print_SD.print(USV_data.gps_day);
    print_SD.print(",");
    print_SD.print(USV_data.gps_hour);
    print_SD.print(":");
    print_SD.print(USV_data.gps_minute);
    print_SD.print(":");
    print_SD.print(USV_data.gps_second);
    print_SD.print(",");
    print_SD.print(USV_data.gps_latitude, coordinate_decimals);
    print_SD.print(",");
    print_SD.print(USV_data.gps_longitude, coordinate_decimals);
    print_SD.print(",");
    print_SD.print(USV_data.gps_altitude);
    print_SD.print(",");
    print_SD.print(USV_data.gps_speed);
    print_SD.print(",");
    print_SD.print(USV_data.gps_course);
    print_SD.print(",");
    print_SD.print(USV_data.gps_n_satelites);
    print_SD.print(",");
    print_SD.print(USV_data.gps_precision);
    print_SD.print(",");
    print_SD.print(USV_data.gps_n_sentenses);
    print_SD.print(",");
    print_SD.print(USV_data.sens_0);
    print_SD.print(",");
    print_SD.print(USV_data.sens_1);
    print_SD.print(",");
    print_SD.print(USV_data.sens_2);
    print_SD.print(",");
    print_SD.print(USV_data.sens_3);
    print_SD.print(",");
    print_SD.print(USV_data.sens_4);
    print_SD.print(",");
    print_SD.print(USV_data.sens_5);
    print_SD.print(",");
    print_SD.print(USV_data.sens_6);
    print_SD.print(",");
    print_SD.print(USV_data.sens_7);
    print_SD.print(",");
    print_SD.print(USV_data.sens_8);
    print_SD.print(",");
    print_SD.print(USV_data.angle_sonar);
    print_SD.print(",");
    print_SD.print(USV_data.confidence_sonar);
    print_SD.print(",");
    print_SD.print(USV_data.deep_sonar);
    print_SD.print(",");    
    print_SD.println(USV_data.profile_sonar);
    print_SD.close();        
}

void Print_Bluetooth_data(){
    Serial3.print("$DATA");
    Serial3.print(",");
    Serial3.print(USV_data.data_millis);
    Serial3.print(",");
    Serial3.print(USV_data.gps_year);
    Serial3.print("/");
    Serial3.print(USV_data.gps_month);
    Serial3.print("/");
    Serial3.print(USV_data.gps_day);
    Serial3.print(",");
    Serial3.print(USV_data.gps_hour);
    Serial3.print(":");
    Serial3.print(USV_data.gps_minute);
    Serial3.print(":");
    Serial3.print(USV_data.gps_second);
    Serial3.print(",");
    Serial3.print(USV_data.gps_latitude, coordinate_decimals);
    Serial3.print(",");
    Serial3.print(USV_data.gps_longitude, coordinate_decimals);
    Serial3.print(",");
    Serial3.print(USV_data.gps_course);
    Serial3.print(",");
    Serial3.print(USV_data.gps_speed);
    Serial3.print(",");
    Serial3.print(USV_data.gps_altitude);
    Serial3.print(",");
    Serial3.print(USV_data.gps_precision);
    Serial3.print(",");
    Serial3.print(USV_data.gps_n_satelites);
    Serial3.print(",");
    Serial3.print(USV_data.sens_0);
    Serial3.print(",");
    Serial3.print(USV_data.sens_1);
    Serial3.print(",");
    Serial3.print(USV_data.sens_2);
    Serial3.print(",");
    Serial3.print(USV_data.sens_3);
    Serial3.print(",");
    Serial3.print(USV_data.sens_4);
    Serial3.print(",");
    Serial3.print(USV_data.sens_5);
    Serial3.print(",");
    Serial3.print(USV_data.sens_6);
    Serial3.print(",");
    Serial3.print(USV_data.sens_7);
    Serial3.print(",");
    Serial3.print(USV_data.sens_8);
    Serial3.print(",");
    Serial3.println(USV_data.deep_sonar); 
}

void Print_PC_Serial_data(){
    Serial.print(USV_data.data_millis);
    Serial.print(",");
    Serial.print(USV_data.gps_year);
    Serial.print("/");
    Serial.print(USV_data.gps_month);
    Serial.print("/");
    Serial.print(USV_data.gps_day);
    Serial.print(",");
    Serial.print(USV_data.gps_hour);
    Serial.print(":");
    Serial.print(USV_data.gps_minute);
    Serial.print(":");
    Serial.print(USV_data.gps_second);
    Serial.print(",");
    Serial.print(USV_data.gps_latitude, coordinate_decimals);
    Serial.print(",");
    Serial.print(USV_data.gps_longitude, coordinate_decimals);
    Serial.print(",");
    Serial.print(USV_data.gps_altitude);
    Serial.print(",");
    Serial.print(USV_data.gps_speed);
    Serial.print(",");
    Serial.print(USV_data.gps_course);
    Serial.print(",");
    Serial.print(USV_data.gps_n_satelites);
    Serial.print(",");
    Serial.print(USV_data.gps_precision);
    Serial.print(",");
    Serial.print(USV_data.gps_n_sentenses);
    Serial.print(",");
    Serial.print(USV_data.sens_0);
    Serial.print(",");
    Serial.print(USV_data.sens_1);
    Serial.print(",");
    Serial.print(USV_data.sens_2);
    Serial.print(",");
    Serial.print(USV_data.sens_3);
    Serial.print(",");
    Serial.print(USV_data.sens_4);
    Serial.print(",");
    Serial.print(USV_data.sens_5);
    Serial.print(",");
    Serial.print(USV_data.sens_6);
    Serial.print(",");
    Serial.print(USV_data.sens_7);
    Serial.print(",");
    Serial.print(USV_data.sens_8);
    Serial.print(",");
    Serial.print(USV_data.angle_sonar);
    Serial.print(",");
    Serial.print(USV_data.confidence_sonar);
    Serial.print(",");
    Serial.print(USV_data.deep_sonar);
    Serial.print(",");    
    Serial.println(USV_data.profile_sonar);       
}

void CreateNewFileName(){
  // Check new Filename 
  for (uint8_t i = 0; i < 100; i++) {
    FileName[4] = i/10 + '0';
    FileName[5] = i%10 + '0';
    if (! SD.exists(FileName)) {
      break;  // leave the loop!
    }
  }
} 

void Print_SD(){    
    if(flag){
        if(new_file){
            CreateNewFileName();     
            print_SD = SD.open(FileName, FILE_WRITE); 
            print_SD.println(F(Header));
            print_SD.close();
            new_file = 0;
        }
        print_SD = SD.open(FileName, FILE_WRITE); 
        if (print_SD){                                           // If SD ok, reading and saving data if flag == True
            OK_SD = "OK";                
            RECORD = "OK";
            Save_data_SD();  
            counter += 1;  
            digitalWrite(led_Pin, !digitalRead(led_Pin));
        }
       else{
           OK_SD = "NA";
           digitalWrite(led_Pin, LOW);                             // LED --> OFF
           Serial.println("SD Error");  
           return;     
      }
    }   
    else{
      RECORD= "NA";
      digitalWrite(led_Pin, LOW);
    }                          
}

//Status(OK_SD,OK_GPS,OK_Sonar,NA_1,NA_2,RECORD,Counter)
void Status(String OK_SD, String OK_GPS, String OK_Sonar, String NA_1, String NA_2, String RECORD, uint16_t Counter){
    Status_REC.concat("$STS");
    Status_REC.concat(",");
    Status_REC.concat(OK_SD);
    Status_REC.concat(",");
    Status_REC.concat(OK_GPS);
    Status_REC.concat(",");
    Status_REC.concat(OK_Sonar);
    Status_REC.concat(",");
    Status_REC.concat(NA_1);
    Status_REC.concat(",");
    Status_REC.concat(NA_2);
    Status_REC.concat(",");
    Status_REC.concat(RECORD);
    Status_REC.concat(",");
    Status_REC.concat(Counter); 
    Serial3.println(Status_REC);
    Status_REC = "";  
}
