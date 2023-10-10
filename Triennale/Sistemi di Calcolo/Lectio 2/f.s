.globl f					# direttiva all'assemblatore, rende f variabile globale visibile a tutti

f: 	movl $11, %eax
   	ret						# per convenzione ret restituisce il valore nel registro A