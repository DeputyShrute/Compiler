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
g:
.long 0
h:
.long 0
i:
.long 0
j:
.long 0
k:
.long 0
l:
.long 0
m:
.long 0
n:
.long 0
o:
.long 0
p:
.long 0
q:
.long 0
r:
.long 0
s:
.long 0
t:
.long 0
u:
.long 0
v:
.long 0
w:
.long 0
x:
.long 0
y:
.long 0
z:
.long 0
.globl _start
_start:
addl $8, c
movl c, %ebx
movl $5, %eax
movl $0, %ecx
movl x, %ebx
loop_start:
cmpl $3, %ecx
je end_loop
addl %eax, %ebx
addl $1, %ecx
jmp loop_start
end_loop:
movl $1, %eax
int $0x80
