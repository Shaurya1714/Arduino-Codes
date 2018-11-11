//Value declaration
//motors
int rm_pin=2;
int lm_pin=3;
int rm_pin2=4;
int lm_pin2=5;
//sensors
int frs_pin=6;
int fls_pin=7;
int frs_value;
int fls_value;
int brs_pin=8;
int bls_pin=9;
int brs_value;
int bls_value;
//defining the function
void read_sen_value()
{ frs_value = digitalRead(frs_pin);
  fls_value = digitalRead(fls_pin);
  brs_value = digitalRead(brs_pin);
  bls_value = digitalRead(bls_pin);
  Serial.print(frs_value);
  Serial.print("|");
  Serial.print(fls_value);
  Serial.print("|");
  Serial.print(brs_value);
  Serial.print("|");
  Serial.println(bls_value);
  }
void forward()//both high
{ 
  Serial.println("forward");
  digitalWrite(lm_pin,1);
  digitalWrite(rm_pin,1);
  
  digitalWrite(lm_pin2,0);
  digitalWrite(rm_pin2,0);
  }
void right()//right high
{ 
  Serial.println("right");
  digitalWrite(lm_pin,1);
  digitalWrite(rm_pin,0);
  
  digitalWrite(lm_pin2,0);
  digitalWrite(rm_pin2,1);
  }  
void left()//left high
{ 
  Serial.println("left");
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

void reverse()//both high
{ 
  Serial.println("reverse");
  digitalWrite(lm_pin,0);
  digitalWrite(rm_pin,0);
  
  digitalWrite(lm_pin2,1);
  digitalWrite(rm_pin2,1);
  } 
    
void check_direction_move()
{ //all sensors see the table
  if(fls_value == 0 && frs_value == 0 && bls_value == 0 && brs_value == 0) 
  {forward();
  }
  //one sensor off the table
  else if(fls_value == 1 && frs_value == 0 && bls_value == 0 && brs_value == 0) 
  {right();
   delay(500);
   forward();   
  delay(400);
  } 

  else if(fls_value == 0 && frs_value == 1 && bls_value == 0 && brs_value == 0) 
  {left();
   delay(500);
   forward();   
  delay(400);
  }

  else if(fls_value == 0 && frs_value == 0 && bls_value == 1 && brs_value == 0) 
  {
   forward();   
  delay(400);
  }

  
  else if(fls_value == 0 && frs_value == 0 && bls_value == 0 && brs_value == 1) 
  {
   forward();   
  delay(400);
  }
  //two sensors off the table
  else if(fls_value == 1 && frs_value == 0 && bls_value == 1 && brs_value == 0)
  {right();
   delay(500);
   forward();
   delay(400);}
   

  else if(fls_value == 0 && frs_value == 1 && bls_value == 0 && brs_value == 1)
  {left();
   delay(500);
   forward();
   delay(400);}
  
  else if(fls_value == 1 && frs_value == 1 && bls_value == 0 && brs_value == 0)
  {reverse();
   delay(500);
   right();
   delay(400);
   forward();
   delay(400);}

  
  else if(fls_value == 0 && frs_value == 0 && bls_value == 1 && brs_value == 1)
  {
   forward();
   delay(400);}

   //three sensors off the table

   
  else if(fls_value == 1 && frs_value == 1 && bls_value == 0 && brs_value == 1)
  {
   left();
   delay(400);
   forward();
   delay(400);}

  else if(fls_value == 1 && frs_value == 1 && bls_value == 1 && brs_value == 0)
  {
   right();
   delay(400);
   forward();
   delay(400);}


 else if(fls_value == 1 && frs_value == 0 && bls_value == 1 && brs_value == 1)
  {
   right();
   delay(400);
   forward();
   delay(400);}

else if(fls_value == 0 && frs_value == 1 && bls_value == 1 && brs_value == 1)
  {
   left();
   delay(400);
   forward();
   delay(400);}

else 
{ STOP();}   
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(rm_pin, OUTPUT);
  pinMode(lm_pin, OUTPUT);
  pinMode(rm_pin2, OUTPUT);
  pinMode(lm_pin2, OUTPUT);
  pinMode(frs_pin, INPUT);
  pinMode(fls_pin, INPUT);
  pinMode(brs_pin, INPUT);
  pinMode(bls_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 read_sen_value();

 check_direction_move();

 
}
