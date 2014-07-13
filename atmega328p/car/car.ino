
int i;

void setup()
{
  dir_init ();
  i = 0;
}

void loop()
{

  if (i < 4) {

    dir_straight();
    
    dir_leftPct (25);
    delay(1000);
    dir_leftPct (50);
    delay(1000);
    dir_leftPct (75);
    delay(1000);
    dir_leftPct (100);
    delay(1000);
  
    dir_straight ();
    delay(1000);
  
    dir_rightPct (25);
    delay(1000);
    dir_rightPct (50);
    delay(1000);
    dir_rightPct (75);
    delay(1000);
    dir_rightPct (100);
    delay(1000);

    i++;
  }

  dir_straight();
  
}

