#ifndef EDA1_SEMINARI_2_CAT_H
#define EDA1_SEMINARI_2_CAT_H

#define MAX_FILENAME 32
#define MAX_OPENED_FILES 16
#define MAX_LINE_SIZE 512
#define BUFFER_SIZE 8192

typedef struct
{
	char line[MAX_LINE_SIZE];
	int size;
	int idx;
} Line;

int cat(char files[MAX_OPENED_FILES][MAX_FILENAME], int num_files, char dest_file[MAX_FILENAME]);

int cat_next_token(Line* line, char token[MAX_FILENAME]);

int cat_parse_stdin_args(char files[MAX_OPENED_FILES][MAX_FILENAME], int* num_files, char dest_file[MAX_FILENAME]);

int cat_parse_prog_args(
	int argc, // Numero de argumentos introducidos en el terminal
	char** argv, // array de argumentos introducidos en el terminal

	char files[MAX_OPENED_FILES][MAX_FILENAME],
	int* num_files,
	char dest_file[MAX_FILENAME]
);

// ERRORS //
#define UNKNOWN_ERROR 1
#define FILE_NOT_FOUND_ERROR 2
#define TWO_OR_MORE_OUT_FILES_ERROR 3
#define CANNOT_READ_ARGS_ERROR 4


#endif //EDA1_SEMINARI_2_CAT_H
