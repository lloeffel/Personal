#Name: Liam Loeffel (utkID: lloeffel)
#Program: Get Rand Function
#Description: This program implements the following c++ code with assembly:
# int64_t get_rand(int64_t mn, int64_t mx) {
#    return mn + rand() % (mx - mn + 1);
# }


# Registers:
# a0 get_rand(a0 mn, a1 mx) {
#    return mn + rand() % (mx - mn + 1);
# }



# THIS CODE HAS BEEN IMPLEMENTED USING THE GUIDE ON CANVAS

.global get_rand                  # makes the get_rand function globally available

get_rand:                         # get_rand function header
	addi    sp, sp, -32       # ra + s0 + s1 = 24 bytes aligned to 32

	sd       ra, 0(sp)        # Save return address
	sd       s0, 8(sp)        # Save old s0:
	sd       s1, 16(sp)       # Save old s1
	
	mv       s0, a0           # minimum
	mv       s1, a1           # maximum
	call     rand             # rand()

	sub      t0, s1, s0       # t0 = mx - mn
	addi     t0, t0, 1        # t0 = mx - mn + 1

	rem      t1, a0, t0       # t1 = rand() % (mx - mn + 1)

	add      a0, s0, t1       # a0 = mn + rand() % (mx - mn + 1)

	ld       ra, 0(sp)        # restore return address
	ld       s0, 8(sp)        # restore original s0
	ld       s1, 16(sp)       # restore original s1

	addi     sp, sp, 32       # Move stack back (deallocate)

	ret                       # return
