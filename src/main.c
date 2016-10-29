#include "stdio.h"
#include "rational.h"

int main(int argc, char **argv){
  TRational *two = new_rational(3, 5);
  TRational *one = new_rational(7, 2);
  TRational *sum = one->rationalSum(one,two);
  TRational *mult = sum->rationalMul(sum,one);

  mult->rationalPrint(mult);

  return 0;
}
