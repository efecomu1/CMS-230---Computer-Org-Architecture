// Efe Comu and Andrea Diaz-Guma

.global _start

.text 

countdown:
	cmp r1, #0
	bne else
	
	mvn r0, #1
	b end
	
	else:
		sub r1, r1, #1
		b countdown
	
	end: 
		pop {ip, pc}

_start:
	push {ip, lr}
	
	mov r1, #4
	bl countdown
	
	pop {ip, pc}
