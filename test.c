char    *complete_line(char *line, int longest_length)
{
    char *return_line;
    return_line = malloc((sizeof(char) * longest_length) + 1);
    if (!return_line)
    {
        perror("");
        exit(1);
    }
    int i;
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != ' ')
            return_line[i] = line[i];
        else
            return_line[i] = 's';
        i++;
    }
    
    return (return_line);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s\n",complete_line("    111100111\n", 17));
// }