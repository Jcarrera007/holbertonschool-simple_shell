#include "simpleshell.h"

/**
 * print_prompt - Muestra el prompt con el directorio actual
 *
 * Usa getcwd(), printf(), perror(), fflush().
 */
void print_prompt(void)
{
    char cwd[BUFFER_SIZE];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s JV ", cwd);
    else
        perror("print_prompt: getcwd");

    fflush(stdout);
}

size_t _strlen(const char *s)
{
    size_t len = 0;
    while (s && s[len])
        len++;
    return len;
}

char *_strcpy(char *dest, const char *src)
{
    char *start = dest;
    while ((*dest++ = *src++));
    return start;
}

char *_strcat(char *dest, const char *src)
{
    char *start = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return start;
}

void print_random_quote(void)
{
    static const char *quotes[] = {
        "“Quiero café… ¡dame café!” —Jovani Vázquez",
        "“¡Toma mango!” —Jovani Vázquez",
        "“Quisiera ser una mosca, para pararme en tu piel y relamerla.” —Jovani Vázquez",
        "“Yo no voy a estar perdiendo mi tiempo. Conmigo no estén jugando, mucho menos con mi tiempo. Yo soy una persona seria.” —Jovani Vázquez",
        "“¡7 veces me caigo 15,000 me levanto!” —Jovani Vázquez",
        "“Dios no te dejará en vergüenza.” —Jovani Vázquez"
    };
    size_t n = sizeof(quotes) / sizeof(quotes[0]);
    static size_t counter = 0;
    /* Índice “aleatorio”: base en PID + contador */
    size_t idx = ((size_t)getpid() + counter) % n;
    counter++;
    printf("\n %s\n\n", quotes[idx]);
}
