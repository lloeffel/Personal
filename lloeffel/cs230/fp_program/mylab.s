# Name: Liam Loeffel
# Program: Floating Point Mapping Function
# Description: This program makes up the global function for mapping doubles in a vector using 4 different mapping functions

.section .text
.global map

# main mapping function
map:
    #allocating space from the stack
    addi    sp, sp, -64      # Getting the space for the stack
    sd      ra, 0(sp)        # return address
    fsd     fs0, 8(sp)       # floating point storage
    sd      s3, 16(sp)       # save 3
    sd      s4, 24(sp)       # save 4
    sd      s0, 32(sp)       # save 0
    sd      s5, 40(sp)       # save 5
    sd      s1, 48(sp)       # save 1

    # This code puts the items in the registers from the arguments into the save registers
    fmv.d   fs0, fa0         # Move map_value into fs0
    mv      s3,  a2          # mapping_func address is now in s3
    mv      s4, a1           # Move num_values into s4
    mv      s0, a0           # values[]
    li      s5, 0            # uint64_t i
    # This is the main code which continually applies the operation to the
    # items in the vector until the array is done
    1:
        bge    s5, s4, 1f    # Jump out if i >= num_values
        slli   t0, s5, 3     # double mapping_func(double left, double right)
        add    t0, s0, t0    # Calculate the address of values[i]
        fld    fa0, 0(t0)    # fa0 = *(double*)s0n  #  Setup fa0 (values[i])
        mv     s1, t0        # saving the shift in save 1 just in case
        fmv.d  fa1, fs0      # Set double right = map_value
        jalr   s3            # mapping_func(fa0, fa1)
        fsd    fa0, 0(s1)    # *(double*)s4 = ft0   #  Store fa0, the return value, back into values[i]
        addi   s5, s5, 1     # i++
        j      1b            # Loop again
    1:
    #reallocation
        ld      ra, 0(sp)        # unloading the return adress
        fld     fs0, 8(sp)       # unloading the float
        ld      s3, 16(sp)       # unloading save 3
        ld      s4, 24(sp)       # unloading save 4
        ld      s0, 32(sp)       # unloading save 0
        ld      s5, 40(sp)       # unloading save 5
        ld      s1, 48(sp)       # unloading save 1
        addi    sp, sp, 64       # putting back the space for the stack
        ret

#function which adds the mapping val to all the items in the vector
.global map_add
map_add:
    #performing the operation
    fadd.d fa0, fa0, fa1
    ret

#function which subtracts the mapping val to all the items in the vector
.global map_sub
map_sub:
    fsub.d fa0, fa0, fa1
    ret
        
#function which compares all items to the mapping val and substitutes in the one that is smaller
.global map_min
map_min:
    fmin.d fa0, fa0, fa1
    ret

#function which compares all items to the mapping val and substitutes in the one that is bigger
.global map_max
map_max:
    fmax.d fa0, fa0, fa1
    ret
