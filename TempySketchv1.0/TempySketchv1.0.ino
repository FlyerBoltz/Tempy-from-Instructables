

// **************************************************************************
// Sketch For Tempy- Temprature Controlled Smiley (On Instructables , By _Boltz_ Please don't change the credit.)Under Liscence CC-by-sa
// **************************************************************************
int mrr = 0.5; // Mood Refresh Rate , Changable, to tune the facial expression refresh rate
// **************************************************************************
#include <math.h>    //loads the more advanced math function
    int val;                //Create an integer variable
  double temp; 
  char mood; 
void setup() { 

}
 
double Thermister(int RawADC) {  //Function to perform the fancy math of the Steinhart-Hart equation
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;              // Convert Kelvin to Celsius
 return Temp;
}
 
void loop() 
{
 MoodRefresh();
 delay(mrr); 
}
void aoff()
{
digitalWrite(PB1,LOW);
digitalWrite(PB2,LOW);
digitalWrite(PB3,LOW);
}
void eyeblink()
{
  digitalWrite(PB4,HIGH);
  delay(random(0,3));
  digitalWrite(PB4,LOW);
  delay(200);
}
void meh()
{
  eyeblink();
  aoff();
}
void happy()
{
  aoff();
  digitalWrite(PB2,HIGH);
  eyeblink();
}
void sweat()
{
  aoff();
  eyeblink();
  digitalWrite(PB3,HIGH);
  digitalWrite(PB1,HIGH);
}

void shiver()
{
  aoff;
  digitalWrite(PB4,HIGH);
  digitalWrite(PB2,HIGH);
  digitalWrite(PB1,LOW);
  delay(150);
  digitalWrite(PB1,HIGH);
  digitalWrite(PB2,LOW);
  delay(150);
}
void MoodRefresh()
{
    val=analogRead(0);      //Read the analog port 0 and store the value in val
  temp=Thermister(val);   //Runs the fancy math on the raw analog value
  if(20<temp<25.4)
  {
    happy();
 }
 else if(25.5<temp<28)
 {
  meh();
 }
 else if(temp<20)
 {
  shiver();
 }
 else if(temp>28.001)
 {
  sweat();
 }
}




