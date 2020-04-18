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
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

// The start of Collyn's section
/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

  // Checking for hault condition
  if ((MemWrite == 1 || MemRead == 1) && ALUresult % 4 != 0)
    return 0;

  else if (MemWrite == 1) // Write to memory
    Mem[ALUresult >> 2] = data2;

  else if (MemRead == 1) // Read from memory
    *memdata = Mem[ALUresult >> 2];

  return 0;
}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
  if (RegWrite == 1)
  {
    if (MemtoReg == 1) // Data coming from memory
    {
      if (RegDst == 1)
        Reg[r3] = memdata;
      else
        Reg[r2] = memdata;
    }
    else // Data coming from ALUresult
    {
      if (RegDst == 1)
        Reg[r3] = ALUresult;
      else
        Reg[r2] = ALUresult;
    }
  }
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
  *PC = *PC + 4; // Update PC per instruction

  if (jump == 1)
    *PC = (jsec << 2) | (*PC | 0xf0000000);
  else if (Branch == 1 && Zero)
    *PC += (extended_value << 2);
}
