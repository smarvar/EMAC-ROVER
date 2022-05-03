
/*
 *  GPS attached to serial2 port as follows:
 *  Gps_TXPin - Serial2_RX_pin 17 
 *  Gps_RXPin - Serial2_TX_pin 16 
 *  Baud rate by default = 9600. To change it see: https://freematics.com/forum/viewtopic.php?t=1759
 *  More info TinyGPS: http://arduiniana.org/libraries/tinygpsplus/  
*/

#include <TinyGPS++.h>
TinyGPSPlus gps;    // The TinyGPS++ object

// Function that prints the GPS date and time
static void DateTime(){ 
    
    if (gps.date.isValid()){ 
        USV_data.gps_year = gps.date.year();
        USV_data.gps_month = gps.date.month();
        USV_data.gps_day = gps.date.day();
    }
    else{
        USV_data.gps_year = 2022;
        USV_data.gps_month = 00;
        USV_data.gps_day = 00;  
    }
  
    if (gps.time.isValid()){
        USV_data.gps_hour = gps.time.hour();
        USV_data.gps_minute = gps.time.minute();
        USV_data.gps_second = gps.time.second();
    }  
    else{
        USV_data.gps_hour = 00;
        USV_data.gps_minute = 00;
        USV_data.gps_second = 00;     
    }
}


// Function that reads and prints different parameters of GPS
void Data_gps(){
        
    DateTime();                                                       // Raw date in YY/MM/DD, time HH:MM:SS:CS
    if (gps.location.isValid()){
        OK_GPS = "OK";
        USV_data.gps_latitude = gps.location.lat();
        USV_data.gps_longitude = gps.location.lng();
        USV_data.gps_altitude = gps.altitude.meters();
        USV_data.gps_speed = gps.speed.mph();
        USV_data.gps_course = gps.course.deg();
        USV_data.gps_n_satelites = gps.satellites.value();
        USV_data.gps_precision = gps.hdop.value();
        USV_data.gps_n_sentenses = gps.sentencesWithFix();
     }
     else{
        OK_GPS = "NA";
        USV_data.gps_latitude = 0;
        USV_data.gps_longitude = 0;
        USV_data.gps_altitude = 0;
        USV_data.gps_speed = 0;
        USV_data.gps_course = 0;
        USV_data.gps_n_satelites = 0;
        USV_data.gps_precision = 0;
        USV_data.gps_n_sentenses = 0;      
      }
                  
}
