#include "UI.h"


UI::UI()
{
	SetConsoleTitle("�p�ǥͪ���ơI");

	//TODO Check Command Prompt Window Size
	//Init nameChars
	chars = { "�s", "��", "�j", "��", "��", "��", "�d", "�˰h",
		"��", "��", "�t", "��", "��", "�R", "�q", "�M��",
		"��", "ı", "�i", "�l", "��", "�Q", "��", "�n�F" };
	twoLinesInDialog = false;
	showBearsinDialog = false;
}

UI::~UI()
{


}

void UI::init()
{
	gotoxy(0, 0);
	println("         ��_______��                                                           �@");
	println("        |�� �_ �_�� ��@�@�@�@�@�@�@|              __�@__|__��__          |        ");
	println("       �A  (��)(��) ��@�@�@�@�@�@�U�@�@�@�@�@�@��    ____    ��    ���@�@|       ");
	println("      |  �] �ġ��� �^��           �U                    ��        ��____|____     ");
	print("�ġġġס@   �U��U ?          ");
	print("���U�@", 14);
	println("                  �U       ��     | ");
	print("    �ġġ�    �@ ��  �@        ");
	print("�� �U  �@", 10);
	print("            ____�U____       ____|____");
	print("         ���p�ǥ� ���]�]       ");
	print("��   �U   �@", 10);
	println("              �U               | ");
	println("      ��       ��          ��    �U     �@            �U               |         ");
	println("(��) /      __��                 �U                 �@�U           ____|____   ");
	println("   �]�ġ�                        �U                                              ");
	println("    �U �� �@ �b               �@ �U                                              ");
	println("     ��    ))                  �@�U                                             ");
	print("                                      �@�@�@�@�֢֡ޢ�Ӣ��@���Ϣ��ա�\n", 13);
	println("");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                                                ");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@���@�@                                                ");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@���@�@           |                                   ");
	println("�@�@�@�@�@�ġġU�ġġ@�@�@�ġġġġġġ@�@�@�@�@�@���@�@�@�@�@�@�ġġġġġġ@�@�@�@�@�@�@�@                                                ");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@���@�@�@�@�@�@�@                                                ");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@���@�@�@�@�@�@�@�@      |                                         ");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@���@�@�@�@�@�@�@�@�@                                                ");
	println("�@�@�@�@�@�@�@�U�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                                                ");
	getchar();
}

void UI::showDialog(std::string name, std::string text)
{
	if (showBearsinDialog == false)
	{
		clearScreen();
	}
#if _DEBUG
	if (text.size() == 0 || name.size() == 0)
	{
		print("[ĵ�i]�o��O���O�֥��F����H�S���r�C�H", 0, 0);
	}
#endif
	if (text.size() > 70)
	{
		text.resize(70);
#if _DEBUG
		print("[ĵ�i]�r�Ӧh�F�C�ХΤ��檩���Ϊ̤����⦸��ܡC", 0, 0);
#endif
	}
	drawFrame(0, 15, 78, 7);
	print(name, 3, 16);
	print("�G");
	print(text, 5, 18);
	if (twoLinesInDialog == false)
	{
		getchar();
	}
}

void UI::showDialog(std::string name, std::string text, std::string text0)
{
	twoLinesInDialog = true;
	showDialog(name, text);
#if _DEBUG
	if (text0.size() == 0)
	{
		print("[ĵ�i]�o��O���O�֥��F����H�S���r�C�H", 0, 0);
	}
#endif
	if (text0.size() > 70)
	{
		text0.resize(70);
#if _DEBUG
		print("[ĵ�i]�r�Ӧh�F�C", 0, 0);
#endif
	}
	print(text0, 5, 19);
	getchar();
	twoLinesInDialog = false;
}

