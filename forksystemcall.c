#include<stdio.h>
#include<unistd.h>
int main()
{
  for (int i =0;;i++) {
  fork();
  }
  printf("hello\n");
}
