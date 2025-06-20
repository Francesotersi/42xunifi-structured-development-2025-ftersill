#include "password_validator.h"

int	ft_strlen(const char *str)
{
	int	i = 0;

	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int	has_character(const char *str, char *to_check)
{
	int		i = 0;
	int 	j = 0;
	bool	checker = false;

	while (to_check[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == to_check[i])
			{
				checker = true;
				break ;
			}
			j++;
		}
		if (checker == true)
			break ;
		i++;
	}
	if (checker == true)
		return (0);
	return (1);
}

int ft_strcmp(const char *s1, const char *s2) 
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
	if (!new_pw)
		return (INVALID);
	if (ft_strlen(new_pw) < 8)
		return (INVALID);
	if (has_character(new_pw, "abcdefghijklmnopqrstuvwxyz") == 1)
		return (INVALID);
	if (has_character(new_pw, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 1)
		return (INVALID);
	if (has_character(new_pw, "@#$%^&*") == 1)
		return (INVALID);
	if (has_character(new_pw, "1234567890") == 1)
		return (INVALID);
	if (ft_strcmp(new_pw, (char *)curr_pw) == 0)
		return (INVALID);
	return (VALID);
}

// int main() {
//     const char *current_password = "OldSecure@123";  // Password corrente

//     // Array di test cases: { nuova_password, risultato_atteso }
//     struct TestCase {
//         const char *new_pw;
//         PwStatus expected;
//     } test_cases[] = {
//         {"Secur3P@ss", VALID},             // Valida
//         {"caccA3P@ss", VALID},                // Troppo corta
//         {"noupper1@", INVALID},            // Nessun maiuscolo
//         {"NOLOWER1@", INVALID},            // Nessun minuscolo
//         {"NoSpecial1", INVALID},           // Nessun carattere speciale
//         {"OldSecure@123", INVALID},        // Uguale alla corrente
//         {"", INVALID},                     // Stringa vuota
//         {NULL, INVALID},                   // NULL
//         {"12345678", INVALID},             // Solo numeri
//         {"ABCdefgh", INVALID},             // Nessun numero o speciale
//         {"ABCdefg@", INVALID},             // Manca numero
//         {"abc123@#", INVALID},             // Manca maiuscolo
//     };

//     int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

//     for (int i = 0; i < num_tests; i++) {
//         PwStatus result = validate_password(test_cases[i].new_pw, current_password);
//         const char *status_str = (result == VALID) ? "VALID" : "INVALID";
//         const char *color = (result == test_cases[i].expected) ? "\033[0;32m" : "\033[0;31m";  // Verde se corretto, rosso se errato

//         printf("Test %d: %sPassword: '%s'\033[0m -> Risultato: %s (%s)\n",
//                i + 1,
//                color,
//                test_cases[i].new_pw ? test_cases[i].new_pw : "NULL",
//                status_str,
//                (result == test_cases[i].expected) ? "✅ PASS" : "❌ FAIL");
//     }

//     return 0;
// }
