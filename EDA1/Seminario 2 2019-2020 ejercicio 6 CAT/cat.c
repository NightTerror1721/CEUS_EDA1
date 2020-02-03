#include "cat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cat(char files[MAX_OPENED_FILES][MAX_FILENAME], int num_files, char dest_file[MAX_FILENAME])
{
	const int standard_dest = dest_file == NULL || strlen(dest_file) == 0;

	FILE* fdest;
	if (standard_dest)
		fdest = stdout;
	else
	{
		fdest = fopen(dest_file, "w");
		if (!fdest)
			return FILE_NOT_FOUND_ERROR;
	}

	if (num_files > MAX_OPENED_FILES)
		num_files = MAX_OPENED_FILES;

	char buffer[BUFFER_SIZE];
	size_t readed;
	for (int i = 0; i < num_files; ++i)
	{
		FILE* f = fopen(files[i], "r");
		if (!f)
			return FILE_NOT_FOUND_ERROR;

		while ((readed = fread(buffer, sizeof(char), BUFFER_SIZE, f)) > 0)
			fwrite(buffer, sizeof(char), readed, fdest);

		fclose(f);
	}

	if (!standard_dest)
		fclose(fdest);

	return 0;
}


int cat_next_token(Line* line, char token[MAX_FILENAME])
{
	int trim_zone = 1, count = 0;
	char c;
	for (;count < (MAX_FILENAME - 1) && line->idx < line->size; ++line->idx)
	{
		c = line->line[line->idx];
		if (c == '\0')
			break;

		if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		{
			if (trim_zone)
				continue;
			break;
		}

		trim_zone = 0;
		token[count++] = c;
	}

	token[count] = '\0';
	return count;
}


int cat_parse_stdin_args(char files[MAX_OPENED_FILES][MAX_FILENAME], int* num_files, char dest_file[MAX_FILENAME])
{
	int readed, out = 0, count = 0;
	char filename[MAX_FILENAME];
	Line line = { .size = 0, .idx = 0 };

	memset(dest_file, 0, sizeof(char) * MAX_FILENAME);

	if (fgets(line.line, MAX_LINE_SIZE, stdin) == NULL)
		return CANNOT_READ_ARGS_ERROR;
	line.size = strlen(line.line);

	while (count < MAX_OPENED_FILES && (readed = cat_next_token(&line, filename)) > 0)
	{
		if (strcmp(filename, ">") == 0)
		{
			if (out)
				return TWO_OR_MORE_OUT_FILES_ERROR;
			out = 1;
		}
		else
		{
			if (out)
			{
				if (out != 1)
					return TWO_OR_MORE_OUT_FILES_ERROR;
				strcpy(dest_file, filename);
				out = 2;
			}
			else strcpy(files[count++], filename);
		}
	}
	*num_files = count;

	return 0;
}

int cat_parse_prog_args(
	int argc, // Numero de argumentos introducidos en el terminal
	char** argv, // array de argumentos introducidos en el terminal

	char files[MAX_OPENED_FILES][MAX_FILENAME],
	int* num_files,
	char dest_file[MAX_FILENAME]
)
{
	int out = 0, count = 0;

	memset(dest_file, 0, sizeof(char) * MAX_FILENAME);

	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], ">") == 0)
		{
			if (out)
				return TWO_OR_MORE_OUT_FILES_ERROR;
			out = 1;
		}
		else
		{
			if (out)
			{
				if (out != 1)
					return TWO_OR_MORE_OUT_FILES_ERROR;
				strcpy(dest_file, argv[i]);
				out = 2;
			}
			else strcpy(files[count++], argv[i]);
		}
	}
	*num_files = count;

	return 0;
}
