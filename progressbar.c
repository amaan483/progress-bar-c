#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#ifdef _WIN32
#include<windows.h>
#define SLEEP() Sleep(x * 1000)
#endif

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
void progressBar(int progress, int total) {
    int barwidth = 50;
    float percent = (float)progress / total * 100;
    int pos = (progress * barwidth) / 100;
    clear_screen();
    printf("Loading: \n[");
    for(int i=0; i<barwidth; i++) {
        if(i<pos){
            printf("=");
        }
        else if(i==pos) {
            printf(">");
        }
        else {printf(" ");}
    }
    printf("] %.0f%%\n", percent);
}

int main() {
    int fileSize = 100;
    int chunksize = 5;
    int copied = 0;
    while(copied<=fileSize) {
        progressBar(copied, fileSize);
        copied += chunksize;
        Sleep(100);
    }
    printf("Task completed successfully.\n");
    return 0;
}