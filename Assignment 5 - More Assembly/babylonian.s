// Andrea Diaz-Guma and Efe Comu

.global _start

div:
	mov r4, r3 // r4 = n = 144
	mov r5, r1 // r5 = x 
	mov r0, #0 // quotient 
	
	while_2:
	
		cmp r4, r5 // 144 - 1
		blt end
		sub r4, r4, r5
		add r0, r0, #1
		b while_2
		
	end: 
		b back
	

squareroot:
	push {ip,lr}

	mov r1, #1

	// Loop until x doesn't change
	do:
    // store x in r1 and oldX in r2
    // the given number n is stored in r3

    mov r2, r1
	bl div
	back:
	add r6, r1, r0
    lsr r6, #1

    // store the result in r1
    mov r1, r6

	while:
    cmp r1, r2
    beq done
    b do

	done:
  		pop {ip, pc}

_start:
	push {ip,lr}
	
	mov r3, #144
	bl squareroot
	
	pop {ip,pc}
