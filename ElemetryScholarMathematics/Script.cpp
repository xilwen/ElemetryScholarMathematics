#include "Script.h"


Script::Script()
{
	ui = new UI;
}

void Script::runScripts()
{
	ui->init();

	//demo code
	ui->fullScreenDialog("�ͩR�O����O...");
	ui->fullScreenDialog("�γ\....", "�ڤ@�����H���N���F��...");
	ui->fullScreenDialog("�~�O�u�����F��C");
	ui->fullScreenDialog("����ı�o�ڥ������D....","�N�⥲���I�X�ܤj���N���C" );
	ui->fullScreenDialog("......", "....");
	ui->fullScreenDialog("..");


	ui->showDialog("������", "�A�ש�ӤF�C");
	ui->showDialog("������", "�ڵ��A�ܤ[�F�~�~");

	/*�}�l�R�W*/
	ui->chooseNamae();
	ui->showDialog("������", "�󫢫����A�s��" + ui->getName() + "�O�ܡC�u�O�Ӧn�W�r�C");

	ui->showDialog(ui->getName(), "�X�ӧa�I�ڪ��D�A�b���̡I");
	ui->showDialog("��k��F�����W�j�N", "�����Ӫ����");
	ui->showDialog(ui->getName(), "���A�o�ܤֻ��A�����򥻨ƴN�X�ۧa�I");

	/*I part*/

	//�[�ӭ�R�_�Ͳ��;��a

	//���D
	if (ui->getName() == "�s�Ƥ�")
	{
		ui->showDialog("��k��F�����W�j�N", "�Q���N�ԯ��A���Ƿ|����ڡI");
		ui->dontB();
	}
	else
	{
		ui->showDialog("��k��F�����W�j�N", "���ڪ̥͡A�f�ڪ̤`!�z����~~");
		ui->dead();
	}

	/*II part*/

	ui->showDialog("��R", "���S�O�f����");
	ui->showDialog(ui->getName(), "�ڤS���X�h�աI�ڤS���i�ӰաI��..");
	ui->showDialog("��R", "(�I�ڴx)");
	ui->showDialog(ui->getName(), "�y�y...���ڥX�D�I");

	//���D
	if (ui->getName() == "�j����")
	{
		ui->showDialog("��R", "�A����򵹧A���o�ئW�r���A�j���ѡC");
	}
	else
	{
		ui->showDialog(ui->getName(), "��...������j���h�j�H");
	}

}

Script::~Script()
{
	delete ui;
}
