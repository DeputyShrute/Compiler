.code32


.section .text

.section .data
a:
.ascii "0"
b:
.ascii "0"
c:
.ascii "0"
d:
.ascii "0"
e:
.ascii "0"
f:
.ascii "0"

.globl _start
_start:


movl $1, %ecx
loop1:
cmpl $4, %ecx
je end1
pushl %ecx

movl $1, %ecx
loop2:
cmpl $4, %ecx
je end2
pushl %ecx

movl $1, %ecx
loop3:
cmpl $4, %ecx
je end3
pushl %ecx


movl $1, %ecx
loop4:
cmpl $4, %ecx
je end4
pushl %ecx


movl $1, %ecx
loop5:
cmpl $4, %ecx
je end5
pushl %ecx


addl $1, %ebx


popl %ecx
addl $1, %ecx
jmp loop5
end5:


popl %ecx
addl $1, %ecx
jmp loop4
end4:


popl %ecx
addl $1, %ecx
jmp loop3
end3:


popl %ecx
addl $1, %ecx
jmp loop2
end2:


popl %ecx
addl $1, %ecx
jmp loop1
end1:

movl $1, %eax
int $0x80
