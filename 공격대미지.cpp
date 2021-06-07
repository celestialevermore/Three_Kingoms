/**
	���� ���ط��� ����մϴ�.
	@param[out] damage	����� ����
	@param unit			�δ�
	@param tactics_id	#����Id
	@param target_pos	��ǥ ��ǥ
	@param type			0 ����, 1 �ݰ�, 2 �ݰ�
	@param critical		0 ġ��Ÿ Ȯ�� ���, 1 ġ��Ÿ ���� ����, 2 ġ��Ÿ ���� ����
	@param ambush		0 ���, 1 ����
*/
void PK_���ݴ����(__damage damage, Unit unit, int tactics_id, Point target_pos, int type, int critical, bool ambush)
{
	Force force(unit.getForceId());
	HexObject target_object(target_pos);

	int atk;
	Unit target_unit;
	Building target_base;

	if (ambush)
		atk = std::max(unit.���� - 5, 1);
	else
		atk = unit.����;

	if (target_object.isInstance(kTypeIdUnit))
		target_unit = target_object;
	else if (Building(target_object).isBase())
		target_base = target_object;

	int _f4 = 0;
	if (����Id_isValid(tactics_id))
	{
		_f4 = Tactics(tactics_id).�δ���ݷ�;
		damage.�������� = randbool(PK_��������Ȯ��(unit, unit.getPos(), target_object, tactics_id));
	}
	// ��ǥ ������Ʈ�� �����Ѱ�� 10
	else if (Map().isNeighbor(unit.getPos(), target_pos))
	{
		_f4 = 10;
	}

	// �°�� ���� �޴� ��� 1
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	int _00 = 0;
	__func_5aed80 func_5aed80;
	func_5aed80.force_id = force.getId();
	if (Map().range(unit.getPos(), 0, 4, func_5aed80))
	{
		_00 = 1;
		damage.���ݷ»�� = true;
	}
	*/

	int _00 = 0;
	__func_5aed80 func_5aed80;
	func_5aed80.force_id = force.getId();
	func_5aed80.pos = unit.getPos();
	// 11�� ������ �ü�.xml���� ������ �� �ִ� ���� �ִ� ���� 10�̱� ������.
	// �������� �°�� �ϳ��� Ȯ���ϸ� ������ ������ ��� �ü��� ���ݷ� ��� ȿ���� ���� �� �ֱ� ������ �ִ� ���� �ȿ� �ִ� ��� �ü��� Ȯ���ؾ���.
	if (Map().range(unit.getPos(), 0, 11, RingCallbackType(func_5aed80.callback)))
	{
		_00 = 1;
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
		if (Map().range(target_unit.getPos(), 0, Facility(facility_id).�ִ���� + 1, RingCallbackType(func_5aedc0.callback)))
			damage.���ýü� = facility_id;
	}

	int troops = func_5aee10(unit);

	switch (critical)
	{
	case 0:
		// ���� ����
		if (����Id_isValid(tactics_id) && !damage.��������)
		{
			damage.ġ��Ÿ = false;
			break;
		}
		// �ݰ�
		if (type != 0)
		{
			damage.ġ��Ÿ = false;
			break;
		}
		damage.ġ��Ÿ = PK_����_ũ��Ƽ��(unit, target_object, tactics_id, !Map().isNeighbor(unit.getPos(), target_pos));
		break;
	case 2:
		damage.ġ��Ÿ = false;
		break;
	case 1:
		damage.ġ��Ÿ = true;
		break;
	}

	if (target_unit)
	{
		int target_def = target_unit.���;
		int target_troops = func_5aee10(target_unit);
		damage.������ = target_unit.����;
		float troops_damage = func_5aee60(atk, troops, _f4, _00, target_def, target_troops);

		switch (unit.����)
		{
		case ����_â:
			if (����Id_isValid(tactics_id))
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.���� == ����_��)
					troops_damage *= 0.85f;
				else if (target_unit.���� == ����_����)
					troops_damage *= 1.15f;
				*/
				if (target_unit.���� == ����_��)
					troops_damage *= ��Ÿxml().��_��;
				else if (target_unit.���� == ����_����)
					troops_damage *= ��Ÿxml().��_��;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}

			if (force.hasTech(�ⱳ_����â��))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_â���ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_��:
			if (����Id_isValid(tactics_id))
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.���� == ����_â)
					troops_damage *= 1.15f;
				else if (target_unit.���� == ����_����)
					troops_damage *= 0.85f;
				*/
				if (target_unit.���� == ����_â)
					troops_damage *= ��Ÿxml().��_��;
				else if (target_unit.���� == ����_����)
					troops_damage *= ��Ÿxml().��_��;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}

			if (force.hasTech(�ⱳ_�����غ�))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_�غ��ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_��:
			if (����Id_isValid(tactics_id))
			{
				if (����Id_to����Id(target_unit.����) == ����_����)
					troops_damage *= 0.85f;
			}

			if (force.hasTech(�ⱳ_�����뺴))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_�뺴�ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_����:
			if (����Id_isValid(tactics_id))
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.���� == ����_â)
					troops_damage *= 0.85f;
				else if (target_unit.���� == ����_��)
					troops_damage *= 1.15f;
				*/
				if (target_unit.���� == ����_â)
					troops_damage *= ��Ÿxml().��_��;
				else if (target_unit.���� == ����_��)
					troops_damage *= ��Ÿxml().��_��;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}

			if (force.hasTech(�ⱳ_�����⺴))
				troops_damage *= 1.15;
			else if (force.hasTech(�ⱳ_�⺴�ܷ�))
				troops_damage *= 1.10;
			break;

		case ����_����:
		case ����_�ְ�:
		case ����_����:
		case ����_����:
			if (����Id_isValid(tactics_id))
			{
				if (����Id_to����Id(target_unit.����) == ����_����)
					troops_damage *= 0.8f;
			}
			break;
		}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// Ư�� ���̵��� ��� 75%�� ����
		/*
		if (Scenario().���̵� == ���̵�_Ư�� && unit.isPlayer())
			troops_damage *= 0.75f;
		*/
		if (unit.isPlayer())
			troops_damage *= ��Ÿxml().������г�Ƽ[Scenario().���̵�];
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		if (type != 0)
		{
			if (type == 1)
				troops_damage *= 0.9f;
			else if (type == 2)
				troops_damage *= 0.4f;

			damage.�������ط� = int(troops_damage);

			// �ݰ� ��Ʈ�̱� ������ target_unit�� ������ ������ �δ븦 ����.
			// �򰥸��� �ʵ��� ����.
			if (target_unit.isInWater())
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.hasSkill(Ư��_����) && randbool(50))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_����;
				}
				*/
				if (target_unit.hasSkill(Ư��_����) && randbool(u::getSkillInt(target_unit, Ư��_����)))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_����;
				}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}
			else
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.hasSkill(Ư��_�޽�) && randbool(50))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_�޽�;
				}
				*/
				if (target_unit.hasSkill(Ư��_�޽�) && randbool(u::getSkillInt(target_unit, Ư��_�޽�)))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_�޽�;
				}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}
		}
		else
		{
			if (damage.ġ��Ÿ)
				troops_damage *= 1.15f;

			damage.�������ط� = int(troops_damage);

			// ��� Ư��, �ⱳ
			if (func_5af230(damage, unit, target_unit, tactics_id))
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
		}

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
		int target_troops;
		int target_def;
		int target_atk;
		func_5af0e0(target_atk, target_troops, _f4, target_def, target_base);
		damage.������ = target_base.����;
		float troops_damage = func_5aee60(atk, troops, _f4, _00, target_def, target_troops);

		if (unit.���� == ����_����)
		{
			troops_damage *= 1.8f;
		}
		else if (unit.���� == ����_����)
		{
			troops_damage *= 1.2f;
		}
		else
		{
			troops_damage = func_5aee60(atk, std::max(troops * 75 / 100, 1), _f4, _00, target_def, target_troops);

			switch (target_base.�ü�)
			{
			case �ü�_����:
				troops_damage *= 0.55f; break;
			case �ü�_����:
				troops_damage *= 0.45f; break;
			case �ü�_�ױ�:
				troops_damage *= 0.60f; break;
			}
		}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// Ư�� ���̵��� ��� 75%�� ����
		/*
		if (Scenario().���̵� == ���̵�_Ư�� && unit.isPlayer())
			troops_damage *= 0.75f;
		*/
		if (unit.isPlayer())
			troops_damage *= ��Ÿxml().������г�Ƽ[Scenario().���̵�];
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		if (type != 0)
		{
			if (type == 1)
				troops_damage *= 0.9f;
			else if (type == 2)
				troops_damage *= 0.4f;

			damage.�������ط� = int(troops_damage);

			// �ݰ� ��Ʈ�̱� ������ target_unit�� ������ ������ �δ븦 ����.
			// �򰥸��� �ʵ��� ����.
			if (target_unit.isInWater())
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.hasSkill(Ư��_����) && randbool(50))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_����;
				}
				*/
				if (target_unit.hasSkill(Ư��_����) && randbool(u::getSkillInt(target_unit, Ư��_����)))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_����;
				}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}
			else
			{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				/*
				if (target_unit.hasSkill(Ư��_�޽�) && randbool(50))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_�޽�;
				}
				*/
				if (target_unit.hasSkill(Ư��_�޽�) && randbool(u::getSkillInt(target_unit, Ư��_�޽�)))
				{
					damage.�������ط� = 0;
					damage.���Ư�� = Ư��_�޽�;
				}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			}
		}
		else
		{
			if (damage.ġ��Ÿ)
				troops_damage *= 1.15f;

			damage.�������ط� = int(troops_damage);
		}
	}

	if (target_object.isInstance(kTypeIdBuilding))
	{
		Building target_building = target_object;
		
		int edi = 5;
		if (����Id_isValid(tactics_id))
			edi = Tactics(tactics_id).�������ݷ�;
		else if (Map().isNeighbor(unit.getPos(), target_pos))
			edi = 0xf;

		float hp_damage;
		if (unit.���� == ����_���� || unit.���� == ����_���)
			hp_damage = func_5af050(atk, troops, _00, edi);
		else
			hp_damage = func_5aeff0(atk, troops, _00, edi);

		if (damage.ġ��Ÿ)
			hp_damage *= 1.15f;

		if (target_building.�ü� >= �ü�_�Ҿ� && target_building.�ü� <= �ü�_��ȭ��)
		{
			hp_damage *= 1.6f;
		}
		else if (target_building.�ü� >= �ü�_���� && target_building.�ü� <= �ü�_����3��)
		{
			hp_damage *= 1.1f;
		}
		else if (target_building.�ü� == �ü�_����)
		{
			hp_damage *= 0.7f;
		}
		else if (unit.���� != ����_���� && unit.���� != ����_���)
		{
			switch (target_building.�ü�)
			{
			case �ü�_����:
			case �ü�_���:
			case �ü�_�����:
			case �ü�_����:
				hp_damage *= 0.7f; break;
			case �ü�_�ױ�:
			case �ü�_��:
				hp_damage *= 0.8f; break;
			case �ü�_���:
				hp_damage *= 0.9f; break;
			case �ü�_����:
			case �ü�_��ä:
				hp_damage *= 0.6f; break;
			}
		}

		damage.�������ط� = int(hp_damage);

		if (target_building.�ü� == �ü�_���� && !target_building.�Ǽ��Ϸ�)
			damage.�������ط� = 0;

		// ����
		if (unit.hasTech(�ⱳ_����))
		{
			if (unit.���� >= ����_�� && unit.���� <= ����_����)
			{
				damage.�������ط� = damage.�������ط� * 1.4f;
				damage.�������ط� = damage.�������ط� * 1.4f;
			}
			else
			{
				damage.�������ط� = damage.�������ط� * 1.2f;
				damage.�������ط� = damage.�������ط� * 1.2f;
			}
		}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// Ư�� ���̵��� ��� 75%�� ����
		/*
		if (Scenario().���̵� == ���̵�_Ư�� && unit.isPlayer())
			damage.�������ط� = damage.�������ط� * 3 / 4;
		*/
		if (unit.isPlayer())
			damage.�������ط� = damage.�������ط� * ��Ÿxml().������г�Ƽ[Scenario().���̵�];
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	}
}

