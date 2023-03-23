// Efe Comu and Andrea Diaz-Guma

.global _start

ziggurat:
	
	mov r4, #0
	recursive:
		cmp r1, #1
		beq done
		mul r3, r1, r1
		add r4, r4, r3
		sub r1, r1, #1
		b recursive
	
	
	done:
		add r4, r4, #1
		mov r0, r4
		pop {ip,pc}

_start:
	push {ip,lr}
	
	mov r1, #5
	bl ziggurat
	
	pop {ip,pc}
