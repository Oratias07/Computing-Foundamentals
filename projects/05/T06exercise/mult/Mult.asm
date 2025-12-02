// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// Assumes that R0 >= 0, R1 >= 0, and R0 * R1 < 32768.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

//R2=0
@R2
M=0

//count=1
@count
M=0

(LOOP)
    //if (R1-count==0) stop the loop
    @count
    D=M
    @R1
    D=M-D

    //out of loop
    @OUT
    D;JEQ

    //R2=R2+R0
    @R0
    D=M
    @R2
    M=M+D

    //count++
    @count
    M=M+1

    //back to loop
    @LOOP
    0;JMP

(OUT)
    @OUT
    0;JMP
