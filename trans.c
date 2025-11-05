#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#define MAX_OUTPUT_SIZE 256
#define MAX_TRANSLIT_BUF (MAX_OUTPUT_SIZE * 3)

char *translit(const wchar_t *in_word) {
    if (setlocale(LC_ALL, "uk_UA.UTF-8") == NULL) {
        fprintf(stderr, "Помилка: не вдалося встановити локаль uk_UA.UTF-8\n");
        return "!NOT_#WORK";
    }
    size_t i = 0;
    static char output_word[MAX_OUTPUT_SIZE]; 
    output_word[0] = L'\0';
    for (int k = 0; in_word[k] != L'\0' && i < MAX_OUTPUT_SIZE - 1; k++) {
        wchar_t c = in_word[k];    
        if (c == L'й') {
            char *trans_j = "j";
            strcat(output_word, trans_j);
        } else if (c == L'ц') {
            char *trans_c = "c";
            strcat(output_word, trans_c);
        } else if (c == L'у') {
            char *trans_u = "u";
            strcat(output_word, trans_u);
        } else if (c == L'к') {
            char *trans_k = "k";
            strcat(output_word, trans_k);
        } else if (c == L'е') {
            char *trans_e = "e";
            strcat(output_word, trans_e);
        } else if (c == L'н') {
            char *trans_n = "n";
            strcat(output_word, trans_n);
        } else if (c == L'г' || c == L'ґ') {
            char *trans_g = "g";
            strcat(output_word, trans_g);
        } else if (c == L'ш') {
            char *trans_sh = "sh";
            strcat(output_word, trans_sh);
        } else if (c == L'щ') {
            char *trans_sh = "sh";
            strcat(output_word, trans_sh);
        } else if (c == L'з') {
            char *trans_z = "z";
            strcat(output_word, trans_z);
        } else if (c == L'х') {
            char *trans_h = "h";
            strcat(output_word, trans_h);
        } else if (c == L'ї') {
            char *trans_yi = "yi";
            strcat(output_word, trans_yi);
        } else if (c == L'ф') {
            char *trans_f = "f";
            strcat(output_word, trans_f);
        } else if (c == L'і') {
            char *trans_i = "i";
            strcat(output_word, trans_i);
        } else if (c == L'в') {
            char *trans_v = "v";
            strcat(output_word, trans_v);
        } else if (c == L'а') {
            char *trans_a = "a";
            strcat(output_word, trans_a);
        } else if (c == L'п') {
            char *trans_p = "p";
            strcat(output_word, trans_p);
        } else if (c == L'р') {
            char *trans_r = "r";
            strcat(output_word, trans_r);
        } else if (c == L'о') {
            char *trans_o = "o";
            strcat(output_word, trans_o);
        } else if (c == L'л') {
            char *trans_l = "l";
            strcat(output_word, trans_l);
        } else if (c == L'д') {
            char *trans_d = "d";
            strcat(output_word, trans_d);
        } else if (c == L'ж') {
            char *trans_zh = "zh";
            strcat(output_word, trans_zh);
        } else if (c == L'є') {
            char *trans_ye = "ye";
            strcat(output_word, trans_ye);
        } else if (c == L'я') {
            char *trans_ya = "ya";
            strcat(output_word, trans_ya);
        } else if (c == L'ч') {
            char *trans_ch = "ch";
            strcat(output_word, trans_ch);
        } else if (c == L'с') {
            char *trans_s = "s";
            strcat(output_word, trans_s);
        } else if (c == L'м') {
            char *trans_m = "m";
            strcat(output_word, trans_m);
        } else if (c == L'и') {
            char *trans_i = "i";
           	strcat(output_word, trans_i);
        } else if (c == L'т') {
            char *transt = "t";
            strcat(output_word, transt);
        } else if (c == L'б') {
            char *trans_b = "b";
            strcat(output_word, trans_b);
        } else if (c == L'ю') {
            char *trans_yu = "yu";
            strcat(output_word, trans_yu);
        } else if (c == L'.') {
            char *trans_point = ";";
            strcat(output_word, trans_point);
        } else if (c == L'ь') {}
        else if (c == L':') {
            char *trans_point = ":";
            strcat(output_word, trans_point);
        }
        else {
			output_word[i++] = c;
			output_word[i] = L'\0';
		}
    }
    strcat(output_word, " ");
    //printf("word: %s\n", output_word);
    return output_word;
}

