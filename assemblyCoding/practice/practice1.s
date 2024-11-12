

.section .text
.global adder
adder:
    add a0, a0, a1
    ret

#   NOS   offset  size
#   name    0      8
#   job     8      8
#   family  16     20 (16, 20, 24, 28, 32)
#   padding x      4
#   total          40 
#   

.global looper
looper:
    addi t0, zero, 0   #initializing i
    addi t1, zero, 5   #initializing branch condition
    addi t3, zero, 0   #initializing return value
    1:
        beq t0, t1, 1f #exit condition
        slli t2, t0, 5 #widen the iterator to an int
        add t2, a0, t2 #move to the place in memory of numbers[i]
        lw t2, 0(t2)   #dereference the pointer
        add t3, t3, t2 #do the shit u wanna do with numbers[i]
        addi t0, t0, 1 #i++
        j 1b           #jumping back to the top
    1:
        mv a0, t3      #putting our sum into the return register
        ret
