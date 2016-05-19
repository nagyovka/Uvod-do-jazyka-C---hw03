#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

/**
 *  @file   errorHandling.h
 *  @author Jiri Weiser
 *  source - https://cecko.eu/public/pb071/hw03_2016
 */

typedef enum {
    ERROR_NO_MEMORY,
    ERROR_WRONG_FORMAT,
    ERROR_WRONG_CMD
} errorType;

/**
 * Function to report errors
 *
 * @param [errorType] {in} type of error
 */
void errorHandle(errorType);

#endif // ERROR_HANDLING
