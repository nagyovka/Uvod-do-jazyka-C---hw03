#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "container.h"

void galleryInit(Gallery *g) {
    g->actual = NULL;
    g->size = 0;
}

void imgInit(Img *i) {
    i->data = NULL;
    i->next = NULL;
    i->prev = NULL;
    i->width = 0;
    i->height = 0;
}

void deallocImg(Img *i) {
    free(i->data);
    free(i);
}

void deallocGallery(Gallery *g) {
    Img *temp = NULL;
    while (g->actual != NULL) {
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
    }
}

// TODO: container implementation
