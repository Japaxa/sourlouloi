#ifndef DECRYPT_H_INCLUDED
#define DECRYPT_H_INCLUDED

void decrypt(string path);

void decrypt(string path)
{

    char c, buff[15000], output[15000];
    int counter = 0;
    FILE *fp;
    DATA_BLOB DataIn;
    DATA_BLOB DataOut;

    fp = fopen(path, "rb");
    if(fp == NULL)
    {
        printf("File does not exist.\n");
        exit(1);
    }
    while((c = getc(fp)) != EOF)
    {
        buff[counter] = c;
        counter+= sizeof(char);
    }
    DataIn.pbData = counter + 1;
    DataIn.pbData = buff;

    if(CryptUnprotectData(&DataIn,NULL,NULL,NULL,NULL,0,&DataOut))
    {
         for (counter=0;counter<DataOut.cbData;counter++)
        {
            output[counter]=DataOut.pbData[counter];
        }
        output[counter+1]='\0';
        printf("\nResult as string: %s\n", output);
    }
    return ;
}


#endif // DECRYPT_H_INCLUDED
