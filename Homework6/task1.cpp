#include <iostream>
#include <stdio.h>
#include <string>

FILE* in, * out;

void in_comment(void)
{
    int c, d;
    c = fgetc(in);
    d = fgetc(in);
    while (c != '*' || d != '/')
    {
        c = d;
        d = fgetc(in);
    }
}

void in_short_comment(void)
{
    int c;
    c = fgetc(in);
    while (c != '\n')
        c = fgetc(in);
}

void find_comment(int c)
{
    int d;
    if (c == '/')
        if ((d = fgetc(in)) == '*')
            in_comment();
        else if (d == '/')
            in_short_comment();
        else
        {
            fputc(c, out);
            fputc(d, out);
        }
    else
        fputc(c, out);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int c;
    char out_f_name[30];
    char in_f_name[30];

    printf("¬ведите им€ файла, в котором надо удалить комментарии: ");
    gets_s(out_f_name);
    fopen_s(&in, out_f_name, "rb");
    if ((in == NULL))
    {
        perror(out_f_name);
        return 1;
    }
    printf("¬ведите им€ файла, в который запишетс€ результат: ");
    gets_s(in_f_name);
    fopen_s(&out, in_f_name, "wb");
    while ((c = fgetc(in)) != EOF)
    {
        find_comment(c);
    }
    fclose(in);
    fclose(out);
    system("pause");
    return EXIT_SUCCESS;
}