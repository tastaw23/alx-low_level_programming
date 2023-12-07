#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_key(const char *username, char *key);

int main(int argc, char *argv[]) {
    char key[256];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return EXIT_FAILURE;
    }

    generate_key(argv[1], key);

    printf("%s\n", key);

    return EXIT_SUCCESS;
}

void generate_key(const char *username, char *key) {
    sprintf(key, "%s-%lu", username, (unsigned long)(strlen(username) * 42));
}

