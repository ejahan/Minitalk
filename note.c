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

8 signaux a envoyer

8 signaux a recevoir 
quand 8 signaux ont ete recus et stockes dans str -> convert to ascii

put ascii dans buffer


http://www.gecif.net/qcm/information/table_de_conversion.pdf


client  ->  *   prend pid de server (lance avant)
				et la chaine de caractere a passer
			*	pour chaque caractere : passe son int en binaire
				envoie chaque 0 ou 1 un par un 
			*	sleep(100)

server  ->  *	tourne en boucle (while (1) -> pause())
			*	quand recoit signal 1 -> recup 1
			*	quand recoit signal 2 -> recup 2
			*	tous les 8 -> 