void UI::drawFrame(int lux, int luy, int length, int height)
{
	//������������ 
	getxy();
	print("�~", lux, luy);
	print("��", lux + length, luy);
	print("��", lux, luy + height);
	print("��", lux + length, luy + height);
	for (int i = 1; i < (length - 1); i += 2)
		print("�w", (lux + i + 1), luy);
	for (int i = 1; i < (length - 1); i += 2)
		print("�w", (lux + i + 1), luy + height);
	for (int i = 1; i < height; i++)
		print("�x", lux, (luy + i));
	for (int i = 1; i < height; i++)
		print("�x", lux + length, (luy + i));
	undoxy();
}


void UI::chooseNamae()
{
	clearScreen();
	drawFrame(8, 1, 60, 2);
	gotoxy(11, 2);
	print("�A�s����W�r�H", 15);
	drawFrame(25, 4, 24, 4);
	print("�Z�Z�Z�Z", 34, 6);
	drawFrame(10, 10, 56, 11);

	print("�@�@�s�@�@���@�@�j�@�@��@�@�š@�@��@�@�d�@�@�˰h", 12, 12);
	print("�@�@�ѡ@�@�ơ@�@�t�@�@�¡@�@�ơ@�@�R�@�@�q�@�@�M��", 12, 15);
	print("�@�@���@�@ı�@�@�i�@�@�l�@�@��@�@�Q�@�@���@�@�n�F", 12, 18);

	int blockCount = 0;

	gotoxy(16, 12);
	print(chars[blockCount], 12);
	gotoxy(16, 12);

	unsigned char tobreak = false;
	while (1)
	{
		if (tobreak)
			break;
		tobreak = false;
		while (!_kbhit())
			;
		int firstinput = _getch();//Arrow Key get two input
		if (firstinput == 224)
		{
			char arrKey = _getch();
			getxy();
			switch (arrKey)
			{
			case 72://GOING UP
				if (blockCount > 7)
				{
					print(chars[blockCount], 15);
					gotoxy(nowx, nowy - 3);
					blockCount = blockCount - 8;
					print(chars[blockCount], 12);
					gotoxy(nowx, nowy - 3);
				}
				else
				{
					print(chars[blockCount], 15);
					gotoxy(nowx, nowy + 6);
					blockCount = blockCount + 16;
					print(chars[blockCount], 12);
					gotoxy(nowx, nowy + 6);

				}
				break;
			case 80://GOING DOWN
				if (blockCount < 16)
				{
					print(chars[blockCount], 15);
					gotoxy(nowx, nowy + 3);
					blockCount = blockCount + 8;
					print(chars[blockCount], 12);
					gotoxy(nowx, nowy + 3);
				}
				else
				{
					print(chars[blockCount], 15);
					gotoxy(nowx, nowy - 6);
					blockCount = blockCount - 16;
					print(chars[blockCount], 12);
					gotoxy(nowx, nowy - 6);

				}
				break;
			case 75://GOING LEFT
				if ((blockCount % 8) > 0)
				{
					print(chars[blockCount], 15);
					gotoxy(nowx - 6, nowy);
					blockCount = blockCount - 1;
					print(chars[blockCount], 12);
					gotoxy(nowx - 6, nowy);
				}
				else
				{
					if (blockCount > 7)
					{
						print(chars[blockCount], 15);
						gotoxy(58, nowy - 3);
						blockCount = blockCount - 1;
						print(chars[blockCount], 12);
						gotoxy(58, nowy - 3);
					}
					else
					{
						print(chars[blockCount], 15);
						gotoxy(nowx + 42, nowy + 6);
						blockCount = 23;
						print(chars[blockCount], 12);
						gotoxy(nowx + 42, nowy + 6);

					}
				}

				break;
			case 77://GOING RIGHT
				if ((blockCount % 8) < 7)
				{
					print(chars[blockCount], 15);
					gotoxy(nowx + 6, nowy);
					blockCount = blockCount + 1;
					print(chars[blockCount], 12);
					gotoxy(nowx + 6, nowy);
				}
				else
				{
					if (blockCount < 16)
					{
						print(chars[blockCount], 15);
						gotoxy(16, nowy + 3);
						blockCount = blockCount + 1;
						print(chars[blockCount], 12);
						gotoxy(16, nowy + 3);
					}
					else
					{
						print(chars[blockCount], 15);
						gotoxy(nowx - 42, nowy - 6);
						blockCount = 0;
						print(chars[blockCount], 12);
						gotoxy(nowx - 42, nowy - 6);

					}
				}
				break;
			}
		}
		else
		{
#if _DEBUG
			getxy();
			print("     ", 10, 0);
			print(std::to_string(firstinput), 10, 0);
			undoxy();
#endif
			if (firstinput == 13)
			{
				switch (blockCount)
				{
				case 7:
					if (name.size() > 1)
					{
						name.resize(name.size() - 2);
						getxy();
						print("�Z", 34 + name.size(), 6);
						undoxy();
					}
					break;
				case 15:
					name.resize(0);
					getxy();
					print("�Z�Z�Z�Z", 34, 6);
					undoxy();
					break;
				case 23:
					if (name.size() == 0)
					{
						print(chars[chars.size() - 1]);
						print("�٨S���W�r�O�C�n�n�a���@�U�a�H", 11, 2);
						blockCount = 0;
						gotoxy(16, 12);
						print(chars[blockCount], 12);
						gotoxy(16, 12);
						break;
					}

					clearScreen();
					tobreak = true;
					break;
				default:
					if (name.size() < 8)
					{
						name += chars[blockCount];
						getxy();
						print(name, 34, 6);
						undoxy();
					}
					else
					{
						getxy();
						print("�A�����|���|�ӳg�߰աH�@�@�@�@�@�@�@", 11, 2);
						undoxy();
					}

					break;
				}

#if _DEBUG
				getxy();
				print("�@�@�@�@�@", 0, 0);
				print("�@�@�@�@�@", 20, 0);
				print(name, 20, 0);
				undoxy();
#endif
			}
			if (firstinput == 8)
			{
				if (name.size() > 1)
				{
					name.resize(name.size() - 2);
					getxy();
					print("�Z", 34 + name.size(), 6);
					undoxy();
				}

			}
		}

#if _DEBUG
		getxy();
		print("�@�@", 0, 0);
		print(std::to_string(blockCount), 0, 0);
		undoxy();
#endif
	}
}

