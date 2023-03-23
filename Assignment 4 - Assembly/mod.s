//Andrea Diaz-Guma and Efe Comu
.global _start

.data

a: .word 4
b: .word 30

.text

_start:

	push {ip, lr}

	ldr r5, =a
	ldr r1, [r5]

	ldr r5, =b
	ldr r2, [r5]
	
	if:
		cmp r1, r2
		ble else
		mov r3, r1
		mov r4, r2
		b while
	
	else:
		mov r3, r2
		mov r4, r1
	
while:
	cmp r3, r4
	blt done
		
	sub r3, r3, r4
	b while
	
done:
	mov r0, r3
	pop {ip, pc}
