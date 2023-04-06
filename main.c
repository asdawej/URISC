#include <stdio.h>
#include <stdlib.h>

#define MEM_size 50
static long long MEM[MEM_size];
#define PROGRAM_size 50
static size_t PROGRAM[PROGRAM_size][3] = {{-1, -1, -1}};

int main(){
    // WORD
    printf("WORD [pos constant]:\n");
    for (size_t pos, constant; ; ){
        scanf("%lld", &pos); scanf("%lld", &constant);
        if (pos == -1) break;
        MEM[pos] = constant;
    }
    // URISC
    FILE* fp = fopen("main.urisc", "r");
    size_t program_size = 0;
    for (register size_t i = 1; !feof(fp); i++){
        for (register int j = 0; j < 3; j++){
            fscanf(fp, "%llu", &PROGRAM[i][j]);
        }
        program_size++;
    }
    fclose(fp);
    for (register size_t i = 1; i <= program_size; i++){
        if (i == 0) break;
        size_t pos1 = PROGRAM[i][0], pos2 = PROGRAM[i][1], line = PROGRAM[i][2];
        MEM[pos2] = MEM[pos2]-MEM[pos1];
        if (MEM[pos2] < 0) i = line-1;
    }
    fp = fopen("data.txt", "w");
    for (register int i = 0; i < MEM_size; i++) fprintf(fp, "%lld\n", MEM[i]);
    fclose(fp);
    return 0;
}
