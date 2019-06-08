#ifndef EDITOR_DEFINES_H
#define EDITOR_DEFINES_H

#define WINDOWS_SIZE_W 1024
#define WINDOWS_SIZE_H 768

#define CELL_SIZE_W 32
#define CELL_SIZE_H 32

#define QUANTITY_CELLS (((WINDOWS_SIZE_W)/(CELL_SIZE_W))*((WINDOWS_SIZE_H)/(CELL_SIZE_H)))

#define IDCLASS_NULL 0
#define IDCLASS_CHELL 1
#define IDCLASS_BLOQUEROCA 2

#define DIR_IMAGEN_CHELL_A "../resources/shell.png"
#define DIR_IMAGEN_BLOQUEROCA "../resources/bloqueRoca.png"

#define IDCOLOR_CHELL_A 1

#define NOMBRE_CHELL "chell"

#endif // EDITOR_DEFINES_H
