//written by xilwen, qqwerfdsa930 and GODKING

#ifndef UI_H
#define UI_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


class UI
{
public:
	UI();

	//�I�s�C���}�l�e��
	void init();

	//��ܹ�ܮءA35�r�@��C
	void showDialog(std::string name, std::string text);
	//��ܮءA35�r���C
	void showDialog(std::string name, std::string text, std::string text0);
	//�t������ܮءC��������C���ݭn�������ܥ��W�L�i���Ѫ����ƧY�i�C
	void showDialog(std::string name, std::string text, int bear0, bool place0, int bear1, bool place1);
	//�t������ܮءC���������C���ݭn�������ܥ��W�L�i���Ѫ����ƧY�i�C
	void showDialog(std::string name, std::string text, std::string text0, int bear0, bool place0, int bear1, bool place1);
	//�t������ܮءC���溵�C���ݭn�������ܥ��W�L�i���Ѫ����ƧY�i�C
	void showDialog(std::string name, std::string text, int bear0);
	//�t������ܮءC����溵�C���ݭn�������ܥ��W�L�i���Ѫ����ƧY�i�C
	void showDialog(std::string name, std::string text, std::string text0, int bear0);

	//���ϥΪ̿�ܵ��סC
	int userChoice(std::string name, std::string option0, std::string option1, std::string option2, std::string option3, int bear);

	//���ù��L��ع�ܮءC����B��m�T�w�C���ݭn�ĤG��ХΪŦr��C
	void fullScreenDialog(std::string text, std::string text0);
	//���ù��L��ع�ܮءC����B��m�T�w�C
	void fullScreenDialog(std::string text);

	//���`�e���C
	void dead();
	//���˹G(�s�ƤѱM��)
	void dontB();

	//(X����ĳ)�b�e�������w�y�ЦL�X��r�C
	void print(std::string in, int x, int y);
	//(X����ĳ)�b�e�������w�y�ЦL�X���w�C�⪺��r�C
	void print(std::string in, int x, int y, int color);
	//�b�e���W��ܥ|�غ��Ctrue = ��, false = �k
	void printBear(int bear, bool place);
	//�b�e���W��ܥ|�غ��m���Ctrue = ��, false = �k
	void printBear(int bear);


	//�Ұʿ�W�r�����C
	void chooseNamae();
	//�M����ӿù�
	void clearScreen();
	~UI();

	//�^�ǥD���W�r(Accessor to name)
	std::string getName();
private:
	//�ѥX��r�C
	void print(std::string in);
	//��X���w��m����r�C
	void print(std::string in, int color);
	//�L����x
	void printBearbackend(int bear);

	//��X��r�ô���C
	void println(std::string);
	//��X���ϱM�δ���C
	void printlnb(std::string);

	//�e�خءA���Wx�I, y�I, ��(��V), ��(���V)
	void drawFrame(int lux, int luy, int length, int height);
	//���ʴ�Ш���w����m�C
	void gotoxy(int x, int y);
	//���o�{�b��Ц�m�C
	void getxy();
	//�^���������Ц�m
	void undoxy();
	//�s���getxy��ƨ��o��X,Y�b��T�C
	int nowx;
	int nowy;
	//�x�s�D�����W�r�C
	std::string name;
	//�x�s�b�W�r��ܤ������i��W�r���M��C
	std::vector<std::string> chars;
	//��ܮجO�_�N��ܨ��(�קK���ƼȰ�)�C�Ω�showdialog�C
	bool twoLinesInDialog;
	//��ܮجO�_���n��X���A�Y���h���M�e���C�Ω�showdialog�C
	bool showBearsinDialog;
	//�n�e���{�b����m
	int bearx;
	int beary;
};

#endif

