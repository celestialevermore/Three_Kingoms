/**
	�δ� ������ ���� �ϼ��� ����մϴ�.
	���� ȭ��� �δ븦 ���������� ������ ���� �ϼ� ��꿡 ���˴ϴ�.
*/
int PK_�δ뺴�������ϼ�(int food, int troops)
{
	return food * 100 / troops;
}

/**
	�δ��� ���� �Ҹ��� ����մϴ�.
	@param unit �δ�
	@bug ������ +-1 ������ �߻��� �� �ֽ��ϴ�.
*/
int PK_�δ뺴���Ҹ�(Unit unit)
{
	if (!isalive(unit))
		return 0;

	float eat = 1.f;
	float burn = 0.f;

	if (unit.���� == �δ�����_����)
	{
		switch (func_49d8e0(unit))
		{
		case �ü�_��ä: eat = 1.f; break;
		case �ü�_���: eat = 4.f / 3.f; break; // 1.333...
		case �ü�_��: eat = 5.f / 3.f; break; // 1.666...
		default: eat = 2.f; break;
		}
	}

	if (unit.isOnFire())
		burn = (6.f - (unit.��ġ / 20.f)) * unit.���� / 100.f;

	int n = unit.���� * eat / 20.f + burn;

	if (n <= 0 && unit.���� > 0)
		return 1;

	return n;
}

// �ֺ��� ��, ��ä, ��� �˻�
int func_49d8e0(Unit unit)
{
	Force force(unit.getForceId());
	if (!isalive(force))
		return -1;

	int facility_id = �ü�_��;
	if (force.�ⱳ[�ⱳ_������ȭ])
		facility_id = �ü�_��ä;
	else if (force.�ⱳ[�ⱳ_�ü���ȭ])
		facility_id = �ü�_���;

	__func_49d870 func_49d870;
	func_49d870.facility_id = facility_id;
	func_49d870.force_id = unit.getForceId();

	if (Map().range(unit.getPos(), 1, Facility(facility_id).�ִ���� + 1, RingCallbackType(func_49d870.callback)))
		return facility_id;

	return -1;
}

class __func_49d870
{
	bool callback(Hex hex, Point pos)
	{
		if (!hex.hasBuilding())
			return false;

		Building building = hex.getBuilding();
		if (!isalive(building) || building.�ü� != facility_id || !building.�Ǽ��Ϸ� || building.getForceId() != force_id)
			return false;

		return true;
	}

	int facility_id;
	int force_id;
};