#ifndef CIO_H
#define CIO_H

#include <stdio.h>

typedef struct BufferData BufferData;

/**
 * Get the size of a file in bytes.
 *
 * @param FILE* fp
 *
 * @return int
 */
size_t IOGetFileSize(FILE* fp);

/**
 * Read the contents of a file and store it in a character array.
 *
 * @param const char* file    The name of the file to be read.
 *
 * @return const char*
 */
const char* IOReadFile(const char* file);

/**
 * Read the contents of a file into BufferData struct.
 *
 * Data must be freed when nolonger needed.
 *
 * @param const char* file    The name of the file to be read.
 *
 * @return BufferData*
 */
struct BufferData* IOReadFileIntoBuffer(const char* file);

/**
 * Free all of the memory associated with the buffer.
 *
 * @param struct BufferData* buffer.
 *
 * @return void
 */
void IODestroyBufferData(struct BufferData* buffer);


#endif // !LDH_CIO_H
