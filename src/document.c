#include "document.h"

char **tokenize_document(char *content)
{
    return (char **)0;
}

ProcessedDocument *process_document(const char *file_name)
{
    FILE *fp = NULL;
    errno_t fopen_errno = fopen_s(&fp, file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error occured: %s\n", strerror(fopen_errno));
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *content_buf = (char *)malloc(sizeof(char) * (file_size + 1));
    if (content_buf == NULL) {
        perror("Failed to allocate file content buffer");
        fclose(fp);
        exit(0);
    }

    size_t bytes_read = fread(content_buf, sizeof(char), file_size, fp);
    if (bytes_read != file_size) {
        perror("Bytes read and file size don't match");
        free(content_buf);
        fclose(fp);
        exit(0);
    }

    content_buf[file_size] = '\0';

    // content_buf has all the content, so something below is not reading everything

    // TODO: read the file signature
    Document *document = (Document *)malloc(sizeof(Document));
    document->size = file_size;
    document->file_type = 0;
    document->file_name = file_name;
    document->id = file_name;

    // depends on the file type
    char *phrase = strtok(content_buf, " ,.\n");

    char **tokens = (char **)malloc(file_size);
    tokens[0] = phrase;
    s32 phrase_idx = 1;

    while (phrase != NULL) {
        tokens[phrase_idx] = phrase;
        phrase_idx++;
    }

    free(content_buf);
    fclose(fp);

    free(tokens);

    return NULL;
}