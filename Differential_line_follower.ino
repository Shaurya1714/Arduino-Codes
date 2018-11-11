//Value declaration
//motors
int rm_pin=2;
int lm_pin=3;
int rm_pin2=4;
int lm_pin2=5;
//sensors
int rs_pin=6;
int ls_pin=7;
int rs_value;
int ls_value;

//defining the function
void read_sen_value()
{ rs_value = digitalRead(rs_pin);
  ls_value = digitalRead(ls_pin);
  }
void forward()//both high
{ 
  digitalWrite(lm_pin,1);
  digitalWrite(rm_pin,1);
  digitalWrite(lm_pin2,0);
  digitalWrite(rm_pin2,0);
  }
void right()//right high
{ 
  digitalWrite(lm_pin,1);
  digitalWrite(rm_pin,0);
  digitalWrite(lm_pin2,0);
  digitalWrite(rm_pin2,1);
  }  
void left()//left high
{ 
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,1);
  digitalWrite(lm_pin2,1);
  digitalWrite(rm_pin2,0);
  }  
void STOP()//both LOW
{ 
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,0);
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,0);
  }  
    
void check_direction_move()
{ 
  if(ls_value == 0 && rs_value == 0) //ww
  {forward();
  }
  else if(ls_value == 0 && rs_value == 1)//wb
  {right();
  }
  else if(ls_value == 1 && rs_value == 0)//bw
  {left();
  }
  else if(ls_value == 1 && rs_value == 1)//bb
  {STOP();
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  pinMode(rm_pin, OUTPUT);
  pinMode(lm_pin, OUTPUT);
  pinMode(rm_pin2, OUTPUT);
  pinMode(lm_pin2, OUTPUT);
  pinMode(rs_pin, INPUT);
  pinMode(ls_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 read_sen_value();

 check_direction_move();
}
