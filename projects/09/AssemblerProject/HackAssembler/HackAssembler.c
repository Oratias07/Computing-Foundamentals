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
        printf("Initialization\n");
        printf("=======================\n");

        //Opens the input file, and gets ready to process it
        const char* assemblyFilename;
        if (argc < 2) {
            fprintf(stderr, "Assembly filename is ../file.asm\n");
            assemblyFilename = "../file.asm";
        }
        else
            assemblyFilename = argv[1];
        if (!parser_init(assemblyFilename)) {
            fprintf(stderr, "Usage: assembler filename (default ../file.asm)\n");
            perror("fopen");
            exit(0);
        }

        // Constructs a symbol table (perdefined symbols)
        symbolTable_addEntry("R0", 0);
        symbolTable_addEntry("R1", 1);
        symbolTable_addEntry("R2",2 );
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
        symbolTable_addEntry("LOOP", 4);
        symbolTable_addEntry("STOP", 18);


        char line[LINE_MAX_SIZE];
        char symbol[LINE_MAX_SIZE]];
        FILE *hp;
        int count = 0;
        
        // First pass
        parser_rewind(assemblyFilename);
        while (parser_parseNextLine(line)) {
            if (parser_instructionType() == COMMENT_OR_EMPTY) continue;
            if (parser_instructionType() == A_INSTRUCTION || parser_instructionType() == C_INSTRUCTION) count++;
            if (parser_instructionType() == L_INSTRUCTION)
                parser_symbol(symbol);
                symbolTable_addEntry(symbol, count);
        }

        // Second pass
        if (!(hp = fopen("output.hack", "w"))) {
            printf("Error with open output.hack file.\n");
            return NULL;
        }

        parser_rewind();
        char strbin[LINE_MAX_SIZE]; 
        int symbol01;
        int intbin, lineCount = 0;

        while (hp) {
            if (parser_instructionType() == A_INSTRUCTION) {
                if (symbol01[0] > '0' && symbol01 < '9') {
                    fprintf(hp,"%s\n", symbolTable_getAddress() ); // code_convertIntToBinString(atoi(symbol01), strbin)
                }
                if (symbolTable_getAddress(symbol01) == -1) {
                    symbolTable_addEntry(symbol01, lineCount);
                    intbin = symbolTable_getAddress(symbol01);


                }
                lineCount++;
            }
            if (parser_instructionType() == C_INSTRUCTION) lineCount++;
        }
















        //learn the example code below delete it and write your code here
         
        //example of using the Parser module
        printf("\n\n\n");
        printf("example of using the Parser module\n");
        printf("====================================\n");

        printf("\nprinting all the lines till the end and then calling parser_rewind().\n");
        char line[LINE_MAX_SIZE];
        while (parser_parseNextLine(line)) {
            printf("%s", line);
        }
        parser_rewind();

        printf("\nReading and parsing the asembly file.\n");
        char symbol[LINE_MAX_SIZE];
        char addressStr[LINE_MAX_SIZE];
        char dest[LINE_MAX_SIZE];
        char comp[LINE_MAX_SIZE];
        char jump[LINE_MAX_SIZE];
        while (parser_parseNextLine(line)) {
            if (parser_instructionType() == COMMENT_OR_EMPTY) {
                printf("                                         comment : %s", line);
            }
            else if (parser_instructionType() == L_INSTRUCTION) {
                parser_symbol(symbol);
                printf("symbol= %-33s, label : %s", symbol ,line);
            }
            else if (parser_instructionType() == A_INSTRUCTION) {
                parser_address(addressStr);
                printf("symbol or address= %-14s, A instruction : %s", addressStr, line);
            }
            else if (parser_instructionType() == C_INSTRUCTION) {
                parser_dest(dest);
                parser_comp(comp);
                parser_jump(jump);
                printf("dest= %-3s, comp= %-5s, jump= %-3s, C instruction : %s", dest, comp, jump, line);
            }
        }




        //example of using the Code module
        printf("\n\n\n");
        printf("example of using the Code module\n");
        printf("====================================\n");
        char destBinaryStr[20];
        char compBinaryStr[20];
        char jumpBinaryStr[20];
        char addressStr1[LINE_MAX_SIZE];
        strcpy(dest, "D");
        code_dest(dest, destBinaryStr);
        printf("strcpy(dest, \"D\");\ncode_dest(dest, destBinaryStr);\ndestBinaryStr <- \"%s\".\n\n", destBinaryStr);
        strcpy(comp, "D+1");
        code_comp(comp, compBinaryStr);
        printf("strcpy(comp, \"D+1\");\ncode_comp(comp, destBinaryStr);\ncompBinaryStr <- \"%s\".\n\n", compBinaryStr);
        strcpy(jump, "JMP");
        code_jump(jump, jumpBinaryStr);
        printf("strcpy(jump, \"JMP\");\ncode_jump(jump, jumpBinaryStr);\njumpBinaryStr <- \"%s\".\n\n", jumpBinaryStr);

        char binaryString[17];
        code_convertIntToBinString(135, binaryString);
        printf("code_convertIntToBinString(135, binaryString)\nbinaryString <- \"%s\".\n\n", binaryString);



        //example of using the SymbolTable module
        printf("\n\n\n");
        printf("example of using the SymbolTable module\n");
        printf("====================================\n");
        printf("symbolTable_addEntry(\"AA\", 0);\n");
        printf("symbolTable_addEntry(\"BB\", 1);\n");
        printf("symbolTable_addEntry(\"CC\", 2);\n");
        printf("symbolTable_addEntry(\"DD\", 3);\n");
        symbolTable_addEntry("AA", 0);
        symbolTable_addEntry("BB", 1);
        symbolTable_addEntry("CC", 2);
        symbolTable_addEntry("DD", 3);
        printf("symbolTable_print().\n");
        symbolTable_print();
        printf("\nsymbolTable_getAddress(\"CC\") returns: %d.\n", symbolTable_getAddress("CC"));
        printf("symbolTable_getAddress(\"FF\") returns: %d.\n\n\n", symbolTable_getAddress("FF"));



        //example of writing to the machine language file 
        printf("\n\n\n");
        printf("example of writing to the machine language file\n");
        printf("====================================\n");

        printf("opening machine language file for writing.\n");
        char hackFilename[100];
        strcpy(hackFilename, assemblyFilename);
        char* dotPosition = strrchr(hackFilename, '.');
        if (dotPosition != NULL) {
            strcpy(dotPosition + 1, "hack");
        }
        FILE* hackFP = fopen(hackFilename, "wt");
        if (hackFP == NULL) {
            perror("fopen");
            exit(0);
        }

        printf("Writes the string to the output file.\n");
        char hackLine[] = "1110110000010000";
        fprintf(hackFP, "%s\n", hackLine);

        printf("Closing the output file.\n");
        fclose(hackFP);
}
