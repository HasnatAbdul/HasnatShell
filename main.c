
#include "functions.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char **output) {

    char userInput[200];
    char *token;

    //const int MAXARG = 200;
    //const int NUMCMD = 9;
    #define NUMCMD 9


    int check;
    // char *inputs[NUMCMD] = {"cd", "info", "pwd", "exit", "clear","ls","date","ex","exb"};
    // int (*inputName[NUMCMD])(char **) = {
    //         &cd_shell, &info_shell, &get_directory, &exit_shell, &clear_shell,&ls,&time_shell,&ex_shell,&exb_shell};
    // int passed = 0;

    while (1) {
    //  char **argue = (char **) malloc(2 * sizeof(char *));
        char *argue[15];
        int counter = 0;
        //userInput[0] = '\0';

        int u = 0;
        printf("AH $ > ");
        fgets(userInput, 200, stdin);
        while(userInput[u] != '\n'){
          u++;
        }
        userInput[u] = '\0';
        //strtok(userInput, "\n");

        argue[counter] = strtok(userInput, " ");
        while (argue[counter] != NULL) {
            //printf("[%p] -- %s\n", token, token);
        //    argue[counter] = token;
            counter++;
            argue[counter] = strtok(NULL, " ");
        }
        int pipe = 0;
        // int g =0;
        // while(argue[g] != NULL){
        //   printf("argument %d is %s\n",g,argue[g]);
        //   g++;
        // }
        // for (check = 0; check < NUMCMD; check++) {
        //   if(userInput[0] == '\0')
        //     continue;
        //     if (strcmp(argue[0], inputs[check]) == 0) {
        //         // printf("%s = ", argue[0]);
        //         passed = (*inputName[check])(argue);
        //     }
        // }
        // if (passed == 0)
        //     printf("Command '%s' not recognised\n", userInput);
               int i = 0;
               int rd = 0;
               int jj = 0;
               while(argue[i] != NULL){
                   if (strcmp(argue[i], ">") == 0){
                     //output_shell(argue, argue[i+1]);
                     rd = 1;
                     jj = i++;
                     }
                     if (strcmp(argue[i], "|") == 0){
                       pipe = 1;
                     }
                   i++;
               }

       if (strcmp(argue[0], "info") == 0) {
           info_shell();

       }
       if (strcmp(argue[0], "exit") == 0) {
           exit_shell();

       }
       else if (strcmp(argue[0], "pwd") == 0) {
           get_directory();
       }
       else if (strcmp(argue[0], "ls") == 0) {
           ls();
       }
       else if (strcmp(argue[0], "date") == 0) {
           time_shell();
       }
       else if (strcmp (argue[0], "clear") == 0){
           clear_shell();
       }
       else if (strcmp (argue[0], "cd") == 0){
         cd_shell(argue);
       }
       else if(pipe == 1){
         pipeline(argue);
       }
       else if(rd == 1){
        output_shell(argue, &argue[jj+1]);
       }
       else if (strcmp (argue[0], "ex") == 0){
          ex_shell(argue,output);
       }
       else if (strcmp (argue[0], "exb") == 0){
          exb_shell(argue,output);
        }
       else {
           printf("Command' %s 'input not recogised\n", userInput);
       }
    }
}
//    while (strcmp(userInput, "exit") != 0);
//    }
