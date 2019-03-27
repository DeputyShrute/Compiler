.section .text
.section .data
a:
.long 0
b:
.long 0
c:
.long 0
d:
.long 0
e:
.long 0
f:
.long 0
.globl _start
_start:
movl $0,  b 
movl  b , %ebx
movl $2,  c 
movl  c , %ebx
movl $1, %eax
movl $1, %ebx
addl %eax, %ebx
movl %ebx, b 
movl b , %ebx
movl $1, %eax
int $0x80
