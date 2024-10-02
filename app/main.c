#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <pwd.h>
#include <stdbool.h>

#include "../src/lab.h"

int main(int argc, char **argv)
{ 
    struct shell *sh = (struct shell *)malloc(sizeof(struct shell));

    // if -v is declared, print the version
    parse_args(argc, argv);
    // int c;  
    // while ((c = getopt (argc, argv, "v")) != -1) { 
    //   switch (c)
    //   {
    //   case 'v':
    //       /* code */
    //       printf("Shell version: %d.%d\n", lab_VERSION_MAJOR, lab_VERSION_MINOR);
    //       exit(0);
    //   default:
    //       printf("Unknown command, exiting now");
    //       exit(0);
    //   }
    // }

    // get prompt from environment
    const char *env = "MY_PROMPT";
    const char *prompt = get_prompt(env);
    sh_init(sh);
    sh->prompt = prompt;

    char *line;
    using_history();
    while ((line=readline(prompt))){
      //printf("%s\n",line);
      add_history(line);
      
      //trim line whitespace
      trim_white(line);

      // parse line and convert line to execvp format
      char **cmd = cmd_parse(line);

      // check if command is built in command
      do_builtin(sh, cmd);

      free(line);
    }

  return 0;
}
