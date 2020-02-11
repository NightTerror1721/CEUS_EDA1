#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "client_line.h"

#define OPTION_INVALID -1
#define OPTION_QUIT 0
#define OPTION_NEW_CLIENT 1
#define OPTION_ATTEND_CLIENT 2


void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int read_int_option(const char* msg) {
    int option = OPTION_INVALID;
    printf("%s", msg);
    scanf("%d", &option);

    flush_input();

    return option;
}

int show_menu() {
    printf("\n1. A client appeared!\n");
    printf("2. Attend a client.\n");
    printf("0. Quit.\n");
    return read_int_option("Choose an option:\n");
}

int main() {
    Client client;
    ClientLine line;
    init_line(&line);

    int option = OPTION_INVALID;
    while (option != OPTION_QUIT) {
        option = show_menu();

        switch (option) {
            case OPTION_NEW_CLIENT:
                read_client_from_stdin(&client);
                client_appeared(&line, &client);
                break;

            case OPTION_ATTEND_CLIENT:
                attend_client(&line);
                break;

            case OPTION_QUIT:
                goto end_while;

            default:
                printf("Invalid option!. Try again...");
                break;
        }
    }
    end_while:

    printf("There are still %d clients in the line!", line.count);

    cleanup(&line);

    return 0;
}