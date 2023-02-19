#include <stdio.h>
#include <unistd.h>

#include "username.h"
#include "block.h"

static char _username[32];

void initialize_username() {
	getlogin_r(_username, 32);
}

void show_username() {
	create_text_block("username", "", _username, "#689d6a");
}
