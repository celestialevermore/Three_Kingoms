/**
	�ǹ��� ����(�ݰ�) �� ���� ������� ����մϴ�.
	@param[out] damage	����� ����
	@param building		�ǹ�
	@param target		��ǥ
*/
void PK_�ǹ����ݴ����(__damage damage, Building building, HexObject target)
{
	// ������� ����
	if (target.isInstance(kTypeIdBuilding))
		assert(false);

	Unit unit(target);
	int troops_damage = 0;
	int atk;
	int def;
	int a3;
	int troops;

	switch (building.�ü�)
	{
	case �ü�_����:
	case �ü�_����:
	case �ü�_�ױ�:
		func_5af0e0(atk, troops, a3, def, building);

		troops_damage = int(func_5aee60(atk, troops, a3, 0, unit.���, func_5aee10(unit)) * 0.8);

		// Ȱ������ ��� �������� �δ뿡�� 0.8��
		if (����Id_to����Id(unit.����) == ����_����)
			troops_damage = int(troops_damage * 0.8);
		break;

	case �ü�_��:
	case �ü�_���:
	case �ü�_��ä:
	case �ü�_�ó�:
	case �ü�_�����:
	case �ü�_������:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	default:
		// �ڵ����� �����
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		troops_damage = func_5af370(building, unit);

		if (building.�ü� == �ü�_������)
			break;

		// Ȱ������ ��� �������� �δ뿡�� 0.8��
		if (����Id_to����Id(unit.����) == ����_����)
			troops_damage = int(troops_damage * 0.8);
		break;
	}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	// Ư���� ��� �÷��̾��� ���ݷ� 0.75��
	if (Scenario().���̵� == ���̵�_Ư�� && building.isPlayer())
		troops_damage = troops_damage * 3 / 4;
	*/
	if (building.isPlayer())
		troops_damage = int(troops_damage * ��Ÿxml().������г�Ƽ[Scenario().���̵�]);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		// ��ȭ ��, ����, �ױ�, ��, ���, ��ä�� ���ݷ� 2��
	if (building.hasTech(�ⱳ_��ȭ) && building.�ü� >= �ü�_���� && building.�ü� <= �ü�_��ä)
		troops_damage *= 2;

	damage.�������ط� = troops_damage;
}

// ����ü��� �δ� ���� ���ط� ���
int func_5af370(Building building, Unit unit)
{
	int atk = 0;
	int bonus = 0;

	switch (building.�ü�)
	{
	case �ü�_��:
		atk = 400;
		bonus = 300;
		break;

	case �ü�_���:
		atk = 600;
		bonus = 300;
		break;

	case �ü�_��ä:
		atk = 800;
		bonus = 300;
		break;

	case �ü�_�ó�:
		atk = 300;
		bonus = 300;
		break;

	case �ü�_�����:
		atk = 500;
		bonus = 400;
		break;

	case �ü�_������:
		atk = 900;
		bonus = 600;
		break;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	default:
		// �ڵ����� �����
		atk = 300;
		bonus = 300;
		break;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	}

	int max_hp = std::max(building.�ִ볻��, 1);
	int cur_hp = std::max(building.����, max_hp / 2);

	float result = float(cur_hp) / max_hp;
	result *= 152 - unit.���;
	result *= atk;
	result /= 132.f; // *= 0.7575758
	result += rand(bonus);

	return int(result);
}