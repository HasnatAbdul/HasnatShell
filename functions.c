//
// Created by Hasnat Abdul on 30/10/2017.
//
#include <stdio.h>
#include "functions.h"
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>

void info_shell() { //info to display module and name
    printf("COMP2211 Simplified shell by Abdul Hasnat\n");
  }

void clear_shell() { //clear the shell
  system("@cls||clear"); //system call to clear the shell
}

void get_directory() {
  //way 1
  char workingDir[1024];
  if (getcwd(workingDir, sizeof(workingDir)) != NULL)
    printf("%s\n", workingDir);
    //  char *pwd = getenv("PWD");
    //  printf("Directory :%s \n", pwd);
  //    char directory[256];
  //        if (getcwd(directory, sizeof(directory)) == NULL) {
  //            perror("getcwd() error");
  //        } else {
  //            printf("Directory: %s\n", directory);
  //        }
}

void ls() {
  //    if (isalpha(argue[1][0]) || isdigit(argue[1][0])){
  //        return 0;
  //    }
  DIR * display;
  struct dirent * ls;
  display = opendir("./");
  if (display != NULL) {
    while ((ls = readdir(display)))
      puts(ls -> d_name);
  }
}

void exit_shell() {
  printf("exiting\n");
  exit(EXIT_SUCCESS);
}

void cd_shell(char **argue) {
  int x;

  if(argue[1] == NULL){
         chdir(getenv("HOME"));
     }
  else {
    if(chdir(argue[1]) != 0)
    printf("Path '%s' not found\n", argue[1]);
  }

}
void time_shell() {
  time_t date;
  time( &date);
  //convert time to string
  char * dateToString = ctime( & date);
  printf("%s", dateToString);
}

void ex_shell(char **argue, char **output) {
  pid_t pid;
  int status;
  pid = fork();
  if (pid < 0) { //Child Process if less than 0
    printf("child process failed\n");
    exit(EXIT_SUCCESS);
  }
  if (pid == 0) { // Parent is reached
    //printf("pid is reached");
    if (execvp(argue[1], argue) == -1) { /* execute the command  */
      printf("exec failed\n");
      exit(EXIT_SUCCESS);
    }
  } else { //run parent
    waitpid(pid, & status, WUNTRACED);
  }
}

void exb_shell(char **argue, char **output) {
  pid_t pid;
  int status;
  pid = fork();

  if (pid < 0) { //Child Process if less than 0
    printf("child process failed\n");
    exit(EXIT_SUCCESS);
  }
  if (pid == 0) { // Parent is reached
    //printf("pid is reached");
    if (execvp(argue[1], argue) == -1) { /* execute the command  */
      printf("exec failed\n");
    }
  }
}

void pipeline(char **argue) {
  pid_t pid, pid2;
  int place[2];
  char * left[256];
  char * right[256];
  pipe(place);
  left[0] = argue[0];
  left[1] = argue[1];
  left[2] = "\0";
  right[0] = argue[3];
  right[1] = argue[4];
  right[2] = "\0";

  pid = fork();
  if (pid == 0) {
    dup2(place[1], STDOUT_FILENO);
    execvp(left[1], left);
    close(place[1]);
  }
  waitpid(pid, NULL, 0);
  pid2 = fork();
  if (pid2 == 0) {
    dup2(place[0], STDIN_FILENO);
    execvp(right[1], right);
    close(place[0]);
  }
  waitpid(pid2, NULL, 0);
}

void output_shell(char  **argue, char **output) {
  int filefeed = open(*output, O_WRONLY | O_CREAT, 0600);
  if (!fork()) {
    close(1); //Close stdout
    dup(filefeed);
    if (execvp(argue[1], argue) == -1) { /* execute the command  */
      printf("exec failed\n");
    } else {
      close(filefeed);
      wait(NULL);
    }
  }
}
