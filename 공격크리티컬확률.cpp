/**
	���� ũ��Ƽ�� ���θ� ����մϴ�.
	@param unit �δ�
	@param target ��ǥ ������Ʈ
	@param tactics #����Id
	@param ranged ���Ÿ� ���� ����
*/
bool PK_����_ũ��Ƽ��(Unit unit, HexObject target, int tactics, bool ranged)
{
	Unit target_unit;
	if (target.isInstance(kTypeIdUnit))
		target_unit = target;

	Hex hex(unit.getPos());

	int target_strength = ��Ÿxml().����ɷ�ġ���� + 1;
	if (target_unit)
		target_strength = target_unit.getBestMemberStat(����ɷ�_����);

	// ����
	if (tactics >= 0 && tactics < ����_��)
	{
		// �п� Ư�� ����
		if (unit.hasSkill(Ư��_�п�))
			return true;
		// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
		if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
			return true;

		switch (unit.����)
		{
		case ����_â:
			// ���� Ư�� ����
			if (unit.hasSkill(Ư��_����))
				return true;
			// â�� Ư�� ����
			if (unit.hasSkill(Ư��_â��))
				return true;
			// â�� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_â��, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			break;

		case ����_��:
			// ���� Ư�� ����
			if (unit.hasSkill(Ư��_����))
				return true;
			// �ؽ� Ư�� ����
			if (unit.hasSkill(Ư��_�ؽ�))
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			break;

		case ����_��:
			// �ý� Ư�� ����
			if (unit.hasSkill(Ư��_�ý�))
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			break;

		case ����_����:
			// ��� Ư�� ����
			if (unit.hasSkill(Ư��_���))
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			break;

		case ����_����:
		case ����_����:
		case ����_����:
		case ����_���:
			// ���� Ư�� ����
			if (unit.hasSkill(Ư��_����))
				return true;
			break;

		case ����_�ְ�:
		case ����_����:
		case ����_����:
			// ���� Ư�� ����
			if (unit.hasSkill(Ư��_����))
				return true;
			// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
				return true;
			break;
		}
	}
	// ����, ����
	else
	{
		// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
		if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
			return true;
		// ���� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
		if (unit.getBestMemberStat(Ư��_����, ����ɷ�_����) > target_strength)
			return true;

		switch (unit.����)
		{
		case ����_����:
			// ���Ÿ� ����, �鸶 Ư�� ����
			if (ranged && unit.hasSkill(Ư��_�鸶))
				return true;
			break;
		}
	}

	// ���� Ư�� ����, �ü� ��ǥ
	if (unit.hasSkill(Ư��_����) && target.isInstance(kTypeIdBuilding))
		return true;

	// �δ� ��ǥ
	if (target_unit)
	{
		// ��, ���� Ư�� ����
		if (hex.���� == ����_�� && unit.hasSkill(Ư��_����))
			return true;
	}

	int result = 0;
	Person leader(unit.����);

	if (unit.���� >= 80)
		result = 2;
	else if (unit.���� >= 60)
		result = 1;

	result += unit.����;

	for (int i = 0; i < 2; i++)
	{
		int deputy = unit.����[i];
		if (!����Id_isValid(deputy))
			continue;

		if (leader.isGikyoudai(deputy) || leader.isFuufu(deputy))
			result += 4;
		else if (leader.isLike(deputy))
			result += 2;
		else if (leader.isDislike(deputy))
			result -= 5;
	}

	return randbool(std::max(result, 0));
}