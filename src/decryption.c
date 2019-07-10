#define MAX_KEY_LENGTH 100
#define FILE_PLAINTEXT "plaintext-recovered.txt"
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
		printf("�X�W�X�d��FQQ!!");
		return -1;
	}
//	printf("password: %s\n", key);

	FILE *ciphertext_file;
	ciphertext_file = fopen(FILE_CIPHERTEXT, "rb");
	if(ciphertext_file == NULL) {
		puts("�k�}���ɮ�!!!");
		return -1;
	}

	FILE *plaintext_file;
	plaintext_file = fopen(FILE_PLAINTEXT, "wb");
	if(plaintext_file == NULL) {
		puts("�L�k�s���ɮ�!!!");
		return -1;
	}
	
	i = 0;
	char plaintext;
	char ciphertext;
	while (1) {
		fscanf(ciphertext_file, "%c", &ciphertext);
		if (feof(ciphertext_file)) {
			break;
		}
		plaintext = (ciphertext + 128 - key[i % length]) % 128;
		//printf("%d %c(%x) %c\n", i, ciphertext, ciphertext & 0xff, plaintext);
		fprintf(plaintext_file, "%c", plaintext);
		i++;
	}

	fclose(ciphertext_file);
	fclose(plaintext_file);
	printf("�����F��(�١���)~\n");

	return 0;
}
