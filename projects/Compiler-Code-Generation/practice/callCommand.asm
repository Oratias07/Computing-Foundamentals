// This file is realization of the CALL command at VM translator
// The pseudo code:
// Using a translator-generated label
// saves LCL of the caller
// saves ARG of the caller
// saves THIS of the caller
// saves THAT of the caller
// RepositionsARG
// RepositionsLCL
// transfers control to the called function
// the same translator-generated label

// call f.funcy 3
// push retAddrLabel
@retAddrLabel
D=A
@SP
A=M
M=D
@SP
M=M+1

// push LCL
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1

// push ARG
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1

// push THIS
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1

// push THAT
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1

// ARG = SP-5-3
@3
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D

// LCL = SP
@SP
D=M
@LCL
M=D

// goto funcy (functionName)
@f.funcy
0;JMP

(retAddrLabel)