int checkarg(int argc, char** argv){
  int rc=0;
  if(argc == 1 || argc >=3) {
    rc = 1;
  }
  else
    rc = 0;
  return rc;
}
