#ifndef CONTAINER_H
#define CONTAINER_H

/**
 *  @file   container.h
 *  @author Anna Nagyova
 */

/**
 *  @brief Structure of an image with all its atributes
 */

typedef struct image {
    char* data;
    struct image* next;
    struct image* prev;
    unsigned int width;
    unsigned int height;
} Img;

/**
 *  @brief Structure of a gallery that holds pointer to the actual picture and the current size of gallery.
 */

typedef struct gallery {
    Img* actual;
    unsigned int size;
} Gallery;


/**
 * @brief Function that initializes the gallery.
 */

void galleryInit(Gallery* );

/**
 * @brief Function that initializes the attributes of an image.
 */

void imgInit(Img *);

/**
 * @brief Function that deallocs the memory used to store an image.
 */

void deallocImg(Img *);

/**
 * @brief Function that deallocs the memory taken by the whole gallery.
 */

void deallocGallery(Gallery* );

#endif // CONTAINER_H
