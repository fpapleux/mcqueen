
int i;

void setup()
{
  dir_init ();
  throttle_init();
  i = 0;
}

void loop()
{

  if (i < 2) {

    dir_straight();
    throttle_idle();
    delay (2000);
    
    dir_leftPct (50);
    throttle_forwardPct (25);
    delay (3000);

    dir_straight();
    throttle_idle();
    delay (2000);    
  
    dir_rightPct (50);
    throttle_reversePct (25);
    delay (3000);

    i++;
  }

  dir_straight();
  throttle_idle ();
  
}

