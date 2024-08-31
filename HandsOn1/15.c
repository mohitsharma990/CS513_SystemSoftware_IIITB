//Write a program to display the environmental variable of the user (use environ)

//Name : Mohit Sharma
//Roll no : MT2024091

//Environment variables are key-value pairs that provide information to the processes 
//running in the operating system, such as PATH, HOME, USER, etc.

#include <stdio.h> // import printf and NULL defination 

int main(int argc, char *argv[], char *envp[]) { // envp[]: An array of strings (character pointers) containing the environment variables. This array is terminated by a NULL pointer.
  
  for(int i=0; envp[i] != NULL; i++) {
    printf("%s\n", envp[i]);
  }
  
  return 0;
}

//command line : ./a.out
/* output : 
TERM_SESSION_ID=w0t0p0:A1E877AC-ED18-4477-B434-A581AA849CA0
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.qzGglH49ui/Listeners
LC_TERMINAL_VERSION=3.5.4
COLORFGBG=15;0
ITERM_PROFILE=Default
XPC_FLAGS=0x0
LANG=en_GB.UTF-8
PWD=/Users/mohitsharma/IIIT Bangalore/Semesters_Info/Sem_1/Software_systems/CS513_SystemSoftware_IIITB/HandsOn1
SHELL=/bin/zsh
__CFBundleIdentifier=com.googlecode.iterm2
TERM_FEATURES=T3LrMSc7UUw9Ts3BFGsSyHNoSxF
TERM_PROGRAM_VERSION=3.5.4
TERM_PROGRAM=iTerm.app
PATH=/Library/Frameworks/Python.framework/Versions/3.11/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/mysql/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Library/Apple/usr/bin:/Library/TeX/texbin:/Applications/iTerm.app/Contents/Resources/utilities
LC_TERMINAL=iTerm2
COLORTERM=truecolor
COMMAND_MODE=unix2003
TERM=xterm-256color
TERMINFO_DIRS=/Applications/iTerm.app/Contents/Resources/terminfo:/usr/share/terminfo
HOME=/Users/mohitsharma
TMPDIR=/var/folders/79/gnvpyv_j61q0zv_8d58pg9lw0000gn/T/
USER=mohitsharma
XPC_SERVICE_NAME=0
LOGNAME=mohitsharma
ITERM_SESSION_ID=w0t0p0:A1E877AC-ED18-4477-B434-A581AA849CA0
__CF_USER_TEXT_ENCODING=0x0:0:0
SHLVL=1
OLDPWD=/Users/mohitsharma/IIIT Bangalore/Semesters_Info/Sem_1/Software_systems/CS513_SystemSoftware_IIITB
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:
P9K_TTY=old
_P9K_TTY=/dev/ttys000
ZSH=/Users/mohitsharma/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
LS_COLORS=di=1;36:ln=35:so=32:pi=33:ex=31:bd=34;46:cd=34;43:su=30;41:sg=30;46:tw=30;42:ow=30;43
P9K_SSH=0
_P9K_SSH_TTY=/dev/ttys000
_=/Users/mohitsharma/IIIT Bangalore/Semesters_Info/Sem_1/Software_systems/CS513_SystemSoftware_IIITB/HandsOn1/./a.out
*/
