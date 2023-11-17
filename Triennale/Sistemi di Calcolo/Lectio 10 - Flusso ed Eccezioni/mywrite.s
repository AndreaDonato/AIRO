# unsigned mywrite(int fd, const void* buffer, unsigned size);		// fd = file descriptor, 1 = stdout
#                     ebx                 ecx            edx
.globl mywrite

mywrite:
	pushl %ebx 					# pusho ebx perché è callee-save
	movl $4, %eax   			# syscall numero 4
	movl 8(%esp), %ebx 			# primo parametro in ebx
	movl 12(%esp), %ecx 		# secondo in ecx
	movl 16(%esp), %edx 		# terzo in edx (non so se a 32bit è la stessa cosa!)
	int $0x80
	popl %ebx
	ret
