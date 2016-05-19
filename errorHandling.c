#include <stdio.h>

#include "errorHandling.h"

//==============================================================================
//  DO NOT MODIFY THIS FILE
//==============================================================================


// That's right, just close it and go play with something else.

/**
 *  @file   errorHandling.c
 *  @author Jiri Weiser
 *  source - https://cecko.eu/public/pb071/hw03_2016
 */

void errorHandle(errorType e) {
    fputs("Error happened: ", stderr);

    switch(e) {
    case ERROR_NO_MEMORY:
        fputs("No available memory.\n", stderr);
        break;
    case ERROR_WRONG_FORMAT:
        fputs("Wrong format of the file.\n", stderr);
        break;
    case ERROR_WRONG_CMD:
        fputs("Unknown command.\n", stderr);
        break;

    default:
        fputs("Unknown error.\n", stderr);
        break;
    }
}

