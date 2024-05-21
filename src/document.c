#include "document.h"

#define PHRASE_DELIM " \r\n"

ProcessedDocument *process_document(const char *file_name)
{
    FILE *fp = NULL;
    errno_t fopen_errno = fopen_s(&fp, file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error occured: %s\n", strerror(fopen_errno));
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *content_buf = (char *)malloc(sizeof(char) * (file_size + 1));
    if (content_buf == NULL) {
        perror("Failed to allocate file content buffer");
        fclose(fp);
        exit(1);
    }

    size_t bytes_read = fread(content_buf, sizeof(char), file_size, fp);
    if (bytes_read != file_size) {
        perror("Bytes read and file size don't match");
        free(content_buf);
        fclose(fp);
        exit(1);
    }

    content_buf[file_size] = '\0';

    char **tokens = (char **)malloc(sizeof(char *) * file_size);
    BASILISK_ASSERT(tokens != NULL);

    char *phrase = strtok(content_buf, PHRASE_DELIM);
    tokens[0] = phrase;
    s32 phrase_idx = 1;

    while (phrase != NULL) {
        tokens[phrase_idx] = phrase;
        phrase_idx++;

        phrase = strtok(NULL, PHRASE_DELIM);
    }

    free(content_buf);
    fclose(fp);

    ProcessedDocument *processed_doc = malloc(sizeof(ProcessedDocument));

    Document *document = malloc(sizeof(Document));
    document->size = file_size;
    document->file_type = 0;
    document->file_name = file_name;
    document->id = file_name;

    processed_doc->document = document;
    processed_doc->content = tokens;
    processed_doc->size = phrase_idx;

    return processed_doc;
}