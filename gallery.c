#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "container.h"
#include "picture.h"
#include "gallery.h"
#include "errorHandling.h"

// TODO: gallery implementation

void help() {
    printf("GALERIE OBRAZKU : : NAPOVEDA\n\n");
    printf("====    SPUSTENI PROGRAMU\n");
    printf("        /home/kontr/PB071/gallery [-s]\n");
    printf("-s      vypne tuto napovedu\n\n");
    printf("====    ZAKLADNI PRIKAZY\n");
    printf("n       nacte novy obrazek v editacnim rezimu\n");
    printf("d       smaze aktualni obrazek\n");
    printf("l r     rotace galerie vlevo nebo vpravo\n");
    printf("s       zjisti pocet obrazku v galerii\n");
    printf("q       ukonci program\n\n");
    printf("====    ROZSIRENE PRIKAZY\n");
    printf("c x     kopiruje nebo vystrihne obrazek do schranky\n");
    printf("v       vlozi obrazek ze schranky na aktualni pozici\n\n");
}

unsigned maximum(unsigned size1, unsigned size2, unsigned size3) {
    unsigned max = size1;
    if (size2 > max)
        max = size2;
    if (size3 > max)
        max = size3;
    return max;
}

void printGallery(Gallery *g) {
    unsigned height = 0;
    switch (g->size) {
    case 0:
        break;
    case 1:
        printImg(g->actual, NULL, NULL, g->actual->height);
        break;
    case 2:
        height = maximum(g->actual->height, g->actual->next->height, 0);
        printImg(g->actual, g->actual->next, NULL, height);
        break;
    default:
        height = maximum(g->actual->prev->height, g->actual->height, g->actual->next->height);
        printImg(g->actual->prev, g->actual, g->actual->next, height);
        break;
    }
}

void addImage(Gallery* g) {
    Img *newImage = loadImg();
    if (newImage) {
        if (g->size == 0) {
            newImage->prev = newImage;
            newImage->next = newImage;
        } else {
            g->actual->prev->next = newImage;
            newImage->prev = g->actual->prev;
            g->actual->prev = newImage;
            newImage->next = g->actual;
        }
        (g->size)++;
        g->actual = newImage;
    }
}

void rotateRight(Gallery *g) {
    if (g->size != 0) {
        g->actual = g->actual->prev;
    }
}

void rotateLeft(Gallery *g) {
    if (g->size != 0) {
        g->actual = g->actual->next;
    }
}

void removeImg(Gallery *g) {
    Img *temp = NULL;
    if (g->size != 0) {
        if (g->actual == g->actual->next) {
            deallocImg(g->actual);
            g->actual = NULL;
        }
        else {
            g->actual->prev->next = g->actual->next;
            g->actual->next->prev = g->actual->prev;
            temp = g->actual->next;
            deallocImg(g->actual);
            g->actual = temp;
        }
        (g->size)--;
    }
}

void printSize(Gallery *g) {
    printf("size: %u", g->size);
    printf("\n");
}

void galleryApp(Gallery *g) {
    printf(">");
    int znak = 0;
    char buffer[4] = "";
    char* token = NULL;
    Img* clipboard = NULL;
    fgets(buffer, 3, stdin);

    while (strcmp(buffer, "q\n")) {
        if (buffer[0] == '\n') {
            errorHandle(ERROR_WRONG_CMD);
        }
        else if (buffer[1] == '\n') {
            token = strtok(buffer, "\n");
            switch (*token) {
            case 'n':
                addImage(g);
                printGallery(g);
                break;
            case 'r':
                rotateRight(g);
                printGallery(g);
                break;
            case 'l':
                rotateLeft(g);
                printGallery(g);
                break;
            case 'd':
                removeImg(g);
                printGallery(g);
                break;
            case 's':
                printSize(g);
                break;
            case 'c':
                clipboard = copyToClipboard(g->actual, clipboard);
                break;
            case 'x':
                clipboard = copyToClipboard(g->actual, clipboard);
                removeImg(g);
                printGallery(g);
                break;
            case 'v':
                addFromClipboard(clipboard, g);
                printGallery(g);
                break;
            default:
                errorHandle(ERROR_WRONG_CMD);
                break;
            }
        } else {
            errorHandle(ERROR_WRONG_CMD);
            while ((znak = getchar()) != '\n')
                ;
        }
        printf(">");
        fgets(buffer, 3, stdin);
        }
    if (clipboard)
        deallocImg(clipboard);
    return;
    }


Img* copyToClipboard(Img *i, Img* clipboard) {
    if (i == NULL)
        return NULL;
    if (clipboard) {
        deallocImg(clipboard);
        clipboard = NULL;
    }
    if (!(clipboard = (Img *) malloc(sizeof(Img)))) {
        errorHandle(ERROR_NO_MEMORY);
        return NULL;
    }
    imgInit(clipboard);
    if (!(clipboard->data = (char *) malloc(i->height*i->width*sizeof(char)))) {
        errorHandle(ERROR_NO_MEMORY);
        free(clipboard);
        clipboard = NULL;
        return NULL;
    }
    clipboard->height = i->height;
    clipboard->width = i->width;
    for (unsigned j = 0; j < (i->height*i->width); j++) {
        clipboard->data[j] = i->data[j];
    }
    return clipboard;
}

void addFromClipboard(Img *clipboard, Gallery *g) {
    Img *i = NULL;
    if (clipboard) {
        if (!(i = (Img*) malloc(sizeof(Img)))) {
            errorHandle(ERROR_NO_MEMORY);
            return;
        }
        imgInit(i);
        if (!(i->data = (char *) malloc(clipboard->height*clipboard->width*sizeof(char)))) {
            errorHandle(ERROR_NO_MEMORY);
            free(i);
            return;
        }
        i->height = clipboard->height;
        i->width = clipboard->width;
        for (unsigned j = 0; j < (i->height*i->width); j++) {
            i->data[j] = clipboard->data[j];
        }
        if (g->size == 0) {
            i->prev = i;
            i->next = i;
        } else {
            g->actual->prev->next = i;
            i->prev = g->actual->prev;
            g->actual->prev = i;
            i->next = g->actual;
        }
        (g->size)++;
        g->actual = i;
    }
}
