#include "Script.h"


Script::Script()
{
	ui = new UI;
}

void Script::runScripts()
{
	ui->init();

	//demo code
	ui->fullScreenDialog("生命是什麼呢...");
	ui->fullScreenDialog("或許....", "我一直不以為意的東西...");
	ui->fullScreenDialog("才是真正的東西。");
	ui->fullScreenDialog("但我覺得我必須知道....","就算必須付出很大的代價。" );
	ui->fullScreenDialog("......", "....");
	ui->fullScreenDialog("..");


	ui->showDialog("謎之音", "你終於來了。");
	ui->showDialog("謎之音", "我等你很久了ㄏㄏ");

	/*開始命名*/
	ui->chooseNamae();
	ui->showDialog("謎之音", "哼哈哈哈，叫做" + ui->getName() + "是嗎。真是個好名字。");

	ui->showDialog(ui->getName(), "出來吧！我知道你在那裡！");
	ui->showDialog("交趾國東征先鋒大將", "不應該阿～～");
	ui->showDialog(ui->getName(), "哼哼，廢話少說，有什麼本事就出招吧！");

	/*I part*/

	//加個凌娜鑰匙產生器吧

	//答題
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

	/*II part*/

	ui->showDialog("凌娜", "怎麼又是逆～～～");
	ui->showDialog(ui->getName(), "我又跳出去啦！我又跳進來啦！打..");
	ui->showDialog("凌娜", "(呼巴掌)");
	ui->showDialog(ui->getName(), "咳咳...換我出題！");

	//答題
	if (ui->getName() == "大中天")
	{
		ui->showDialog("凌娜", "你媽怎麼給你取這種名字阿，大中天。");
	}
	else
	{
		ui->showDialog(ui->getName(), "那...比較的大門多大？");
	}

}

Script::~Script()
{
	delete ui;
}
