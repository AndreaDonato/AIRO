.globl swap

swap:
	movb (%rdi), %dl
	movb (%rsi), %cl
	movb %cl, (%rdi)
	movb %dl, (%rsi)
	ret
