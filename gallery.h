#ifndef GALLERY_H
#define GALLERY_H

/**
 *  @file   gallery.h
 *  @author Anna Nagyova
 */

#include "container.h"

/**
 * @brief Function to count the maximum.
 *
 * Takes up to three parameters. Needed for the printing.
 */

unsigned maximum(unsigned , unsigned , unsigned );

/**
 * @brief Function to print the gallery.
 *
 * Uses the size of the gallery to determine how many pictures to print.
 */

void printGallery(Gallery* );

/**
 * @brief Function to add one image into the gallery, if there is enough space.
 */

void addImage(Gallery* );

/**
 * @brief Rotates the gallery to the right.
 */

void rotateRight(Gallery* );

/**
 * @brief Rotates the gallery to the left.
 */

void rotateLeft(Gallery* );

/**
 * @brief Removes one image from the gallery.
 */

void removeImg(Gallery* );

/**
 * @brief Prints the size of the gallery.
 */

void printSize(Gallery* );

/**
 * @brief Full program.
 *
 * Takes the commands and executes them, provided they are correct.
 */

void galleryApp(Gallery* );

/**
 * @brief Instructions on how the gallery works.
 */

void help();

/**
 * @brief Function that copies the actual image to clipboard.
 * @return  allocated clipboard with the image, when the gallery is not empty.
 */

Img* copyToClipboard(Img* , Img*);

/**
 * @brief Function that adds image from clipboard to gallery.
 */

void addFromClipboard(Img*, Gallery*);

#endif // GALLERY_H
