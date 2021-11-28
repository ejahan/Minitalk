◦ write
◦ ft_printf et tout équivalent que VOUS avez codé
🔶 signal <3
◦ sigemptyset
◦ sigaddset
◦ sigaction
🔶 kill <3
🔶 getpid <3
🔶 malloc <3
🔶 free <3
◦ pause
◦ sleep
🔶 usleep <3
🔶 exit <3


int kill(pid_t pid, int sig);
envoie signal au pid

int signal(int sig, void (*func)(int))
recoie signal + fait fonction 

SIGUSR1 -> 1
SIGUSR2 -> 0
