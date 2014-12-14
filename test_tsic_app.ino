#include <tsic.h>
/*Don't use Digital Pin 13 for Tsic-Sensor, because it is intern connected with a LED*/
/*Application is capable of testing Tsic506 zacwire and Tsic306/506analog*/

int error;
int error1;  //1 = OK, 0 = parity error    return value of getTSicTemp()
int temperatur;
int temperatur1;  // "return" of temperature in degrees Celsius * 100
float temp;
float temp1; // temperature in degrees Celsius

int czujnik = 0;
float odczyt,voltage,temperatura;

tsic Sensor1(3, 2);  //firstValue = VCC-Pin, secondValue = Signal-Pin
tsic Sensor2(3, 4);  //firstValue = VCC-Pin, secondValue = Signal-Pin

void setup(){
  Serial.begin (9600);

}
void loop(){ 
  error = Sensor1.getTSicTemp(&temperatur);  //turn the TSIC-Sensor ON -> messure -> OFF
  error1 = Sensor2.getTSicTemp(&temperatur1);  //turn the TSIC-Sensor ON -> messure -> OFF
  temp=temperatur/100.0;
  temp1=temperatur1/100.0;
  Serial.print("Temperatur1: ");
  Serial.print(temp);
  Serial.println(" GradCelsius");
  Serial.print("Temperatur11: ");
  Serial.print(temp1);
  Serial.println(" GradCelsius");  
  Serial.print("Status: ");
  Serial.print(error);
  Serial.println(error1);
  
  odczyt = analogRead(1);
  voltage = (odczyt*0.0048828125); //current level
  temperatura = (voltage*200)-50; //recalculated temp
  Serial.print("Voltage:");
  Serial.println(voltage);
  Serial.print("Temperatura Analogowa:");
  Serial.println(temperatura);
  
  delay(1000);
}




