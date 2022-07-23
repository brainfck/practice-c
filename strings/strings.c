#include <stdio.h>

int string_length(const char *str){
    const char *p;
    for(p = str; *p; p++){
    }
    return p - str;
}

int main() {
    printf("%i \n", string_length("SOME BIG STRING"));
    return 0;
}
