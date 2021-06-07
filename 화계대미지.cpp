/**
	ȭ�� ���ط� ���
	@param[out] damage	����� ����
	@param unit			�δ�
	@param target		��ǥ
	@param critical		ũ��Ƽ��
*/
void PK_ȭ������(__damage damage, Unit unit, HexObject target, bool critical)
{
	Force target_force(target.getForceId());
	int atk;

	// ��ǥ������Ʈ�� �δ�
	if (target.isInstance(kTypeIdUnit))
	{
		atk = 300;
		damage.�������ط� = atk + rand(200);
	}
	// ��ǥ������Ʈ�� �ǹ�
	else
	{
		atk = 100;
		damage.�������ط� = atk + rand(50);
	}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	if (isalive(target_force) && target.hasTech(�ⱳ_���࿬��))
	{
		damage.�������ط� = damage.�������ط� + atk;
		damage.���ݱⱳ = �ⱳ_���࿬��;
	}
	*/
	if (��Ÿxml().���࿬�����׼��� ? isalive(unit) && unit.hasTech(�ⱳ_���࿬��) : isalive(target_force) && target.hasTech(�ⱳ_���࿬��))
	{
		damage.�������ط� = damage.�������ط� + atk;
		damage.���ݱⱳ = �ⱳ_���࿬��;
	}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	

	// ȭ�� Ư�⸦ �������̸� ����� 2��
	if (isalive(unit) && unit.hasSkill(Ư��_ȭ��))
	{
		damage.�������ط� = damage.�������ط� * 2;
		damage.����Ư�� = Ư��_ȭ��;
	}

	// ��ǥ������Ʈ�� � Ư�⸦ �������̸� ����� 2��
	if (target.hasSkill(Ư��_�))
	{
		damage.�������ط� = damage.�������ط� * 2;
		damage.���Ư�� = Ư��_�;
	}
	// ��ǥ������Ʈ�� ȭ�� Ư�⸦ �������̸� ��ȿ
	else if (target.hasSkill(Ư��_ȭ��))
	{
		damage.�������ط� = 0;
		damage.���Ư�� = Ư��_ȭ��;
	}

	// ȸ������ ������ ��� ��ȿ
	if (isinstance(target, kTypeIdBuilding))
	{
		Building building(target);
		if (building.�ü� == �ü�_���� && !building.�Ǽ��Ϸ�)
			damage.�������ط� = 0;
	}
}