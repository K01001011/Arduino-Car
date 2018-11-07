
#include <SoftwareSerial.h>
//L293D
//Motor A
const int motorPin1  = 7;  // Pin 14 of L293
const int motorPin2  = 8;  // Pin 10 of L293
//Motor B
const int motorPin3  = 4; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293
const int spd  = 10;
const int spd1  = 11;

const int trigPin = 3;
const int echoPin = 2;
long duration;
int distance=12;

const int trigPin1 = 13;
const int echoPin1 = 12;
long duration1;
int distance1=12;

char command;
String string;

/*

      MOTOR A
      8     7
      MOTOR B
      5     4

      WHICHEVER HAS 180 WILL MOVE
      8 and 5 are facing forward


*/



//This will run only one time.
void setup(){

    Serial.begin(9600);
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(spd, OUTPUT);
    pinMode(spd1, OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);
    pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin1, INPUT);
  
}


void loop(){
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
    distance= duration*0.034/2;
    distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.println(distance1);
    analogWrite(spd,120);
    analogWrite(spd1,120);
    if (Serial.available() > 0)
    {
        string = "";
    }
    while(Serial.available() > 0)
    {
        command = ((byte)Serial.read());
        if(command == ':')
        {
            break;
            Serial.println(string);
        }
        else
        {
            string += command;
            Serial.println(string);
        }
        delay(1);
    }
    if(string == "UP")
    {
        up();
        string = "";
    }
    if(string =="RT")
    {
        right();
        string = "";
        Serial.println(string); //debug
    }
    if(string =="LT")
    {
        left();
        string = "";
        Serial.println(string); //debug
    }
}

void left()
{
//    //This code  will turn Motor A clockwise for 2 sec.
//    analogWrite(motorPin1,5);
//    analogWrite(motorPin2, 0);
//    analogWrite(motorPin3, 5);
//    analogWrite(motorPin4, 0);
    //This code will turn Motor B clockwise for 2 sec.

    //LEFT
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(2000);
    //And this code will stop motors
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
    delay(5000);
}


void up()
{
//    //This code will turn Motor B counter-clockwise for 2 sec.
//    analogWrite(motorPin1, 180);
//    analogWrite(motorPin2, 0);
//    analogWrite(motorPin3, 0);
//    analogWrite(motorPin4, 180);
//    //This code  will turn Motor A clockwise for 2 sec.
//    analogWrite(motorPin1,5);
//    analogWrite(motorPin2, 0);
//    analogWrite(motorPin3, 5);
//    analogWrite(motorPin4, 0);
//    delay(2000);
//    //And this code will stop motors
//    analogWrite(motorPin1, 0);
//    analogWrite(motorPin2, 0);
//    analogWrite(motorPin3, 0);
//    analogWrite(motorPin4, 0);
//    delay(5000);

    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(2000);
    //And this code will stop motors
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
    delay(5000);
}


void right()
{
//    //This code will turn Motor B clockwise for 2 sec.
//    analogWrite(motorPin1, 0);
//    analogWrite(motorPin2, 180);
//    analogWrite(motorPin3, 180);
//    analogWrite(motorPin4, 0);
//    //This code will turn Motor A counter-clockwise for 2 sec.
//    analogWrite(motorPin1, 0);
//    analogWrite(motorPin2, 180);
//    analogWrite(motorPin3, 0);
//    analogWrite(motorPin4, 180);
//    delay(2000);
//    //And this code will stop motors
//    analogWrite(motorPin1, 0);
//    analogWrite(motorPin2, 0);
//    analogWrite(motorPin3, 0);
//    analogWrite(motorPin4, 0);


    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(2000);
    //And this code will stop motors
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
    delay(5000);
}
