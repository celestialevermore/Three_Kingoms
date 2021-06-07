/**
	���� ���ط� ���
	@details	�������� ���� ���ط��� �ٸ� �Լ����� ���˴ϴ�.\n
				������ ������ �������� ��� PK_ȭ������ ����� �������ϴ�.(���� Ư�� ���� �� ���ط��� 90% ���������� �����δ� �ݰ��� ��ó�� ���̴� ������.)
	@param[out] damage	����� ����
	@param trap_id		���� #�ü�Id
	@param unit			�δ�
	@param target		��ǥ
	@param critical		ũ��Ƽ��
*/
void PK_���������(__damage damage, int trap_id, Unit unit, HexObject target, bool critical)
{
	int result = 0;
	int bakuyaku = 0; // ���࿬�� �ⱳ �߰� ���ط�

	if (target.isInstance(kTypeIdUnit))
	{
		bakuyaku = 300;
		switch (trap_id)
		{
		case �ü�_�Ҿ�:
		case �ü�_ȭ��:
			result = 300 + rand(100) + 50;
			break;

		case �ü�_ȭ����:
			result = 400 + rand(200) + 50;
			break;

		case �ü�_ȭ����:
		case �ü�_ȭ��:
			result = 400 + rand(100) + 50;
			break;

		case �ü�_��ȭ��:
		case �ü�_��ȭ��:
			result = 500 + rand(200) + 50;
			break;

		case �ü�_����:
			result = 1500 + rand(500) + 50;
			break;

		default:
			result = 0 + rand(0) + 50;
			break;
		}
	}
	else
	{
		bakuyaku = 100;
		int hp = 0;
		switch (trap_id)
		{
		case �ü�_�Ҿ�:
			result = 100 + rand(100) + 50;
			break;

		case �ü�_ȭ����:
		case �ü�_ȭ��:
		case �ü�_ȭ��:
			result = 200 + rand(100) + 50;
			break;

		case �ü�_ȭ����:
		case �ü�_��ȭ��:
			result = 300 + rand(100) + 50;
			break;

		case �ü�_��ȭ��:
			result = 400 + rand(100) + 50;
			break;

		case �ü�_����:
			result = 800 + rand(1000) + 50;
			break;

		case �ü�_����:
			// ������ ����
			hp = Building(target).����;
			if (target.isInstance(kTypeIdBuilding) && hp > 0)
			{
				int n = hp - std::max(hp - rand(40) - 980, 1);
				result = std::max(n, 0);
			}
			break;

		default:
			result = 0 + rand(0) + 50;
			break;
		}
	}

	if (trap_id == �ü�_���� || trap_id == �ü�_����)
	{
		if (target.hasSkill(Ư��_�))
		{
			result = result / 2;
			damage.���Ư�� = Ư��_�;
		}
	}
	else
	{
		if (isalive(unit) && unit.hasTech(�ⱳ_���࿬��))
			result = result + bakuyaku;
		if (isalive(unit) && unit.hasSkill(Ư��_ȭ��))
			result = result * 2;

		if (target.hasSkill(Ư��_�))
		{
			result = result * 2;
			damage.���Ư�� = Ư��_�;
		}
		else if (target.hasSkill(Ư��_ȭ��))
		{
			result = 0;
		}
	}

	if (target.hasSkill(Ư��_����))
	{
		result *= 0.1;
		damage.���Ư�� = Ư��_����;
	}

	if (target.isInstance(kTypeIdUnit))
		damage.�������ط� = result;
	else
		damage.�������ط� = result;

	// ȸ������ ������ ��� ��ȿ
	if (isinstance(target, kTypeIdBuilding))
	{
		Building building(target);
		if (building.�ü� == �ü�_���� && !building.�Ǽ��Ϸ�)
			damage.�������ط� = 0;
	}
}