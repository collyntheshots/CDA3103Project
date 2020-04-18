#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    // Transcribe the contents of reg[r1] and reg[r2] into data1 and data2
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    //Shift the sigFig 15 spaces to the right in order to get the sigFig value
    unsigned sigFig = offset >> 15;
    //If the sigFig is negative, then it must be expanded to 32 bits, and the left half are all ones.
    if(sigFig == 1)
    {
        *extended_value = offset | 0xffff0000;
    }
    //If the sigFig is nonnegative, keep it at 16 bits
    else
    {
        *extended_value = offset & 0x0000ffff;
    }
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
    if(ALUOp < 0 || ALUOp > 7)
        return 1;
    
    if(ALUOp == 7)
    {
        //Addition
        if(funct == 32)
            ALUOp = 0;
        //Subtraction
        else if(funct == 34)
            ALUOp = 1;
        //Signed comparison
        else if(funct == 42)
            ALUOp = 2;
        //Unsigned comparison
        else if(funct == 43)
            ALUOp = 3;
        //AND
        else if(funct == 36)
            ALUOp = 4;
        //OR
        else if(funct == 37)
            ALUOp = 5;
        //Shift bits left
        else if(funct == 4)
            ALUOp = 6;
        else
            return 1;
    }
    //If ALUSrc is equal to one, set data2 equal to the extended value
    if(ALUSrc == 1)
        data2 = extended_value;
    //Run ALU
    ALU(data1, data2, ALUOp, ALUresult, Zero)
    return 0;
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

