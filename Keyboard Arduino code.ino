const int trigPin1 = 11; // trigger output pin (s1)
const int echoPin1 = 10; // echo input pin (s1)     
const int trigPin2 = 6;  // trigger output pin (s2) 
const int echoPin2 = 5;  // echo input pin (s2) 
const int trigPin3 = 3;  // trigger output pin (s2) 
const int echoPin3 = 2;  // echo input pin (s2) 

//////distance calculation 
long duration;                               
int distance1, distance2,distance3; 
float r;
unsigned long temp=0;
int temp1=0;
int l=0;
//////

void find_distance (void);


void find_distance (void)                   
{ 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH, 5000);
  r = 3.4 * duration / 2;                
  distance1 = r / 100.00;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance2 = r / 100.00;
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance3 = r / 100.00;
  delay(100);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  delay (1000);
    
}
void loop() {
{
  find_distance();
  if (distance3>0){
       Serial.println("Pause");                
  }
  else{                 
  if(distance2<=20 && distance2>=10) 
  { 
    temp=ms();                  
    while(ms()<=(temp+300))     
      find_distance();
      if(distance2<=20 && distance2>=10) 
      {
        temp=distance2;                        
        while(distance2<=20 && distance2>=10)    
        {
          find_distance();                   
          if((temp+6)>distance2)          
         {
          Serial.println("up");        
        }
       }
      }
    else                                   
    {
      Serial.println("next");              
    }
  }

  else if(distance1<=20 && distance1>=10)   
  {
    temp=ms();                          
    while(ms()<=(temp+300))             
    {
       find_distance();
       if(distance2>=10 && distance1>=10)  
       {
         Serial.println("change");         
         l=1;                              
         break;                           
       }
    }
    
    if(l==0)                               
    {
    
  if(distance1<=20 && distance1>=10)
  { 
    temp=ms();                   
    while(ms()<=(temp+300))    
      find_distance();
      if(distance1<=20 && distance1>=10) 
      {
        temp=distance1;                         
        while(distance1<=20 && distance1>=10) 
        {
          find_distance();                  
          if((temp+6)>distance1)          
         {
          Serial.println("down");       
        }
       }
      }
    else                                 
    {
      Serial.println("previous");    
    }
  }                  
    }
    l=0;                                  
   }
   
}

}
}
