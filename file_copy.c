#include "file.h"

/**
 * main - copies data from a source file to a destination file
 * 
 * Description: Note that this does not work for all file types. Examples of unsupported file types include doc.x,
 * 
 * Return: 0 on success
 */
int main(void)
{
    char source_file[100], destination_file[100];
    int c, r;
    FILE *fptr_s, *fptr_d;
    
    printf("Enter the source file name: ");
    scanf("%s", source_file);
    /*fgets(source_file, sizeof(source_file), STDIN_FILENO);*/ /* fgets is safer than scanf to prevent possible overflow */
    /*source_file[strcspn(source_file, "\n")] = '\0';*/ /* replace the newline character with null */
    printf("Enter the destination file name: ");
    scanf("%s", destination_file);

    fptr_s = fopen(source_file, "r"); /* open the source file in read mode */
    fptr_d = fopen(destination_file, "w"); /* open destination file in write mode */

    if (fptr_s != NULL && fptr_d != NULL)
    {
        c = fgetc(fptr_s);
        while (c != EOF)
        {
            fputc(c, fptr_d);
            c = fgetc(fptr_s);
        }
        fclose(fptr_s);
        fclose(fptr_d);
    }
    else
    {
        printf("Error opening one of the files. Check that both files already exist.\n");
    }

    /* after copying the source file, remove it using remove() sys call */
    r = remove(source_file);    /* remove() returns an int, 0 on success and non-zero on failure */
    if (r == 0)
    {
        printf("Copied file successfully deleted.\n");
    }
    else
    {
        printf("Error deleting copied file.\n");
    }

    return(0);
}