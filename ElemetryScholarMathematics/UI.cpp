#include "UI.h"


UI::UI()
{
	runRoutine = true;
	routineBuster = std::thread(&UI::routineRunner, this);
	SetConsoleTitle(L"小學生的算數！");
	//Init nameChars
	chars = { "龍", "中", "大", "比", "巫", "凌", "卡", "倒退",
		"天", "傲", "暗", "黑", "瘋", "娜", "皓", "清除",
		"葉", "覺", "張", "子", "渣", "利", "不", "好了" };
	//初始化變數
	twoLinesInDialog = false;
	showBearsinDialog = false;
	aniEnd = false;
	horizontal = 0;
	vertical = 0;
	clearScreenSwitch = true;
	repeatWave = false;
	//預產生亂數種子
	srand(unsigned(time(NULL)));
}

UI::~UI()
{
	runRoutine = false;
	routineBuster.join();
}

void UI::blinkStart()
{
	for (int i = 12; i < 16; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		print("＞＞ＰＲＥＳＳ　ＳＴＡＲＴ＜＜", 45, 12);
		print("　　　　　　　｜", 0, 14);
		print("　　　　　　　｜　　　　　　　　　　　　　　＼　　　　／", 0, 15);
		print("　　　　　　　｜　　　　　　　　　　　　　　　＼　　／　　           |", 0, 16);
		print("　　　　　＿＿｜＿＿　　　＿＿＿＿＿＿　　　　　＼／　　　　　　＿＿＿＿＿＿\n", 0, 17);
		print("　　　　　　　｜　　　　　　　　　　　　　　　　／＼\n", 0, 18);
		print("　　　　　　　｜　　　　　　　　　　　　　　　／　　＼　　　　　     |", 0, 19);
		print("　　　　　　　｜　　　　　　　　　　　　　　／　　　　＼\n", 0, 20);
		print("　　　　　　　｜", 0, 21);
		for (int j = 0; j < 10; j++)
		{
			Sleep(50);
			if (aniEnd == true) return;
		}
		print("                                ", 45, 12, 15);
		for (int j = 0; j < 10; j++)
		{
			Sleep(50);
			if (aniEnd == true) return;
		}
		if (i == 15)
			i = 1;
		if (aniEnd == true)
			break;
	}
	SetConsoleTextAttribute(hConsole, 15);

}

