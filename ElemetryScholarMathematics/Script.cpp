#include "Script.h"
#include "SimpleArea.h"


Script::Script()
{
	ui = new UI;
}

void Script::runScripts()
{
	/*debug*/
	
	
	ui->init();

	//demo code
	ui->fullScreenDialog("生命是什麼呢...");
	ui->fullScreenDialog("或許....", "我一直不以為意的東西...");
	ui->fullScreenDialog("才是真正的東西。");
	ui->fullScreenDialog("但我覺得我必須知道....","就算必須付出很大的代價。" );
	ui->fullScreenDialog("......", "....");
	ui->fullScreenDialog("..");


	ui->showDialog("謎之音", "你終於來了。", 0, true, 1, false);
	ui->showDialog("謎之音", "我等你很久了ㄏㄏ", 0, true, 1, false);

	/*開始命名*/
	ui->chooseNamae();
	ui->showDialog("謎之音", "哼哈哈哈，叫做" + ui->getName() + "是嗎。真是個好名字。", 0, true, 1, false);

	ui->showDialog(ui->getName(), "出來吧！我知道你在那裡！", 0, true, 1, false);
	ui->showDialog("交趾國東征先鋒大將", "不應該阿～～", 0, true, 1, false);
	ui->showDialog(ui->getName(), "哼哼，廢話少說，有什麼本事就出招吧！", 0, true, 1, false);

	/*I part*/
	int a, b, answer;
	a = (rand() % 10 + 1);
	b = (rand() % 10 + 1);
	ui->showDialog("交趾國東征先鋒大將", std::to_string(a) + "+" + std::to_string(b) + "等於幾?", 0, true, 1, false);
	
	//加個凌娜鑰匙產生器吧

	//答題
	answer = ui->userChoice(ui->getName(), std::to_string(a + b), std::to_string(a*b), std::to_string(a - b), std::to_string(b-a), 0);
	if (answer == 0)
	{
		ui->showDialog("交趾國東征先鋒大將", "居然對了，阿不就好棒棒。", 0, true, 1, false);
	}
	else
	{
		ui->showDialog("交趾國東征先鋒大將", "尼錯了，答案是" + std::to_string(a + b), 0, true, 1, false);
		if (ui->getName() == "龍傲天")
		{
			ui->showDialog("交趾國東征先鋒大將", "想取代戰神，先學會仰望我！");
			ui->dontB();
		}
		else
		{
			ui->showDialog("交趾國東征先鋒大將", "順我者生，逆我者亡!哇哈哈~~");
			ui->dead();
		}
	}

	/*II part*/

	ui->showDialog("凌娜", "怎麼又是逆～～～", 0, true, 3, false);
	ui->showDialog(ui->getName(), "我又跳出去啦！我又跳進來啦！打..", 0, true, 3, false);
	ui->showDialog("凌娜", "(呼巴掌)", 0, true, 3, false);
	ui->showDialog(ui->getName(), "咳咳...換我出題！", 0, true, 3, false);

	//答題
	ui->clearScreen();
	SimpleArea fromUser;	//給user輸入 mode 及 底邊和高
	fromUser.ShowGraph();
	fromUser.AreaCalculating();
	getchar();
	getchar();
	
	if (ui->getName() == "大中天")
	{
		ui->showDialog("凌娜", "你媽怎麼給你取這種名字阿，大中天。", 0, true, 3, false);
	}
	
	ui->showDialog(ui->getName(), "我好像心中有個東西突然不見的感覺...");
	ui->showDialog(ui->getName(), "感覺好像...", "我的人生改變了..");
	ui->showDialog("凌娜", "我也覺得我的人生，就在這裡", "寫下了汙點");
	ui->showDialog("凌娜", "ㄍㄋㄇㄉ看醫生遊戲");
}

Script::~Script()
{
	delete ui;
}
