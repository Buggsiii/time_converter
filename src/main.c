#include "utils.c"
#include <stdio.h>
#define len(a) (sizeof(a) / sizeof((a)[0]))

int main(void) {
  const char *units[] = {"Seconds", "Minutes", "Hours", "Days",
                         "Weeks",   "Months",  "Years"};
  const int choice_count = len(units);
  const enum Unit input_unit =
      choice("What unit is your input?", units, choice_count);

  double input;
  printf("\nHow many %s: ", units[input_unit]);
  scanf_s("%lf", &input);

  const enum Unit output_unit =
      choice("What unit is your output?", units, choice_count);

  double output = convert(input, input_unit, output_unit);

  printf("\n%.2lf %s is %.2lf %s", input, units[input_unit], output,
         units[output_unit]);
}