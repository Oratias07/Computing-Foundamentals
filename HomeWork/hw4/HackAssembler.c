//Neta Baron 213554512 & Or Atias 212604458
//assembler_modified5.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

int main(int argc, char* argv[]) 
{
        ////////////////////////////////////////////////////////////
        //Initialization
        ////////////////////////////////////////////////////////////
        printf("\n\n\n");
        printf("maor program loading\n");
        printf("=======================\n");

        //Opens the input file, and gets ready to process it
        const char* file;
        if (argc < 2) {
            fprintf(stderr, "Assembly filename is ../file.asm\n");
            file = "../file.asm";
        }
        else
            file = argv[1];
        if (!parser_init(file)) {
            fprintf(stderr, "Usage: assembler filename (default ../file.asm)\n");
            perror("fopen");
            exit(0);
        }


        symbolTable_addEntry("R0", 0);
        symbolTable_addEntry("R1", 1);
        symbolTable_addEntry("R2", 2);  
        symbolTable_addEntry("R3", 3);
        symbolTable_addEntry("R4", 4);
        symbolTable_addEntry("R5", 5);
        symbolTable_addEntry("R6", 6);
        symbolTable_addEntry("R7", 7);
        symbolTable_addEntry("R8", 8);
        symbolTable_addEntry("R9", 9);
        symbolTable_addEntry("R10", 10); 
        symbolTable_addEntry("R11", 11);
        symbolTable_addEntry("R12", 12);
        symbolTable_addEntry("R13", 13);
        symbolTable_addEntry("R14", 14); 
        symbolTable_addEntry("R15", 15);    
        symbolTable_addEntry("SCREEN", 16384);
        symbolTable_addEntry("KBD", 24576);
        symbolTable_addEntry("SP", 0);    
        symbolTable_addEntry("LCL", 1);
        symbolTable_addEntry("ARG", 2); 
        symbolTable_addEntry("THIS", 3);
        symbolTable_addEntry("THAT", 4);
        ////////////////////////////////////////////////////////////
        char line[LINE_MAX_SIZE];
        char symbol[LINE_MAX_SIZE];
        char addressStr[LINE_MAX_SIZE];
        char dest[LINE_MAX_SIZE];
        char comp[LINE_MAX_SIZE];
        char jump[LINE_MAX_SIZE];
        char binaryString[17];
        char compBinaryStr[20];
        char destBinaryStr[20];
        char jumpBinaryStr[20];
        int newcounter=17, num, count=0;

        char hackfile[100];
        strcpy(hackfile, file);
        char* dotPosition = strrchr(hackfile, '.');
        if (dotPosition != NULL) {
            strcpy(dotPosition + 1, "hack");
        }
        FILE* hackFP = fopen(hackfile, "wt");
        if (hackFP == NULL) {
            perror("fopen");
            exit(0);                                        
        }
        // First Pass: Add labels to the symbol table
        while (parser_parseNextLine(line)) {
             if (parser_instructionType() == L_INSTRUCTION) {
                parser_symbol(symbol);
                symbolTable_addEntry(symbol,count);
            }
            else if (parser_instructionType() == A_INSTRUCTION ||parser_instructionType() == C_INSTRUCTION ) {
                count++;
            }
        }  parser_rewind();




        // Second Pass: Translate instructions


       while (parser_parseNextLine(line)) {
         if (parser_instructionType() == COMMENT_OR_EMPTY || parser_instructionType() == L_INSTRUCTION) { // Comment or empty line or L-instruction
                continue;
            }
       else if (parser_instructionType() == A_INSTRUCTION){ // A-instruction
            parser_address(addressStr);
            if (addressStr[0] >= '0' && addressStr[0] <= '9'){
            int x=atoi(addressStr);
            code_convertIntToBinString(x,binaryString);
            fprintf(hackFP,"%s\n",binaryString);
           }
           else{
            num=symbolTable_getAddress(addressStr);
            if(num==-1){
                code_convertIntToBinString(newcounter,binaryString);   //symbol not found
                fprintf(hackFP,"%s\n",binaryString);
                symbolTable_addEntry(addressStr,newcounter);
                newcounter++;
            }
            else{
                code_convertIntToBinString(num,binaryString); //    symbol found
                fprintf(hackFP,"%s\n",binaryString);
            }
           }
        }
        else if (parser_instructionType() == C_INSTRUCTION) {  // C-instruction
            parser_dest(dest);
            parser_comp(comp);
            parser_jump(jump);
            code_comp(comp, compBinaryStr);
            code_dest(dest, destBinaryStr);
            code_jump(jump, jumpBinaryStr);
            strcpy(binaryString,"111");
            strcat(binaryString,compBinaryStr);
            strcat(binaryString,destBinaryStr);
            strcat(binaryString,jumpBinaryStr);
            fprintf(hackFP,"%s\n",binaryString);
        }
            

       }
       fclose(hackFP);
        ////////////////////////////////////////////////////////////
        //Finalization MAOR AND IDAN!!!!!!!!!!!!!!!!!!!
        ////////////////////////////////////////////////////////////
        printf("\n\n\n");
        printf("FINISHED\n");
        printf("=======================\n");
        parser_close();
        symbolTable_free();

        return 0;
    }
