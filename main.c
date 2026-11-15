#include <stdio.h>

#define FILE_PATH "./test.aseprite"

#define DWORD unsigned int
#define WORD unsigned short
#define BYTE unsigned char
#define SHORT short

typedef struct {
    DWORD file_size;
    WORD magic;
    WORD frames;
    WORD width;
    WORD height;
    WORD color_depth;
    DWORD flags;
    WORD speed;
    DWORD set_be_0_1;
    DWORD set_be_0_2;
    BYTE pixel_width;
    BYTE pixel_height;
    SHORT x_pos_grid;
    SHORT y_pos_grid;
    WORD grid_width;
    WORD grid_height;
    BYTE future[84];
} Header;

int main() {
    FILE *file = fopen(FILE_PATH, "r");

    Header header;
    fread(&header, sizeof(header), 1, file);
    printf("file_size = %d\n", header.file_size);
    printf("magic = %x\n", header.magic);

    fclose(file);
    return 0;
}
