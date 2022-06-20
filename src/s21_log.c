#include "s21_math.h"

long double s21_log(double x) {
  long double answ = 0;
  long double temp;
  int n = 0;
  if (x != x) {
    answ = S21_NAN;
  } else if (x == S21_INF) {
    answ = S21_INF;
  } else if (x < 0) {
    answ = S21_NAN;
  } else if (x == 0) {
    answ = -S21_INF;
  } else if (x == 1) {
    answ = 0;
  } else {
    for (; x >= S21_EXP; x /= S21_EXP, n++) {
    }
    for (int i = 0; i < 90; i++) {
      temp = answ;
      answ += 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
    }
    answ += n;
  }
  return answ;
}
