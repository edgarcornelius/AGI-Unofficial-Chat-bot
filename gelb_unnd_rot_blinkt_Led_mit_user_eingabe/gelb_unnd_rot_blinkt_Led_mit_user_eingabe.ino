
int yellowLEDPin=9; // gelbe diode
int redLEDPin=8; // rote diode

int yellowOnTime=200; // gelbe diode an
int yellowOffTime=200; // gelbe diode aus

int redOnTime=200; // rote diode an in millisekunden
int redOffTime=200; // rote diode aus

int nummergelbblinkt=5;  // oft blinkt die gelbe Diode 
int nummerrotblinkt=5; // so oft blinkt die rote Diode

float writeValueYellow; // Variable zugewiesen 
float writeValueRed; 

void setup() {   //Feste Einstellungen
  
  Serial.begin(9600);      //´sendet mit 9600 Speed zum seriellen Monitor
  pinMode(yellowLEDPin, OUTPUT); //Output über Pin 9 
  pinMode(redLEDPin, OUTPUT);  //Output über Pin 8

  Serial.println("Tippe eine Nummer zwischen 0 und 255 für die gelbe LED ");
  while (Serial.available()==0){} //wartet auf user input
  writeValueYellow=Serial.parseInt(); //lese user Input

  Serial.println("Tippe eine Nummer zwischen 0 und 255 für die Rote LED  ");
  while (Serial.available()==0){} //wartet auf user input
  writeValueRed=Serial.parseInt(); //lese user input
}
void loop() {   //niemals endende Wiederholungsschleife

  
Serial.println("");  
Serial.println("The YellowLED is Blinking");   //Start des Zählers
for (int i=1; i<=nummergelbblinkt; i=i+1 ) {  //Zähler funktion kleiner als

  Serial.print("Gelb blinkt zum   #:");        //Gibt Zahl aus
  Serial.println(i);
 analogWrite(yellowLEDPin,writeValueYellow);
  delay(yellowOnTime);  
  analogWrite(yellowLEDPin,0);
  delay(yellowOffTime);
} 
Serial.println("");


Serial.println("The Red LED is Blinking");
for (int i=1; i<=nummerrotblinkt; i=i+1 ) 
{
  Serial.print("Rot blinkt zum    #:");
  Serial.println(i);
  analogWrite(redLEDPin,writeValueRed);   //von digital nach anolog geändert 1volt =51
  delay(redOnTime);  
  analogWrite(redLEDPin,0);
  delay(redOffTime);
  }
   }

