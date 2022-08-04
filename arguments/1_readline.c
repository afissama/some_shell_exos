#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *buffer;
    size_t buf_len;

    buf_len = 1024;
    buffer = (char *)malloc(buf_len * sizeof(char));
    if(buffer == NULL)
    {
        perror("unable to allocate buffer");
        exit(1);
    }

    printf("$ ");
    while (getline(&buffer, &buf_len, stdin) != -1)
    {
        printf("%s", buffer);
        printf("$ ");
    }
    
    return 0;
}
