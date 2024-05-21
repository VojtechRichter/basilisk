#include "inverted_index.h"
#include "document.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc > 1) {
        char **file_names = (char **)malloc(argc * sizeof(const char *));
        for (int i = 1; i < argc; i++) {
            file_names[i - 1] = argv[i];
        }

        process_document(file_names[0]);

        free(file_names);
    } else {
        fprintf(stderr, "No document provided.\n");
        exit(0);
    }

    return 0;
}