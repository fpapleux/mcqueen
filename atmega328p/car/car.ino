
int i;

void setup()
{
  dir_init ();
  throttle_init();
  i = 0;
}

void loop()
{

  if (i < 3) {

    dir_straight();
    throttle_idle();
    delay (2000);
    
    throttle_forwardPct (25);
    delay (2000);
    throttle_reversePct (25);
    delay (2000);
    throttle_forwardPct (25);
    delay (2000);

    i++;
  }

  dir_straight();
  throttle_idle ();
  
}

