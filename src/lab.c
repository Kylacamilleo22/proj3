#include "../src/lab.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <pwd.h>
#include <stdbool.h>
#include <ctype.h>

#include <editline/readline.h>

#define ARG_MAX sysconf(_SC_ARG_MAX)
#define MAX_CHAR_SIZE 20



  void sh_init(struct shell *sh) {
 /* See if we are running interactively.  */
  sh->shell_terminal = STDIN_FILENO;
  sh->shell_is_interactive = isatty (sh->shell_terminal);

  if (sh->shell_is_interactive)
    {
      /* Loop until we are in the foreground.  */
      while (tcgetpgrp ( sh->shell_terminal) != (sh->shell_pgid = getpgrp ()))
        kill (- sh->shell_pgid, SIGTTIN);

      /* Ignore interactive and job-control signals.  */
      signal (SIGINT, SIG_IGN);
      signal (SIGQUIT, SIG_IGN);
      signal (SIGTSTP, SIG_IGN);
      signal (SIGTTIN, SIG_IGN);
      signal (SIGTTOU, SIG_IGN);
      signal (SIGCHLD, SIG_IGN);

      /* Put ourselves in our own process group.  */
      sh->shell_pgid = getpid ();
      if (setpgid (sh->shell_pgid, sh->shell_pgid) < 0)
        {
          perror ("Couldn't put the shell in its own process group");
          exit (1);
        }

      /* Grab control of the terminal.  */
      tcsetpgrp (sh->shell_terminal, sh->shell_pgid);

      /* Save default terminal attributes for shell.  */
      tcgetattr (sh->shell_terminal, &sh->shell_tmodes);
    }
    // sh->prompt = NULL;
  }

  void parse_args(int argc, char **argv){
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

  void sh_destroy(struct shell *sh) {
    free(sh->prompt);
    free(sh);
  }

char *get_prompt(const char *env) {
  const char *env_prompt = getenv(env);
  char *prompt = (char *) malloc(sizeof(char) * MAX_CHAR_SIZE);

  char *default_prompt = (char *)malloc(7);

  if (!default_prompt || !prompt) {
    exit(1);
  }

  if (env_prompt != NULL) {
    strcpy(prompt, env_prompt);
    return prompt;
  } 

  if (env_prompt == NULL) {
    strcpy(default_prompt, "shell>");
    return default_prompt;
  }
  
}

  int change_dir(char **dir) {
    return 0;
  }

char **cmd_parse(char const *line) {
    char **args = malloc(sizeof(char*) * ARG_MAX);
    char *lineCopy = strdup(line); // copy line

    if (!args)
    {
      exit(1);
    }

    char *token = strtok(lineCopy, " \t\n");
    int i = 0;

    while (token != NULL && i < ARG_MAX) {
      args[i] = strdup(token);
      token = strtok(NULL, " \n\t");
      i++;
    }
    args[i] = NULL;

    return args;
}

void cmd_free(char ** line) {
  for (int i = 0; line[i] != NULL; i++) {
    free(line[i]);
  }
  free(line);
}

char *trim_white(char *line) {
  char *start = line;

  if (line == NULL) {
    fprintf(stderr, "No line to trim!\n");
    return NULL;
  }

   // leading white space at the start
  while (isspace(*start)){
    start++;
  } 

  // start is at 0, length - 1
  char *end = start + strlen(start) - 1;
  

  while (end > start && isspace(*end)) {
    end--;
  }

  // terminate the string when it reaches the end
  *(end + 1) = '\0';
  
  return start;
}


bool do_builtin(struct shell *sh, char **argv) {
    bool builtin = false; 
    char cwd[1024];
    
    if(argv[0] == NULL){
      return false;
    }

    // exit or ctrl-d
    if(strcmp(argv[0], "exit") == 0){ 
      builtin = true; 
      sh_destroy(sh);
      exit(0);
    }
    // cd
    if (strcmp(argv[0], "cd") == 0){
      builtin = true; 
      //change_dir(argv);
    }
    // pwd
    if(strcmp(argv[0], "pwd") == 0) {
      builtin = true;
      getcwd(cwd, sizeof(cwd));
      printf("%s\n", cwd);
    }  
    // gets history of command entries
    if(strcmp(argv[0], "history") == 0) {
      builtin = true;
      HIST_ENTRY *history;
      int i = 0;
      while ((history = history_get(++i)) != NULL) { // history_list() doesn't work
        printf("%d: %s\n", i, history->line);
      }
    }
    return builtin;
}
