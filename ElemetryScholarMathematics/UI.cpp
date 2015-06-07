#include "UI.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
UI::UI()
{
	//Get Screen resolution
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	unsigned int horizontal = desktop.right;
	unsigned int vertical = desktop.bottom;

	//For Windows 10 Compability and appearance
	SMALL_RECT windowSize = { 0, 0, 80, 23 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	_CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
	GetCurrentConsoleFontEx(hConsole, FALSE, &Font);
	if (horizontal > 1024 && vertical > 768)
		Font.dwFontSize = { 24, 24 };
	else
		Font.dwFontSize = { 16, 16 };

	SetCurrentConsoleFontEx(hConsole, false, &Font);

	SetConsoleTitle(L"小學生的算數！");
	//TODO Check Command Prompt Window Size
	//Init nameChars
	chars = { "龍", "中", "大", "比", "巫", "凌", "卡", "倒退",
		"天", "傲", "暗", "黑", "瘋", "娜", "皓", "清除",
		"葉", "覺", "張", "子", "渣", "利", "不", "好了" };
	//初始化變數
	twoLinesInDialog = false;
	showBearsinDialog = false;
	//預產生亂數種子
	srand(unsigned(time(NULL)));
	//非Big5編碼系統相容性調整
	//SetConsoleOutputCP(950);
}

UI::~UI()
{

}

void UI::init()
{
	gotoxy(0, 0);
	println("         ∩_______∩                                                           　");
	println("        |ˊ ︵ ︵ˋ 科　　　　　　　|              __＼__|__／__          |        ");
	println("       ∕  (⊙)(⊙) 科　　　　　　｜　　　　　　／    ____    ／    ／　　|       ");
	println("      |  （ ＿●＿ ）＝           ｜                    ／        ／____|____     ");
	print("＿＿＿＝　   ｜Ｕ｜ ?          ");
	print("／｜＼", 14);
	println("                  ｜       ／     | ");
	print("    ＿＿＿    ＼ ˊ  ＼        ");
	print("／ ｜  ＼", 10);
	print("            ____｜____       ____|____");
	print("         ／小學生 ／（（       ");
	print("／   ｜   ＼", 10);
	println("              ｜               | ");
	println("      ／       ／          ／    ｜     ＼            ｜               |         ");
	println("(屁) /      __／                 ｜                 ＼｜           ____|____   ");
	println("   （＿＿                        ｜                                              ");
	println("    ｜ ／ ＼ ｝               ＼ ｜                                              ");
	println("     ∪    ))                  ＼｜                                             ");
	print("                                      　　　　＞＞ＰＲＥＳＳ　ＳＴＡＲＴ＜＜\n", 13);
	println("");
	println("　　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　                                                ");
	println("　　　　　　　｜　　　　　　　　　　　　　　＼　　　　／　　                                                ");
	println("　　　　　　　｜　　　　　　　　　　　　　　　＼　　／　　           |                                   ");
	println("　　　　　＿＿｜＿＿　　　＿＿＿＿＿＿　　　　　＼／　　　　　　＿＿＿＿＿＿　　　　　　　　                                                ");
	println("　　　　　　　｜　　　　　　　　　　　　　　　　／＼　　　　　　                                                ");
	println("　　　　　　　｜　　　　　　　　　　　　　　　／　　＼　　　　　      |                                         ");
	println("　　　　　　　｜　　　　　　　　　　　　　　／　　　　＼　　　　                                                ");
	println("　　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　                                                ");
	getchar();
}

void UI::showDialog(std::string name, std::string text)
{
	if (showBearsinDialog == false)
	{
		clearScreen();
	}
	if (text.size() > 70)
	{
		text.resize(70);
#if _DEBUG
		print("[警告]字太多了。請用分行版本或者分成兩次對話。", 0, 0);
#endif
	}
	drawFrame(0, 15, 78, 7);
	print(name, 3, 16);
	print("：");
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
		print("[警告]這行是不是少打了什麼？沒有字耶？", 0, 0);
	}
#endif
	if (text0.size() > 70)
	{
		text0.resize(70);
#if _DEBUG
		print("[警告]字太多了。", 0, 0);
#endif
	}
	print(text0, 5, 19);
	getchar();
	twoLinesInDialog = false;
}

