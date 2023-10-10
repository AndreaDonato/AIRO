.globl stampa_parametro

stampa_parametro:
 	movl 8(%rsp), %eax
	movl 16(%rsp), %ebx
	ret
