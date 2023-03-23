//Andrea Diaz-Guma and Efe Comu

// Add two variables
.global _start

/*** Data section ***/
.data

a: .word 10
b: .word 20
c: .word 30


/*** Code section ***/
.text

_start:
    push {ip, lr}

    // r0 <- a
    ldr r0, =a
    ldr r0, [r0]

    // r1 <- b
    ldr r1, =b
    ldr r1, [r1]

    // r0 <- r0 + r1
    add r0, r0, r1

    // r1 <- c
    ldr r1, =c
    ldr r1, [r1]

    //r0 <- r0 +r1
    add r0, r0, r1

    // Return
    pop {ip, pc}
