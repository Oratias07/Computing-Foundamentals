// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

//initializing SP (address 0)
@SCREEN
D=A
@SP
M=D

//R1=7
@7
D=A
@R1
M=D

//R2=14
@14
D=A
@R2
M=D

//save R2 in stack
@R2
D=M
@SP
M=M-1
A=M
M=D

//save R1 in stack
@R1
D=M
@SP
M=M-1
A=M
M=D

//saving the return address
@RET1
D=A
@SP
M=M-1
A=M
M=D

//calling mult function
@MULT
0;JMP

(RET1)
    //saving the return function
    @R3
    M=D

    //freeing parameters
    @3
    D=A
    @SP
    M=M+D

//while(1);
(INFLOOP)
    @INFLOOP
    0;JMP

// Multiplies a and b and stores the result in res.
(MULT)
    //saving parameters to variables
    //b=R2
    @SP
    A=M+1
    A=A+1
    D=M
    @b
    M=D

    //a=R1
    @SP
    A=M+1
    D=M
    @a
    M=D

    //count=0
    @count
    M=0

    //res=0
    @res
    M=0

    (LOOP)
        //if (b-count==0) stop the loop
        @count
        D=M
        @b
        D=M-D

        //out of loop
        @OUT
        D;JEQ

        //res=res+a
        @a
        D=M
        @res
        M=M+D

        //count++
        @count
        M=M+1

        //back to loop
        @LOOP
        0;JMP

    (OUT)
        //saving the result in D
        @res
        D=M

        //out of function, back to the right row
        @SP
        A=M
        A=M
        0;JMP
