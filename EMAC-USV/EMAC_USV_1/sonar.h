
/*
 *  Ping-Sonar-R2-RP attached to serial1 port as follows:
 *  PING_TX (white) - Serial1_RX_Pin = 19 
 *  PING_RX (green) - Serial1_TX_Pin = 18 
 *  General info Ping Sonar:  https://bluerobotics.com/store/sensors-sonars-cameras/sonar/ping-sonar-r2-rp/
 *  Github oficial            https://github.com/bluerobotics/ping-arduino
 *  Info Library              http://docs.bluerobotics.com/ping-arduino/annotated.html
*/ 

#include "ping1d.h"

static Ping1D ping { Serial1 }; // The Ping1D object
float angle_sonar = 0.0;        // Sonar emission angle
String P_data;

void Data_sonar(bool);


// Function that reads and prints the sonar data
void Data_sonar(bool profile_data){        
  
   // Get profile points vector
   if (ping.request(Ping1DNamespace::Profile)){         
        OK_Sonar = "OK";
        USV_data.angle_sonar = angle_sonar; // Angle in grades
        USV_data.deep_sonar = ping.distance(); // Deep in mm
        USV_data.confidence_sonar = ping.confidence(); // Confidence en %                                          
        if (profile_data){
            for (int i = 0; i < ping.profile_data_length(); i++){  // Read ping.profile_data_length() = 200 
                P_data.concat(ping.profile_data()[i]);             // Every cell betwen (0-255)    
                P_data.concat(",");
                }                                          
            USV_data.profile_sonar = P_data;
            P_data = "";        
        }                                             
    } 
    else{
        OK_Sonar = "NA"; 
        USV_data.angle_sonar = 0; 
        USV_data.deep_sonar = 0; 
        USV_data.confidence_sonar = 0;  
        USV_data.profile_sonar = "0";   
    }
}
