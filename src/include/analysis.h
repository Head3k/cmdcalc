#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <stdio.h>
#include <string.h>

int analys(char **argv, int string_length);                             //Есть
int bracket_detector(char **argv, int string_length);                   //Есть
int correct_input_detector(char **argv, int string_length, char *list); //Есть
int space_detector(char **argv, int string_length);                     //Есть
int operator_detector(char **argv, int string_length);                  //Есть
char type_of_mistake_1(char **argv, int string_length);                 //Есть
int space_detector_2(char **argv, int string_length);                   //Есть
int type_of_mistake_2(char **argv, int string_length);                  //Есть
int type_of_mistake_3(char **argv, int string_length);                  //Есть

#endif