// This program iterates over an integer array whose base address is stored in R1 
// and whose size is stored in R2, 
// and computes the sum of all even elements in the array. 
// The sum is accumulated in register R0, which is initialized to zero at the beginning of the program.
// An index variable is used to traverse the array from the first element to the last,
// and the loop continues as long as the index is smaller than the array size.
// For each iteration, the program accesses the current array element,
// checks whether it is even using a bitwise AND with 1,
// and adds it to the sum only if it is even. Odd elements are skipped.
// When all elements have been processed,
// the program enters an infinite loop,
// leaving the final result stored in R0.


//initialize sum=0 (R0)
@R0
M=0

//initialize index=0
@index
M=0

//initialize size (R2)
@R2
D=M
@size
M=D

//initialize arr (R1)
@R1
D=M
@arr
M=D

(WHILE)
    //if(size(R2)-index <= 0)
    @index
    D=M
    @size
    D=M-D

    //if(D <= 0) goto OUT
    @OUT
    D;JLE

    //save in D=arr[i]
    @index
    D=M
    @arr
    A=M+D
    D=M

    //save the value of arr[i]
    @value
    M=D

    //if ((arr[i]&1) != 0)
    @1
    D=D&A
    //goto CONTINUE
    @CONTINUE
    D;JNE

    //else adding value tu the sum (R0)
    @value
    D=M
    @R0
    M=M+D // sum = sum + arr[i] if arr[i]&1 === 0

    (CONTINUE)
    //update index++
    @index
    M=M+1

    //continue loop
    @WHILE
    0;JMP

(OUT)
    @OUT
    0;JMP
    