#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
	DIR *dir;
	struct dirent *ent;
	long blockDevice = 0;
	long characterDevice = 0;
	long directory = 0;
	long namedPipe = 0;
	long symbolicLink = 0;
	long regularFile = 0;
	long domainSocket = 0;
	long unknown = 0;

	dir = opendir(argv[1]);

	while((ent = readdir(dir)))
	{

		if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) 
			continue;

		if(ent->d_type == DT_BLK)
			blockDevice++;

		if(ent->d_type == DT_CHR)
			characterDevice++;

		if(ent->d_type == DT_DIR)
			directory++;

		if(ent->d_type == DT_FIFO)
			namedPipe++;

		if(ent->d_type == DT_LNK)
			symbolicLink++;

		if(ent->d_type == DT_REG)
			regularFile++;

		if(ent->d_type == DT_SOCK)
			domainSocket++;

		if(ent->d_type == DT_UNKNOWN)
			unknown++;
	}

	closedir(dir);

	printf("File stats\n");
	printf("%s - %ld\n", "Block device", blockDevice);
	printf("%s - %ld\n", "Character device", characterDevice);
	printf("%s - %ld\n", "Directory", directory);
	printf("%s - %ld\n", "Named pipe", namedPipe);
	printf("%s - %ld\n", "Symbolic link", symbolicLink);
	printf("%s - %ld\n", "Regular file", regularFile);
	printf("%s - %ld\n", "Domain socket", domainSocket);
	printf("%s - %ld\n", "Unknown", unknown);

	return 0;
}