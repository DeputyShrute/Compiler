.code32

.include "record-def.s"
.include "linux.s"

.equ ST_WRITE_BUFFER, 8
.equ ST_FILEDES, 12
.section .text
.globl write_record
.type write_record, @function
write_record:
pushl %ebp
movl %esp, %ebp

pushl %ebx
movl $SYS_WRITE, %eax
movl ST_FILEDES(%ebp), %ebx
movl ST_WRITE_BUFFER(%ebp),%ecx
movl $RECORD_SIZE, %edx
int $LINUX_SYSCALL

popl %ebx

movl %ebp, %esp
popl %ebp
ret


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

file_name:
.ascii "test.dat\0"
.equ ST_FILE_DESCRIPTOR, -4

.globl _start
_start:

addl $1, a

#Copy the stack pointer to %ebp
movl %esp, %ebp


movl $SYS_OPEN, %eax
movl $file_name, %ebx
movl $0101, %ecx

movl $0666, %edx
int $LINUX_SYSCALL

movl %eax, ST_FILE_DESCRIPTOR(%ebp)


pushl ST_FILE_DESCRIPTOR(%ebp)
pushl $a
call write_record
addl $8, %esp


pushl ST_FILE_DESCRIPTOR(%ebp)
pushl $b
call write_record


pushl ST_FILE_DESCRIPTOR(%ebp)
pushl $c
call write_record


pushl ST_FILE_DESCRIPTOR(%ebp)
pushl $d
call write_record

pushl ST_FILE_DESCRIPTOR(%ebp)
pushl $e
call write_record


pushl ST_FILE_DESCRIPTOR(%ebp)
pushl $f
call write_record



#Exit
movl $SYS_EXIT, %eax
movl $0, %ebx
int $LINUX_SYSCALL
