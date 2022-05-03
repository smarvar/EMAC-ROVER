
#include "main.h"
#include "bluetooth.h"
#include "servo2.h"
#include "data_file_sensors.h"
#include "starter_main.h"
#include "print_data.h"
#include "sonar.h"
#include "gps.h"

void setup(){
  
    Serial_main();
    Serial.println("EMAC-USV Version 20/04/2022 --> sensors (CH0 = tem007, CH1 = obs001); Sensors_null = -9999");
    Bluetooth_conf();       //Enable Bluetooth comunication
    Activate_sensors();     //Enable Power Sensors
    Activate_gsm();         //Enable gsm communication
    //Activate_servo();     //Enable Servo
    Activate_SD();          //Enable SD
    Upload_files_config(1); //Load the sensors data file. To see data in Serial port, setting 1 otherwise 0
    Sampling_time();        //Set sampling data through Config-file, default 0 --> max rate
    Header_data();          //Printing data head in Serial port

}

void loop(){
    // Nothing happened
}

// For every gps reading (Serial interrupt)
void serialEvent2(){                                                                             
      while (Serial2.available() > 0){
          Timer_millis();                                                   // Start timer                      
          if (gps.encode(Serial2.read())){                                  // If there is conexion with gps --> reading data                          
              Bluetooth_read();                                             // Reading Bluetooth
              Data_gps();                                                   // Reading data gps, if Bluetooth setting 1 otherwise 0     
              Data_sensors();                                               // Reading data sensors   
              Data_sonar(Activate_Sonar_profile);                           // Reading data sonar, if profile data setting 1 otherwise 0; and if Bluetooth setting 1 otherwise 0                                         
              Print_Bluetooth_data();                                       // Print data Bluetooth and PC
              Print_PC_Serial_data(); 
              Print_SD();                                                   // Save data in SD if flag = 1 (the flag is sent by bluetooth)  
              delay(sampling_rate);                                         // Sampling rate to data          
              Status(OK_SD,OK_GPS,OK_Sonar,NA_1,NA_2,RECORD,counter);       // The status of sensors and state is sent by bluetooth 
         }
       //  counter_zero(); //use only with digital channel 8 connected  
     }                        
}
