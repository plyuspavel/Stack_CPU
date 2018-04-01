#include "Stack.h"
#include "CPU.h"

size_t ReadCommands(const char* name, int array[]);

const int MAX_NUM_OF_COMMANDS = 3500;
const int MAX_FILE_NAME = 256;
const int VERSION = 1;
const int NAME = 'PPA';

int main() {
    CPU cpu;
    CPU_ctor(&cpu);

    int com_array[MAX_NUM_OF_COMMANDS] = {};
    char fileName[MAX_FILE_NAME] = "";
    printf("Enter the program-file location>\n");
    scanf("%s", fileName);

    size_t size = ReadCommands(fileName, com_array);
    if ((size == 0) || errno) {
        printf("Some problems with file");
        perror("");
        return 1;
    }

    if (com_array[0] != NAME)
    {
        printf("It isn't a program file");
        return 1;
    }

    if(com_array[1] != VERSION)
    {
        printf("Versions of program and CPU don't maches");
        return 1;
    }



    if(!startWorking(&cpu, com_array, size))
    {
        printf("Program has been successfully finished");
    }
    else perror("Program hasn't been successfully finished");


    CPU_dtor(&cpu);

    return 0;
}

size_t ReadCommands(const char* name, int array[])
{
    FILE* in = fopen(name, "rb");
    if (in == NULL)
    {
        errno = ENOENT;
        return 0;
    }
    fseek(in, 0, SEEK_END);
    size_t length = 0;
    length = ftell(in);

    if (length == 0)
    {
        errno = EIO;
        fclose(in);
        return 0;
    }
    rewind(in);
    size_t size = 0;
    size = fread(array, sizeof(array[0]), length, in);
    return size;
}

