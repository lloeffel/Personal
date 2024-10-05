# Name: Liam Loeffel
# netID: lloeffel
# Date: 5/14/2024
# Description: this takes a structure with a key and finds if the key matches with a given argument, 
#              then returns the index of that key in an array of structures

# NOS   offset    size
# key     0        24
# value   24       8
# size    x        32
.section .text
.global find
find:
    li t0, 0     #iterator
    li t1, -1    #return value when no key is found
    li t6, 23
    li a3, 32
    top:
        bge t0, a1, bottom    #if i = num_values (break)
        mul t2, t0, a3        #widening the iterator to the size of the struct
        add t2, a0, t2        #going to array[i] in memory
        li t3, -1             #secondary iterator (j)
        3:
            addi t3, t3, 1    #iterate j
            add  t4, a2, t3   #going to char[j] for the argument
            add  t5, t2, t3   #going to char[j] for the actual key
            lb   t4, 0(t4)    #loading char[j]'s actual value
            lb   t5, 0(t5)    #loading char[j]'s actual value
            bne  t4, t5, 3f   # is key[j] != argument[j]
            beq  t3, t6, real # does j == 23
            j 3b              # check the next character
        3:   
            addi t0, t0, 1
            j top
    bottom:
        mv a0, t1
        ret
    real:
        mv a0, t0
        ret
