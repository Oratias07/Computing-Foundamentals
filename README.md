# Computing Foundations

Coursework for **Computing Foundations** — Software Engineering, 2nd year, Braude College of Engineering.

The course follows **Nand2Tetris** (*The Elements of Computing Systems*, Nisan & Schocken): building a complete computer system from elementary NAND gates up to a high-level language, compiler, and operating system.

> The folders below are listed in the logical learning order. The simulator/tooling (the official Nand2Tetris software suite) is **not** included in this repo — download it from [nand2tetris.org](https://www.nand2tetris.org/software) to run the `.hdl`, `.asm`, `.vm`, and `.jack` files.

## `projects/` — course projects

| # | Folder | Topic |
|---|--------|-------|
| 0  | [`Getting-Started`](projects/Getting-Started)                       | Project 0 setup |
| 1  | [`Boolean-Logic`](projects/Boolean-Logic)                           | Elementary logic gates (And, Or, Not, Mux, DMux, ...) |
| 2  | [`Boolean-Arithmetic`](projects/Boolean-Arithmetic)                 | Adders and the ALU |
| 3  | [`Sequential-Logic`](projects/Sequential-Logic)                     | Flip-flops, registers, RAM, program counter |
| 4  | [`Machine-Language`](projects/Machine-Language)                     | Hack assembly programs (Fill, findMax, ...) |
| 5  | [`Computer-Architecture`](projects/Computer-Architecture)           | CPU, Memory, and the full Hack computer |
| 6  | [`Assembler`](projects/Assembler)                                   | Hack assembler (assembly → binary) |
| 7  | [`VM-Stack-Arithmetic`](projects/VM-Stack-Arithmetic)               | VM translator I: stack arithmetic & memory access |
| 8  | [`VM-Program-Control`](projects/VM-Program-Control)                 | VM translator II: program flow & function calls |
| 9  | [`High-Level-Language-Jack`](projects/High-Level-Language-Jack)     | Jack programs (Pong, Square, ...) |
| 10 | [`Compiler-Syntax-Analysis`](projects/Compiler-Syntax-Analysis)     | Jack compiler I: tokenizer & parser |
| 11 | [`Compiler-Code-Generation`](projects/Compiler-Code-Generation)     | Jack compiler II: VM code generation |
| 12 | [`Operating-System`](projects/Operating-System)                     | Jack OS (Math, Memory, Screen, Keyboard, String, ...) |
| 13 | [`Bonus-Object-Oriented`](projects/Bonus-Object-Oriented)           | Chapter 13 extension (Point class) |

## `HomeWork/` — assignments

| Folder | Topic |
|--------|-------|
| [`HW1-Adders-and-Subtractors`](HomeWork/HW1-Adders-and-Subtractors) | Adder/subtractor chips + gate practice |
| [`HW2-ALU-and-Memory`](HomeWork/HW2-ALU-and-Memory)                 | ALU variants and sequential memory chips |
| [`HW3-Assembly-and-C`](HomeWork/HW3-Assembly-and-C)                 | Hack assembly and C implementations (findk, sumArr) |
| [`HW4-Hack-Assembler`](HomeWork/HW4-Hack-Assembler)                 | Hack assembler in C |

## Notes

- Generated test output (`*.out`), build artifacts, and archives are excluded via `.gitignore`.
- Hardware: `.hdl` (chips) with `.tst` (test scripts) and `.cmp` (expected output).
- Software: `.asm` (Hack assembly), `.vm` (VM code), `.jack` (Jack source).
