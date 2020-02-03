#include "cat.h"

#define CAT_TERMINAL_MODE 0



#if !defined(CAT_TERMINAL_MODE) || CAT_TERMINAL_MODE == 0


int main()
{
	char files[MAX_OPENED_FILES][MAX_FILENAME];
	int num_files;
	char dest_file[MAX_FILENAME];

	int status = cat_parse_stdin_args(files, &num_files, dest_file);
	if (status != 0)
		return status;

	status = cat(files, num_files, dest_file);

	return status;
}


#elif CAT_TERMINAL_MODE != 0


int main(int argc, char** argv)
{
	char files[MAX_OPENED_FILES][MAX_FILENAME];
	int num_files;
	char dest_file[MAX_FILENAME];

	int status = cat_parse_prog_args(argc, argv, files, &num_files, dest_file);
	if (status != 0)
		return status;

	status = cat(files, num_files, dest_file);

	return status;

	return 0;
}


#endif

