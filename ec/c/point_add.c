#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "point_add.h"


void point_construct(void *point) {
    
}

void point_add(
    const point_projective_t *a,
    const point_projective_t *b,
    point_projective_t *res
){
    // print out a and b to show that a and b are passed in from rust correctly
    printf("point a:");
    hexDump("x", a->x, 48);
    hexDump("y", a->y, 48);
    hexDump("z", a->z, 48);

    printf("point b:");
    hexDump("x", b->x, 48);
    hexDump("y", b->y, 48);
    hexDump("z", b->z, 48);

    // =================================
    // call FPGA addition function here
    // =================================

    // temporary setup res to show it is passed back to rust correctly
    memset(res->x, 7, 48);
    memset(res->y, 8, 48);
    memset(res->z, 9, 48);

}



// Credit: https://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data
void hexDump(const char *desc, const void *addr, const int len)
{
	int i;
	unsigned char buff[17];
	const unsigned char *pc = (const unsigned char *)addr;

	// Output description if given.
	if (desc != NULL)
		printf("%s:\n", desc);

	if (len == 0)
	{
		printf("  ZERO LENGTH\n");
		return;
	}
	if (len < 0)
	{
		printf("  NEGATIVE LENGTH: %i\n", len);
		return;
	}

	// Process every byte in the data.
	for (i = 0; i < len; i++)
	{
		// Multiple of 16 means new line (with line offset).
		if ((i % 16) == 0)
		{
			// Just don't print ASCII for the zeroth line.
			if (i != 0)
				printf("  %s\n", buff);
			// Output the offset.
			printf("  %04x ", i);
		}

		// Now the hex code for the specific character.
		printf(" %02x", pc[i]);

		// And store a printable ASCII character for later.
		if ((pc[i] < 0x20) || (pc[i] > 0x7e))
			buff[i % 16] = '.';
		else
			buff[i % 16] = pc[i];
		buff[(i % 16) + 1] = '\0';
	}

	// Pad out last line if not exactly 16 characters.
	while ((i % 16) != 0)
	{
		printf("   ");
		i++;
	}

	// And print the final ASCII bit.
	printf("  %s\n", buff);
}