.globl massimo

massimo:
	movl 4(%esp), %eax
	#movl 8(%esp), %ecx
	#cmpl %eax, %ecx
	#Jge F
	#movl %ecx, %eax
	#F: ret

	cmpl %eax, 8(%esp)
	Jge F
	movl 8(%esp), %eax
	F: ret
	