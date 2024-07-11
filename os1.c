#include <stdio.h>

struct filep {
    int id;
    int start;
    int count;
};
typedef struct filep files;

void allocate(files *f, int *disk, int id, int count, int disk_size) {
    for (int i = 0; i < disk_size; i++) {
        int j;
        for (j = 0; j < count; j++) {
            if (i + j >= disk_size || disk[i + j] != -1) {
                break;
            }
        }
        if (j == count) {  // Found enough contiguous space
            f->id = id;
            f->start = i;
            f->count = count;
            for (int k = 0; k < count; k++) {
                disk[i + k] = id;
            }
            printf("File %d allocated from %d to %d\n", id, i, i + count - 1);
            return;
        }
    }
    printf("Not enough space to allocate file %d\n", id);
}

void deallocate(files *f, int *disk) {
    for (int i = f->start; i < f->start + f->count; i++) {
        disk[i] = -1;
    }
    printf("File %d deallocated from %d to %d\n", f->id, f->start, f->start + f->count - 1);
    f->id = -1;  // Mark as deallocated
}

void display_disk(int *disk, int disk_size) {
    for (int i = 0; i < disk_size; i++) {
        printf("%3d ", disk[i]);
    }
    printf("\n");
}

int main() {
    int disk[100];
    files f[3];

    for (int i = 0; i < 100; i++) {
        disk[i] = -1;
    }
    for (int i = 0; i < 3; i++) {
        f[i].id = -1;  // Initialize file entries as deallocated
    }

    // Example usage:
    allocate(&f[0], disk, 1, 5, 100);
    display_disk(disk, 100);

    allocate(&f[1], disk, 2, 3, 100);
    display_disk(disk, 100);

    deallocate(&f[0], disk);
    display_disk(disk, 100);

    allocate(&f[2], disk, 3, 7, 100);
    display_disk(disk, 100);

    return 0;
}

