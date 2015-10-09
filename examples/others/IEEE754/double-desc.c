#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkarg(int, char**);

int main(int argc, char** argv)
{
  double data;
  unsigned long buf;
  int i;
  char s[67];
  int rc;
  rc = checkarg(argc, argv);

  if(rc == 1) {
    printf("Usage: ./double-desc double-number\n");
    exit(1);
  }
  else{
    data = atof(argv[1]);
  }

  // data = 0.1; /* 0.75; */
  memcpy(&buf, &data, 8);

  for(i=65;i>=0;i--) {
    if(i==1 || i==13) {
      s[i] = '-';
    }
    else {
      if(buf % 2 == 1) {
        s[i] = '1';
      } 
      else {
        s[i] = '0';
      }
      buf /= 2;
    }
  }
  s[66] = '\0';
  printf("%s\n", s);
  return 0;
}

