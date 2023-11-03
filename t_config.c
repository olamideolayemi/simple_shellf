#include "shell.h"

/**
 * init_term - Configures the terminal to operate in non-canonical mode
 * @config: pointer to term_cfg struct
 */
void init_term(terminal_cfg *config)
{
	struct termios new_cfg;

	tcgetattr(STDIN_FILENO, &(config->original));

	new_cfg.c_lflag &= ~ICANON;

	new_cfg.c_lflag &= ~ECHO;

	tcsetattr(STDIN_FILENO, TCSANOW, &new_cfg);
}

/**
 * reset_term_init - Resets the terminal settings to the original settings
 * @config: Pointer to term_cfg struct
 */

void reset_term_init(struct term_cfg *config)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(config->original));
}
