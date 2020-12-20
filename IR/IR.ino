int timer = 500;

int IR_Sensor_1 = 8;
int IR_Sensor_2 = 12;
int IR_Sensor_3 = 13;

int IR_1;
int IR_2;
int IR_3;

int relay = 4;

void setup(){
    Serial.begin(9600);
    pinMode(IR_Sensor_1, INPUT);
    pinMode(IR_Sensor_2, INPUT);
    pinMode(IR_Sensor_3, INPUT);
    pinMode(relay, OUTPUT);
    delay(timer);
}

void loop(){
    Serial,printf("Hello");
    IR_1 = digitalRead(IR_Sensor_1);
    IR_2 = digitalRead(IR_Sensor_2);
    IR_3 = digitalRead(IR_Sensor_3);
    Serial.print("IR_1=");
    Serial.println(IR_1);
    Serial.print("IR_2=");
    Serial.println(IR_2);
    Serial.print("IR_3=");
    Serial.println(IR_3);
    //-------------------------------------

    if (IR_1 == 0 && IR_2 == 1 && IR_3 == 1){
        water();
        delay(timer);
    }
}

int water(){
    digitalWrite(relay, HIGH);
    delay(timer);
    digitalWrite(relay, LOW);
    delay(timer);
}