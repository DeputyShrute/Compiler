.code32
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
space:
.ascii " "
.globl _start
_start:
movl $1,  a
movl $1,  c
movl $0,  d
movl $0, %ecx
loop_start_1:
cmpl $100000, %ecx
je end_loop_1
pushl %ecx
movl  c , %eax
movl $0, %edx
movl  a, %ebx
divl %ebx
movl %eax, %ebx
movl %ebx, b 
movl  a , %eax
movl $4, %ebx
addl %eax, %ebx
movl %ebx, a 
movl  d , %eax
movl  b, %ebx
addl %eax, %ebx
movl %ebx, d 
popl %ecx
addl $1, %ecx
jmp loop_start_1
end_loop_1:
movl $3,  a
movl $0, %ecx
loop_start_2:
cmpl $100000, %ecx
je end_loop_2
pushl %ecx
movl  c , %eax
movl $0, %edx
movl  a, %ebx
divl %ebx
movl %eax, %ebx
movl %ebx, b 
movl  a , %eax
movl $4, %ebx
addl %eax, %ebx
movl %ebx, a 
movl  b, %eax
movl  d , %ebx
subl %eax, %ebx
movl %ebx, d
popl %ecx
addl $1, %ecx
jmp loop_start_2
end_loop_2:
movl d, %eax
movl $4, %ebx
imull %eax, %ebx
movl %ebx, d
jmp end
end:
movl z, %eax
xorl %esi, %esi
printz:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movey
jmp printz
movey:
movl y, %eax
pushl space
incl %esi
jmp printy
printy:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movex
jmp printy
movex:
movl x, %eax
pushl space
incl %esi
jmp printx
printx:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movew
jmp printx
movew:
movl w, %eax
pushl space
incl %esi
jmp printw
printw:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movev
jmp printw
movev:
movl v, %eax
pushl space
incl %esi
jmp printv
printv:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moveu
jmp printv
moveu:
movl u, %eax
pushl space
incl %esi
jmp printu
printu:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movet
jmp printu
movet:
movl t, %eax
pushl space
incl %esi
jmp printt
printt:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moves
jmp printt
moves:
movl s, %eax
pushl space
incl %esi
jmp prints
prints:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz mover
jmp prints
mover:
movl r, %eax
pushl space
incl %esi
jmp printr
printr:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moveq
jmp printr
moveq:
movl q, %eax
pushl space
incl %esi
jmp printq
printq:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movep
jmp printq
movep:
movl p, %eax
pushl space
incl %esi
jmp printp
printp:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moveo
jmp printp
moveo:
movl o, %eax
pushl space
incl %esi
jmp printo
printo:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moven
jmp printo
moven:
movl n, %eax
pushl space
incl %esi
jmp printn
printn:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movem
jmp printn
movem:
movl m, %eax
pushl space
incl %esi
jmp printm
printm:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movel
jmp printm
movel:
movl l, %eax
pushl space
incl %esi
jmp printl
printl:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movek
jmp printl
movek:
movl k, %eax
pushl space
incl %esi
jmp printk
printk:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movej
jmp printk
movej:
movl j, %eax
pushl space
incl %esi
jmp printj
printj:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movei
jmp printj
movei:
movl i, %eax
pushl space
incl %esi
jmp printi
printi:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moveh
jmp printi
moveh:
movl h, %eax
pushl space
incl %esi
jmp printh
printh:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moveg
jmp printh
moveg:
movl g, %eax
pushl space
incl %esi
jmp printg
printg:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movef
jmp printg
movef:
movl f, %eax
pushl space
incl %esi
jmp printf
printf:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movee
jmp printf
movee:
movl e, %eax
pushl space
incl %esi
jmp printe
printe:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moved
jmp printe
moved:
movl d, %eax
pushl space
incl %esi
jmp printd
printd:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movec
jmp printd
movec:
movl c, %eax
pushl space
incl %esi
jmp printc
printc:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz moveb
jmp printc
moveb:
movl b, %eax
pushl space
incl %esi
jmp printb
printb:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz movea
jmp printb
movea:
movl a, %eax
pushl space
incl %esi
jmp printa
printa:
movl $0, %edx
movl $10, %ebx
divl %ebx
addl $48, %edx
pushl %edx
incl %esi
cmpl $0, %eax
jz next
jmp printa
next:
cmpl $0, %esi
jz exit
decl %esi
movl $4, %eax
movl %esp, %ecx
movl $1, %ebx
movl $1, %edx
int $0x80
addl $4, %esp
jmp next
exit:
movl $1, %eax
int $0x80
