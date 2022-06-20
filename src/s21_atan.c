#include "s21_math.h"

long double s21_atan_0(double x) {
  long double answ = x;
  for (int i = 1; i < 50; i++) {
    answ += s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1) / (2 * i + 1);
  }
  return answ;
}

long double s21_atan(double x) {
  int sign = x > 0 ? 1 : -1;
  x = s21_fabs(x);
  long double answ = 0;
  if (x != x) {
    answ = S21_NAN;
  } else if (x - x != 0) {
    answ = S21_PI / 2;
  } else if (x < 7.0 / 16) {
    answ = s21_atan_0(x);
  } else if (7.0 / 16 < x && x < 11.0 / 16) {
    answ = 0.46364760900080611621 + s21_atan_0((x - 1.0 / 2) / (1.0 + x / 2));
  } else if (11.0 / 16 <= x && x < 19.0 / 16) {
    answ = 0.78539816339744830962 + s21_atan_0((x - 1) / (1.0 + x));
  } else if (19.0 / 16 <= x && x < 39.0 / 16) {
    answ = 0.98279372324732906799 + s21_atan_0((x - 1.5) / (1.0 + 3 * x / 2));
  } else if (39.0 / 16 <= x && x < S21_INF) {
    answ = 1.57079632679489661923 + s21_atan_0(-1 / x);
  }
  return sign == 1 ? answ : -answ;
}
