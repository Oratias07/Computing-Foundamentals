/*
//set R0 to max from R0 to R1
@R1
D=M
@R2
D=D-M // UPDATE D >?< 0

// IF R2 < R1 JUMP TO ELSE
@ELSE
D;JGT

@R2 // SAVE R2 IN D Because R2 > R1
D = M
@NEXT
0;JMP

(ELSE) // SAVE R1 IN D Because R2 < R1
@R1
D=M

(NEXT) // placement D at R0
@R0
M=D

(ENDPROG)
@ENDPROG
0;JMP
