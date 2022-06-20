#include "s21_math.h"

long double s21_tan(double x) {
  long double answ = 0;
  int sign = x > 0 ? 1 : -1;
  x = s21_fabs(x);
  long n = x / S21_PI;
  x = x - n * S21_PI;
  x = sign == 1 ? x : -x;
  if (x == S21_PI / 2) {
    answ = 16331239353195370;
  } else if (x == -S21_PI / 2) {
    answ = -16331239353195370;
  } else {
    answ = s21_sin(x) / s21_cos(x);
  }
  return answ;
}
