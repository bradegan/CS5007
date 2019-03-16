# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans:
	pushq %rbp			#
	movq  %rsp, %rbp		#

					# (2) What is going on here
					# Ans:
	movq $1, %rax			# moving 1 into rax and 1 into 1 rdi and comparing them and print hello string
	movq $1, %rdi			#
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: syscall is a library function that calls the system call whose assembly 
					language interface corresponds with the specified arguments. Sys call is a way for 
					a script to interact with the operating system.
	syscall				# Which syscall is being run?
					# Ans: runs whatever value is in rax 1 - system write

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: use echo

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	making a system exit call
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	There are 13 characters that need to be printed.
