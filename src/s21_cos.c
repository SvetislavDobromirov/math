#include "s21_math.h"

long double s21_cos(double x) {
  long double answ = 1;
  int sign = x > 0 ? 1 : -1;
  x = s21_fabs(x);
  long n = x / (S21_PI * 2);
  x = x - n * (S21_PI * 2);
  x = sign == 1 ? x : -x;
  for (int i = 1; i < 50; i++) {
    answ += s21_pow_int(-1, i) * s21_pow_int(x, 2 * i) / s21_factorial(2 * i);
  }
  return answ;
}
