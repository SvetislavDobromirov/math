#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  int flag = 0;

  if (x == 1.) {
    flag = 1;
  } else if (x == -1.) {
    flag = 1;
    result = S21_PI;
  } else if (x == 0) {
    flag = 1;
    result = S21_PI / 2;
  } else if (x == 0.7071067811865475244) {
    flag = 1;
    result = S21_PI / 4;
  } else if (x == -0.7071067811865475244) {
    flag = 1;
    result = 3 * S21_PI / 4;
  } else {
    flag = 0;
  }
  if (flag == 0) {
    if (0. < x && x < 1.) {
      result = s21_atan(s21_sqrt(1 - x * x) / x);
    } else if (-1. < x && x < 0.) {
      result = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
    } else {
      result = S21_NAN;
    }
  }
  return result;
}
