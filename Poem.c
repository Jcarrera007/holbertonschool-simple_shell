#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * print_random_poem - Prints a randomly generated poem
 * 
 * Description: This function selects lines randomly from
 * predefined arrays to form a unique poem on each execution.
 * The enhanced version includes more lines, themes, and poetic structures.
 */
void print_random_poem(void)
{
    char *opening[] = {
        "In the silence of the stars,",
        "Through the whispers of the rain,",
        "Where shadows meet the light,",
        "Beneath the fading dusk,",
        "On the edge of morning's breath,",
        "When autumn leaves confess,",
        "Between the lines of fate,",
        "As twilight paints the sky,",
        "Within the ocean's sigh,",
        "Beyond the reach of time,",
        "Where forgotten rivers flow,",
        "Under the moon's pale gaze,",
        "When winter speaks in frost,",
        "Along the spider's thread,",
        "Inside a fleeting thought,"
    };

    char *middle[] = {
        "a dream begins to grow,",
        "the heart begins to roam,",
        "a secret softly flows,",
        "the wind begins to hum,",
        "the soul begins to glow,",
        "memories dance unseen,",
        "time folds upon itself,",
        "silence finds its voice,",
        "shadows learn to fly,",
        "loneliness blooms,",
        "the earth remembers,",
        "all promises dissolve,",
        "light becomes liquid,",
        "the universe pauses,",
        "fear turns to dust,"
    };

    char *ending[] = {
        "and time forgets its name.",
        "while hope begins to bloom.",
        "then fades into the blue.",
        "and peace becomes our flame.",
        "until the night is through.",
        "as eternity watches.",
        "leaving only echoes.",
        "in a language without words.",
        "like a prayer in the wind.",
        "against the canvas of forever.",
        "with the weight of feathers.",
        "between one breath and the next.",
        "where all journeys converge.",
        "as the cosmos exhales.",
        "in the space between stars."
    };

    char *titles[] = {
        "Ephemeral", "Whispers", "Fugue", "Lumen", "Chiaroscuro",
        "Sonder", "Evanescent", "Petrichor", "Liminal", "Ophelia",
        "Sonnet for the Void", "Ode to Transience", "Elegy for Icarus"
    };

    int o, m, e, t;
    int lines = sizeof(opening) / sizeof(opening[0]);

    o = rand() % lines;
    m = rand() % lines;
    e = rand() % lines;
    t = rand() % (sizeof(titles) / sizeof(titles[0]));

    printf("\n%s\n\n%s\n%s\n%s\n\n", titles[t], opening[o], middle[m], ending[e]);
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
