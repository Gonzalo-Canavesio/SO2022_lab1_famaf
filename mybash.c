#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "command.h"
#include "execute.h"
#include "parser.h"
#include "parsing.h"
#include "builtin.h"

static void show_prompt(void) {
    printf ("mybash> ");
    fflush (stdout);
}

int main(int argc, char *argv[]) {
    pipeline pipe = NULL;
    Parser input = parser_new(stdin);
    quit = false; // initialize variable (in builtin.h)

    while (!quit) {
        show_prompt();
        pipe = parse_pipeline(input);

        execute_pipeline(pipe);
        pipeline_destroy(pipe);

        /* ¿Hay que salir luego de ejecutar? */
        quit = parser_at_eof(input);
    }
    parser_destroy(input);
    input = NULL;
    return EXIT_SUCCESS;
}

