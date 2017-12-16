class Motor {
    private:
       
        int _directionPin1;
        int _directionPin2;

    public:
        Motor(int dp1, int dp2) {
           
            _directionPin1 = dp1;
            _directionPin2 = dp2;
        }
        void begin() {
           
            pinMode(_directionPin1, OUTPUT);
            pinMode(_directionPin2, OUTPUT);
            digitalWrite(_directionPin1, LOW);
            digitalWrite(_directionPin2, LOW);
        }
        void forward() {
            digitalWrite(_directionPin1, HIGH);
            digitalWrite(_directionPin2, LOW);
        }
        void reverse() {
            digitalWrite(_directionPin1, LOW);
            digitalWrite(_directionPin2, HIGH);
        }
     
        void stop() {
           
            digitalWrite(_directionPin1, LOW);
            digitalWrite(_directionPin2, LOW);
        }
};
Motor waistMotor(3,5);
Motor leftMotor(10,11);
Motor rightMotor(6,9);
void setup() {
  
  Serial.begin(9600);
    leftMotor.begin();
    rightMotor.begin();
    pinMode(2,OUTPUT);
    digitalWrite(2,HIGH);
    Serial.println("Please enter number of steps to go!");
}
void roboForward(int x) 
    {
      for (int i=0;i<x;i++)
           {
      waistMotor.forward();
      rightMotor.forward();
      delay(300);
      rightMotor.stop();
      waistMotor.reverse();
      leftMotor.forward();
      delay(300);
      leftMotor.stop();
      rightMotor.forward();
          }
    }
void roboReverse(int y)
    {
      for (int i=0;i<y;i++)
        {
      waistMotor.forward();
      
      rightMotor.reverse();
      delay(300);
      rightMotor.stop();
      waistMotor.reverse();
      leftMotor.reverse();
      delay(300);
      leftMotor.stop();
      rightMotor.reverse();
        }
    }

void loop(){
  
while (Serial.available() == 0);

int steps = Serial.parseInt(); 

Serial.println(steps);

roboForward(steps);

roboReverse(steps);
}