/***/
int func_5aecc0(Unit unit, Unit target_unit)
{
	if (isalive(unit) && isalive(target_unit) && unit.���� == ����_â && unit.hasTech(�ⱳ_��������))
	{
		int a = rand(unit.����) + unit.����;
		int b = std::max(unit.���� / 2, 1);
		int c = target_unit.����;
		int d = unit.�ִ뺴�� - unit.����;
		return std::min(a, b, c, d);
	}
	return 0;
}

/** ���ݷ� ��� ȿ���� ���� �ü� �˻� */
class __func_5aed80
{
	bool callback(Hex hex, Point pos)
	{
		Building building = hex.getBuilding();
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		/*
		return isalive(building) && building.�ü� == �ü�_�°�� && building.�Ǽ��Ϸ� && building.getForceId() == this.force_id;
		*/

		if (isalive(building) && building.�Ǽ��Ϸ� && building.getForceId() == this.force_id)
		{
			// �ü� �߽� ��ǥ���� Ȯ��
			if (pos != building.getPos())
				return false;

			if (�ü�xml(building.�ü�).���ݷ»��) {
				int max_range = Facility(building.�ü�).�ִ����;
				if (building.�ü� == �ü�_����)
					max_range++;
				if (Map().getDistance(this.pos, pos) <= max_range)
					return true;
			}
		}
		return false;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	}

