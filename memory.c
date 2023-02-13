#include "memory.h"
#include <stdio.h>

int *sc_memoryInit(){
    int *tmp = calloc(SIZE, sizeof(int));
    return tmp;
}

int sc_memorySet(int *memory, int address, int value){

    if(address >= 0 && address < SIZE){
        memory[address] = value;
    } else {
        printf("Entered address higher than max RAM size!\n");
        return 1;
    }

    return 0;
}

int sc_memoryGet(int *memory, int address, int *value){
    if(address >= 0 && address < SIZE){
        *value = memory[address];
    } else {
        printf("Entered address higher than max RAM size!\n");
        Flag |= FlagM;
        return 1;
    }

    return 0;
}

int sc_memorySave (int *memory, char *filename){
    FILE *file = fopen(filename, "wb");
    if(fwrite(memory, sizeof(int), SIZE, file)){
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}

int sc_memoryLoad(int *memory, char * filename){
    FILE *file = fopen(filename, "rb");
    if(fread(memory, sizeof(int), SIZE, file)){
        fclose(file);
        return 0;
    } 

    fclose(file);
    return 1;
}

int sc_regInit(){
    Flag = 0;
    return 0;
}

int sc_regSet(int registr, int value){
    if(!(value == 0 || value == 1))
        return 1;
  
    switch(registr){
    case FlagP:
        if(value)
            Flag |= FlagP;
        else
            Flag &= ~FlagP;
        break;
    case Flag0:
        if(value)
            Flag |= Flag0;
        else
            Flag &= ~Flag0;
        break;
    case FlagM:
        if(value)
            Flag |= FlagM;
        else
            Flag &= ~FlagM;
        break;
    case FlagT:
        if(value)
            Flag |= FlagT;
        else
            Flag &= ~FlagT;
        break;
    case FlagE:
        if(value)
            Flag |= FlagE;
        else
            Flag &= ~FlagE;
        break;
    }

    return 1;
}

int sc_regGet(int registr, int *value)
{
	switch (registr)
	{
	case FlagP:
		if ((registr & FlagP) > 0)
			*value = 1;
		else 
			*value = 0;
		break;
	case Flag0:
		if ((registr & Flag0) > 0)
			*value = 1;
		else 
			*value = 0;
		break;
	case FlagM:
		if ((registr & FlagM) > 0)
			*value = 1;
		else 
			*value = 0;
		break;
	case FlagT:
		if ((registr & FlagT) > 0)
			*value = 1;
		else 
			*value = 0;
		break;
	case FlagE:
		if ((registr & FlagE) > 0)
			*value = 1;
		else
			*value = 0;
		break;
	default:
		return 0;
	}

	return 1;
}
