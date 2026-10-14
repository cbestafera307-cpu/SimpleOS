#include <stdio.h>

#define echo(msg) \
printf(msg)

char[1024] cmd;
char[1024] echo;
void __shell__() {
printf("[echo]");
scanf(">%s", &cmd);
}
void echomsg(char* msg) {
  echo(msg);
}
if (cmd == "echo") {
  scanf("echo %s", &echo);
  echomsg(echo);
}
