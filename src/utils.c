#include <stdio.h>

enum Unit { SECONDS, MINUTES, HOURS, DAYS, WEEKS, MONTHS, YEARS };

enum Unit choice(const char *question, const char **choices, int count) {
  printf("%s\n", question);

  for (int i = 0; i < count; i++) {
    printf("%d. %s\n", i + 1, choices[i]);
  }

  int choice;
  scanf_s("%d", &choice);

  return choice - 1;
}

double to_seconds(double input, enum Unit input_unit) {
  switch (input_unit) {
  case MINUTES:
    return input * 60;
  case HOURS:
    return input * 3600;
  case DAYS:
    return input * 86400;
  case WEEKS:
    return input * 604800;
  case MONTHS:
    return input * 18408600;
  case YEARS:
    return input * 31557600;
  default:
    return input;
  }
}

double convert(double input, enum Unit input_unit, enum Unit output_unit) {
  double input_seconds = to_seconds(input, input_unit);

  switch (output_unit) {
  case MINUTES:
    return input_seconds / 60;
  case HOURS:
    return input_seconds / 3600;
  case DAYS:
    return input_seconds / 86400;
  case WEEKS:
    return input_seconds / 604800;
  case MONTHS:
    return input_seconds / 18408600;
  case YEARS:
    return input_seconds / 31557600;
  default:
    return input_seconds;
  }
}