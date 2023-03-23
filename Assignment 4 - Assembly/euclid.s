// Andrea Diaz-Guma and Efe Comu

.global _start

.data

a: .word 60
b: .word 25

.text

_start:

	push {ip, lr}

	ldr r5, =a
	ldr r1, [r5]

	ldr r5, =b
	ldr r2, [r5]

while:
	cmp r1, r2
	beq done
		
	if:
		cmp r1, r2
		ble else
		sub r1, r1, r2
		b while
		
	else:
		sub r2, r2, r1
		b while
	
done:
	mov r0, r1
	pop {ip, pc}
