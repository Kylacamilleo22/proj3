# Summary of Project 1

## Task 3 - Print Version

I was able to print the version using getop. When the argument '-v' is passed in, it will print out the shell version, in this project it was version 1.0

## Task 4 - User input

I was able to use the code provided and go from there. Using the readline/readline.h and readline/history.h, we are able to raed the line from the user input and add it to the history of commands. This is useful for making our shell.

## Task 5 - Custom Prompt 

I was able to get create a custom prompt for the shell using getenv and searches for "MY_PROMPT=". This allows for a retrieval of environment variables to set our custom prompt.

## Task 6 - Built in Commands

I was able to create some built in commands - 
- 'exit' - destroys the shell and exits normally 
- 'pwd' - returns the pwd of the shell, I used getcwd to find the cwd
- 'history' - prints the history of the commands entered, I ran into some issues history_list() but was get the history using history_get()
- 'cd' - changes the directory, I didn't get to do 'cd' I ran out of time.

## Task 7 - Create a Process

Creates a new process and wait for it to complete. Uses fork() for a new process, execvp, and waitpid to wait for process to finish. I didn't get to this part.

## Task 8 - Signals
Used to ignore signals. Used in initializing the shell, and launching jobs. I didn't get to this part.

## Task 9 - Background Processes
Processes that runs in the background. Activates when an ampersand is the last character on the line. I didn't get to this part.

## Task 10 - Jobs Command
Creates a new built-in command called jobs that prints out all the background commands athat are running or done. I didn't ge to this part. 