	int force_id;
	Point pos;
};

/** ��, ���, ��ä �˻� */
class __func_5aedc0
{
	bool callback(Hex hex, Point pos)
	{
		Building building = hex.getBuilding();
		return isalive(building) && building.�Ǽ��Ϸ� && building.getForceId() == this.force_id && (building.�ü� == �ü�_�� || building.�ü� == �ü�_��� || building.�ü� == �ü�_��ä);
	}

	int force_id;
};

/** ���� ������ ���� �� */
int func_5aee10(Unit unit)
{
	Person leader(unit.����);
	if (isalive(leader))
		return std::min(leader.����, unit.����);
	return unit.����;
}

/***/
float func_5aee60(int src_atk, int src_troops, int a3, int a4, int dst_def, int dst_troops)
{
	float result = sqrt(a3 * 64.f);
	result += std::max((src_troops - dst_troops) / 2000, 0);

	int atk = std::max(src_atk, 40);
	int def = std::max(dst_def, 40);
	atk *= atk;
	def *= def;

	result += std::max((atk - def) / 300, 0);
	result += 50.f;
	result *= a4 + 10;

	atk = (src_troops / 100 + 300) * (src_atk + 50) * (src_atk + 50) / 100;
	def = (dst_troops / 100 + 300) * (dst_def + 50) * (dst_def + 50) / 100;
	int sum = atk + def;
	int tmp;
	if (atk >= def)
		tmp = atk * 100 / sum;
	else
		tmp = std::max(100 - (def * 100 / sum), 1);

	result *= tmp;

	float st0 = float(std::max(src_troops / 4, 1));
	st0 = std::min(sqrt(st0), 40.f);

	result *= st0;
	result /= 2100.f; // *= 0.0004761905
	result += src_troops / 200;
	return result;
}

