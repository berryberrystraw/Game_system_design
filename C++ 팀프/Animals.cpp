#include "Animals.h"

// ������ ���ϴ� ������ ��ũ��
#define myabs(x) ((x) < 0 ? -(x) : (x))

// �䳢 Ŭ���� 
Rabbit::Rabbit(unsigned int iTeam) : Animal(2, 2, Animal::Rabbit, iTeam){
	// �ڵ� ���� 
}
bool Rabbit::Move(int ax, int ay, int bx, int by) const{
	// x�� �������� �̵� 
	if((ay == by) && (myabs(ax - bx) == 2)) return Animal::Move(ax, ay, bx, by);
	// y�� �������� �̵� 
	if((ax == bx) && (myabs(ay - by) == 2)) return Animal::Move(ax, ay, bx, by);
	// �밢�� �������� �̵� 
	if((myabs(ax - bx) == 2) && (myabs(ay - by) == 2)) return Animal::Move(ax, ay, bx, by);
}
bool Rabbit::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 2) || (myabs(ay - by) <= 2)){
		if(((myabs(ax - bx) == 1) && (myabs(ay - by) == 2)) || ((myabs(ay - by) == 1) && (myabs(ax - bx) == 2))){
			return false;
		}
		return true;
	}

	return false;
}

// ���� Ŭ���� 
Pig::Pig(unsigned int iTeam) : Animal(3, 2, Animal::Pig, iTeam){
	this->ability_range = 5;
}
bool Pig::Move(int ax, int ay, int bx, int by) const{
	// x�� �������� �̵� 
	if((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y�� �������� �̵� 
	if((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// �밢�� �������� �̵� 
	if((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Pig::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;
	
	return false;
}
// if((turn % 3)== 0) Pig::own_ability(ability_range);
void Pig::own_ability(int ability_range){
	//3�� ��� �ϸ��� �ڽ��� �߽����� 5*5 �ȿ� �ִ� ��� ��(���� �� ����)���� ü�� +1 => change(1, 0) �̿��ϱ� 
}

// �ϸ� Ŭ���� 
Hippo::Hippo(unsigned int iTeam) : Animal(4, 3, Animal::Hippo, iTeam){
	// �ڵ� ���� 
}
bool Hippo::Move(int ax, int ay, int bx, int by) const{
	// x�� �������� �̵� 
	if((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y�� �������� �̵� 
	if((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// �밢�� �������� �̵� 
	if((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Hippo::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;
	
	return false;
}
void Hippo::own_ability(bool enemy_survive){
	//���� ������ ����� hp�� 0���ϰ� �Ǿ� survive�� false�� �Ǹ� ���ݷ�+1, ü��+1 
	if(!enemy_survive) change(1, 1); 
}

// �ڳ��� Ŭ����
Elephant::Elephant(unsigned int iTeam) : Animal(4, 4, Animal::Elephant, iTeam){
	this->ability_range = 3;
}
bool Elephant::Move(int ax, int ay, int bx, int by) const{
	// x�� �������� �̵� 
	if((ay == by) && (myabs(ax - bx) == 1)) return Animal::Move(ax, ay, bx, by);
	// y�� �������� �̵� 
	if((ax == bx) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
	// �밢�� �������� �̵� 
	if((myabs(ax - bx) == 1) && (myabs(ay - by) == 1)) return Animal::Move(ax, ay, bx, by);
}
bool Elephant::Attack(int ax, int ay, int bx, int by) const{
	if((myabs(ax - bx) <= 1) || (myabs(ay - by) <= 1)) return true;
	
	return false;
}
/* Attack�Լ��� ���ϰ��� true�̸� �ڳ��� ���� ������ ���̹Ƿ�
   own_ability�Լ� ���� */ 
void Elephant::own_ability(int ability_range){
	//���� �� �ڽ��� �߽����� 3*3 �ȿ� �ִ� ��� ��(�Ʊ� �� ����) ü��-1
}
