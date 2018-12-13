//
// Created by Hasnat Abdul on 30/10/2017.
//

#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

#endif //SHELL_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

void info_shell();
void get_directory();
void ls();
void exit_shell();
void cd_shell(char **argue);
void clear_shell();
void time_shell();
void ex_shell(char **argue, char **output);
void exb_shell(char **argue,char **output );
void pipeline(char **argue);
void output_shell(char **argue,char **output);
