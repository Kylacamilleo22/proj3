#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../src/lab.h"

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

    char *line;

    // if -v is declared, print the version
    parse_args(argc, argv);

    // get prompt from environment
    const char *env = "MY_PROMPT";
    const char *prompt = getenv(env);

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

    


  return 0;
}
