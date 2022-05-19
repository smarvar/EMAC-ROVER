//Bluetooth attached to serial3 port

String text_bluetooth = "", Status_REC ="", Data_file ="";
bool flag = 0;
bool new_file = 0;

void Bluetooth_conf();
void Bluetooth_read();


void Bluetooth_conf(){
  pinMode(Bluetooth_pin, OUTPUT);       // Power pin Bluetooth Activated
  digitalWrite(Bluetooth_pin, HIGH);
  Serial3.begin(Bluetooth_Baud); // BT serial port started
}

void Bluetooth_read(){  
    //Read data from Bluetooth
    while(Serial3.available()>0)
    text_bluetooth = Serial3.readString();
    Serial3.println(text_bluetooth);
    if (text_bluetooth.equals("$REC")){
        flag = 1;
        new_file = 1;  
        Serial.println("SD data recording enabled");
        Serial3.println(text_bluetooth);
    }
    if(text_bluetooth.equals("$STOP")){
        flag = 0;
        new_file = 0;
        Data_file = "";  
        counter = 0;  
        Serial.println("SD data recording disabled");
        Serial3.println(text_bluetooth);  
    }    
    text_bluetooth = ""; //reset     
}
