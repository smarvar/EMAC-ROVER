
/*
 * IniFile.h is a library to explore .ini and .sen files
 * for more info to see IniFile repo: https://github.com/stevemarple/IniFile 
 * 
 * Serardor.h is a library to obtain data that is separated by ',' , ';' , '/t', ' ' etc.   
 * This requires the type of data separator and the position of the element in the array
*/

#include <IniFile.h>
#include <Separador.h>

/*
  SD card attached to SPI bus as follows:
  
  Adafruit Module :
  DI - pin 51 
  DO - pin 50 
  CLK - pin 52 
  CS - pin 53
  
  HW-125 Module:
  CS - pin 53
  SCK - pin 52
  MOSI - pin 51
  MISO - pin 50  
  
  More info SD.h: https://learn.adafruit.com/adafruit-micro-sd-breakout-board-card-tutorial/arduino-library
                  https://create.arduino.cc/projecthub/electropeak/sd-card-module-with-arduino-how-to-read-write-data-37f390
*/

uint32_t digital_counter = 0;
long last_interrupt = millis();
float correntometro_coversion = 0.01; //--> 5/500
float num_null = -9999;

#include <SD.h>
File print_SD;      // The SD object

struct Sensors_info{
      String Descripcion, Unidad, X, Y;
      uint8_t ID, Decimales, Entrada, Modo, Salida;
      uint16_t Raw;
      float Sensor_value;};

Sensors_info Sensorx[analog_sensors];
Separador s;
char buffer_data[bufferLen];
float analog_resolution = DC_power/ADC_resolution;
unsigned long sampling_rate = 0;


struct Sensors_data{
      float gps_latitude, gps_longitude, gps_altitude, gps_speed, gps_course, sens_0=num_null, sens_1=num_null, sens_2=num_null, 
      sens_3=num_null, sens_4=num_null, sens_5=num_null, sens_6=num_null, sens_7=num_null, sens_8=num_null, angle_sonar;
      uint8_t gps_n_satelites, gps_precision, gps_n_sentenses, gps_month, gps_day, gps_hour, gps_minute, gps_second;
      uint16_t data_millis, gps_year, confidence_sonar;
      uint32_t deep_sonar;
      String profile_sonar;};

Sensors_data USV_data;

//Scans the contents of a file using a given path and description
String Scan_file(const char *filename, const char *variable){
      
      while (true) {
         char sectName[bufferLen];
         IniFileState state;     
         IniFile ini(filename);
         
          if (!ini.open()) {
              return "Ini file does not exist ";
              break;
          }
        
          // Check the file is valid. This can be used to warn if any lines
          // are longer than the buffer.
          if (!ini.validate(buffer_data, bufferLen)) {
              return "ini file not valid ";
              break;
          }
          else{ 
              while (ini.browseSections(sectName, bufferLen, state)) {
                  if (ini.getValue(sectName, variable, buffer_data, bufferLen)) { 
                      return buffer_data;
                      break;
                  } 
                  else{
                      return "No variable ";  
                      break;
                    }
              }
          }
      }
}

//Get the path of a file if it exists in the folder
String GetFilePath(String name_file, String folder) {
    
      print_SD = SD.open(Sensors_folder);    
      String fil; 
      String path;
      while (true) {
          File entry =  print_SD.openNextFile();    
          fil = entry.name();
          fil.toLowerCase();
          
          if (name_file == fil){
              path += folder;
              path += "/";
              path += name_file;   
              entry.close();
              return path;
              break;      
            }
      
          if (! entry) {
            // no more files
              return "no_file";
              break;
          }
           entry.close();
      }
}


