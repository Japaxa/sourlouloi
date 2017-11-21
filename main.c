#include <stdio.h>
#include <stdlib.h>
#include <strlib.h>


string first_path(void);
string second_path(void);
short found_data(string path);
int find_chrome(void);

int main()
{
    int path_option;
    path_option = find_chrome();
    if(!path_option)
    {
        printf("Chrome not installed.\n");
        exit(1);
    }
    printf("%d", path_option);

    return 0;
}

string second_path(void)
{
    string drive, path, path2;
    int search_result;

    drive = Concat(getenv("HOMEDRIVE"), "/");
    path = getenv("HOMEPATH");
    search_result = FindChar('\\', path, 1);
    path2 = SubString(path, search_result + 1, StringLength(path) - 1);
    path = SubString(path, 1, search_result - 1);
    path = Concat(path,Concat("/", path2));
    return Concat(drive,Concat(path, "/Local Settings/Application Data/Google/Chrome/User Data/Default/Login Data"));

}

string first_path(void)
{
    string drive, path, path2;
    int search_result;

    drive = Concat(getenv("HOMEDRIVE"), "/");
    path = getenv("HOMEPATH");
    search_result = FindChar('\\', path, 1);
    path2 = SubString(path, search_result + 1, StringLength(path) - 1);
    path = SubString(path, 1, search_result - 1);
    path = Concat(path,Concat("/", path2));
    return Concat(drive,Concat(path, "/AppData/Local/Google/Chrome/User Data/Default/Login Data"));

}

int find_chrome(void)
{
    if(found_data(first_path()))
        return 1;
    if(found_data(second_path()))
        return 2;
    return 0;
}

short found_data(string path)
{
    FILE *exist;
    exist = fopen(path, "r");
    if(exist == NULL)
        return 0;
    return 1;
}
