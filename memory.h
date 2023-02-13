#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include <stdint.h>

#define SIZE 100

enum FlagMask{
    FlagP = 0b00000001, // Переполнение при выполнении операции
	Flag0 = 0b00000010, // Ошибка деления на 0
	FlagM = 0b00000100, // Ошибка выхода за границы памяти
	FlagT = 0b00001000, // Игнорирование тактовых импульсов
	FlagE = 0b00010000  // Указана неверная команда
};

uint8_t Flag;

int *sc_memoryInit();
int sc_memorySet(int *memory, int address, int value);
int sc_memoryGet(int *memory, int address, int *value);
int sc_memorySave(int *memory, char *filename);
int sc_memoryLoad(int *memory, char *filename);
int sc_regSet(int registr, int value);
int sc_regGet(int registr, int *value);


#endif