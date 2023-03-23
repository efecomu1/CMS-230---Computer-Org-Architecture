//Andrea Diaz-Guma and Efe Comu

//Triple Max
/*** Data section ***/
.data

x: .word 10
y: .word 5
z: .word 20


/*** Code section ***/
.text

_start:
    push {ip, lr}

//  Use registers for local variables declared in main

    // r0 <- x
    ldr r0, =x
    ldr r0, [r0]

    // r1 <- y
    ldr r1, =y
    ldr r1, [r1]

    // r2 <- z
    ldr r2, =z
    ldr r2, [r2]

	if:

		cmp r1, r0
		ble if2
		mov r0, r1

	if2:
		cmp r2, r0
		ble done
		mov r0, r2

done:
	pop {ip, pc}
