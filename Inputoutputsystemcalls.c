#include <stdio.h>
#include <unistd.h>

int main(){
    char c;
    int a = 1;
    while(a != 0){
        read(0, &c, 1);
        write(1, &c, 1);
        a = (c != '0');
    }
    return 0;
}
