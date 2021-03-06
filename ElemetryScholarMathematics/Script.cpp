﻿#include "Script.h"


Script::Script()
{
	ui = new UI;
	bmpl = new BMPloader;
	pa = new PolygonArea;
}

void Script::runScripts()
{
	/*debug*/
	bool win = false;
	while (1)
	{
		ui->init();

		//demo code
		ui->fullScreenDialog("生命是什麼呢...");
		ui->fullScreenDialog("或許....", "我一直不以為意的東西...");
		ui->fullScreenDialog("才是真正的東西。");
		ui->fullScreenDialog("但我覺得我必須知道....", "就算必須付出很大的代價。");
		ui->fullScreenDialog("......", "....");
		ui->fullScreenDialog("..");


		ui->showDialog("謎之音", "你終於來了。", 0, true, 4, false, true);
		ui->showDialog("謎之音", "我等你很久了ㄏㄏ", 0, true, 4, false, true);

		/*開始命名*/
		ui->chooseNamae();
		ui->setWaveRepeat(false);
		std::thread sp(&UI::playWave, ui, "Musics\\SouthPark.wav");
		ui->showDialog("謎之音", "哼哈哈哈，叫做" + ui->getName() + "是嗎。真是個好名字。", 0, true, 4, false, true);
		ui->print("ㄏㄏ", 5, 19);

		ui->showDialog(ui->getName(), "...莫名其妙", 0);
		
		/*開門動畫*/
		ui->showDialog(ui->getName(), "......", 10);
		ui->showDialog(ui->getName(), "喔？", 12);
		ui->showDialog(ui->getName(), "是你阿，凌娜。", 0, true, 1, false, false);
		ui->showDialog("凌娜", "...有找到什麼嗎？", 0, true, 1, false, true);
		ui->showDialog(ui->getName(), "有...但是他們在一個恐怖的世界裡。", 0, true, 1, false, false);
		ui->showDialog("凌娜", "恐怖的世界裡？你要編故事也該正常點！", "你根本就是有病吧！", 0, true, 1, false, true);
		ui->showDialog(ui->getName(), "你說什麼！我說的都是真的阿！", 0, true, 1, false, false);
		ui->showDialog("凌娜", "那好 ...", 0, true, 1, false, true);

		sp.join();
		/*掏鑰匙*/
		ui->showDialog("凌娜", "你答對我的問題我就承認你說的是真的。", 1);

		/*I part*/
		int a, b, answer;
		a = (rand() % 10 + 1);
		b = (rand() % 10 + 1);
		ui->showDialog("凌娜", "我左手上有" + std::to_string(a) + "把鑰匙，我右手上有"
			+ std::to_string(b) + "把鑰匙，請問我有幾把鑰匙？", 11, true, 1, false);

		//加個凌娜鑰匙產生器吧

		//答題
		answer = ui->userChoice(ui->getName(), std::to_string(a + b), std::to_string(a*b), std::to_string(a - b), std::to_string(b - a), 0);
		if (answer == 0)
		{
			ui->showDialog("凌娜", "哼！", 0, true, 1, false, true);
			ui->aniBear(1, true);
		}
		else
		{
			ui->showDialog("凌娜", "你還是吃屎吧！" + ui->getName() + "！答案是 " + std::to_string(a + b), 0, true, 1, false, true);
			ui->aniBear(1, true);
		}

		/*穿過user身上*/
		ui->showDialog(ui->getName(), "......", 0);

		/*II part*/

		ui->showDialog(ui->getName(), "......", 10);
		ui->showDialog(ui->getName(), "喔？", 12);
		ui->showDialog("魯凱", "...", 0, true, 2, false, true);
		ui->showDialog("魯凱", ui->getName() + "，我一直想要住在這種雙人小套房。", 0, true, 2, false, true);

		/*換表情(驚嚇)*/
		ui->showDialog(ui->getName(), "什麼...", 0, true, 2, false, false);
		ui->showDialog("魯凱", "可以跟我心愛的人住在一起這樣多棒。", 0, true, 6, false, true);
		ui->showDialog(ui->getName(), "(跟我說這些要幹嘛阿！！", "難道...)", 0);
		ui->showDialog(ui->getName(), "不行！想辦法轉移他的注意力。", 0);
		ui->showDialog(ui->getName(), "......對了，", "這個東西好特別喔！", 0, true, 2, false, false);
		ui->showDialog("魯凱", "什麼東西？", 0, true, 2, false, true);

		int choice;

		choice = ui->userChoice(ui->getName(), "床", "三角胖次", "平行四邊形地毯", "春聯", 0);
		ui->showDialog("魯凱", "怎麼了嗎？", 0, true, 2, false, false);


		if (choice == 0)
		{
			ui->showDialog(ui->getName(), "好...好大阿！？", 0, true, 2, false, false);
			/*魯凱表示害羞*/
			ui->showDialog("魯凱", "......", 0, true, 6, false, true);
			ui->showDialog(ui->getName(), "不是啦！這是多少乘多少的床，", "怎麼這麼大？", 0, true, 2, false, false);
			//
			if ((a % 3) == 0)
			{
				//
				int botRec = 5, heiRec = 7;

				//
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Rectangle(botRec, heiRec);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是" + std::to_string(botRec) + " * " + std::to_string(heiRec), "面積為" + std::to_string(botRec * heiRec), 0, true, 2, false, true);
			}
			else if ((a % 3) == 1)
			{
				int botRec = 6, heiRec = 6;

				//
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Rectangle(botRec, heiRec);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是" + std::to_string(botRec) + " * " + std::to_string(heiRec), "面積為" + std::to_string(botRec * heiRec), 0, true, 2, false, true);
			}
			else if ((a % 3) == 2)
			{
				int botRec = 6, heiRec = 7;

				//
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Rectangle(botRec, heiRec);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是" + std::to_string(botRec) + " * " + std::to_string(heiRec), "面積為" + std::to_string(botRec * heiRec), 0, true, 2, false, true);
			}
		}
		else if (choice == 1)
		{
			ui->showDialog(ui->getName(), "好...好特別的...造型！？", 0, true, 2, false, false);
			/*魯凱表示害羞*/
			ui->showDialog("魯凱", "......", 0, true, 6, false, true);
			ui->showDialog(ui->getName(), "不是啦！這...好穿嗎！？", 0, true, 2, false, false);
			if ((a % 4) == 0)
			{
				int botTri = 18, heiTri = 5;

				//
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Triangle(botTri, heiTri);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是褲頭 " + std::to_string(botTri) + " ，長 " + std::to_string(heiTri) + " 的三角形",
					"面積為" + std::to_string((botTri * heiTri) / 2), 0, true, 2, false, true);
			}
			else if ((a % 4) == 1)
			{
				int botTri = 8, heiTri = 5;

				//
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Triangle(botTri, heiTri);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是褲頭 " + std::to_string(botTri) + " ，長 " + std::to_string(heiTri) + " 的三角形",
					"面積為" + std::to_string((botTri * heiTri) / 2), 0, true, 2, false, true);
			}
			else if ((a % 4) == 2)
			{
				int botTri = 10, heiTri = 6;

				//
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Triangle(botTri, heiTri);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是褲頭 " + std::to_string(botTri) + " ，長 " + std::to_string(heiTri) + " 的三角形",
					"面積為" + std::to_string((botTri * heiTri) / 2), 0, true, 2, false, true);
			}
			else if ((a % 4) == 3)
			{
				int botTri = 9, heiTri = 4;
				ui->clearScreen();
				ui->gotoxy(0, 2);
				//
				SA.Show_Triangle(botTri, heiTri);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "這是褲頭 " + std::to_string(botTri) + " ，長 " + std::to_string(heiTri) + " 的三角形",
					"面積為" + std::to_string((botTri * heiTri) / 2), 0, true, 2, false, true);
			}
		}
		else if (choice == 3)
		{
			ui->showDialog(ui->getName(), "這....阿！", "這裡居然有春聯耶", 0, true, 2, false, false);
			if (a > 7)
			{
				//
				a = a + 1;
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Diamond(a);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "對阿，這是一個 " + std::to_string(a) + " * " + std::to_string(a) + " 的地毯",
					"面積為 " + std::to_string(a*a), 0, true, 2, false, true);
			}
			else
			{
				//
				b = b + 1;
				ui->clearScreen();
				ui->gotoxy(0, 2);
				SA.Show_Diamond(b);
				ui->print("[ENTER]繼續", 2, 21);
				getchar();
				ui->showDialog("魯凱", "對阿，這是一個 " + std::to_string(b) + " * " + std::to_string(b) + " 的地毯",
					"面積為 " + std::to_string(b*b), 0, true, 2, false, true);
			}
		}
		else if (choice == 2)
		{
			ui->showDialog(ui->getName(), "好...好奇特的形狀！？", 0, true, 2, false, false);
			//
			a = a + 1;
			b = b + 1;
			ui->clearScreen();
			ui->gotoxy(0, 2);
			SA.Show_Parallelogram(a, b);;
			ui->print("[ENTER]繼續", 2, 21);
			getchar();
			ui->showDialog("魯凱", "會嗎？就是一個 " + std::to_string(a) + " * " + std::to_string(b) + " 的地毯",
				"面積為 " + std::to_string(a*b), 0, true, 2, false, true);
		}

		ui->showDialog("魯凱", "你覺得這個尺寸需要換嗎？", 0, true, 2, false, true);
		ui->showDialog(ui->getName(), "...現在不是說這些的時候吧？", 0, true, 2, false, false);
		ui->showDialog("魯凱", "...是沒錯啦，我只是看到有感而發而已。", "先走了。", 0, true, 2, false, true);
		ui->aniBear(2, true);

		/*III part*/

		//黑暗女巫開門動畫
		ui->showDialog(ui->getName(), "......", 10);
		ui->showDialog(ui->getName(), "喔？", 12);

		ui->showDialog("黑暗女巫", "......", 0, true, 3, false);
		ui->aniBear(3, true);
		ui->showDialog(ui->getName(), "等等！", 0);
		ui->aniBear(0, true);

		//追出去
		ui->showDialog("黑暗女巫", "我只是引誘你，你還真的跟過來了。", 0, true, 3, false);
		ui->showDialog(ui->getName(), "什麼意思...？", "難道這個詭異的世界是你...？", 0, true, 3, false);
		ui->showDialog("黑暗女巫", "讓我可愛的寵物陪你玩玩吧...", 0, true, 3, false);

		//跟小寵物打鬧了一下
		win = ui->littleGame();
		if (win == false)
		{
			ui->dead();
			continue;
		}

		ui->showDialog(ui->getName(), "呼...解決掉他了", 0);

		//石板出場
		ui->showDialog(ui->getName(), "這是什麼怪東西？", 0, true, 14, false);

		std::string fileLocation = ui->loadBMP("石板上寫著", "請開啟一個BMP單色圖檔", 14);
		int rcode = bmpl->init(fileLocation);
		while (rcode != 0)
		{
			ui->showDialog(ui->getName(), "好像是錯覺的樣子。可以不要亂撿地上的東西嗎?(請重開檔案)", 14);
			std::string fileLocation = ui->loadBMP("石板上寫著", "請開啟一個BMP單色圖檔", 14);
			rcode = bmpl->init(fileLocation);
		}


		x = bmpl->getX();
		y = bmpl->getY();
		ui->showCOORD("石板上的點", x, y);


		ConvexHull ch(x, y);
		ch.Andrew_monotone_chain();
		x = ch.getX();
		y = ch.getY();
		ui->showCOORD("好像從圖上看到了疑似凸多邊形的頂點", x, y);
		double parea(pa->PolygonAreaCalculating(x, y));
		ui->showDialog("謎之音", "把奇怪的頂點連起來後得到了面積" + std::to_string(parea));

		ui->fullScreenDialog("所以這究竟代表了什麼呢...");
		ui->fullScreenDialog("答案已經觸手可及，", "但彷彿遠在天邊。");

		ui->showDialog(ui->getName(), "我好像心中有個東西突然不見的感覺...");
		ui->showDialog(ui->getName(), "感覺好像...", "我的人生改變了..");

		ui->fullScreenDialog("我也覺得我的人生，就在這裡", "寫下了汙點");
		ui->fullScreenDialog("ㄍㄋㄇㄉ看醫生遊戲");
		ui->fullScreenDialog("FIN 看醫生的遊戲");
		ui->fullScreenDialog("Um!", "Un!");
		ui->fullScreenDialog("UUm!", "OH!");
		ui->playWave("Musics\\DJT.wav");
		ui->runED();
	}
}

Script::~Script()
{
	delete ui;
	delete bmpl;
	delete pa;
}
