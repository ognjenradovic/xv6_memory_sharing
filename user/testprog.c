#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{	

	int *a=5551251;
	int *b=556;
	int *c=521512512;

	


	printf("Vracena vrednost je: %d \n\n",sharemem("Ime jedan",&a,sizeof(a)));
	printf("Vracena vrednost je: %d \n\n",	sharemem("Ime dva",&b,sizeof(b)));
	printf("Vracena vrednost je: %d \n\n",	sharemem("Ime dva",&c,sizeof(c)));
	int pid, wpid;
	if(getpid() > 3){
		fprintf(2, "BLOCK\n");
		exit();
	}
		for(int i=0;i<1;i++){
			pid = fork();
			if(pid < 0){
				printf("testprog: fork failed\n");
				exit();
			}
			if(pid == 0){
				int *a2;
				get_shared("Ime jedan",&a2);
				printf("a2 je %d\n",a2);

				exec("/bin/testprog", argv);
				printf("init: exec sh failed\n");
				exit();
					exit();
			}
			while((wpid=wait()) >= 0 && wpid != pid)
				printf("zombie!\n");
		}
	exit();
}
