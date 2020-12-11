#include <Servo.h>

Servo myservo;

int timer = 500;

// 設定紅外線腳位
int IR_Sensor_1 = 8;
int IR_Sensor_2 = 12;
int IR_Sensor_3 = 13;

int IR_1;
int IR_2;
int IR_3;

// 設定繼電器腳位
int relay = 4;

void setup(){
    Serial.begin(9600);
    pinMode(IR_Sensor_1, INPUT);
    pinMode(IR_Sensor_2, INPUT);
    pinMode(IR_Sensor_3, INPUT);
    pinMode(relay, OUTPUT);
    myservo.attach(9);
    myservo.write(0);
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

    // 設定條件一 -> 閥 奶茶
    if (IR_1 == 0 && IR_2 == 1 && IR_3 == 1){
        delay(2000); // 加入等待秒數，防止手臂還沒到就啟動
        water();
        delay(timer);
    }

    // 設定條件二 -> 閥 紅茶
    if (IR_1 == 1 && IR_2 == 0 && IR_3 == 1){
        delay(2000); // 加入等待秒數，防止手臂還沒到就啟動
        servo();
        delay(timer);
    }

    // 設定條件三 -> 伺服馬達
    if (IR_1 == 1 && IR_2 == 0 && IR_3 == 0){
        delay(2000); // 加入等待秒數，防止手臂還沒到就啟動
        water();
        delay(timer);
    }
}

// add milktea redtea
int water(){
    digitalWrite(relay, HIGH); // 加水
    delay(3000);
    digitalWrite(relay, LOW); // 停水
}

// add bubble
int servo(){
    myservo.write(90);
    delay(3000);
    myservo.write(0);
}