#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include<string.h>
#include "../src/lab.c"

int terminal_count () {
  static int shell_count = 0;
  return shell_count++;
}

int main(int argc, char **argv)
{ 
  // printf("hello world\n");
  int c;
    struct shell sh;
    
    // char *name = "MY_PROMPT";
    // char *env = getenv(name);
    char *env = "MY_PROMPT";
    const char *prompt = getenv(env);
  char *line;

 while ((c = getopt (argc, argv, "vbc:")) != -1) { 
  switch (c)
  {
  case 'v':
    /* code */
    printf("Shell version: %d.%d", lab_VERSION_MAJOR, lab_VERSION_MINOR);
    printf("prompt: %s", prompt);
    exit(0);
  case 'b':
    printf("get b here");
    
    break;
  case 'c':
    printf("get c here");
    break;
  // case '?':
  //   if (isprint (optopt)) {
  //     fprintf(stderr, "Unknown option", optopt ); 
  //   } else {
  //     fprintf(stderr, "Uknown option", optopt);
  //   }
  //   return 1;
  default:
    // will run here if no other arguments are included
    // such as ./myprogram or MY_PROMPT="foo>" ./myprogram
    //getprompt here, calling get_prompt
    // printf("%s", env);
        printf("hello");

    using_history();
    while ((line=readline("$"))){
        printf("%s\n",line);
        add_history(line);
        free(line);
    }

    

    //start the shell
    sh.shell_is_interactive = 1;
    sh.prompt = prompt;
    sh.shell_pgid = getpid();
    sh.shell_terminal = terminal_count();
    // sh.shell_tmodes.c_cc = 

    
    break;
  }
 }
  return 0;
}
