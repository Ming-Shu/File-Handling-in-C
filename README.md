# File-Handling-in-C
C Programming simple examples on file handling

File handle:
----------------------------------------------------------------

Data.txt:

              Record 0~4.data binary file of context.

read_binary.c:

              Read 0~4.data any a binary file.

decode.c:

              Read All XXX.data binary file,and count total value.
              
Practice:
------------------------------------------------------------------
fakefile.c:

            pack a file in to another

unfakefile.c:

            unpack fake file


Point function:

FILE *fopen(const char *path, const char *mode);

The second argument is the mode can be :

‘r’  : Open text file for reading.

‘r+’ : Open for reading and writing. 

‘w’  : Truncate file to 'zero length'(empty data) or create text file for writing.

‘w+’ : Open for reading and writing. The file is created if it does not exist, otherwise it is truncated.

‘a’  : Open for appending (writing at end of file). 

‘a+’ : Open for reading and appending (writing at end of file).
