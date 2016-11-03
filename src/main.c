#include "stdio.h"
#include "rational.h"

int main(int argc, char **argv){
  TRational *two = new_rational(3, 5);
  double value = two->rationalToDouble(two);
  printf("%.2lf",value);

  return 0;
}
