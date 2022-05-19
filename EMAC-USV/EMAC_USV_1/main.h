#define seconds_interrupt 10
#define Sensors_Pin 7
#define Digital_pin 2
#define GSM_Pin 5
#define led_Pin 13
#define SD_pin 53
#define Servo_pin 11
#define Bluetooth_pin 5
#define DC_power 5.0
#define ADC_resolution 1024
#define Sonar_Baud 115200
#define GPS_Baud 38400  
#define PC_Baud 115200
#define Bluetooth_Baud 9600
#define Second 1000
#define Minute 60000
#define bufferLen 150
#define analog_sensors 2
#define data_separator ','
#define sens_separator ';'
#define coordinate_decimals 6
#define Activate_Sonar_profile 1
#define Conf_file "/EMACConf.ini"
#define Sensors_folder "/Sensors"
#define Header "Timer, Date, Time, Latitude, Longitude, Alture, Speed, Course, N_Sateleites, HDOP, RX_GPS, CH0, CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8, Sonar_Angle, Confidence, Deep, Profile_points"
const char* channel[] = {"CH0_conf", "CH1_conf", "CH2_conf", "CH3_conf", "CH4_conf", "CH5_conf", "CH6_conf", "CH7_conf", "CH8_conf"};
String OK_SD ="NA", OK_GPS ="NA", OK_Sonar ="NA", NA_1 ="NA", NA_2 ="NA", RECORD ="NA";
uint16_t counter = 0;
char FileName[] = "EMAC00.csv";
