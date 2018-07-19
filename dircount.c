#include <dirent.h>
#include <stdio.h>
#include <string.h>

int count_files(const char*name);

int main(int argc, char* argv[])
{
	if (argc == 1) {
		printf("%d\n", count_files("."));
	}
	for (int i = 1; i < argc; ++i) {
		printf("%d\n", count_files(argv[i]));
	}
}

int count_files(const char*name)
{
	DIR* dir = opendir(name);
	int amount = 0;
	struct dirent* entry;
	while (entry = readdir(dir)) {
		if (strcmp(entry->d_name, ".") == 0) continue;
		if (strcmp(entry->d_name, "..") == 0) continue;
		++amount;
	}
	return amount;
}
