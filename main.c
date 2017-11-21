#include <stdio.h>
#include <stdlib.h>
#include <strlib.h>
#include <windows.h>
#include <wincrypt.h>

#include "file_finder.h"
#include "decrypt.h"

int main()
{
    int path_option;
    path_option = find_chrome();
    if(path_option == 2)
    {
        decrypt(second_path());
    }else if(path_option == 1)
    {
        decrypt(first_path());
    }else
    {
        printf("Chrome not installed");
        exit(1);
    }


    return 0;
}
