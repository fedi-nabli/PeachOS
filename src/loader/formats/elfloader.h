#ifndef ELFLOADER_H
#define ELFLOADER_H

#include <stdint.h>
#include <stddef.h>

#include "elf.h"
#include "config.h"

struct elf_file {
  char filename[PEACHOS_MAX_PATH];

  int in_memory_size;

  /**
   * The physical memory address that this elf file is loaded at
   */
  void* elf_memory;

  /**
   * The virtual base address of this binary
   */
  void* virtual_base_address;

  /**
   * The ending virtual address
   */
  void* virtual_end_address;

  /**
   * The physical base address of this binary
   */
  void* physical_base_address;

  /**
   * The physical virtual address
   */
  void* physical_end_address;
};

#endif