void UI::drawFrame(int lux, int luy, int length, int height)
{
	//╔═╗╚═╝ 
	getxy();
	print("╭", lux, luy);
	print("╮", lux + length, luy);
	print("╰", lux, luy + height);
	print("╯", lux + length, luy + height);
	for (int i = 1; i < (length - 1); i += 2)
		print("─", (lux + i + 1), luy);
	for (int i = 1; i < (length - 1); i += 2)
		print("─", (lux + i + 1), luy + height);
	for (int i = 1; i < height; i++)
		print("│", lux, (luy + i));
	for (int i = 1; i < height; i++)
		print("│", lux + length, (luy + i));
	undoxy();
}


void UI::chooseNamae()
{
	clearScreen();
	drawFrame(8, 1, 60, 2);
	gotoxy(11, 2);
	print("你叫什麼名字？", 15);
	drawFrame(25, 4, 24, 4);
	print("╴╴╴╴", 34, 6);
	drawFrame(10, 10, 56, 11);

	print("　　龍　　中　　大　　比　　巫　　凌　　卡　　倒退", 12, 12);
	print("　　天　　傲　　暗　　黑　　瘋　　娜　　皓　　清除", 12, 15);
	print("　　葉　　覺　　張　　子　　渣　　利　　不　　好了", 12, 18);

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
						print("╴", 34 + name.size(), 6);
						undoxy();
					}
					break;
				case 15:
					name.resize(0);
					getxy();
					print("╴╴╴╴", 34, 6);
					undoxy();
					break;
				case 23:
					if (name.size() == 0)
					{
						print(chars[chars.size() - 1]);
						print("還沒有名字呢。好好地取一下吧？", 11, 2);
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
						print("你ㄚ的會不會太貪心啦？　　　　　　　", 11, 2);
						undoxy();
					}

					break;
				}

#if _DEBUG
				getxy();
				print("　　　　　", 0, 0);
				print("　　　　　", 20, 0);
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
					print("╴", 34 + name.size(), 6);
					undoxy();
				}

			}
		}

#if _DEBUG
		getxy();
		print("　　", 0, 0);
		print(std::to_string(blockCount), 0, 0);
		undoxy();
#endif
	}
}

void UI::print(std::string in)
{
	//︿︽　︾　︿　﹀←　→　↖　↗　↙　↘↑　↓ 非Unicode可用
	std::cout << in;
}

void UI::print(std::string in, int color)
{
	//Color Reference http://kowala21.blogspot.tw/2012/01/dev-c-console.html
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << in;
	SetConsoleTextAttribute(hConsole, 15); //還原成黑底白字
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
	gotoxy(0, 0);*/ //低效能　閃爍

	//高效能低閃爍 可自訂性不明?
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
	getxy();
	switch (place)
	{
	case true:
		bearx = 3;
		beary = 3;
		break;
	case false:
		bearx = 40;
		beary = 3;
		break;
	}
	printBearbackend(bear);
	undoxy();
}

void UI::printBear(int bear)
{
	getxy();
	bearx = 25;
	beary = 3;
	printBearbackend(bear);
	undoxy();
}

