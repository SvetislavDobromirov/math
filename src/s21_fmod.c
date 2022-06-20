#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double answ;
  if (x - x != 0 || y == 0 || y != y) {
    answ = S21_NAN;
  } else if (y - y != 0) {
    answ = x;
  } else {
    long n = x / y;
    answ = x - n * y;
  }
  return answ;
}
