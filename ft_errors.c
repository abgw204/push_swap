#include "stack.h"

void ft_error(int error_status)
{
    if (error_status == 0)
    {
        write(1, "Error code 0: No arguments\n", 28);
        exit(1);
    }
    else if (error_status == 1)
    {
        write(1, "Error code 1: Int overflow detected\n", 37);
        exit(1);
    }
    else if (error_status == 2)
    {
        write(1, "Error code 2: Duplicated input. \n", 34);
        exit(1);
    }
    else if (error_status == 3)
    {
        write(1, "Error code 3: Invalid input. \n", 31);
        exit(1);
    }
}