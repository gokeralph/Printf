#include "main.h"

/**
  * printError - writes the character c to stdout
  * @message: The character to print
  *
  */


void printError(const char *message)
{
	write(2, message, strlen(message));
}

/**
  * my_write - writes the character c to stdout
  * @message: The character to print
  *
  */

void my_write(const char message)
{
	write(1, &message, strlen(&message));
}

