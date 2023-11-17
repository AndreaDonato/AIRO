.globl absol

absol:
	movl (%rdi), %eax
	cmpl $0, %eax
	Jge F
	negl %eax
	F: ret
