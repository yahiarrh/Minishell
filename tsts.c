#include <libc.h>

int main()
{
    char *const argv[] = {"/bin/ls", "-l", NULL};
    char *const arg[] = {"/bin/cat", NULL, NULL};
    char *const envp[] = {NULL};
    int fd = open("ff", O_CREAT | O_RDWR | O_APPEND, 0777);

    dup2(fd, 1);
    dup2(fd, 0);
    if (execve("/bin/ls", argv, envp) == -1) {
        perror("execve");
        return 1;
    }
    if (execve("/bin/cat", argv, envp) == -1) {
        perror("execve");
        return 1;
    }
}