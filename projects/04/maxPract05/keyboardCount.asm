// When the keyboard is pressed, the processor writes the key code at address 24576, whose symbol is KBD. When the key is not pressed, the value at this address is zero.
// Here is a program that counts the number of times any key has been pressed.
// You can notice that when a key is pressed for a long time, the loop that counts the number of times KBD is different from zero will give a very large number that does not reflect the number of presses. Because this is how you need to count the number of key presses or releases.
// Assuming that the user only presses one key at a time, before pressing KBD is equal to zero, while after pressing it is greater than zero. Because of this, if you write a loop that compares the current key press with the previous one, if the current key press is greater than the previous one, it means that exactly one key has been pressed.
// The following code counts the presses:


//cur define
@cur
//prev=0
@prev
M=0

(WHILE)
    //save KBD
    @KBD
    D=M

    //cur=KBD
    @cur
    M=D

    //update D=cur-prev
    @prev
    D=M
    @cur
    D=M-D

    //if cur-prev<=0 goto cuntinue
    @CONTINUE
    D;JLE

    //if cur>prev >> count++
    @counter
    M=M+1

    (CONTINUE)
    //prev=cur
        @cur
        D=M
        @prev
        M=D
    
    //back to while loop
    @WHILE
    0;JMP

(END)
//End program
    @END
    0;JMP
