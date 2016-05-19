#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "picture.h"
#include "errorHandling.h"
#include "container.h"

void printImg(Img *img1, Img *img2, Img *img3, unsigned height) {
    for (unsigned y = 1; y <= height; y++) {
        printOneLine(img1, y, height);
        if (img2) {
            printf(" | ");
            printOneLine(img2, y, height);
            if (img3) {
                printf(" | ");
                printOneLine(img3, y, height);
            }
        }
        putchar('\n');
    }
}

void printOneLine(Img *i, unsigned y, unsigned height) {
    unsigned tempH = 0;
    if (height == i->height) {
        for (unsigned x = 0; x < i->width; x++)
            putchar(i->data[(y-1)*i->width + x]);
    } else if ((height - i->height) % 2 == 0) {
        if (((y >= 1) && (y <= ((height - i->height) / 2))) || ((y > (height - ((height - i->height) / 2))) && (y <= height))) {
            for (unsigned x = 0; x < i->width; x++)
                putchar(' ');
        } else {
            tempH = y - (height - i->height)/2;
            for (unsigned x = 0; x < i->width; x++) {
                putchar(i->data[(tempH-1)*i->width + x]);
            }
        }
    } else {
        if (y <= (height - i->height)) {
            for (unsigned x = 0; x < i->width; x++)
                putchar(' ');
        } else {
            tempH = y - (height - i->height);
            for (unsigned x = 0; x < i->width; x++) {
                putchar(i->data[(tempH-1)*i->width + x]);
            }
        }
    }
}

Img* loadImg() {
    Img* image = NULL;
    char *tmpPtr = NULL;
    unsigned int length = 0;
    unsigned int tempW = 0;
    if (!(image = (Img *) malloc(sizeof(Img)))) {
        errorHandle(ERROR_NO_MEMORY);
        char last = '\n';
        int znak = 0;
        while ((znak = getchar())) {
            if ((last == '\n') && (znak == '\n'))
                    break;
            last = znak;
        }
        return NULL;
    }
    imgInit(image);
    int znak = getchar();
    if (znak == '\n') {
        deallocImg(image);
        image = NULL;
        return NULL;
    }
    if (!(image->data = (char *) malloc(sizeof(char)))) {
        deallocImg(image);
        errorHandle(ERROR_NO_MEMORY);
        char last = '\n';
        while ((znak = getchar())) {
            if ((last == '\n') && (znak == '\n'))
                    break;
            last = znak;
        }
        return NULL;
    }
    image->data[0] = znak;
    tempW += 1;
    image->height += 1;
    length += 1;
    znak = getchar();
    while (znak != '\n') {
        tmpPtr = realloc(image->data, (length + 1)*sizeof(char));
        if (!tmpPtr) {
            errorHandle(ERROR_NO_MEMORY);
            deallocImg(image);
            char last = '\n';
            while ((znak = getchar())) {
                if ((last == '\n') && (znak == '\n'))
                        break;
                last = znak;
            }
            return NULL;

        }
        image->data = tmpPtr;
        image->data[length] = znak;
        length += 1;
        tempW += 1;
        znak = getchar();
    }
    image->width = tempW;
    tempW = 0;
    znak = getchar();
    while (znak != '\n') {
        while (znak != '\n') {
            tmpPtr = realloc(image->data, (length + 1)*sizeof(char));
            if (!tmpPtr) {
                errorHandle(ERROR_NO_MEMORY);
                deallocImg(image);
                char last = '\n';
                while ((znak = getchar())) {
                    if ((last == '\n') && (znak == '\n'))
                            break;
                    last = znak;
                }
                return NULL;
            }
            image->data = tmpPtr;
            tempW += 1;
            image->data[length] = znak;
            length += 1;
            znak = getchar();
        }
        if (tempW != image->width) {
            errorHandle(ERROR_WRONG_FORMAT);
            deallocImg(image);
            char last = '\n';
            while ((znak = getchar())) {
                if ((last == '\n') && (znak == '\n'))
                        break;
                last = znak;
            }
            return NULL;
        }
        tempW = 0;
        image->height += 1;
        znak = getchar();
    }
    return image;

}

// TODO: picture implementation
