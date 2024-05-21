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

        ProcessedDocument *processed_document = process_document(file_names[0]);

        char **tokenized_document = processed_document->content;
        for (s32 i = 0; i < processed_document->size; i++) {
            printf("tokenized_document[%d]: %s\n", i, tokenized_document[i]);
        }

        // jesus christ do smth about this
        free(processed_document->document);
        free(processed_document->content);
        free(processed_document);
        free(file_names);
    } else {
        fprintf(stderr, "No document provided.\n");
        exit(0);
    }

    return 0;
}