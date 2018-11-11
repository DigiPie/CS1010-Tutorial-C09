/*
 * CS1010 Semester 1 AY18/19
 * Struct
 * https://nus-cs1010.github.io/1819-s1/21-assert/index.html
 * @file: struct.c
 * @author: Evan Tay (Group C09)
 */
#include <stdio.h>
#define MC_CONVERSION 2.5f

struct module {
  char *code;
  char *title;
  int mc;
};

void print_mod(struct module mod) {
  printf("%s: %s (%d mc)\n", mod.code, mod.title, mod.mc);
}

void update_mc(struct module *mod, int workload) {
  //(*mod).mc = workload/MC_CONVERSION;
  mod->mc = workload/MC_CONVERSION;
}

struct module create_mod(char *code, char *title, int mc) {
  struct module new_mod = {
    .code = code,
    .title = title,
    .mc = mc
  };

  return new_mod;
}

int main() {
  struct module math;
  math.code = "CS1231";
  math.title = "Discrete Structures";
  math.mc = 4;

  print_mod(math);

  math = (struct module){
    .code = "MA1521",
    .title = "Calculus for Computing",
    .mc = 4
  };

  printf("After changing math pre-requisite:\n");
  print_mod(math);
  printf("\n");

  struct module cs1101s = create_mod("CS1101S", 
      "Programming Methodology", 5);

  print_mod(cs1101s);
  
  update_mc(&cs1101s, 10);
  printf("After curriculum change:\n");
  print_mod(cs1101s);
}
