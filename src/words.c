#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **word;
static int index_str = 0;
static int size = 0;

void init_words ( ) {
	char path[255];
	snprintf ( path, 255, "assets/language/en.lng" );
	FILE *fp = fopen ( path, "r" );

	char *line = calloc ( 4096, 1 );

	while ( fgets ( line, 4096, fp ) ) {
		size++;
		word = realloc ( word, sizeof ( char * ) * size );
		char *s = strchr ( line, '\n' );
		if ( s ) *s = 0;
		int length = strlen ( line );
		word[index_str] = calloc ( length + 1, 1 );
		strncpy ( word[index_str], line, length );
		index_str++;
	}
	
	fclose ( fp );
	free ( line );
}
