#ifndef IDT_H
#define IDT_H

#include <stdint.h>

struct idt_desc {
  uint16_t offset_1; // Offset bits 0 - 15
  uint16_t selector; // Selector thats in our GDT
  uint8_t zero; // Does nothing, unused set to zero
  uint8_t type_attr; // Descriptor type and attributes
  uint16_t offset_2; // Offset bits 16-31
} __attribute__((packed));

struct idtr_desc {
  uint16_t limit; // Size of descriptor table -1
  uint32_t base; // Base address of the start of the interrupt desscriptor table
} __attribute__((packed));

struct interrupt_frame {
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t reserved;
  uint32_t ebx;
  uint32_t edx;
  uint32_t ecx;
  uint32_t eax;
  uint32_t ip;
  uint32_t cs;
  uint32_t flags;
  uint32_t esp;
  uint32_t ss;
} __attribute__((packed));

void idt_init();
void enable_interrupts();
void disable_interrupts();

#endif