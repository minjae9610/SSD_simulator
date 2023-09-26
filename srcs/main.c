#include "main.h"

int main(int argc, char **argv)
{
    if (!ssd_init())
    {
        putstr_fd(STDERR_FD, "ssd_init() failed\n");
        return 1;
    }
    switch (valid_command(argc, (const char **)argv))
    {
    case WRITE:
        if (!ssd_write(atoi(argv[2]), strtol(argv[3], NULL, 16)))
        {
            putstr_fd(STDERR_FD, "ssd_write() failed\n");
            return 1;
        }
        break;
    case READ:
        printf("0x%.8X\n", ssd_read(atoi(argv[2])));
        break;
    default:
        putstr_fd(STDERR_FD, "[Usage]\nwrite:\t./ssd_simulator [W] [LBA] [DATA]\nread:\t./ssd_simulator [R] [LBA]\n");
        break;
    }

    return 0;
}

int valid_command(const int argc, const char **argv)
{
    if (argc == 4 && !strcmp(argv[1], "W") && isdigit_str(argv[2]) && ishex_str(argv[3]))
        return WRITE;
    if (argc == 3 && !strcmp(argv[1], "R") && isdigit_str(argv[2]))
        return READ;
    return NONVALID;
}
