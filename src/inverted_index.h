#ifndef BASILISK_INVERTED_INDEX_H
#define BASILISK_INVERTED_INDEX_H

#include "types.h"

#include <stdio.h>
#include <errno.h>

typedef struct {
    s32 document_id;
    s32 document_pos;
} FoundPhrase;

typedef struct {
    const char *phrase;
    FoundPhrase *documents;
} IndexRecord;

IndexRecord *build_index(char **file_names, s32 file_count);

#endif // BASILISK_INVERTED_INDEX_H