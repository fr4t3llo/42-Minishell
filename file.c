#include <unistd.h>
#include <stdio.h>

int main( int ac, char **av)
{
    char pwd[1024];
    getcwd(pwd, 1024);
    printf("%s\n", pwd); 
    if (chdir("~/Desktop") == -1)
        printf("ERROR\n");
    getcwd(pwd, 1024);
    printf("%s\n", pwd); 
    pause();
    return 0;
}