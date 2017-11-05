#include <atx.h>

#define fl 0
#define bl 1
#define fr 2
#define br 3

int light_left;
int light_middle;
int light_right;

int dark_left;
int dark_middle;
int dark_right;

int s_left;
int s_middle;
int s_right;

void forward(int sp) {
  motor(fl, sp);
  motor(bl, sp);
  motor(fr, sp);
  motor(br, sp);
}
void backward(int sp) {
  motor(fl, -sp);
  motor(bl, -sp);
  motor(fr, -sp);
  motor(br, -sp);
}
void turn_right(int sp) {
  motor(fl, sp);
  motor(bl, sp);
  motor(fr, -sp);
  motor(br, -sp);
}
void turn_left(int sp) {
  motor(fl, -sp);
  motor(bl, -sp);
  motor(fr, sp);
  motor(br, sp);
}
void pause() {
  motor(fl, 0);
  motor(fr, 0);
  motor(bl, 0);
  motor(br, 0);
}

void read_light() {
  int r = 1000;
  for (int i = 0; i < r; i++) {
    light_left += analog(0);
    light_middle += analog(1);
    light_right += analog(2);
    sleep(10);
  }
  light_left /= r;
  light_middle /= r;
  light_right /= r;
}
void read_dark() {
  int r = 1000;
  for (int i = 0; i < r; i++) {
    dark_left += analog(0);
    dark_middle += analog(1);
    dark_right += analog(2);
    sleep(10);
  }
  dark_left /= r;
  dark_middle /= r;
  dark_right /= r;
}
void set_average_light() {
  s_left = (dark_left + light_left) / 2;
  s_middle = (dark_middle + light_left) / 2;
  s_right = (dark_right + light_right) / 2;
}

void setup()
{
  lcd("press sw1 for setup");  
}

void loop()
{
  if (sw1() == 0) {
    pause();
    if (knob() < 500) {
      read_light();
    } else {
      read_dark();
    }
    lcd("setting up");
    set_average_light();
    lcd("L: %d, M: %d, #nR: %d", s_left, s_middle, s_right);
  }
  if (sw2() == 0) {
    forward(50);
    lcd("go");
  }
}
