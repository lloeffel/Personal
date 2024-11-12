#Name: Liam Loeffel
#Program: structures program
#Description: This program finds the angles and hypotenuse of a right triangle given two side lengths.



.global make_triangle

make_triangle:

    # allocating space on the stack
    addi        sp,  sp,   -48          # Getting the space for the stack
    sd          s0,  0(sp)              # save 0
    fsd         fs0, 8(sp)              # side 1
    fsd         fs1, 16(sp)             # side 2
    fsd         fs2, 24(sp)             # hypotenuse
    sd          ra,  32(sp)             # return address

    # putting values into the save registers and RAM
    mv          s0,  a0                 # putting a0 into s0
    fmv.s       fs0, fa0                # storing side0 in fs0
    fmv.s       fs1, fa1                # storing side1 in fs1
    fsw         fs0, 0(s0)              # putting side0 in storage (RAM)
    fsw         fs1, 4(s0)              # putting side1 in RAM

    # calculating hypotenuse
    fmul.s      ft0, fs0, fs0           # side0 squared
    fmul.s      ft1, fs1, fs1           # side1 squared
    fadd.s      fa0, ft0, ft1           # adding the squared vals
    call        sqrtf                   # square rooting the sum
    fsw         fa0, 8(s0)              # storing the hypotenuse
    fmv.s       fs2, fa0                # putting the hypotenuse in fs2
    
    # calculating theta0
    fdiv.s      fa0, fs0, fs2           # fa0 = fs0 / fs2
    call        asinf                   # fa0 = asinf(fa0)
    fsw         fa0, 12(s0)             # rt.theta0 = asinf(fa0)
    
    # calculating theta1
    fdiv.s      fa0, fs1, fs2           # fa0 = fs1 / fs2
    call        asinf                   # fa0 = asinf(fa0)
    fsw         fa0, 16(s0)             # rt.theta0 = asinf(fa0)
    
    # reallocate storage
    mv          a0,  s0                 # moving save 0 back into a0
    ld          s0,  0(sp)              # save 0
    fld         fs0, 8(sp)              # side 0
    fld         fs1, 16(sp)             # side 1
    fld         fs2, 24(sp)             # hypotenuse
    ld          ra,  32(sp)             # return address
    addi        sp,  sp,    48          # Getting the space for the stack

    ret

