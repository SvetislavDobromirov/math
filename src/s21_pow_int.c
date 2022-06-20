#include "s21_math.h"

long double s21_pow_int(long double x, unsigned exp) {
  long double answ = x;
  for (unsigned i = 1; i < exp; i++) {
    answ *= x;
  }
  return answ;
}
