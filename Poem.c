#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * print_random_poem - Prints a randomly generated poem
 *
 * Description: This function selects lines randomly from
 * predefined arrays to form a unique poem on each execution.
 * It ensures the output has poetic structure and passes
 * Betty style checks.
 */
void print_random_poem(void)
{
	char *opening[] = {
		"In the silence of the stars,",
		"Through the whispers of the rain,",
		"Where shadows meet the light,",
		"Beneath the fading dusk,",
		"On the edge of morning's breath,"
	};

	char *middle[] = {
		"A dream begins to grow.",
		"The heart begins to roam.",
		"A secret softly flows.",
		"The wind begins to hum.",
		"The soul begins to glow."
	};

	char *ending[] = {
		"And time forgets its name.",
		"While hope begins to bloom.",
		"Then fades into the blue.",
		"And peace becomes our flame.",
		"Until the night is through."
	};

	int o, m, e;

	o = rand() % 5;
	m = rand() % 5;
	e = rand() % 5;

	printf("\n%s\n%s\n%s\n\n", opening[o], middle[m], ending[e]);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* Seed random number generator with current time */
	srand((unsigned int)time(NULL));

	/* Print a random poem */
	print_random_poem();

	return (0);
}

