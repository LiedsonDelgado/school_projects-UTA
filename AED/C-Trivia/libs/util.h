#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/**
 * @brief Lê e faz validação de inteiros não-negativos da entrada do usuario
 * @param prompt uma string constante com a mensagem do usuario
 * @return valor inteiro digitado e validado do usuario
 */
int validateInt(const char *prompt);

/**
 * @brief Lê e faz a validação de strings da entrada de usuario
 * @param prompt uma string constante com a mensagem do usuario
 * @param destination local onde a string será armazenada
 * @param maxLenght tamanho maximo que a string pode ter
 * @return - `0` erro na leitura (EOF, erro do sistema, etc)
 * @return - `1` string válida lida com sucesso
 */
int validateString(const char *prompt, char *destination, int maxLenght);

char validateChar(const char *prompt);

char generateCorrectOption();

#endif