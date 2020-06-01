#pragma once
#include"gameNode.h"
#include"progressBar.h"
//���ʹ� Ŭ������ ��ӹ޾Ƽ� ������ ���ϵ��� �����ȴ�.
class enemy : public gameNode
{
public :

	image * _image;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;
	int _count;
	bool _life = 1;

	//�������� �Ѿ� �߻��� ������
	int _fireCount;
	int _rndFireCount;


	// ���α׷�����
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;


public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();
	

	virtual void draw();
	virtual void animation();
	virtual void animation(int x, int y);

	bool bulletCountFire(int x);

	RECT getRect() { return _rc; }

	//�Ǳ�� �Լ�
	void hitDamage(float damage);

};

