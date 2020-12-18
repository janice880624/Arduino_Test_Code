int LED_1 = 4;
int isObstaclePin_1 = 7;  
int isObstacle_1 = HIGH;
int LED_2 = 5;
int isObstaclePin_2 = 8;  
int isObstacle_2 = HIGH; 
int LED_3 = 6;
int isObstaclePin_3 = 9;  
int isObstacle_3 = HIGH;   

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
