// Efe Comu and Andrea Diaz-Guma

.global _start

.data

a: .word 2520

.text 

mod:
	ldr r4, =a
	ldr r4, [r4]
	mov r1, #1
	IT:
	mov r3, #0 // quotient
	add r1, r1, #1
	cmp r1, #21 // the divisor
	beq done
	mov r2, r0 // for division
	
	
	div_while:
		
		cmp r2, r1
		blt end
		sub r2, r2, r1
		add r3, r3, #1
		b div_while
	
	end:
		
		cmp r2, #0
		beq IT
		add r0, r0, r4
		b mod
	
	done:
		pop {ip, pc}
		
_start:
	push {ip, lr}
	
	ldr r0, =a
	ldr r0, [r0]
	
	bl mod
	
	pop {ip, pc}
