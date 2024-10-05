#Name: Liam Loeffel (utkID: lloeffel)
#Program: multi-user lab in riscv
#Description: This implements 3 functions. a function that can look at the room one is currently in.
#             one that looks at all the rooms in the array of structs, and one that moves to a new
#             room.

#c++ reference for the struct
# struct Room {
#     char *title;
#     char *description;
#     int exits[4]; // 0 – N, 1 – E, 2 – S, 3 - W
# };

# NOS Table for word structure
# Name                      Off    Size
# char *title                0      8
# char *description          8      8
# int exits[4]               16     16
# Total size = 32

.section .rodata
exit_string: .asciz "%s\n%s\nExits: "
north: .asciz "n "
east:  .asciz "e "
south: .asciz "s "
west:  .asciz "w "
newline: .asciz "\n"


.section .text
.global look_at_room
look_at_room:
    #allocating space in the stack
    addi    sp, sp, -16
    sd      s0, 0(sp)
    sd      ra, 8(sp)

    #moving the params to registers
    mv      s0, a0          # Copy char *title into s0
    la      a0, exit_string # Load the address of exit_string into a0
    ld      a1, 0(s0)       # You will need to load the title
    ld      a2, 8(s0)       # You will need to load the description
    call    printf

    1:
        #getting exit[0]
        lw   t0, 16(s0)
        blt t0, zero, 2f #seeing if the exit is there
        la   a0, north
        call    printf
    2:
        #getting exit[1]
        lw   t0, 20(s0)
        blt t0, zero, 3f #seeing if the exit is there
        la   a0, east
        call    printf
    3:
        #getting exit[2]
        lw   t0, 24(s0)
        blt t0, zero, 4f #seeing if the exit is there
        la   a0, south
        call    printf
    4:
        #getting exit[3]
        lw   t0, 28(s0)
        blt t0, zero, 5f #seeing if the exit is there
        la   a0, west
        call    printf
    5:
        la   a0, newline
        call    printf
        #reallocation of stack
        ld      s0, 0(sp)
        ld      ra, 8(sp)
        addi    sp, sp, 16
        ret

.global look_at_all_rooms
look_at_all_rooms:
    #allocating the stack
    addi    sp, sp, -32
    sd      ra, 0(sp)
    sd      s0, 8(sp)
    sd      s1, 16(sp)
    sd      s2, 24(sp)

    #moving the params to registers
    mv      s0, a0        #rooms
    mv      s1, a1        #num_rooms
    li      s2, 0         #i
    1: #for loop
        bge    s2, s1, 1f   #exit condition
        mv     t0, s2       #putting our param into a temp register so we can mess with it
        slli   t0, t0, 5    #shifting i to increment rooms
        mv     a0, s0       #moving the memory address of the array of structures into a0
        add    a0, a0, t0   #incrementing thru rooms
        call look_at_room   
        la     a0, newline
        call printf
        addi   s2, s2, 1    #i++
        j      1b
    1:
        #reallocation of memory
        ld      ra, 0(sp)
        ld      s0, 8(sp)
        ld      s1, 16(sp)
        ld      s2, 24(sp)
        addi    sp, sp, 32
        ret
.global move_to
move_to:
    1:
        slli   t1, a2, 2      #shifting a2 to get the exit direction's index
        addi   a1, a1, 16     #going to exits in the struct
        add    a1, a1, t1     #adding the shift to exits to get the direction
        lw     t2, 0(a1)      #dereferencing the pointer
        blt    t2, zero, 1f   #comparing current->exits[direction] != -1
        slli   t2, t2, 5      #getting the amount we need to shift to get the correct room to move to
        add    a0, a0, t2     #return rooms + current->exits[direction]
        ret
    1:
        mv      a0, zero    # return nullptr
        ret
