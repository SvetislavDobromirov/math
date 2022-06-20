#include "s21_math.h"

long double s21_asin(double x) {
  int sign = x > 0 ? 1 : -1;
  x = s21_fabs(x);
  long double answ = 0;
  if (x - x != 0 || x > 1) {
    answ = 0.;
    answ = answ / 0.;
  } else if (x < 0.5) {
    for (int i = 0; i < 30; i++) {
      answ += s21_factorial(2 * i) * s21_pow(x, 2 * i + 1) / s21_pow(4, i) /
              s21_pow(s21_factorial(i), 2) / (2 * i + 1);
    }
  } else {
    answ = S21_PI / 2 - 2 * s21_asin(s21_sqrt((1 - x) / 2));
  }
  return sign == 1 ? answ : -answ;
}
