#include <stdio.h>
#include <unistd.h>

#include "username.h"
#include "block.h"

void show_username() {
	create_text_block("username", "", getlogin(), "#689d6a");
}
