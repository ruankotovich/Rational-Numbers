#include "stdio.h"
#include "rational.h"

int main(int argc, char **argv){
  TRational* rat = new_rationalFromFloat(3.533232);
  rat->print(rat);

  return 0;
}
