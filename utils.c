#include "simpleshell.h"

/**
 * print_prompt - muestra el prompt con el directorio actual
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

/**
 * _strlen - calcula la longitud de una cadena
 * @s: cadena de entrada
 *
 * Return: longitud de la cadena (número de caracteres antes de '\0')
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - copia una cadena de src a dest
 * @dest: buffer destino
 * @src: cadena de origen
 *
 * Return: puntero a dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while ((*ptr++ = *src++) != '\0')
		;

	return (dest);
}

/**
 * _strcat - concatena src al final de dest
 * @dest: cadena destino y resultado
 * @src: cadena a anexar
 *
 * Return: puntero a dest
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
		ptr++;

	while ((*ptr++ = *src++) != '\0')
		;

	return (dest);
}

/**
 * print_random_quote - imprime una frase aleatoria de Jovani Vázquez
 *
 * Usa getpid() y un contador interno para rotar frases sin rand()/time().
 */
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
	size_t idx;

	idx = ((size_t)getpid() + counter) % n;
	counter++;

	printf("\n%s\n\n", quotes[idx]);
}
