#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
int shell_call(std::string &cmdstr) {
enum { maxline=100 };
char line[maxline];
FILE *fpin;
int ret;

if((fpin = popen(cmdstr.c_str(), "r")) == NULL) {
printf("popen error\n");
exit(-1);
}
for(;;) {

fputs("prompt> ", stdout);
fflush(stdout);
if(fgets(line, maxline, fpin) == NULL) /*read from pipe*/
break;
if(fputs(line, stdout) == EOF) {
printf("fputs error\n");
exit(-1);
}
}
if((ret = pclose(fpin)) == -1) {
printf("pclose error\n");
exit(-1);
}
return ret;
}
int main
{
std::string cmd("ls");
shell_call(cmd);
return 0;
}