/***/
float func_5aeff0(int src_atk, int src_troops, int a3, int a4)
{
	src_troops = std::max(src_troops, 1);
	float a = sqrt(src_atk * src_atk / 15.f);
	float b = sqrt(src_troops);
	float c = a3 + 10;
	float d = a4 * 4 + 100;
	return a * b * c * d / 10000;
}

/***/
float func_5af050(int src_atk, int src_troops, int a3, int a4)
{
	src_troops = std::max(src_troops, 1);
	float a = sqrt(src_atk * src_atk / 15.f);
	float b = sqrt(src_troops);
	float c = a3 + 10;
	float d = a4 * 4 + 100;
	return a * std::min(b, 40.f) * c * d / 10000 + (src_troops / 25) + b;
}

/***/
void func_5af0e0(int &out atk, int &out troops, int &out a3, int &out def, Building building)
{
	a3 = 10;

	Person taishu(building.�¼�);

	if (isalive(taishu))
	{
		atk = std::max(taishu.���� - 25, 40);
		def = std::max(taishu.��� - 25, 40);
		troops = std::min(building.����, taishu.����);
	}
	else
	{
		atk = 30;
		def = 30;
		troops = std::min(building.����, 7000);
		if (troops != 0)
			troops = std::max(troops, 500);
	}
}

/** ��� Ư��, �ⱳ */
bool func_5af230(__damage damage, Unit unit, Unit target_unit, int tactics_id)
{
	if (����Id_isValid(tactics_id))
		return false;

	Point pos = unit.getPos();
	Point target_pos = target_unit.getPos();

	if (target_unit.���� == ����_��)
	{
		// ȭ�����
		if (target_unit.hasTech(�ⱳ_ȭ�����))
		{
			if (!Map().isNeighbor(pos, target_pos) && randbool(30))
			{
				damage.���ⱳ = �ⱳ_ȭ�����;
				return true;
			}
		}

		// ū����
		if (target_unit.hasTech(�ⱳ_ū����))
		{
			if (Map().isNeighbor(pos, target_pos) && randbool(30))
			{
				damage.���ⱳ = �ⱳ_ū����;
				return true;
			}
		}
	}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// �ұ�
	/*
	if (target_unit.���� < 3000 && target_unit.hasSkill(Ư��_�ұ�) && randbool(50))
	{
		damage.���Ư�� = Ư��_�ұ�;
		return true;
	}
	*/
	if (target_unit.hasSkill(Ư��_�ұ�) && u::test_fukutsu(target_unit))
	{
		damage.���Ư�� = Ư��_�ұ�;
		return true;
	}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// �ݰ�
	/*
	if (damage.�������ط� < 500 && target_unit.hasSkill(Ư��_�ݰ�) && randbool(50))
	{
		damage.���Ư�� = Ư��_�ݰ�;
		return true;
	}
	*/
	if (target_unit.hasSkill(Ư��_�ݰ�) && u::test_kongou(target_unit, damage.�������ط�))
	{
		damage.���Ư�� = Ư��_�ݰ�;
		return true;
	}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	return false;
}