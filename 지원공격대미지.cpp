/**
	�������� ���ط��� ����մϴ�.
	@param[out] damage	����� ����
	@param unit			�δ�
	@param target_pos	��ǥ ��ǥ
*/
void PK_�������ݴ����(__damage damage, Unit unit, Point target_pos)
{
	Force force(unit.getForceId());
	HexObject target_object(target_pos);

	int atk = unit.����;
	Unit target_unit;
	Building target_base;

	if (target_object.isInstance(kTypeIdUnit))
		target_unit = target_object;
	else if (Building(target_object).isBase())
		target_base = target_object;
	
	// ��ǥ ������Ʈ�� �����Ѱ�� 10
	int _60 = 0;
	if (Map().isNeighbor(unit.getPos(), target_pos))
		_60 = 10;

	// �°�� ���� �޴� ��� 1
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	int _6c = 0;
	__func_5aed80 func_5aed80;
	func_5aed80.force_id = force.getId();
	if (Map().range(unit.getPos(), 0, 4, func_5aed80))
	{
		_6c = 1;
		damage.���ݷ»�� = true;
	}
	*/

	int _6c = 0;
	__func_5aed80 func_5aed80;
	func_5aed80.force_id = force.getId();
	func_5aed80.pos = unit.getPos();
	// 11�� ������ �ü�.xml���� ������ �� �ִ� ���� �ִ� ���� 10�̱� ������.
	// �������� �°�� �ϳ��� Ȯ���ϸ� ������ ������ ��� �ü��� ���ݷ� ��� ȿ���� ���� �� �ֱ� ������ �ִ� ���� �ȿ� �ִ� ��� �ü��� Ȯ���ؾ���.
	if (Map().range(unit.getPos(), 0, 11, RingCallbackType(func_5aed80.callback)))
	{
		_6c = 1;
		damage.���ݷ»�� = true;
	}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if (target_unit)
	{
		Force target_force(target_unit.getForceId());
		int facility_id = �ü�_��;
		if (target_force.hasTech(�ⱳ_�ü���ȭ))
			facility_id = �ü�_���;
		if (target_force.hasTech(�ⱳ_������ȭ))
			facility_id = �ü�_��ä;
		__func_5aedc0 func_5aedc0;
		func_5aedc0.force_id = target_force.getId();
		if (Map().range(target_unit.getPos(), 0, Facility(facility_id).���ط����ҹ��� + 1, RingCallbackType(func_5aedc0.callback)))
			damage.���ýü� = facility_id;
	}

	int troops = func_5aee10(unit);

	damage.ġ��Ÿ = false;

	if (target_unit)
	{
		int target_def = target_unit.���;
		int target_troops = func_5aee10(target_unit);
		float troops_damage = func_5aee60(atk, troops, _60, _6c, target_def, target_troops);

		switch (unit.����)
		{
		case ����_â:
			if (force.hasTech(�ⱳ_����â��))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_â���ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_��:
			if (force.hasTech(�ⱳ_�����غ�))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_�غ��ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_��:
			if (force.hasTech(�ⱳ_�����뺴))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_�뺴�ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_����:
			if (force.hasTech(�ⱳ_�����⺴))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_�⺴�ܷ�))
				troops_damage *= 1.10;
			break;
		}

		damage.�������ط� = int(troops_damage);

		// ��� Ư��, �ⱳ
		if (func_5af230(damage, unit, target_unit, -1))
			damage.�������ط� = 0;
		
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// ��� �����
		/*
		if (unit.hasSkill(Ư��_����))
			damage.������ط� = 5;
		if (unit.hasSkill(Ư��_��ǳ))
			damage.������ط� = 20;
		*/
		if (unit.hasSkill(Ư��_����))
			damage.������ط� = u::getSkillInt(unit, Ư��_����);
		if (unit.hasSkill(Ư��_��ǳ))
			damage.������ط� = u::getSkillInt(unit, Ư��_��ǳ);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		// ����ȹ��
		damage.����ȹ�� = damage.�������ط� = func_5aecc0(unit, target_unit);

		// Ư�� ���̵��� ��� 75%�� ����
		if (Scenario().���̵� == ���̵�_Ư�� && unit.isPlayer())
			damage.�������ط� = damage.�������ط� * 3 / 4;

		// ��ǥ�δ밡 � Ư�⸦ ������ ��� 50%�� ����
		if (target_unit.hasSkill(Ư��_�))
			damage.�������ط� = damage.�������ط� / 2;

		// �ü� �� ����� ����
		switch (damage.���ýü�)
		{
		case �ü�_��:
			damage.�������ط� = damage.�������ط� * 0.85; break;
		case �ü�_���:
			damage.�������ط� = damage.�������ط� * 0.75; break;
		case �ü�_��ä:
			damage.�������ط� = damage.�������ط� * 0.65; break;
		}
	}
	else if (target_base)
	{
		assert(false);
	}

	if (target_object.isInstance(kTypeIdBuilding))
	{
		assert(false);
	}

	// �ּ� ���� �����
	if (damage.�������ط� != 0)
		damage.�������ط� = std::max(damage.�������ط� / 2, rand(100) + 200);

	// �ּ� ���� �����
	if (damage.�������ط� != 0)
		damage.�������ط� = std::max(damage.�������ط� / 2, rand(10) + 20);
}