void UI::print(std::string in)
{
	//�s�o�@�p�@�s�@�t���@���@���@���@���@�����@�� �DUnicode�i��
	std::cout << in;
}

void UI::print(std::string in, int color)
{
	//Color Reference http://kowala21.blogspot.tw/2012/01/dev-c-console.html
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << in;
	SetConsoleTextAttribute(hConsole, 15); //�٭즨�©��զr
}

void UI::print(std::string in, int x, int y)
{
	gotoxy(x, y);
	std::cout << in;
}

void UI::print(std::string in, int x, int y, int color)
{
	gotoxy(x, y);
	print(in, color);
}

void UI::println(std::string in)
{
	if (in.size() > 78)
		in.resize(78);
	std::cout << in << std::endl;
}

void UI::gotoxy(int x, int y)
{
	COORD point;
	point.X = x, point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void UI::clearScreen()
{
	//http://edisonx.pixnet.net/blog/post/37742661-%5Bw%5D-console-%E8%A6%96%E7%AA%97%E6%8E%A7%E5%88%B6
	//TODO [UNTEST PART]
	/*gotoxy(0, 0);
	for (int i = 0; i < 2000; i++)
	print(" ");
	gotoxy(0, 0);*/ //�C�į�@�{�{

	//���į�C�{�{ �i�ۭq�ʤ���?
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '),
		dwConSize,
		coordScreen,
		&cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole,
		csbi.wAttributes,
		dwConSize,
		coordScreen,
		&cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);

}

void UI::getxy()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	nowx = csbi.dwCursorPosition.X;
	nowy = csbi.dwCursorPosition.Y;
}

std::string UI::getName()
{
	return name;
}

