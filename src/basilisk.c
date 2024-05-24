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

        size_t file_names_count = argc - 1;

        ProcessedDocument **docs = parse_documents(file_names, file_names_count);

        for (int i = 0; i < file_names_count; i++) {
            printf("document: {file_name: %s}, {file_type: %x} {size: %zd}\n",
                    docs[i]->document->file_name,
                    docs[i]->document->file_type,
                    docs[i]->size);
        }

        // jesus christ do smth about this
        for (s16 i = 0; i < file_names_count; i++) {
            free(docs[i]->document);
            free(docs[i]->content);
            free(docs[i]);
        }        

        free(file_names);
    } else {
        fprintf(stderr, "No document provided.\n");
        exit(0);
    }

    return 0;
}