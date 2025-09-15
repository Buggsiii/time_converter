#include <stdio.h>

#define SECONDS_IN_WEEK 604800
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

int calc(int *rest, int amount) {
  int output = (*rest - *rest % amount) / amount;
  *rest = *rest % amount;
  return output;
}

int main(void) {
  int input;
  printf("Sekunder: ");
  scanf("%d", &input);

  int rest = input;
  int weeks = calc(&rest, SECONDS_IN_WEEK);
  int days = calc(&rest, SECONDS_IN_DAY);
  int hours = calc(&rest, SECONDS_IN_HOUR);
  int minutes = calc(&rest, SECONDS_IN_MINUTE);
  int seconds = rest;

  printf("%d uger, %d dage, %d timer, %d minutter og %d sekunder", weeks, days,
         hours, minutes, seconds);
}