void UI::printBear(int bear, bool place)
{
	clearScreen();
	getxy();
	switch (place)
	{
	case true:
		gotoxy(3, 3);
		break;
	case false:
		gotoxy(40, 3);
		break;
	}
	switch (bear)
	{
	case 0:
		println("�@�@       �@�@�@  ��ġġġġġ�@");
		println("�@�@       �@�@�@ �U�@�s �@�s���@��@");
		println("�@�@  �@�@�@�@�@�@���]�ݡ^�]�ݡ^�@��U�@");
		println("�@  �@�@�@�@�@�@�@�U�@�]�Ģ��ġ^�ס@�U�@�@");
		println("�@�@�@�@�ġġġġġס@�@�U��U���@�@�@�U�[�o�@");
		println("�@�@�@�@�@�ġġġġġ@�@�@�@�@�@�@�@�U�@�@��");
		println("�@�@�@�@�@�@�@�@�@���@�@�@�@���]�]�]�U�ġ�");
		println("�@�@�@�@�@�@�@�@���@�@�@�@���@�@�@�@�U");
		println("�]�������^�@���@�@�@�ġ��@�@�@�@�@�U");
		println("�@�@�@�@�@�@�]�ġ@�@�@���@�@�@�@�@�@�U");
		println("�@�@�@�@�@�@�U���@�@�@�b�@�@�@�@�@�@�U");
		println("�@�@�@�@�@�@��@�@�@�^�^");
		break;
	case 1:
		println("�@�@�@��ġġġġ�@");
		println("�@�@��s �@�@�s���U");
		println("�@��@�֡@�]�ݡ^�@��");
		println("�ס@�]�Ģ��ġ^�@�@�U");
		println("�@�@�@�U��U�@�@�@�סġġġġ��@");
		println("�@�@���@�@�@�@�@�@�ġġġġġġĢ@");
		println("�@���@���@�@�@�@�@�@");
		println("�^�@���@�@�@�@�@�@�@�@");
		println("    �@�@�@�@�@�@�@�@�@�@");
		println("�@�@�@�@�@�@�@�@�@�@�@�ġ^�@�]�����e�A�@�ӧk�I�^");
		println("�@�@�@�@�@�@�a�@���@�@�U");
		println("�@�@�@�@�@�@�]�]�@�@�@��");
		break;
	case 2:

		break;
	case 3:
		println("�@�@�@��ġġġġ�");
		println("�@�@��s �@�@�s���U");
		println("�@��]���^�]���^�@");
		println("�ס@�]�Ģ��ġ^�@�U");
		println("�@�@�@�U��U�@�@��");
		println("�@�@���@�@�@�@�]������B�@�������@�B�����@����@����I�@�����@����@�������I�^");
		break;
	default:
#if _DEBUG
		print("[���~]�W�X�i��ܪ���!", 0, 0);
#endif
		break;
	}
	undoxy();
}


void UI::showDialog(std::string name, std::string text, int bear0, bool place0, int bear1, bool place1)
{
	showBearsinDialog = true;
	printBear(bear0, place0);
	printBear(bear1, place1);
	showDialog(name,text);
	showBearsinDialog = false;
}
void UI::showDialog(std::string name, std::string text, std::string text0, int bear0, bool place0, int bear1, bool place1)
{
	showBearsinDialog = true;
	printBear(bear0, place0);
	printBear(bear1, place1);
	showDialog(name, text, text0);
	showBearsinDialog = false;
}

void UI::dead()
{
	clearScreen();
	getxy();
	print("�ӱѤD�L�a�`�Ƥ]", 33, 11);
	print("�j�L�Э��s�ӹL�a", 33, 13);
	undoxy();
	getchar();
}

void UI::dontB()
{
	clearScreen();
	getxy();
	print("���˹G�A�˹G�D�p�A", 32, 12);
	undoxy();
	getchar();

}

void UI::undoxy()
{
	gotoxy(nowx, nowy);
}

