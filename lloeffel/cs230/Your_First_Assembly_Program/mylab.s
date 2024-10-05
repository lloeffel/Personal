# Name: Liam Loeffel (UTK ID: lloeffel)
# Program-Name: My First Assembly Program :)
# Description: This program is the assembly version of a c++ function
#	       that takes an array of parameters and sums and
#	       multiplies all values in the array.


#Source: This program was entirely created using the guide on canvas
.section .text
.global sum_prod
sum_prod:
	li	t0, 0   # Loads the sum variable
	li	t1, 1   # Loads the product variable
	li	t2, 0   # Loads the i iterator for the for loop
	bge    t2, a1, 1f
	1: #loop
		bge	t2, a1, 1f    # exit condition (if i is greater than or equal to the size of the array)
		slli    t3, t2, 2     # t3 = t2 * 4
		add     t3, t3, a0    # t3 = &values[i]
		lw	t4, 0(t3)     # loads the array
		add	t0, t0, t4    # t0 (sum)     += t4 (values[i])
		mul	t1, t1, t4    # t1 (product) *= t4 (values[i])
		addi	t2, t2, 1     # adds 1 to the iterator
		j	1b            # jumps back to the top of the loop
	1:
		mv	a0, t0        # return register a0 = t0 (accumulating sum)
		sw      t1, 0(a2)     # *product = t1 (accumulating product)
ret #return

