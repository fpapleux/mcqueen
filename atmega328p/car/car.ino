
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
    
    dir_leftPct (25);
    throttle_forwardPct (25);
    delay(1000);
    dir_leftPct (50);
    throttle_forwardPct (50);
    delay(1000);
    dir_leftPct (75);
    throttle_forwardPct (75);
    delay(1000);
    dir_leftPct (100);
    throttle_forwardPct (100);
    delay(1000);
  
    dir_straight ();
    throttle_idle ();
    delay(1000);
  
    dir_rightPct (25);
    throttle_reversePct (25);
    delay(1000);
    dir_rightPct (50);
    throttle_reversePct (50);
    delay(1000);
    dir_rightPct (75);
    throttle_reversePct (75);
    delay(1000);
    dir_rightPct (100);
    throttle_reversePct (100);
    delay(1000);

    i++;
  }

  dir_straight();
  throttle_idle ();
  
}

