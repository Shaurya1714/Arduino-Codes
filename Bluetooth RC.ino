//Value declaration
//motors
int rm_pin=2;
int lm_pin=3;
int rm_pin2=4;
int lm_pin2=5;

char data ='S' ;
//defining the function
 
void forward()//both high
{ 
  digitalWrite(lm_pin,1);
  digitalWrite(rm_pin,1);
  digitalWrite(lm_pin2,0);
  digitalWrite(rm_pin2,0);
  }
void backward()//right high
{ 
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,0);
  digitalWrite(lm_pin2,1);
  digitalWrite(rm_pin2,1);
  }  
void left()//left high
{ 
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,1);
  digitalWrite(lm_pin2,1);
  digitalWrite(rm_pin2,0);
  }  

  void right()//left high
{ 
  digitalWrite(lm_pin,1);
  digitalWrite(rm_pin,0);
  digitalWrite(lm_pin2,0);
  digitalWrite(rm_pin2,1);
}
void STOP()//both LOW
{ 
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,0);
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,0);
  }  
    




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(500);
  pinMode(rm_pin, OUTPUT);
  pinMode(lm_pin, OUTPUT);
  pinMode(rm_pin2, OUTPUT);
  pinMode(lm_pin2, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available() > 0)
  {
     data = Serial.read();
     Serial.println(data);
     if(data == 'S')
        STOP();
     else if(data == 'F')
        forward();
     else if(data == 'B')
        backward();
     else if(data == 'L')
        left();
     else if(data == 'R')
        right();
  }             
}
