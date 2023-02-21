#include <stdio.h>
#include <unistd.h>

#include "username.h"
#include "block.h"
#include "color.h"

static char _username[32];
static char* _user_icons[] = { "", "" };
static char* _user_icon;

void initialize_username() {
	getlogin_r(_username, 32);
	if (getuid()) {
		_user_icon = _user_icons[0];
	} else {
		_user_icon = _user_icons[1];
	}
}

void show_username() {
	create_text_block("username", _user_icon, _username, DarkGreen);
}