void UI::printBearbackend(int bear)
{
	switch (bear)
	{
	case 0:
		printlnb("　　　　　　∩＿＿＿＿＿∩　");
		printlnb("　　        ｜　︿ 　︿ˋ｜");
		printlnb("　　  　　　／（Ｏ）（Ｏ）\\");
		printlnb("　  　　　　｜（＿０＿）＝/");
		printlnb("＿＿＿＿＿＝　　｜Ｕ｜　｜");
		printlnb("　　＿＿＿＿＿　＼　　／、＼");
		printlnb("　　　　　　　　／　　　　／\_<");
		printlnb("　　　　　　　／　　　　／");
		printlnb("           ／　　　＿／");
		printlnb("　　　　　（＿　　　／");
		printlnb("　　　　　｜／　＼　｝");
		printlnb("          ∪      ∪");
		break;
	case 1:
		printlnb("　　　∩＿＿＿＿∩");
		printlnb("   　｜︿     ︿ˋ｜");
		printlnb("　　／　＞　（Ｏ）　\’");
		printlnb("　　＝　（＿０＿）　｜");
		printlnb("　　　　　 ｜Ｕ｜　　＝＿＿＿／＼");
		printlnb("　　　／＼　　　　　＿＿＿＿＿＿ ＼");
		printlnb("　　／　／＼　　　　＼");
		printlnb("　）　ｖ　　＼　　　　＼");
		printlnb("　　　　　　　＼　　　　＼");
		printlnb("　　　　　　　　　＿）");
		printlnb("　　　　　　　　｛　／　＼｜");
		printlnb("　　　　　　　　（（　　　Ｕ");
		break;
	case 2:
		printlnb("　　　∩＿＿＿＿∩");
		printlnb("　　／︿ 　　︿ˋ｜");
		printlnb("　　（０）（０）＼");
		printlnb("　　（＿０＿）　｜");
		printlnb("　　　｜Ｕ｜　＼");
		printlnb("　　／　　　　　／／／／｝");
		printlnb("　／　／＼　　　＼");
		printlnb("｛　／　　＼　　　＼");
		printlnb("　　　　　　＼　　　＼");
		printlnb("　　　　　　／　／＼　＼");
		printlnb("　　　　　／　／　　＼　＼");
		printlnb("　　　　（　／　　　　＼　）");
		break;
	case 3:
		printlnb("");
		printlnb("");
		printlnb("");
		printlnb("　　　∩＿＿＿＿＿∩");
		printlnb("　　　＼　０　０　／");
		printlnb("　　　　＼（０）／");
		printlnb("　　　　　＼︶／");
		printlnb("　　　　／　　　＼");
		printlnb("　　　／／／　＼＼＼");
		printlnb("　　／／／　　　＼＼＼");
		printlnb("　　︸　｜　　　｜　︸");
		printlnb("　　　　／＼－／＼");
		break;
	default:
#if _DEBUG
		print("[錯誤]超出可選擇的熊!", 0, 0);
#endif
		break;
	}

}


void UI::showDialog(std::string name, std::string text, int bear0, bool place0, int bear1, bool place1)
{
	clearScreen();
	showBearsinDialog = true;
	printBear(bear0, place0);
	printBear(bear1, place1);
	showDialog(name, text);
	showBearsinDialog = false;
}
void UI::showDialog(std::string name, std::string text, std::string text0, int bear0, bool place0, int bear1, bool place1)
{
	clearScreen();
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
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　＿＿　　　　　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　＿＿＿｜　　｜＿＿＿　　　　　　　　");
	println("　　　　　　　　｜　　　　　　　　　　｜　　　　勝敗乃兵家常事也");
	println("　　　　　　　　｜＿＿＿　　　　＿＿＿｜　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　大俠請重新來過吧");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　　　　");
	println("　　　　　　　　　　　　｜　　｜　　　　　　　　　");
	println("　　　　　　　　　　　　｜＿＿｜　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　");
	undoxy();
	getchar();
}

