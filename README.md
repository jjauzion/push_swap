# PUSH_SWAP
Sort a pile of number using a second pile with a limited list of possible operations.

# Operations
-	sa : swap a - swap the first two elements of pile A.
-	sb : swap b - swap the first two elements of pile B.
-	ss : sa and sb simultaneously.
-	pa : push a - Take out the first element of pile A and put it on top of pile B.
-	pb : push b - Take out the first element of pile B and put it on top of pile A.
-	ra : rotate a - Shift all element of pile A by 1 toward the top. The first element becomes the last.
-	rb : rotate b - Shift all element of pile B by 1 toward the top. The first element becomes the last.
-	rr : ra and rb simultaneously.
-	rra : reverse rotate a - Shift all element of pile A by 1 toward the bottom. The last element becomes the first.
-	rrb : reverse rotate b - Shift all element of pile B by 1 toward the bottom. The last element becomes the first.
-	rrr : rra and rrb simultaneously.

# Usage
-	git clone the repository
-	make
-	./push_swap arg1 arg2 ...
-	./checker [-v -c] arg1 arg2 ...
		-v : visual mode
		-c : show last command
-	./validation_test/test.sh to run validation test

## compatibility
Mac OS

## Exemple

![alt text](https://raw.githubusercontent.com/kylax/push_swap/master/img/exemple.png)
