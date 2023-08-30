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
    char source_file[100];
    char destination_file[100];
    FILE *fptr_o, *fptr_d;
    int c;
    
    printf("Enter the source file name: ");
    scanf("%s", source_file);
    /*fgets(source_file, sizeof(source_file), STDIN_FILENO);*/ /* fgets is safer than scanf to prevent possible overflow */
    /*source_file[strcspn(source_file, "\n")] = '\0';*/ /* replace the newline character with null */
    printf("Enter the destination file name: ");
    scanf("%s", destination_file);

    fptr_o = fopen(source_file, "r"); /* open the source file in read mode */
    fptr_d = fopen(destination_file, "w"); /* open destination file in write mode */

    if (fptr_o != NULL && fptr_d != NULL)
    {
        printf("Both files have been opened.\n");
        while ((c = fgetc(fptr_o)) != EOF)
        {
            fputc(c, fptr_d);
        }
        fclose(fptr_o);
        fclose(fptr_d);
    }
    else
    {
        printf("Error opening one of the files. Check that both files are created.\n");
    }

    return(0);
}