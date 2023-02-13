#include <stdio.h>
#include "memory.c"

int main(){
    // srand(1330);
    int *aboba, *aboba_loaded, value;
    // aboba = sc_memoryInit();
    // aboba_loaded = sc_memoryInit();

    // sc_memorySet(aboba, 50, 777);
    // for(int i = 0; i < 100; i++){
    //     sc_memorySet(aboba, i, rand() % 100);
    // }

    // Flag |= FlagE;
    // printf("%d ", Flag);
    sc_regInit();
    // printf("%d ", Flag);
    value = 0;
    sc_regSet(FlagT, value);
    printf("%d\n", Flag);
    Flag = 0;
    sc_regGet(Flag0, &value);
    printf("%d\n", Flag);
    printf("%d\n", value);

    // sc_memorySave(aboba, "data.bin");
    // sc_memoryLoad(aboba_loaded, "data.bin");
    // sc_memoryGet(aboba, 100, &value); 
    // printf("%d\n", value);

    // for(int i = 0; i < SIZE; i++){
    //     printf("%d:%d\t ", i, aboba[i]);
    // }
    // printf("\n");

    return 0;
}