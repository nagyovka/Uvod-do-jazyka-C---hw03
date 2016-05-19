#ifndef PICTURE_H
#define PICTURE_H


/**
 *  @file   picture.h
 *  @author Anna Nagyova
 */

#include "container.h"

/**
 * @brief Loads image given by the user, provided its format is correct
 * @return  pointer to the new image
 */

Img *loadImg();

/**
 * @brief Prints the images.
 *
 * Uses the values of @a Img* and the maximum @a height of the pictures in order to correctly
 * print them.
 */

void printImg(Img* , Img* , Img* , unsigned );

/**
 * @brief Prints one line of the picture.
 *
 * Uses the current maximum @a height and current @a y position to print either spaces or the
 * image data.
 */

void printOneLine(Img* , unsigned , unsigned );

#endif // PICTURE_H