void translate(FILE *input_file, FILE *output_file) {
	if (setlocale(LC_ALL, "uk_UA.UTF-8") == NULL) {
        fwprintf(stderr, L"Помилка: не вдалося встановити локаль в translate.\n");
        return;
    }

    wchar_t buffer[1024];

    while(fwscanf(input_file, L"%ls", buffer) != EOF) {
        if (wcscmp(buffer, L"взяти") == 0) {
            fprintf(output_file, "#include <");
        } else if (wcscmp(buffer, L"вхід:вихід") == 0) {
            fprintf(output_file, "stdio.h>\n");
        } else if (wcscmp(buffer, L"стандартну:бібліотеку") == 0) {
            fprintf(output_file, "stdlib.h>\n");
        }
         
        else if (wcscmp(buffer, L"числова:функція") == 0) {
            fprintf(output_file, "\nint ");
        } else if (wcscmp(buffer, L"головна") == 0) {
            fprintf(output_file, "main()");
        } else if (wcscmp(buffer, L":") == 0) {
            fprintf(output_file, "\"");
        } else if (wcscmp(buffer, L"строкова:змінна") == 0) {
            fprintf(output_file, "\n\tchar *");
        } else if (wcscmp(buffer, L"(") == 0) {
            fprintf(output_file, "{");
        } else if (wcscmp(buffer, L")") == 0) {
            fprintf(output_file, "\n}\n");
        } else if (wcscmp(buffer, L"=") == 0) {
            fprintf(output_file, " = ");
        } else if (wcscmp(buffer, L".") == 0) {
            fprintf(output_file, ";\n");
        } else if (wcscmp(buffer, L"вивести") == 0) {
            fprintf(output_file, "\n\tprintf");
        } else if (wcscmp(buffer, L"повернути") == 0) {
            fprintf(output_file, "\n\treturn ");
        } else if (wcscmp(buffer, L"числова:змінна") == 0) {
            fprintf(output_file, "\n\tint ");
        } else if (wcscmp(buffer, L":ч") == 0) {
            fprintf(output_file, "%%d");
        } else if (wcscmp(buffer, L":чн") == 0) {
            fprintf(output_file, "%%d\\n");
        } else if (wcscmp(buffer, L":с") == 0) {
            fprintf(output_file, "%%s");
        } else if (wcscmp(buffer, L":сн") == 0) {
            fprintf(output_file, "%%s\\n");
        } else if (wcscmp(buffer, L"1:") == 0) {
            fprintf(output_file, "(");
        } else if (wcscmp(buffer, L":2") == 0) {
            fprintf(output_file, ")");
        } else if (wcscmp(buffer, L"%") == 0) {
            fprintf(output_file, "&");
        } else if (wcscmp(buffer, L"ввести") == 0) {
            fprintf(output_file, "\n\tscanf");
        } else if (wcscmp(buffer, L",") == 0) {
            fprintf(output_file, ",");
        }
		else {
			fprintf(output_file, "%s", translit(buffer));
			//fprintf(output_file, " ");
		}
    }
}

int main (int argc, char *argv[]) {
	//printf("argc: %d\n", argc);
	if (strcmp(argv[1], "--help") == 0) {
    	printf("Аргументи: \n");
    	printf("\tКомпілятори: gcc, tcc;\n");
    	printf("\tПлатформи: linux, windows;\n");
    	return 0;
    } else if (argc != 4) {
        printf("Компілятор не знайдено. Використайте: ./translator <файл> <назва-компілятору> <назва-платформи>\n");
        printf("Для надання більш детальної інформації, напишіть: ./translator --help\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Помилка вхідного файлу!\n");
        return 1;
    }
    FILE *output = fopen("output.c", "w");
    if (output == NULL) {
        perror("Помилка створення вихідного файлу!\n");
        fclose(input);
        return 1;
    }
    translate(input, output);
    fclose(input);fclose(output);
    char compile_command[256];
    if (strcmp(argv[2], "gcc") == 0) {
    	strcpy(compile_command, "gcc output.c -o a.out");
    } else if (strcmp(argv[2], "tcc") == 0) {
    	strcpy(compile_command, "tcc output.c");
    } else {
    	printf("Помилка знаходження компілятору!");
    	return 1;
    }
    system(compile_command);

    if (strcmp(argv[3], "linux") == 0) {
    	//system("rm -rf output.c");
    	system("./a.out");
    } else if (strcmp(argv[3], "windows") == 0) {
    	//system("del output.c");
    	system("output.exe");
    } else {
    	printf("Помилка запуску!");
    	return 1;
    }
	return 0;
}
