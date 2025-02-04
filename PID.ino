float e_sum = 0;
const int signal_PIN = 3;

float PID(float e, float p,float d, float i, float e_prev){
  float prop = p * e;
  float deri = (e - e_prev) * d;
  e_sum += e;
  float inte = e_sum * i;
  
  float u = prop + deri + inte;

  return u;
}

void runMotor(float u){

u = map(u,-200,200,0,200);
u = constrain(u,0,50);
analogWrite(signal_PIN, u);

}