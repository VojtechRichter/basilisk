#ifndef BASILISK_DOCUMENT_H
#define BASILISK_DOCUMENT_H

#include "types.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PDF_SIGNATURE 25504446
#define MAX_FILE_SIZE 1024 * 1024 * 1024 * 5

typedef struct {
    size_t size;
    s16 file_type;
    const char *file_name;
    const char *id;
} Document;

typedef struct {
    Document *document;
    char **content;
    size_t size;
} ProcessedDocument;


char **tokenize_document(char *content);
ProcessedDocument *process_document(const char *file_name);


#endif // BASILISK_DOCUMENT_H