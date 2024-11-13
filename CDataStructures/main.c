#include <stdio.h>
#include "vec.h"
#include "stack.h"
#include "linkedList.h"

int main(void) {
  printf("HelloWorld\n");

  node p;
  p = addNode(0,1);
  while(p!= NULL) {
    printf("%d",p);
    p = p->next;
  }

}
