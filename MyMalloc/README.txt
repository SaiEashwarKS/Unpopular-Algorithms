Refer the problem statement present in "prblm_stmt.pdf" first.


->The allocation policy implemented by me is Worst Fit.

->To implement Worst Fit policy, I first assume the block with worst fit to have free size of 0 bytes and store in "worst_block". I iterate over all books and update the worst_block if the book is free and if it has sufficient space as requested by the user and if the size is greater than the worst_block. I'll also keep updating the "index" variable which will hold the index of the book of the block of worst fit. If the index is not valid (-1), NULL is returned. Else, the pointer to the free block of worst fit is returned. Now, we have to check if the remaining free space of the block must be merged with the same block or not. If the remaining space is too small to even store a book, it is merged with the previous block itself. Otherwise, a new book is created for the block and its values are initialized.

->Explanation of myfree: I'll have 3 pointers to three consecutive books (prev, pres, next). I iterate over all the books and find the book which contains the pointer passed as argument (by comparing the address of the pointer and "ptr" of the book). pres will point to this matching book. prev and next will point to the left and right books of pres (if they are present). Many cases are checked and the following merges happen:
	-if prev is NULL and next is free, pres and next are merged
	-if next is NULL and prev is free, prev and pres are merged
	-if prev and next are not null:
		-if prev is not free and next is free, pres and next are merged
		-if next is not free and prev is free, prev and pres are merged
		-if both prev and next are free, all the three books are merged 
		
->Explanation of book keeping structure: My book keeping structure has three variables:
	-int isfree : tells if the book points to a free block (isfree = 1) or an allocated block (isfree = 0)
	-int size : tells the size in bytes of the block pointed to by the book
	-long int ptr : stores the address of the block the books points to i.e., if a pointer to the block is returned, ptr will have the value of that pointer
The size of my book is 16 bytes.
