/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdbool.h>
#include <stdint.h>

void alu(int32_t A, int32_t B, bool aluOp1, bool aluOp0, int8_t ALUinput, int32_t* aluResult, bool* zero) {

    /* ALU control
     ALU Control Input       Function
     ------------------    ------------
           000                  and
           001                  or
           010                  add
           110                  sub
           111                  slt    
     * 
     ALUop Input      Operation
     -------------   -------------
          00          load/store
          01          beq
          10          determined by opcode
     * 
     Opcode  aluOp  Operation  Funct Field  Action  ALU input
     ------  -----  ---------  -----------  ------  ---------
     LW      00     load       xxxxxx       add     010
     SW      00     store      xxxxxx       add     010
     branch  01     branch eq  xxxxxx       sub     110
     R       10     add        100000       add     010
     R       10     sub        100010       sub     110
     R       10     AND        100100       and     000
     R       10     OR         100101       or      001
     R       10     set less   101010       set less111
     */

    // ALU operations
    switch (ALUinput) {
        case 0x00: // AND
            *aluResult = A & B;
            *zero = 0;
            break;
        case 0x01: // OR
            *aluResult = A | B;
            *zero = 0;
            break;
        case 0x02: // ADD (ersetzen sie das + durch eine entsprechende Lösung auf der Basis von & oder |)
            *aluResult = A + B;
            *zero = 0;
            break;
        case 0x06: // SUB (ersetzen sie das - durch eine entsprechende Lösung auf der Basis von & oder |)
            *aluResult = A - B;
            *zero = 0;
            break;
        case 0x07: // set on less than (ersetzen sie das < durch eine entsprechende Lösung auf der Basis von & oder |)
            if (A < B)
                *zero = 1;
            else
                *zero = 0;
            break;
    }
}

