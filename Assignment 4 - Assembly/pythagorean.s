//Andrea Diaz-Guma and Efe Comu 
// a^2 + b^2 = c^2
.global _start

.data

a: .word 3
b: .word 4

.text

_start:

	push {ip, lr}

	ldr r5, =a
	ldr r1, [r5]

	ldr r5, =b
	ldr r2, [r5]
	
	mov r3, r1
	mov r4, r2
	
	mov r5, r1
	mov r6, r2
while:
	
	cmp r3, #1
	beq while_2
	
	add r1, r1, r5
		
	sub r3, r3, #1
	b while
	
while_2:
	
	cmp r4, #1
	beq done 
	
	add r2, r2, r6
	sub r4, r4, #1
	b while_2
	
done:
	add r0, r1, r2
	pop {ip, pc}
