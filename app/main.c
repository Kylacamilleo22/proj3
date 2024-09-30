#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../src/lab.h"

// int terminal_count () {
//   static int shell_count = 0;
//   return shell_count++;
// }

int main(int argc, char **argv)
{ 
  // printf("hello world\n");
  
    struct shell *sh;
    const char *prompt_default = "shell>";
    
    // char *name = "MY_PROMPT";
    // char *env = getenv(name);

    char *line;

    // if -v is declared, print the version
    //parse_args(argc, argv);
    int c;  
    while ((c = getopt (argc, argv, "v")) != -1) { 
      switch (c)
      {
      case 'v':
          /* code */
          printf("Shell version: %d.%d\n", lab_VERSION_MAJOR, lab_VERSION_MINOR);
          exit(0);
      default:
          printf("Unknown command, exiting now");
          exit(0);
      }
    }

    // get prompt from environment
    const char *env = "MY_PROMPT";
    const char *prompt = get_prompt(env);

    //start the shell
    // need to implement sh_init
    // sh->shell_is_interactive = 1;
    // sh->prompt = prompt;
    // sh->shell_pgid = getpid();
    // sh->shell_terminal = terminal_count();
    // sh->shell_tmodes.c_iflag = 0;

    // If no prompt provided, then use shell>
    // if (!prompt) {
    //   prompt = prompt_default;
    // } 
    // printf("%s\n", prompt);
    
    using_history();
    
    while ((line=readline(prompt))){
      printf("%s\n",line);

      // convert line to execvp format


      // check if command is built in command
      // do_builtin(sh, )

      add_history(line);
      free(line);
    }



  return 0;
}