void UI::dontB()
{
	clearScreen();
	getxy();
	gotoxy(0, 1);
	println("　　　　　　　　　　︷︷︷︷︷︷︷　　　　　　　　　　　　　　　");
	println("　　　　　　　　　｛　　　　　　　｝　　　　　　　　　");
	println("　　　　　　　　　　︸︸︸︸︸︸︸　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　／／　　　　　︷︷︷　　　　　　");
	println("　　　　　　　　　　　／／　　　　　｛　　　｝　　　 ");
	println("　　　　　　　　　　／／　　　　　　　︸︸︸　　　　　　　");
	println("　　　　　　　　　／／　　　　　　　　　＼　　　　　   莫裝逼");
	println("　　　　　　　　　＼＼　　　　　︷︷　　　＼　　　　　");
	println("　　　　　　　　　　＼＼　　　｛　　｝　　　＼　　　   ");
	println("　　　　　　　　　　　＼＼　　　︸︸　　　　／　　     裝逼遭雷劈");
	println("　　　　　　　　　　　／／　　　／　　　　／　　");
	println("　　　　　　　　　　／／　　　／　　　　／　　　");
	println("　　　　　　　　　／／　　　　＼　　　　＼　　　　");
	println("　　　　　　　　／／　　／＼　／　　　　／　　　　　　　　");
	println("　　　　　　　／／－－－｜｜／－－－－／－　　　　　　");
	println("　　　　　　　　　　　　　　　　　　　／＼　　　　　　");
	println("　　　　　　　　／＼　　　　　　　　　｜｜　　　　　　　　");
	println("　　　　　　　　｜｜　　　　　　　／＼　　　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　｜｜　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　／＼　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　｜｜　　　　　　　　　　　　　");
	undoxy();
	getchar();
}

void UI::undoxy()
{
	gotoxy(nowx, nowy);
}

void UI::fullScreenDialog(std::string text, std::string text0)
{
	clearScreen();
	print(text, 8, 8);
	getchar();
	print(text0, 8, 11);
	getchar();
}

void UI::fullScreenDialog(std::string text)
{
	clearScreen();
	print(text, 8, 9);
	getchar();
}

void UI::printlnb(std::string text)
{
	gotoxy(bearx, beary);
	print(text);
	beary++;
}

void UI::showDialog(std::string name, std::string text, int bear0)
{
	clearScreen();
	showBearsinDialog = true;
	printBear(bear0);
	showDialog(name, text);
	showBearsinDialog = false;
}

void UI::showDialog(std::string name, std::string text, std::string text0, int bear0)
{
	clearScreen();
	showBearsinDialog = true;
	printBear(bear0);
	showDialog(name, text, text0);
	showBearsinDialog = false;

}

int UI::userChoice(std::string name, std::string option0, std::string option1, std::string option2, std::string option3, int bear)
{
	clearScreen();
	printBear(bear);
	drawFrame(0, 15, 78, 7);
	print(name, 3, 16);
	print("：");
	//TODO PROTECT
	print("＊", 2, 18);
	print("1) " + option0, 5, 18);
	print("2) " + option1, 43, 18);
	print("3) " + option2, 5, 19);
	print("4) " + option3, 43, 19);

	int option = 0;
	while (1)
	{
		while (!_kbhit())
			;
		int firstinput = _getch();//Arrow Key get two input
		if (firstinput == 224)
		{
			print("  ", 2, 18);
			print("  ", 40, 18);
			print("  ", 2, 19);
			print("  ", 40, 19);

			char arrKey = _getch();
			getxy();
			switch (arrKey)
			{
			case 72://GOING UP
				if (option > 1)
					option -= 2;
				else
					option += 2;
				break;
			case 80://GOING DOWN
				if (option > 1)
					option -= 2;
				else
					option += 2;
				break;
			case 75://GOING LEFT
				if (option == 1 || option == 3)
					option -= 1;
				else if (option == 0)
					option = 3;
				else
					option = 1;
				break;
			case 77://GOING RIGHT
				if (option == 0 || option == 2)
					option += 1;
				else if (option == 3)
					option = 0;
				else
					option = 2;
				break;
			}
			switch (option)
			{
			case 0:
				print("＊", 2, 18);
				break;
			case 1:
				print("＊", 40, 18);
				break;
			case 2:
				print("＊", 2, 19);
				break;
			case 3:
				print("＊", 40, 19);
				break;
			}
		}
		else
		{
			if (firstinput == 13) //ENTER
			{
				return option;
			}
		}
	}

}