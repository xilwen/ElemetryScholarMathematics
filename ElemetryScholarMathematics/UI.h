//written by xilwen, qqwerfdsa930 and GODKING

#ifndef UI_H
#define UI_H

#define ConsoleWidth 80
#define ConsoleHeight 24

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>    //for srand
#include <io.h>	    //for _setmode
#include <fcntl.h>	//for _setmode
#include <thread>   //for animations

class UI
{
public:
	UI();

	//呼叫遊戲開始畫面
	void init();

	//顯示對話框，35字一行。
	void showDialog(std::string name, std::string text);
	//對話框，35字兩行。
	void showDialog(std::string name, std::string text, std::string text0);
	//含熊的對話框。單行雙熊。不需要雙熊的話打超過可提供的熊數即可。
	void showDialog(std::string name, std::string text, int bear0, bool place0, int bear1, bool place1);
	//含熊的對話框。雙行雙熊。不需要雙熊的話打超過可提供的熊數即可。
	void showDialog(std::string name, std::string text, std::string text0, int bear0, bool place0, int bear1, bool place1);
	//含熊的對話框。單行單熊。不需要雙熊的話打超過可提供的熊數即可。
	void showDialog(std::string name, std::string text, int bear0);
	//含熊的對話框。雙行單熊。不需要雙熊的話打超過可提供的熊數即可。
	void showDialog(std::string name, std::string text, std::string text0, int bear0);

	//讓使用者選擇答案。
	int userChoice(std::string name, std::string option0, std::string option1, std::string option2, std::string option3, int bear);

	//全螢幕無邊框對話框。雙行、位置固定。不需要第二行請用空字串。
	void fullScreenDialog(std::string text, std::string text0);
	//全螢幕無邊框對話框。雙行、位置固定。
	void fullScreenDialog(std::string text);

	//死亡畫面。
	void dead();
	//莫裝逼(龍傲天專屬)
	void dontB();

	//(X不建議)在畫面的指定座標印出文字。
	void print(std::string in, int x, int y);
	//(X不建議)在畫面的指定座標印出指定顏色的文字。
	void print(std::string in, int x, int y, int color);
	//在畫面上顯示四種熊。true = 左, false = 右
	void printBear(int bear, bool place);
	//在畫面上顯示四種熊置中。true = 左, false = 右
	void printBear(int bear);

	//移動游標到指定的位置。
	void gotoxy(int x, int y);

	//啟動選名字介面。
	void chooseNamae();
	//載入BMP畫面
	std::string loadBMP(std::string name, std::string text, int bear0);

	//清除整個螢幕
	void clearScreen();
	~UI();

	//顯示座標畫面
	void showCOORD(std::string in, std::vector<short> x, std::vector<short> y);

	//熊移動動畫
	void aniBear();

	//回傳主角名字(Accessor to name)
	std::string getName();
private:
	//書出文字。
	void print(std::string in);
	//輸出指定色彩的文字。
	void print(std::string in, int color);
	//印熊後台
	void printBearbackend(int bear);

	//輸出文字並換行。
	void println(std::string);
	//輸出熊圖專用換行。
	void printlnb(std::string);

	//畫框框，左上x點, y點, 長(橫向), 高(直向)
	void drawFrame(int lux, int luy, int length, int height);
	
	//取得現在游標位置。
	void getxy();
	//回到紀錄的游標位置
	void undoxy();
	//存放由getxy函數取得的X,Y軸資訊。
	int nowx;
	int nowy;
	//儲存主角的名字。
	std::string name;
	//儲存在名字選擇介面中可選名字的清單。
	std::vector<std::string> chars;
	//對話框是否將顯示兩行(避免重複暫停)。用於showdialog。
	bool twoLinesInDialog;
	//對話框是否有要輸出熊，若有則不清畫面。用於showdialog。
	bool showBearsinDialog;
	//要畫熊現在的位置
	int bearx;
	int beary;
	//除了ENTER之外都不會讓你繼續的!代替getchar
	void waitEnter();
	//捲動軸
	void scrollBar(unsigned int totalPages, unsigned int nowPages, bool showArrow);
	//動畫是否結束。用於感知thread結束。
	bool aniEnd;
	//Blink PRESS START
	void blinkStart();
	//跟著UI執行的checker
	void routineRunner();
	//是否執行checker
	bool runRoutine;
	//獨立變數，以便destructor停止
	std::thread routineBuster;
	//Console Handler
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Predefined for Performance
	unsigned int horizontal;
	unsigned int vertical;
	unsigned int horizontalt;
	unsigned int verticalt;
	



};

#endif

