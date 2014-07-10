/**
 *
 * Sensing program for atmega328 reading commands from the serial port and returning value of the sensors
 *
 **/

char inCommand [20] = {};   // string to receive commands on the serial line

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Read sensors
  
  // Check for serial request
  bytesToRead = Serial.available();
  if (bytesToRead > 0) {
    incomingByte = Serial.read();
  }
  if (incomingByte == '0') digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);
  delay(1000);
  Serial.write("pass ");
}



/**
 *
 * void getCommand()
 * Loads next command from the serial line into the 'inCommand' char array if available.  Empties the array otherwise.
 *
 **/

void getCommand () {
  int 
  int bytesToRead = Serial.available();
  if (bytesToRead > 0) {
    while (
  }
}
