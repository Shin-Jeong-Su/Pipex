#include "pipex_bonus.h"
int main(){
	int p_fd[2];
	pid_t pid;
	pipe(p_fd);
	pid = fork();
	if(pid == 0){
		printf("I'm child\n");
	}
	else{
		int status;
		waitpid(pid,&status,0);
		if (WIFEXITED(status))
			printf("%d\n",WEXITSTATUS(status));
	}
}