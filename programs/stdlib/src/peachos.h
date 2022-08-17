#ifndef PEACHOS_H
#define PEACHOS_H

#include <stddef.h>
#include <stdbool.h>

struct command_argument {
  char argument[512];
  struct command_argument* next;
};

void print(const char* message);
int peachos_getkey();

void peachos_putchar(char c);
void* peachos_malloc(size_t size);
void peachos_free(void* ptr);
int peachos_getkeyblock();
void peachos_terminal_readline(char* out, int max, bool output_while_typing);
void peachos_process_load_start(const char* filename);
struct command_argument* peachos_parse_command(const char* command, int max);

#endif