#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int my_rand(){
    srand(time(0));
    return rand() % 5;
}

void simple_no_block(){
    if (my_rand()) printf("simple_no_block\n");
    printf("return\n");
}

void simple_block(){
    if (my_rand()) {
      printf("simple_block 1\n");
      printf("simple_block 2\n");
    } else {
      printf("simple_block else 1\n");
      printf("simple_block else 2\n");
    }
    printf("return\n");
}

void simple_nested(){
    if (my_rand()) {
        int r = my_rand();
	if (r) {
	    printf("simple_nested\n");
	} else {
            printf("simple_nested else\n");
        }
        printf("simple_nested outer\n");
    }
    printf("return\n");
}

int main(){
    simple_no_block();
    simple_block();
    simple_nested();
    
    return 0;
}















