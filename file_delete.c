#include "file.h"

/**
 * main - calls delete_file and handles the output
 * 
 * Return: 0 on success
 */
int main(void)
{
    char file[100];
    int d;

    printf("Enter file name to delete: ");
    scanf("%s", file);

    printf("You entered: %s\n", file);

    d = delete_file(file);
    
    if (d == -1)
    {
        printf("Filename is not given.\n");
    }
    else if (d == 0)
    {
        printf("File successfully deleted.\n");
    }
    else if (d == 1)
    {
        printf("File does not exist.\n");
    }
    else
    {
        printf("Error deleting file.\n");
    }

    return (0);
}

/**
 * delete_file - deletes a file specified by the user
 * @filename: the file to be deleted
 * 
 * Return: 0 on success, non-zero on failure
*/

int delete_file(char filename[])
{
    FILE *fptr;

    if (filename == NULL)
    {
        return (-1); /*filename is not given*/
    }

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        return (1); /* file does not exist*/
    }
    fclose(fptr);

    return (remove(filename));  /*Can this also return 1/-1? In which case the main function might print the wrong message*/
}   