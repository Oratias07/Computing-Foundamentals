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
    