#include <Servo.h>

Servo myservo;

// setting timer
int timer_wait = 5000;
int timer_water = 6000;
int timer_arm = 2000;
int timer_bubble = 1500;

// setting IR position
int IR_Sensor_1 = 8;
int IR_Sensor_2 = 12;
int IR_Sensor_3 = 13;

int IR_1;
int IR_2;
int IR_3;

// setting relay position
int relay_1 = 7;
int relay_2 = 4;

void setup(){
    Serial.begin(9600);
    pinMode(IR_Sensor_1, INPUT);
    pinMode(IR_Sensor_2, INPUT);
    pinMode(IR_Sensor_3, INPUT);
    pinMode(relay_1, OUTPUT);
    pinMode(relay_2, OUTPUT);
    myservo.attach(9);
    myservo.write(0);
    delay(timer_wait);
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

    // condition 1st -> valve milktea
    if (IR_1 == 1 && IR_2 == 1 && IR_3 == 0){
        delay(timer_arm); // add delay avoid start the arm before it arrives
        water_1();
        delay(timer_wait);
    }

    // condition 2ed -> valve blacktea
    if (IR_1 == 1 && IR_2 == 0 && IR_3 == 1){
        delay(timer_arm); // add delay avoid start the arm before it arrives
        water_2();
        delay(timer_wait);
    }

    // condition 3rd -> add bubble
    if (IR_1 == 0 && IR_2 == 1 && IR_3 == 1){
        delay(timer_arm); // add delay avoid start the arm before it arrives 
        servo_bubble();
        delay(timer_wait);
    }
    
}

// add milktea
int water_1(){
    digitalWrite(relay_1, HIGH); // add water
    delay(timer_water);
    digitalWrite(relay_1, LOW); // stop water
}

// add blacktea
int water_2(){
    digitalWrite(relay_2, HIGH); // add water
    delay(timer_water);
    digitalWrite(relay_2, LOW); // stop water
}

// add bubble
int servo_bubble(){
    myservo.write(90);
    delay(timer_bubble);
    myservo.write(0);
}