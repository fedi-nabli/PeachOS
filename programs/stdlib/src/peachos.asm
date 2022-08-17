[BITS 32]

section .asm

global print:function
global peachos_getkey:function
global peachos_putchar:function
global peachos_malloc:function
global peachos_free:function
global peachos_process_load_start:function
global peachos_system:function
global peachos_process_get_arguments:function
global peachos_exit:function

; void print(const char* message);
print:
  push ebp
  mov ebp, esp
  push dword[ebp+8]
  mov eax, 1 ; Command print
  int 0x80
  add esp, 4

  pop ebp
  ret

; int peachos_getkey();
peachos_getkey:
  push ebp
  mov ebp, esp
  mov eax, 2 ; Command getkey
  int 0x80
  pop ebp
  ret

; void peachos_putchar(char c);
peachos_putchar:
  push ebp
  mov ebp, esp
  mov eax, 3 ; Command putchar
  push dword[ebp+8] ; Variable "c"
  int 0x80
  add esp, 4
  pop ebp
  ret

; void* peachos_malloc(size_t size);
peachos_malloc:
  push ebp
  mov ebp, esp
  mov eax, 4 ; Command malloc
  push dword[ebp+8] ; Variable "size"
  int 0x80
  add esp, 4
  pop ebp
  ret

; void peachos_free(void* ptr);
peachos_free:
  push ebp
  mov ebp, esp
  mov eax, 5 ; Command free
  push dword[ebp+8]
  int 0x80
  add esp, 4
  pop ebp
  ret

; void peachos_process_load_start(const char* filename);
peachos_process_load_start:
  push ebp
  mov ebp, esp
  mov eax, 6 ; Command process_load_start
  push dword[ebp+8] ; "Variable filename"
  int 0x80
  add esp, 4
  pop ebp
  ret

; int peachos_system(struct command_argument* arguments);
peachos_system:
  push ebp
  mov ebp, esp
  mov eax, 7 ; Command 7
  push dword[ebp+8]
  int 0x80
  add esp, 4
  pop ebp
  ret

; void peachos_process_get_arguments(struct process_arguments* arguments);
peachos_process_get_arguments:
  push ebp
  mov ebp, esp
  mov eax, 8 ; Command 8
  push dword[ebp+8] ; Variable "arguments"
  int 0x80
  add esp, 4
  pop ebp
  ret

; void peachos_exit();
peachos_exit:
  push ebp
  mov ebp, esp
  mov eax, 9 ; Command 9
  int 0x80
  pop ebp
  ret