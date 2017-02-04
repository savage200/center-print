#include <stdio.h>
#include <unistd.h>

#define INDEX 0
#define GETMAXXY 21523

void foo(const char *str) {
  struct {
    unsigned short y;
    unsigned short x;
    unsigned short _y;
    unsigned short _x;
  } size;
  ioctl(INDEX, GETMAXXY, &size);
  printf("\x1B[%d;%df%s", size.y/2, (size.x - strlen(str))/ 2 , str);
}

int main() {
  foo("Hello!Savage.");
  getchar();
}