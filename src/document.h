#ifndef BASILISK_DOCUMENT_H
#define BASILISK_DOCUMENT_H

#include "types.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PDF_SIGNATURE 25504446

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

ProcessedDocument *process_document(const char *file_name);
void release_processed_doc(ProcessedDocument *doc);
ProcessedDocument **parse_documents(char **file_names, s16 count);


#endif // BASILISK_DOCUMENT_H