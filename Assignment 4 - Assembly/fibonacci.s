// Andrea Diaz-Guma and Efe Comu

.global _start

.data

a: .word 1
b: .word 0

.text

_start:

	push {ip, lr}

	ldr r1, =a
	ldr r1, [r1]

	ldr r2, =b
	ldr r2, [r2]

	mov r3, #1
	mov r4, #0

while:

    cmp r3, #10
    bge final // bgt gives us the 11th Fibonacci number, bge gives 
              // us the tenth - Fib(10) = 55 
    add r4, r1, r2
    mov r2, r1
	  mov r1, r4
    add r3, r3, #1
    b while

final:
   mov r0, r1

   pop {ip, pc}
