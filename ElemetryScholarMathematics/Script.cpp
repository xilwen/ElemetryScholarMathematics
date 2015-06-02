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
	ui->fullScreenDialog("�ͩR�O����O...");
	ui->fullScreenDialog("�γ\....", "�ڤ@�����H���N���F��...");
	ui->fullScreenDialog("�~�O�u�����F��C");
	ui->fullScreenDialog("����ı�o�ڥ������D....","�N�⥲���I�X�ܤj���N���C" );
	ui->fullScreenDialog("......", "....");
	ui->fullScreenDialog("..");


	ui->showDialog("������", "�A�ש�ӤF�C", 0, true, 1, false);
	ui->showDialog("������", "�ڵ��A�ܤ[�F�~�~", 0, true, 1, false);

	/*�}�l�R�W*/
	ui->chooseNamae();
	ui->showDialog("������", "�󫢫����A�s��" + ui->getName() + "�O�ܡC�u�O�Ӧn�W�r�C", 0, true, 1, false);

	ui->showDialog(ui->getName(), "�X�ӧa�I�ڪ��D�A�b���̡I", 0, true, 1, false);
	ui->showDialog("��k��F�����W�j�N", "�����Ӫ����", 0, true, 1, false);
	ui->showDialog(ui->getName(), "���A�o�ܤֻ��A�����򥻨ƴN�X�ۧa�I", 0, true, 1, false);

	/*I part*/
	int a, b, answer;
	a = (rand() % 10 + 1);
	b = (rand() % 10 + 1);
	ui->showDialog("��k��F�����W�j�N", std::to_string(a) + "+" + std::to_string(b) + "����X?", 0, true, 1, false);
	
	//�[�ӭ�R�_�Ͳ��;��a

	//���D
	answer = ui->userChoice(ui->getName(), std::to_string(a + b), std::to_string(a*b), std::to_string(a - b), std::to_string(b-a), 0);
	if (answer == 0)
	{
		ui->showDialog("��k��F�����W�j�N", "�~�M��F�A�����N�n�δΡC", 0, true, 1, false);
	}
	else
	{
		ui->showDialog("��k��F�����W�j�N", "�����F�A���׬O" + std::to_string(a + b), 0, true, 1, false);
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
	}

	/*II part*/

	ui->showDialog("��R", "���S�O�f����", 0, true, 3, false);
	ui->showDialog(ui->getName(), "�ڤS���X�h�աI�ڤS���i�ӰաI��..", 0, true, 3, false);
	ui->showDialog("��R", "(�I�ڴx)", 0, true, 3, false);
	ui->showDialog(ui->getName(), "�y�y...���ڥX�D�I", 0, true, 3, false);

	//���D
	ui->clearScreen();
	SimpleArea fromUser;	//��user��J mode �� ����M��
	fromUser.ShowGraph();
	fromUser.AreaCalculating();
	getchar();
	getchar();
	
	if (ui->getName() == "�j����")
	{
		ui->showDialog("��R", "�A����򵹧A���o�ئW�r���A�j���ѡC", 0, true, 3, false);
	}
	
	ui->showDialog(ui->getName, "�ڦn���ߤ����ӪF���M�������Pı...");
	ui->showDialog(ui->getName, "�Pı�n��...", "�ڪ��H�ͧ��ܤF..");
	ui->showDialog("��R", "�ڤ]ı�o�ڪ��H�͡A�N�b�o��", "�g�U�F���I");
	ui->showDialog("��R", "�|�z�v�x����͹C��");
}

Script::~Script()
{
	delete ui;
}
