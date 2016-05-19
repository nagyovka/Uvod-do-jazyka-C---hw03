#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "container.h"
#include "picture.h"
#include "gallery.h"
#include "errorHandling.h"

// TODO: CLI and utilities

int main(int argc, char** argv)
{
    Gallery g;
    galleryInit(&g);
    if (argc == 2) {
        if (strcmp(argv[1], "-s"))
            help();
    } else {
        help();
    }
    galleryApp(&g);
    deallocGallery(&g);
    return 0;
}

