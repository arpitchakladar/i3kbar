#include <stdio.h>
#include <unistd.h>

#include "username.h"
#include "block.h"

void show_username() {
	char username[32];
	getlogin_r(username, 32);
	create_text_block("username", "", username, "#689d6a");
}
