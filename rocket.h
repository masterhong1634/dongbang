#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"progressBar.h"
#define PLAYERSPEED 5


//���� :  ��������� ���� ������ ������ �ӵ��� ���ϵȴ�.
/*
	class A�� a.h�ְ� class B�� b.h�� �ִµ�
	B�� A�� ����ϰ� A�� B�� ����� ��� :���谡 �߸��Ǿ��ٰ� ���� �ִ�.
	����ڷ� �ϸ� �����ϱ⵵ ����� ������ �����.

	���̴� ���� �����͸� �˱����ؼ� ���� ������ �˾ƾ��ϰ� �� �� ����� ��Ŭ��� �ؾ��Ѵ�.
	������ �񿡼� �̹� ���̶�� ����� ��Ŭ��带 �ϰ� �ֱ⿡ ���̿��� ���� ����� ��Ŭ��� �ϸ� ��ȣ ���� ������ �ȴ�.
	������ �ٲ��� ������ ��Ŭ��� �Ҽ� ����.
	���̿��� �� ��Ŭ��� �Ѵٰ� �Ҷ� ���� �� ����� �����Ǹ� ��Ŭ��� �κе� 
	�̿����� �ޱ� ������ ������ ���������� ������ �ӵ��� ���ϵȴ�.
	�̰��� �ذ��ϱ� ���� ����� ���漱���̴�.
	(���� :  �����Ϸ��� ������Ͽ� ������ ���ܵ� �����ϴ� ������Ͽ����� ���������� �̷�� ���� �ʴ´�.)
	�� ���� �ؾ� ���� :  ���漱���� ��� �� Ŭ���� ���� ��ü�� ������������ �����ؾ� �Ѵ�.
	���� ���������� �ƴ� ��ü�� ������ ��� ���漱���� Ư¡�� �� ��ü�� ũ�⸦ ��Ȯ�� �ľ��Ͽ� �Ҵ��� �����ֱ�
	�����̴�.(�ش� Ŭ������ �ִٴ� ������ ����� �𸥴�.)
*/

//��ȣ������ �� �Ŵ��� Ŭ���� ���漱��
class enemyManager;
class rocket :public gameNode
{
private:
	image * _player;
	image * _player1;
	image * _destroy;
	missile* _missile;
	nuclear* _nuclear;
	skill* _skill;
	RECT rc;
	RECT temp; // �浹Ȯ�ο�.

	//���α׷����� 
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;

	int _maxLife = 3;


	enemyManager* _em;		//�� �Ŵ��� Ŭ���� ����


	int frame_count = 0;
	int frame_speed = 0;
	int missile_count = 0;
	int nuclear_count = 0;
	int skill_count = 3;//
	bool _isLeft = false;
	bool _isRight = false;

public:
	rocket();
	~rocket();

	HRESULT init();
	void release();
	void update();
	void render();

	//�̽� ����
	void removeMissile(int arrNum);
	//��ų ����
	void removeSkill(int arrNum);
	//�浹�Լ�
	void collision();
	void collision2();
	//�Ǳ�� �Լ�
	void hitDamage(float damage);

	//��Ŭ���� ��������
	nuclear* getMissile() { return _nuclear; }
	//
	skill* getSkill() { return _skill; }
	//���� �̹��� ��������
	image* getRocketImage() { return _player; }

	int getskill_count() { return skill_count; }

	RECT getRocketRect() // �浹��ų ĳ���� ����.
	{
		RECT rc1 = { rc.left + 22, rc.top + 20, rc.right - 22, rc.bottom - 30 };
		return rc1;
	}

	void setEnemyMemoryLink(enemyManager* em) { _em = em; }
};

