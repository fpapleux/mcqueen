
int i;

void setup()
{
  dir_init ();
  throttle_init();
  i = 0;
  Serial.begin (9600);
  pinMode (5, INPUT);
}

void loop()
{

  char in;
  int pulse = 0;
  int cm = 0;
  
  if (Serial.available() > 0) {
  
    in = Serial.read();
    if (in == 32) {
      pulse = pulseIn (5, HIGH);
      cm = (pulse / 147) * 2.54;
      Serial.println ("");
      Serial.print ("distance: ");
      Serial.print (cm);
      Serial.println (" cm");
    }  
  
  }
  
}

