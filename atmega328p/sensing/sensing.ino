/**
 *
 * Sensing program for atmega328 reading commands from the serial port and returning value of the sensors
 *
 **/

char inCommand [20] = {
};   // string to receive commands on the serial line
int ledRX = 5;
int ledTX = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledRX, OUTPUT);
  pinMode(ledTX, OUTPUT);
}

void loop() {
  int bytesToRead = 0;
  int incomingByte = 0;

  // Turn off leds
  digitalWrite (ledRX, LOW);
  digitalWrite (ledTX, LOW);

  // Read sensors

  // Check for serial request
  bytesToRead = Serial.available();
  if (bytesToRead > 0) {
    incomingByte = Serial.read();
    digitalWrite(ledRX, HIGH);
    delay(50);
  }
}



