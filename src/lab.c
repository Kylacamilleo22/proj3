#include "../src/lab.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>



  void parse_args(int argc, char **argv){
    // int numArgs = 0;
    // for (int i = 0; i < argc; i++) {
    //     numArgs++;

    //     printf("arguments: %c", *argv[i]);

    // }   
    // printf("%d %d", argc,**argv);
    int c;  
    while ((c = getopt (argc, argv, "v")) != -1) { 
    switch (c)
    {
    case 'v':
        /* code */
        printf("Shell version: %d.%d", lab_VERSION_MAJOR, lab_VERSION_MINOR);
        exit(0);
    default:
        printf("Unknown command, exiting now");
        exit(0);
    }
   
}
  }