void UI::init()
{
	clearScreen();
	repeatWave = true;
	waveBuster = std::thread(&UI::playWave, this, "Musics\\FF7FIGHT.wav");
	gotoxy(0, 0);
	println("　　　 ∩＿＿＿＿＿∩　");
	println("       ｜＿＿＿＿＿｜                                                           　");
	println("        |ˊ ＼ ／ˋ ＼　　　　　 　|              __＼__|__／__          |        ");
	println("       ∕  (Ｏ)(Ｏ) 科　　　　　　｜　　　　　　／    ____    ／    ／　　|       ");
	println("      |  （ ＿０＿ ）＝          ｜                    ／        ／____|____     ");
	print("＿＿＿＝　   ｜︿｜ \\          ");
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

	std::thread blink(&UI::blinkStart, this);
	waitEnter();
	repeatWave = false;
	aniEnd = true;
	blink.join();
	aniEnd = false;

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
	print(text, 5, 18, 8);
	Sleep(100);
	print(text, 5, 18);
	if (twoLinesInDialog == false)
	{
		waitingEnter = true;
		enterWaitBuster = std::thread(&UI::blinkWaitEnter, this, 75, 21);
		waitEnter();
		waitingEnter = false;
		enterWaitBuster.join();
		print("  ", 75, 21);
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
	print(text0, 5, 19, 8);
	Sleep(100);
	print(text0, 5, 19);
	waitingEnter = true;
	enterWaitBuster = std::thread(&UI::blinkWaitEnter, this, 75, 21);
	waitEnter();
	waitingEnter = false;
	enterWaitBuster.join();
	print("  ", 75, 21);
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
		print("─", (lux + i + 1), luy); //─
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
	print(name, 34, 6);
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
	clearScreen();
	
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
	if (clearScreenSwitch == true)
	{
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
	//Drew by GODKING
	int tmpx;
	switch (bear)
	{
	case 0:
		printlnb("　　　　　　　∩＿＿＿＿＿∩　");
		printlnb("　　｜　　　　｜＿＿＿＿＿｜　　");
		printlnb("　　｜     　／ ＼ 　／　＼");
		printlnb("　　｜　　　｜（Ｏ）（Ｏ）｜　");
		printlnb("　  ｜　　　｜（＿０＿）　/");
		printlnb("＿＿｜＿＿　／　｜︿｜　　｜＼");
		printlnb("　　｜＿＿／／＼　　　　　／＼｜");
		printlnb("　　｜＿＿／　／＼＿＿＿／");
		printlnb("　　　　　　／　｜　　　｜　");
		printlnb("　　　　　／　　｜＿＿＿｜　　　");
		printlnb("　　　　／　　　（＿　＿）　");
		printlnb("　　　　／＼／＼｜／　＼｜　　");
		printlnb("       　　　　 ∪ 　　∪　");
		break;
	case 1:
		printlnb("　　　∩＿＿＿∩　");
		printlnb("   　｜ ︿   ︿｜");
		printlnb("    ／（x）（x）＼");
		printlnb("　　｜（＿０＿）｜");
		printlnb("　　＼　｜３｜　／");
		printlnb("　    --------- ");
		printlnb("　　／｜  ８  ｜＼ ");
		printlnb("　／／｜　８　｜＼＼");
		printlnb("　︸　｜　８　｜　︸");
		printlnb("　　　／＿＿＿＼");
		printlnb("　　  ｜｜  ｜｜");
		printlnb("　　　 Ｖ    Ｖ ");
		break;
	case 2:
		printlnb("　　︿＿＿＿＿＿︿");
		printlnb("　　＼　0　 0　 ／");
		printlnb("　　　＼　０　／");
		printlnb("　　    ＼V／");
		printlnb("      　／　＼");
		printlnb("   ／ ｜＿｜＿｜＼");
		printlnb("　Ｔ／｜　｜　｜＼Ｔ");
		printlnb("　　　  ＼  ／ ");
		printlnb("　　　　／／＼＼");
		printlnb("　　　／／  ／／");
		printlnb("　　　Ｖ　  Ｖ");
		break;

	case 3:
		printlnb("　　　∩＿＿＿＿∩　");
		printlnb("   　｜︿   　︿｜ ");
		printlnb("    ／（！）（！）＼");
		printlnb("　　｜　（＿０＿）｜");
		printlnb("　　／＼　｜３｜　／＼　　＿＿＿＿＿");
		printlnb("　／　　＼Ｕ　Ｕ／　　＼／");
		printlnb("　　＼　　＼　／");
		printlnb("　　　＼　／　＼");
		printlnb("　　　　／　　　＼");
		printlnb("　　　／＿＿＿＿＿＼");
		printlnb("　　　　｜　　　｜");
		printlnb("　　　　Ｖ　　　Ｖ");
		break;

	case 4:
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
	case 5:
		printlnb("　　　　　　∩＿＿＿＿＿∩　");
		printlnb("　　        ｜　︿ 　︿ˋ｜");
		printlnb("　　  　　　／（Ｏ）（Ｏ）\\");
		printlnb("　  　　　　｜（＿０＿）＝/");
		printlnb("＿＿＿＿＿＝　　｜Ｕ｜　｜");
		printlnb("　　＿＿＿＿＿　＼　　／、＼");
		printlnb("　　　　　　　　／　　　　／＼_<");
		printlnb("　　　　　　　／　　　　／");
		printlnb("           ／　　　＿／");
		printlnb("　　　　　（＿　　　／");
		printlnb("　　　　　｜／　＼　｝");
		printlnb("          ∪      ∪");
		break;
	case 6:
		printlnb("　　︿＿＿＿＿＿︿");
		getxy();
		tmpx = nowx;
		println("");
		getxy();
		gotoxy(tmpx - 18, nowy);
		runRoutine = false; //Safty Guard
		_setmode(_fileno(stdout), _O_WTEXT);
		wprintf(L"　　＼　❤　❤ 　／");
		_setmode(_fileno(stdout), _O_TEXT);
		runRoutine = true;
		printlnb("");
		printlnb("　　　＼　０　／");
		printlnb("　　    ＼３／");
		printlnb("  ＿＿　／　＼　＿＿");
		printlnb("Ｔ＿＿｜＿｜＿｜＿＿Ｔ");
		printlnb("　　　｜　｜　｜");
		printlnb("　　　  ＼  ／");
		printlnb("　　　　／／＼＼");
		printlnb("　　　／／  ／／");
		printlnb("　　　Ｖ　  Ｖ");
		break;
	case 7:
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
	case 8:
		printlnb("　　　∩＿＿＿＿∩");
		printlnb("   　｜︿     ︿ˋ｜");
		printlnb("　　／　＞　（Ｏ）　\\");
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
	case 9:
		printlnb("　　　∩＿＿＿∩　");
		printlnb("   　｜       ｜");
		printlnb("    ／         ＼");
		printlnb("　　｜         ｜");
		printlnb("　　＼　       ／");
		printlnb("　    --------- ");
		printlnb("　　／｜      ｜＼ ");
		printlnb("　／／｜　  　｜＼＼");
		printlnb("　︸　｜　  　｜　︸");
		printlnb("　　　／＿＿＿＼");
		printlnb("　　  ｜｜  ｜｜");
		printlnb("　　　 Ｖ    Ｖ ");
		break;
	case 10:
		printlnb("　　　＿＿＿＿＿＿＿＿");
		printlnb("比　　＼　       　 ／");
		printlnb("較　　　＼　　Ｘ　／");
		printlnb("的　　　　＼　　／");
		printlnb("大　　　　　＼／");
		printlnb("門　　　　　／＼");
		printlnb("　　　　　／　　＼");
		printlnb("　　　　／　Ｙ　　＼");
		printlnb("　　　／＿＿＿＿＿＿＼");
		break;
	case 11:
		printlnb("      ___________ ");
		printlnb("      ｜   　　｜");
		printlnb("      ｜Ｋｅｙ ｜");
		printlnb("      ｜_______｜");
		printlnb("           ｜");
		printlnb("           ｜");
		printlnb("           ｜");
		printlnb("           ｜＿ ");
		printlnb("           ｜＿｜");
		printlnb("           ｜＿");
		printlnb("           ｜＿｜");
		break;
	case 12:
		printlnb("＿＿＿＿＿＿＿＿　＿＿＿＿＿＿　");
		printlnb("＼　       　 ／｜　　　　　　｜");
		printlnb("　＼　　　　／　｜　　　　　　｜");
		printlnb("　　＼　　／　　｜　　　　　　｜");
		printlnb("　　　＼／　　　｜　　　　　　｜");
		printlnb("　　　／＼　　　｜　　　　　　｜");
		printlnb("　　／　　＼　　｜　　　　　　｜");
		printlnb("　／　　　　＼　｜　　　　　　｜");
		printlnb("／＿＿＿＿＿＿＼｜＿＿＿＿＿＿｜");
		break;
	case 13:
		printlnb("         　／＼__／＼");
		printlnb("           ｜＼  ／｜");
		printlnb("     ______｜　！　｜______");
		printlnb("    |   　 ｜　０　｜　　　|");
		printlnb("    |      ｜______｜　　　|");
		printlnb("    |        ｜　｜　　　　|");
		printlnb("    |        ｜　｜　　　　|");
		printlnb("    |        ｜　｜　　　　|");
		printlnb("   ＶＶ　    ＼　／　　　ＶＶ");
		printlnb("           　　Ｖ");
		break;
	case 14:
		printlnb(" ╭──────────╮");
		printlnb(" │853c2ffeb37eb9d9423c│");
		printlnb(" │120662f7e578!@#$%^^%│");
		printlnb(" │2A5F1B6F4980A54BB984│");
		printlnb(" │33AF9709F5E0#$&#*@^!│");
		printlnb(" │2A5F1B6F4980A54BB984│");
		printlnb(" │33AF9709F5E0!^@&#*$&│");
		printlnb(" │2A5F1B6F4980A54BB984│");
		printlnb(" │33AF9709F5E0$*%(*^&#│");
		printlnb(" ╰──────────╯");
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

void UI::showDialog(std::string name, std::string text, int bear0, bool place0, int bear1, bool place1, bool light)
{
	clearScreen();
	showBearsinDialog = true;
	if (light == true)
		SetConsoleTextAttribute(hConsole, 8);
	printBear(bear0, place0);
	if (light == true)
		SetConsoleTextAttribute(hConsole, 15);
	else
		SetConsoleTextAttribute(hConsole, 8);
	printBear(bear1, place1);
	if (light == false)
		SetConsoleTextAttribute(hConsole, 15);
	showDialog(name, text);
	showBearsinDialog = false;

}

void UI::showDialog(std::string name, std::string text, std::string text0, int bear0, bool place0, int bear1, bool place1, bool light)
{
	clearScreen();
	showBearsinDialog = true;
	if (light == true)
		SetConsoleTextAttribute(hConsole, 8);
	printBear(bear0, place0);
	if (light == true)
		SetConsoleTextAttribute(hConsole, 15);
	else
		SetConsoleTextAttribute(hConsole, 8);
	printBear(bear1, place1);
	if (light == false)
		SetConsoleTextAttribute(hConsole, 15);
	showDialog(name, text, text0);
	showBearsinDialog = false;
}

void UI::dead()
{
	clearScreen();
	getxy();
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　＿＿　　　　　　　　　　　　");
	println("　　　　　　　　　　　　｜你死｜　　　　　　　　");
	println("　　　　　　　　　　　　｜了你｜　　　　　　　　");
	println("　　　　　　　　　＿＿＿｜死了｜＿＿＿　　　　　　　　");
	println("　　　　　　　　｜你死了你死了你死了你｜　");
	println("　　　　　　　　｜＿＿＿你死了你＿＿＿｜　　　　");
	println("　　　　　　　　　　　　｜你死｜　　　　　　　　");
	println("　　　　　　　　　　　　｜了你｜　　　　　　　　");
	println("　　　　　　　　　　　　｜死了｜　　　　　　　　");
	println("　　　　　　　　　　　　｜你死｜　　　　　　　　");
	println("　　　　　　　　　　　　｜了你｜　　　　　　　　");
	println("　　　　　　　　　　　　｜死了｜　　　　　　　　");
	println("　　　　　　　　　　　　｜你死｜　　　　　　　　　　　");
	println("　　　　　　　　　　　　｜了你｜　　　　　　　　　");
	println("　　　　　　　　　　　　｜＿＿｜　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　　　　　");
	println("　　　　　　　　　　　　　　太大意惹　　　");
	println("　　　　　　　　　　　　　　　　　");
	undoxy();
	waitingEnter = true;
	std::thread blink(&UI::blinkWaitEnter, this, 75, 18);
	waitEnter();
	waitingEnter = false;
	blink.join();
	
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
	waitEnter();
}

void UI::undoxy()
{
	gotoxy(nowx, nowy);
}

void UI::fullScreenDialog(std::string text, std::string text0)
{
	clearScreen();
	print(text, 8, 8, 8);
	Sleep(100);
	print(text, 8, 8);

	waitingEnter = true;
	enterWaitBuster = std::thread(&UI::blinkWaitEnter, this, 70, 11);
	waitEnter();
	waitingEnter = false;
	enterWaitBuster.join();
	print("  ", 70, 11);

	print(text0, 8, 11, 8);
	Sleep(100);
	print(text0, 8, 11);

	waitingEnter = true;
	enterWaitBuster = std::thread(&UI::blinkWaitEnter, this, 70, 14);
	waitEnter();
	waitingEnter = false;
	enterWaitBuster.join();
	print("  ", 70, 14);
}

void UI::fullScreenDialog(std::string text)
{
	clearScreen();
	print(text, 8, 9, 8);
	Sleep(100);
	print(text, 8, 9);

	waitingEnter = true;
	enterWaitBuster = std::thread(&UI::blinkWaitEnter, this, 70, 11);
	waitEnter();
	waitingEnter = false;
	enterWaitBuster.join();
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

void UI::waitEnter()
{
	while (1)
	{
		while (!_kbhit());
		int firstinput = _getch();//Arrow Key get two input
		if (firstinput == 13) //ENTER
		{
			return;
		}
	}
}

void UI::showCOORD(std::string in, std::vector<short> x, std::vector<short> y)
{
	int column, row;
	int pages = x.size() / 17 / 5 + ((x.size() % 17 > 0 || (x.size() / 17) % 5 > 0) ? 1 : 0);
	int nowPage = 1;
	unsigned int i = 0;
	char arrKey = 0;
	while (1)
	{
		scrollBar(x.size(), i + 1, true);
		clearScreen();
		drawFrame(0, 0, ConsoleWidth - 2, ConsoleHeight - 1);
		print(in + "：", 3, 1);
		column = row = 0;
		scrollBar(x.size(), i + 1, true);
		print(std::to_string(nowPage) + "/" + std::to_string(pages) + "      ", 65, 22);
		for (; i < x.size(); i++)
		{
			if (row > 4)
			{
				++column;
				if (column > 17)
				{
					column = 0;

					print(((nowPage == 1) ? "[↓]捲動卷軸  [Tab]繼續" : "[↑][↓]捲動卷軸  [Tab]繼續"), 2, 23);
					print(std::to_string(i) + "/" + std::to_string(x.size()) + "       ", 60, 22);
					while (1)
					{
						while (!_kbhit());
						int firstinput = _getch();//Arrow Key get two input
						if (firstinput == 9)
						{
							return;
						}
						if (firstinput == 224)
						{
							arrKey = _getch();
							if (arrKey == 72)//GOING UP
							{
								if (nowPage > 1)
								{
									--nowPage;
									if (i >= 180)
									{
										i = i - (18 * 5 * 2);
										clearScreen();
										drawFrame(0, 0, ConsoleWidth - 2, ConsoleHeight - 1);
										print(in + "：", 3, 1);
									}
								}
								else
									i = 0;
								break;
							}
							if (arrKey == 80)//GOING DOWN
							{
								++nowPage;
								clearScreen();
								drawFrame(0, 0, ConsoleWidth - 2, ConsoleHeight - 1);
								print(in + "：", 3, 1);
								break;
							}
						}
					}
					scrollBar(x.size(), i + 1, true);
				}
				row = 0;
			}
			print(("(" + std::to_string(x[i]) + ", " + std::to_string(y[i]) + ")"), (5 + row * 14), (3 + column));
			++row;
		}
		print(std::to_string(i) + "/" + std::to_string(x.size()) + "       ", 60, 22);
		if (x.size() / 90 > 0)
		{
			print("[↑]捲動卷軸  [Tab]繼續", 2, 23);
			scrollBar(x.size(), i + 1, true);
			while (arrKey != 72)
			{
				while (!_kbhit());
				int firstinput = _getch();
				if (firstinput == 9)
				{
					return;
				}
				if (firstinput == 224)
				{
					arrKey = _getch();
					if (arrKey == 72)//GOING UP
					{
						--nowPage;
						i = i - ((18 * 5) + (x.size() % 90));
						clearScreen();
						drawFrame(0, 0, ConsoleWidth - 2, ConsoleHeight - 1);
						print(in + "：", 3, 1);
						break;
					}
				}
			}
		}
		else
		{
			for (int j = 2; j < 23; j++)
				print(" ", 76, j);
			print("[Tab]繼續", 2, 23);
			while (arrKey != 72)
			{
				while (!_kbhit());
				int firstinput = _getch();
				if (firstinput == 9)
				{
					return;
				}
			}
		}
	}
}


void UI::scrollBar(unsigned int totalPages, unsigned int nowPages, bool showArrow)
{
	int nowPlace(totalPages);
	if (showArrow = true)
	{
		print("↑", 76, 2);
		print("↓", 76, 21);
	}
	int boxPlace = ceil((int)((double)nowPages / ((double)totalPages / 17.0f)));

	if (boxPlace > 1)
		print(" ", 76, 3 + (int)boxPlace - 1);
	if (boxPlace < 16)
		print(" ", 76, 3 + (int)boxPlace + 1);
	print("■", 76, 3 + boxPlace);
}


void UI::routineRunner()
{
	while (runRoutine == true)
	{
		//Get Screen resolution and set position
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		horizontalt = desktop.right;
		verticalt = desktop.bottom;

		//For Windows 10 Compability and appearance
		if (horizontal != horizontalt || vertical != verticalt)
		{
			HWND thisConsole = GetConsoleWindow();
			RECT currentSize;
			CONSOLE_FONT_INFOEX Font;// = { sizeof(CONSOLE_FONT_INFOEX) };
			GetCurrentConsoleFontEx(hConsole, FALSE, &Font);
			CONSOLE_FONT_INFOEX cfi;
			cfi.cbSize = sizeof cfi;
			cfi.nFont = 0;
			if (horizontalt >= 1900 && verticalt >= 1000)
				cfi.dwFontSize = { 30, 30 };
			else if (horizontalt >= 1000 && verticalt >= 900)
				cfi.dwFontSize = { 26, 26 };
			else if (horizontalt >= 1000 && verticalt >= 700)
				cfi.dwFontSize = { 20, 20 };
			else
				cfi.dwFontSize = { 16, 16 };
			cfi.FontFamily = FF_DONTCARE;
			cfi.FontWeight = FW_NORMAL;

			if (GetConsoleOutputCP() == 950)
				wcscpy_s(cfi.FaceName, L"細明體");
			else
				wcscpy_s(cfi.FaceName, L"新宋体");


			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

			Sleep(1100);
			GetWindowRect(thisConsole, &currentSize);
			SetWindowPos(thisConsole, HWND_TOP, 10, 10, 1920, (currentSize.bottom - currentSize.top +5), SWP_SHOWWINDOW);
			horizontal = horizontalt;
			vertical = verticalt;
		}

		Sleep(2000);

	}
}

std::string UI::loadBMP(std::string name, std::string text, int bear0)
{
	//std::string fileLocation;
	clearScreen();
	showBearsinDialog = true;
	twoLinesInDialog = true;
	printBear(bear0);
	showDialog(name, text);
	showBearsinDialog = false;
	twoLinesInDialog = false;

	OPENFILENAME ofn;
	wchar_t szFile[1000];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"BMP file\0*.BMP";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&ofn);
	std::wstring ws(szFile);
	std::string str(ws.begin(), ws.end());
	rewind(stdin);
	return str;
}

void UI::blinkWaitEnter(int x, int y)
{
	while (waitingEnter == true)
	{
		print("▼", x, y);
		for (int i = 0; i < 250; i++)
		{
			Sleep(2);
			if (waitingEnter == false) return;
		}
		print(" ", x, y);
		for (int i = 0; i < 250; i++)
		{
			Sleep(2);
			if (waitingEnter == false) return;
		}
	}
}

bool UI::littleGame()
{
	waveBuster.join();
	int playerHP(500);
	int enemyHP(500);
	std::string enemyName("鐘樓怪");
	std::string enemySkill("原子吐息");
	int enemySkillDamage(-200);
	int enemyNormalDamage(-50);
	std::string playerSkill("能量槍");
	int playerNormalDamage(-100);
	int playerSkillDamage(-150);
	int damage;
	clearScreen();
	clearScreenSwitch = false;
	//PlayStrangeMusic
	waveBuster = std::thread(&UI::playWave, this, "Musics\\GodzillaRoar.wav");
	//BearDraw
	aniBear(13, true);
	for (int i = 0; i < 3; i++)
	{
		Sleep(400);
		clearScreenSwitch = true;
		clearScreen();
		clearScreenSwitch = false;
		Sleep(400);
		bearx = 44;
		beary = 5;
		printBearbackend(13);
	}
	Sleep(400);
	bearx = 4;
	beary = 5;
	printBearbackend(0);
	waveBuster.join();
	showGameDialog(enemyName + "想要和" + name + "來場對戰!");
	while (playerHP > 0 && enemyHP > 0)
	{
		print("HP : ?", 2, 2);
		print("HP : ?", 72, 2);
		print("              ", 2, 1);
		gotoxy(2, 1);
		//
		for (int i = 0; i < (playerHP / 100); i++)
			print("▉");
		print("              ", 68, 1);
		gotoxy(68, 1);
		for (int i = 0; i < (enemyHP / 100); i++)
			print("▉");


		clearDialog();
		switch (userChoice("想要" + name + "做什麼", "普通攻擊", "背包", "技能", "逃跑", 99))
		{
		case 0:
			damage = playerNormalDamage - (rand() % 100 + 1);
			enemyHP += damage;

			showGameDialog(name + "空白鍵連打，對" + enemyName + "造成了" + std::to_string(-damage) + "點傷害!");
			break;
		case 1:
			showGameDialog("背包籠罩著黑暗氣息。似乎打不開了。");
			break;
		case 2:
			damage = playerSkillDamage - (rand() % 200 + 1);
			enemyHP += damage;
			showGameDialog(name + "對" + enemyName + "使用了雷射槍!");
			if (damage < -200)
				showGameDialog("效果拔群!");
			else
				showGameDialog("效果一般!");
			showGameDialog(name + "對" + enemyName + "造成了" + std::to_string(-damage) + "點傷害。");
			break;
		case 3:
			showGameDialog("哼；就算" + name + "叫破喉嚨也不會有人來幫忙的。");
			break;
		}

		//
		print("              ", 2, 1);
		gotoxy(2, 1);
		for (int i = 0; i < (playerHP / 100); i++)
			print("▉");
		print("              ", 68, 1);
		gotoxy(68, 1);
		for (int i = 0; i < (enemyHP / 100); i++)
			print("▉");

		if (enemyHP < 0) break;
		switch (rand() % 2)
		{
		case 0:
			damage = enemyNormalDamage - (rand() % 100 + 1);
			playerHP += damage;
			showGameDialog(enemyName + "輕拍" + name + "，造成了" + std::to_string(-damage) + "點傷害!");
			break;
		case 1:
		default:
			damage = enemySkillDamage - (rand() % 300 + 1);
			playerHP += damage;
			showGameDialog(enemyName + "對" + name + "使用了原子吐息!");
			if (damage < -250)
				showGameDialog("效果拔群!");
			else
				showGameDialog("效果一般!");
			showGameDialog(enemyName + "對" + name + "造成了" + std::to_string(-damage) + "點傷害!");
			break;
		}
	}
	clearScreenSwitch = true;
	if (playerHP < 0)
		return false;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			Sleep(400);
			clearScreen();
			clearScreenSwitch = false;
			Sleep(400);
			bearx = 44;
			beary = 5;
			printBearbackend(13);
			clearScreenSwitch = true;
		}
		clearScreen();
		Sleep(1000);
		return true;
	}
}

void UI::showGameDialog(std::string in)
{
	showBearsinDialog = true;
	twoLinesInDialog = true;
	clearDialog();
	showDialog("", "");
	print(in, 3, 16);
	waitingEnter = true;
	enterWaitBuster = std::thread(&UI::blinkWaitEnter, this, 75, 21);
	waitEnter();
	waitingEnter = false;
	enterWaitBuster.join();
	print("  ", 75, 21);
	showBearsinDialog = false;
	twoLinesInDialog = false;
}

void UI::clearDialog()
{
	gotoxy(0, 15);
	for (int i = 0; i < 10; i++)
		print("                                                            ");
}

void UI::playWave(std::string path)
{
	do
	{
		std::wstring stemp = std::wstring(path.begin(), path.end());
		LPCWSTR sw = stemp.c_str();
		PlaySound(sw, NULL, SND_FILENAME | SND_NODEFAULT);
	} while (repeatWave == true);
}

void UI::aniBear(int bear, bool direction)
{
	for (int i = 0; i < 12; i++)
	{
		clearScreen();
		if (direction == true)
			bearx = 0 + 4 * i;
		else
			bearx = 65 - 4 * i;
		beary = 5;
		printBearbackend(bear);
		Sleep(50);
	}
}

void UI::setWaveRepeat(bool in)
{
	repeatWave = in;
}

