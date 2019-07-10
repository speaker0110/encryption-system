#define MAX_KEY_LENGTH 100
#define FILE_PLAINTEXT "plaintext.txt"
#define FILE_CIPHERTEXT "ciphertext.txt"

#include <stdio.h>

int main(void) {
	int i; 
	char key[MAX_KEY_LENGTH + 1];
	printf("��J�K�X�]�̦h %d �Ӧr�^�G", MAX_KEY_LENGTH);
	scanf("%s", key);
	int length = -1;
	for (i = 0; i < MAX_KEY_LENGTH + 1; i++) {
		if (key[i] == '\0') {
			length = i;
			break;
		}
	}
	if (length == -1) {
		printf("�K�X�W�X�d��FQQ!!");
		return -1;
	}
//	printf("password: %s\n", key);

	FILE *plaintext_file;
	plaintext_file = fopen(FILE_PLAINTEXT, "rb");
	if(plaintext_file == NULL) {
		puts("�L�k�}���ɮ�!!!");
		return -1;
	}

	FILE *ciphertext_file;
	ciphertext_file = fopen(FILE_CIPHERTEXT, "wb");
	if(ciphertext_file == NULL) {
		puts("�L�k�s���ɮ�!!!");
		return -1;
	}

	i = 0;
	char plaintext;
	char ciphertext;
	while (1) {
		fscanf(plaintext_file, "%c", &plaintext);
		if (feof(plaintext_file)) {
			break;
		}
		ciphertext = (plaintext + key[i % length]) % 128;
//		printf("%d %c(%x) %c(%x)\n", i, plaintext, plaintext & 0xff, ciphertext, ciphertext & 0xff);
		fprintf(ciphertext_file, "%c", ciphertext);
		i++;
	}

	fclose(plaintext_file);
	fclose(ciphertext_file);
	printf("�����F�U( �X �� �X)~\n");

	return 0;
}
