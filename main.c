/**
 * File              : main.c
 * Date              : 14.12.2017
 * Last Modified Date: 14.12.2017
 */
/**
 * File              : main.c
 * Date              : 14.12.2017
 * Last Modified Date: 14.12.2017
 */
/**
 * File              : main.c
 * Date              : 14.12.2017
 * Last Modified Date: 14.12.2017
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "alloy.h"
//#include "gpu.h"
#include "multicore.h"
//#include "cpu.h"
#include "main.h"

#define WRITE_IMAGE false 
#define NUM_GENERATIONS 100

#define WIDTH 1024 * 2
#define HEIGHT 1024 * 2

#define MAT_CONST_1 0.75
#define MAT_CONST_2 1.0
#define MAT_CONST_3 1.25

int main(int argc, char** argv) {
    srand(time(NULL));

    materials_def mat_def = create_materials_def(MAT_CONST_1, MAT_CONST_2,
            MAT_CONST_3);
    alloy* my_alloy = create_alloy(WIDTH, HEIGHT, mat_def);

    stamp_dots(my_alloy);
    stamp_pattern(my_alloy);

    for (int i = 0; i < NUM_GENERATIONS; i++) {
        update_alloy(i, my_alloy);

        if (WRITE_IMAGE) {
            /*write_alloy_image(my_alloy, i);*/
        }

        printf("%d\n", i);

        printf("temp: %f\n", my_alloy->points_a[0]);
    }

    free_alloy(my_alloy);

    return 0;
}

/*void write_alloy_image(alloy* my_alloy, int generation) {
    char *path = (char*)malloc((7 + 5 + 4 + 1) * sizeof(char));
    sprintf(path, "images/%05d.png", generation);

    write_alloy_png(my_alloy, generation, path);

    free(path);
}*/
