#include "stdio.h"
#include "rational.h"

int main(int argc, char **argv){
  TRational* rat = new_rationalFromFloat(23.45);
  rat->print(rat);

  return 0;
}