//Reading file sensors by channel
void Sensors(bool print_serial){

    for (int cont = 0; cont < analog_sensors; cont += 1){  
        String file_name = Scan_file(Conf_file, channel[cont]);    
        String path = GetFilePath(file_name, Sensors_folder);
         
        if (file_name != "0" && path != "no_file"){               
            char path_char[bufferLen];
            path.toCharArray(path_char, bufferLen);    
            String ID = Scan_file(path_char, "ID");
            Sensorx[cont].ID = ID.toInt();
            Sensorx[cont].Descripcion = Scan_file(path_char, "Descripcion");
            Sensorx[cont].Unidad = Scan_file(path_char, "Unidad");
            String Decimales = Scan_file(path_char, "Decimales");
            Sensorx[cont].Decimales = Decimales.toInt();
            String Entrada = Scan_file(path_char, "Entrada");
            if (Entrada == "TENSION")
                Sensorx[cont].Entrada = 0;
            else
                Sensorx[cont].Entrada = 1;
            String Modo = Scan_file(path_char, "Modo");
            if (Modo == "CICLO")
                Sensorx[cont].Modo = 0;
            else
                Sensorx[cont].Modo = 1;
            String Salida = Scan_file(path_char, "Modo");
            if (Salida == "TEXTO")
                Sensorx[cont].Salida = 0;
            else
                Sensorx[cont].Salida = 1;   
            Sensorx[cont].X = Scan_file(path_char, "X");
            Sensorx[cont].Y = Scan_file(path_char, "Y");
            if (print_serial){
                Serial.print("Channel_conf: ");
                Serial.println(cont);           
                Serial.println(Sensorx[cont].ID);
                Serial.println(Sensorx[cont].Descripcion);
                Serial.println(Sensorx[cont].Unidad);
                Serial.println(Sensorx[cont].Decimales);
                Serial.println(Sensorx[cont].Entrada);
                Serial.println(Sensorx[cont].Modo);
                Serial.println(Sensorx[cont].Salida);
                Serial.println(Sensorx[cont].X);
                Serial.println(Sensorx[cont].Y);
                Serial.println();
                }  
        }
        else{
            Sensorx[cont].ID = 0;
            Sensorx[cont].Descripcion ="NA";
            Sensorx[cont].Unidad ="NA";
            Sensorx[cont].Decimales = 1;
            Sensorx[cont].Entrada = 0;
            Sensorx[cont].Modo = 0;
            Sensorx[cont].Salida = 0;
            Sensorx[cont].X = "0";
            Sensorx[cont].Y = "0";
            Serial.print("Channel_conf: ");
            Serial.print(cont);  
            Serial.print(" has no sensor assigned, or the file doesn't exist ");   
            Serial.println();                  
        }
    }
}

//Get sensor value by channel selected
float SensorValue(int channel){  
  
      Sensorx[channel].Raw= analogRead(channel);
      //Sensorx[channel].Raw = 512; //Valor de prueba
      float Analogic_value = Sensorx[channel].Raw * analog_resolution;
      if (Sensorx[channel].Descripcion != "NA"){
          for (int pos=0; pos <= Sensorx[channel].X.length(); pos+=1){
              String X1 = s.separa(Sensorx[channel].X, sens_separator, pos);
              String X2 = s.separa(Sensorx[channel].X, sens_separator, pos+1);
              String Y1 = s.separa(Sensorx[channel].Y, sens_separator, pos);
              String Y2 = s.separa(Sensorx[channel].Y, sens_separator, pos+1);
              float X1_f = X1.toFloat();
              float X2_f = X2.toFloat();
              float Y1_f = Y1.toFloat();
              float Y2_f = Y2.toFloat();
              if ((Analogic_value >= X1_f) && (Analogic_value <= X2_f)){  
                  float m = (Y2_f-Y1_f)/(X2_f-X1_f);
                  float b = Y1_f-(m*X1_f);
                  float real_value = (m*Analogic_value)+b;
                  pos = Sensorx[channel].X.length()+1;
                  return real_value;
                  break;
              }
          }
      }
      else {
          return 0;
      }
}


void Pulse_counter(){
  digital_counter += 1;  
  USV_data.sens_8 = digital_counter*correntometro_coversion;
 }


void counter_zero(){
    if (millis() - last_interrupt > seconds_interrupt*1000){
        last_interrupt = millis();
        digital_counter = 0;
        USV_data.sens_8 = digital_counter*correntometro_coversion;
    }
}


// Function that reads and prints the analog ports for others sensors connected

void Data_sensors (){
  
     for (int ch = 0; ch < analog_sensors; ch += 1) {  
            
          if (Sensorx[ch].Descripcion != "NA"){    
                               
              switch (ch) {
                  case 0:
                    USV_data.sens_0 = SensorValue(ch);
                    break;
                  case 1:
                    USV_data.sens_1 = SensorValue(ch);
                    break;
                  case 2:
                    USV_data.sens_2 = SensorValue(ch);
                    break; 
                  case 3:
                    USV_data.sens_3 = SensorValue(ch);
                    break; 
                  case 4:
                    USV_data.sens_4 = SensorValue(ch);
                    break;             
                  case 5:
                    USV_data.sens_5 = SensorValue(ch);
                    break;             
                  case 6:
                    USV_data.sens_6 = SensorValue(ch);
                    break;             
                  case 7:
                    USV_data.sens_7 = SensorValue(ch);
                    break;                                   
            }
        }

    }
}
