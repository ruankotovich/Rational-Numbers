#include "stdio.h"
#include "../include/rational.h"

int main(int argc, char **argv){
  float no;
  printf("Set float no. -> ");
  scanf("%f",&no);
  TRational* rat = new_rationalFromFloat(no);
  rat->print(rat);

  return 0;
}
