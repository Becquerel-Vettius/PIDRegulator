#include <Wire.h>

float roll;
float pitch;

float error = 0;


const float r = 0;

const float Kp = 20;
const float Kd = 0.00;
const float Ki = 0.000;

void setup() {
  Serial.begin(57600);
  startgyro(); // Kalibrerar även gyron.
}

void loop() {
  getangles(pitch, roll);

  //Serial.print(roll, 1);
  //Serial.print(", ");
  //Serial.println(pitch, 1);


  float e_prev = error;
  error = roll-r;

  float u = PID(error,Kp,Kd,Ki, e_prev);

  Serial.println(u);
  Serial.println(error);
  Serial.println(analogRead(0));
  Serial.println();

  if (analogRead(0)<=35){
    runMotor(0);
  } else {
    runMotor(u);
  }
}

