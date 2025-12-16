// Main program
// initialize variables
(MAIN)
    // initialize variables
    // put the address in R1 to arr
    @R1
    D=M
    @arr
    M=D
    // initial size
    @R2
    D=M
    @size
    M=D
    // initial k
    @R3
    D=M
    @k
    M=D

    // put values to stack (k->size->arr)
    // save k
    @k
    D=M
    @SP
    M=M-1
    A=M
    M=D
    // save size
    @size
    D=M
    @SP
    M=M-1
    A=M
    M=D
    // save *arr
    @arr
    D=A
    @SP
    M=M-1
    A=M
    M=D

    // save returning address
    @RET01
    D=A
    @SP
    M=M-1
    A=M
    M=D

    // function calling
    @findKth
    0;JMP

    (RET01)
    // save returning value
    @kth
    M=D

    // freeing stack
    @4
    D=A
    @SP
    M=M+D




    // put values to stack (size->arr->kth)
    // save k
    @size
    D=M
    @SP
    M=M-1
    A=M
    M=D
    // save *arr
    @arr
    D=A
    @SP
    M=M-1
    A=M
    M=D
    // save kth
    @kth
    D=M
    @SP
    M=M-1
    A=M
    M=D

    // save returning address
    @RET02
    D=A
    @SP
    M=M-1
    A=M
    M=D

    // function calling
    @findAboveCount
    0;JMP

    (RET02)
    // save returning value
    @aboveCount
    M=D
    // save to R2 too
    @R2
    M=D

    // freeing stack
    @4
    D=A
    @SP
    M=M+D

    // end of program
    (END)
    @END
    0;JMP

// Finds the k-th largest element in the array
// findKth(int arr[], int size, int k)
(findAboveCount)
    // initialize variables
    @i
    M=0
    @greaterThan
    M=0

    // initialize variables from stack (to global variables)
    // size = size
    @SP
    A=M
    D=M
    @size
    M=D
    // *arr = *arr
    @SP
    A=M+1
    D=M
    @arr
    M=D
    // num = num
    @SP
    A=M+1
    A=A+1
    D=M
    @num
    M=D

(LOOP1)
    // D=size-i
    @i
    D=M
    @size
    D=M-D

    // if (D<=0) goto (CONT1)
    @CONT1
    D;JLE

    // D=arr[i]-num
    @i
    D=M
    @arr
    A=M+D
    D=M
    @num
    D=D-M

    // if (D<=0) goto (CONTLOOP1)
    @CONTLOOP1
    D;JLE

    // greaterThan++
    @greaterThan
    M=M+1

    (CONTLOOP1)
        @i
        M=M+1
        @LOOP1
        0;JMP

(CONT1)
    // return greaterThan
    @greaterThan
    D=M

    // out of function
    @SP
    A=M
    A=M
    0;JMP
    
// Finds the k-th largest element in the array
// findKth(int arr[], int size, int k)
(findKth)
    // initialize variables
    @i
    M=0

    // initialize variables from stack (to global variables)
    // k = k
    @SP
    A=M
    D=M
    @k
    M=D
    // size = size
    @SP
    A=M+1
    D=M
    @size
    M=D
    // *arr = *arr
    @SP
    A=M+1
    A=A+1
    D=M
    @arr
    M=D

(LOOP2)
    // D=size-i
    @i
    D=M
    @size
    D=M-D

    // if (D<=0) goto (CONT2)
    @CONT2
    D;JLE
    
    // push values to stack
    // save size
    @size
    D=M
    @SP
    M=M-1
    A=M
    M=D
    // save *arr
    @arr
    D=A
    @SP
    M=M-1
    A=M
    M=D
    // save arr[i]
    @i
    D=M
    @arr
    A=M+D
    D=M
    @SP
    M=M-1
    A=M
    M=D

    // save returning address
    @RET2
    D=A
    @SP
    M=M-1
    A=M
    M=D

    // function calling
    @findAboveCount
    0;JMP

    (RET2)
    // save returning value
    @aboveCount
    M=D

    // freeing stack
    @4
    D=A
    @SP
    M=M+D

    // if (k-(aboveCount+1)!=0) goto (CONTLOOP2)
    @aboveCount
    D=M+1
    @k
    D=M-D

    @CONTLOOP2
    D;JNE

    // return arr[i]
    @i
    D=M
    @arr
    A=M+D
    D=M

    // out of function - successed
    @SP
    A=M
    A=M
    0;JMP

    (CONTLOOP2)
        @i
        M=M+1
        @LOOP2
        0;JMP
(CONT2)
    D=-1

    // out of function
    @SP
    A=M
    A=M
    0;JMP
