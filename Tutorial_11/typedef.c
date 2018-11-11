/*
 * CS1010 Semester 1 AY18/19
 * Typedef
 * https://nus-cs1010.github.io/1819-s1/21-assert/index.html
 * @file: typedef.c
 * @author: Evan Tay (Group C09)
 */
#include <stdio.h>
#define MC_CONVERSION 2.5f

typedef struct {
  char *code;
  char *title;
  int mc;
} module;

void print_mod(module mod) {
  printf("%s: %s (%d mc)\n", mod.code, mod.title, mod.mc);
}

void update_mc(module *mod, int workload) {
  //(*mod).mc = workload/MC_CONVERSION;
  mod->mc = workload/MC_CONVERSION;
}

module create_mod(char *code, char *title, int mc) {
   module new_mod = {
    .code = code,
    .title = title,
    .mc = mc
  };

  return new_mod;
}

int main() {
  module math;
  math.code = "CS1231";
  math.title = "Discrete Structures";
  math.mc = 4;

  print_mod(math);

  math = (module){
    .code = "MA1521",
    .title = "Calculus for Computing",
    .mc = 4
  };

  printf("After changing math pre-requisite:\n");
  print_mod(math);
  printf("\n");

  module cs1101s = create_mod("CS1101S", 
      "Programming Methodology", 5);

  print_mod(cs1101s);
  
  update_mc(&cs1101s, 10);
  printf("After curriculum change:\n");
  print_mod(cs1101s);
}
