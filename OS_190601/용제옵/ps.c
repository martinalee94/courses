#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    printf(2, "usage: ps pid...\n");
    exit();
  }
  for(int i=1; i<argc; i++)
    ps(atoi(argv[i]));
  exit();
}
