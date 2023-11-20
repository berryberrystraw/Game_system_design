#pragma once

class Animal{
	private:
		int hp; // ü�� 
		int attack_damage; // ���ݷ� 
		bool survive; // �������� Ȯ�� 
		unsigned int iType;
		unsigned int iTeam;
	public:
		enum{
			// 1~3�� �� �߰� 
			Rabbit = 4,
			Pig = 5,
			Hippo = 6,
			Elephant = 7
		};
		
		enum{
			player1 = 0,
			player2 = 1
		};
	
	protected:
		Animal(int hp, int attack_damage, unsigned int iType, unsigned int iTeam);
	
	public:
		Animal(const Animal &animal);		
		virtual bool Move(int ax, int ay, int bx, int by) const;
		virtual bool Attack(int ax, int ay, int bx, int by) const;
		// ������ ���� ���� ���ݷ¸�ŭ �������� �Դ� �Լ� 
		void damaged(int attack_damage);
		// ���� �ɷ� �� hp�� ���ݷ��� ��ȭ��Ű�� �ɷ��� ������ �Լ�(��, ����, ����, �ϸ�) 
		void change(int hp, int attack_damage);
		int get_attack_damage();
		bool get_survive();
		
	public:
		const unsigned int &Type = iType;
		const unsigned int &Team = iTeam;
};
