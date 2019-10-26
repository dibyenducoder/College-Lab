/*Program to copy a file to a new file where all small letters are converted to capital letters and vice versa.*/

#include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main() {
        int ch;
        FILE *fp1, *fp2;
        char file1[MAX], file2[MAX];

        /* get the file1 file name from the user */
        printf("Enter your source file name:");
        fgets(file1, MAX, stdin);
        file1[strlen(file1) - 1] = '\0';

        /* get the destination file name from the user */
        printf("Enter your destination file name:");
        fgets(file2, MAX, stdin);
        file2[strlen(file2) - 1] = '\0';

        /* open the first file in read mode */
        fp1 = fopen(file1, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open the file %s\n", file1);
                return 0;
        }

        /* open the destination file in write mode */
        fp2 = fopen(file2, "w");

        /* error handling */
        if (!fp2) {
                printf("Unable to open the file %s\n", file2);
                fclose(fp1);
                return 0;
        }

        /* coverts Uppercase to lowercase and vice versa */
        while (!feof(fp1)) {
                ch = fgetc(fp1);

                if (ch == EOF) {
                        continue;
                } else if (ch >= 'A' && ch <= 'Z') {
                        fputc((ch - 'A' + 'a'), fp2);
                } else if (ch >= 'a' && ch <= 'z') {
                        fputc((ch - 'a' + 'A'), fp2);
                } else {
                        fputc(ch, fp2);
                }
        }

        /* close the opened files */
        fclose(fp1);
        fclose(fp2);

        return 0;
  }
