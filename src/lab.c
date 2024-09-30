#include "../src/lab.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

  const char *prompt_default = "shell>";
  
  int terminal_count () {
  static int shell_count = 0;
  return shell_count++;
  }

  void sh_init(struct shell *sh) {
    sh->shell_is_interactive = 1;
    sh->prompt = NULL;
    sh->shell_pgid = getpid();
    sh->shell_terminal = terminal_count();
    sh->shell_tmodes.c_iflag = 0;
  }

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

  char *get_prompt(const char *env) {
    const char *prompt = getenv(env);

    if (!prompt) {
      prompt = prompt_default;
    }

    return prompt;
  }