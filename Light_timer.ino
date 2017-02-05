const int Touchsens1 = 2;
const int LED = 3;
const int Touchsens2 = 4;
const int push_button = 6;

  int people = 0; // # of people in the room 
  int on = HIGH; //helps to keep track if the light is on or off
  int off = LOW; 
  boolean state = true; //tells shether the room is for sleeping or not
  int hold;
void setup() {
  // put your setup code here, to run once:
  pinMode(Touchsens1, INPUT);
  pinMode(Touchsens2, INPUT);
  pinMode(push_button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sns1 = digitalRead(Touchsens1);
  int sns2 = digitalRead(Touchsens2);
  int work  = digitalRead(push_button);
  delay(100);
  if (work == HIGH && state == true){
    state = false;
    digitalWrite(LED, off);
    delay(1000);
  }
  else if(work == HIGH && state == false){
    state = true;
    digitalWrite(LED, hold);
    delay(500);
  }
  if (sns1 == HIGH && sns2 == LOW){
    int time = 0;
    while(time < 180000){
      int sns1 = digitalRead(Touchsens1);
    int sns2 = digitalRead(Touchsens2);
      if(sns2 == HIGH && sns1 == LOW){
      people += 1;
      break;
      }
      delay(100);
      time+= 100;
    }
  delay(1000);
  }
  if (sns1 == LOW && sns2 == HIGH){
    delay(100);
    int time = 0;
    while(time < 180000){
      int sns1 = digitalRead(Touchsens1);
    int sns2 = digitalRead(Touchsens2);
      if(sns2 == LOW && sns1 == HIGH){
        if(people != 0){
        people -= 1;
        }
      break;
      }
      delay(100);
      time+= 100;
    }
    delay(1000);
  }
  if(state == true){
  if (people >= 1){
    digitalWrite(LED, on);
    hold = on;
  }
  if (people == 0){
    digitalWrite(LED, off);
    hold = off;
  }
  }
  if(state == false){
    if (people >= 1){
    hold = on;
  }
    if (people == 0){
      hold = off;
    }
  }
}

