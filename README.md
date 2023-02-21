# i3kbar
A personalised i3bar status command executable.

## Table Of Contents
- [Requirements](#requirements)
- [Installing](#installing)
- [ToDo List](#todo-list)

### Requirements
- make (>= 4.4)
- gcc (>= 12.2.1) or any other c compiler and linker
- Any [nerd font](https://github.com/ryanoasis/nerd-fonts)

### Installing
1. Clone the repository.
```sh
git clone https://github.com/arpitchakladar/i3kbar
cd i3kbar
```
2. Build for release
```sh
make config=release
# or for desktop
make config=release mode=desktop
```
3. Move executable to local binaries
```sh
mv build/a.out ~/.local/bin/i3kbar
```
4. Add the status command to your i3 config (~/.config/i3/config)
```
bar {
	status_command ~/.local/bin/i3kbar
}
```

### ToDo List
- Add mode items to the bar
	- volume
	- active process count
- fix the way internet status is determied
