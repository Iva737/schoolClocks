#include "main.h"

char* cmd;

int main(void) {
    command(cmd, 3, "hello", "game");
    printf("data: %s\n", cmd);
    return 0;
}
