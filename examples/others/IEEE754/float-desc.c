#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkarg(int,char**);

int main(int argc, char** argv)
{
  float data;
  unsigned long buf;
  int i;
  char s[35];
  int rc;
  rc = checkarg(argc, argv);

  if(rc == 1) {
    printf("Usage: ./float-desc float-number\n");
    exit(1);
  }
  else{
    data = atof(argv[1]);
  }

  //printf("%s\n", argv[0]);
  //printf("%s\n", argv[1]);
  //printf("length of %s is  %lu\n", argv[1], strlen(argv[1])); 

  //printf("%f\n", data);
  // data = (float)0.1; /* 0.75; */
  memcpy(&buf, &data, 4);

  for(i=33;i>=0;i--) {
    if(i==1 || i==10) {
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
  s[34] = '\0';
  printf("%s\n", s);
  return 0;
}

