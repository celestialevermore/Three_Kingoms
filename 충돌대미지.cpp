/**
	�浹 ���ط� ���
	@param[out] damage	����� ����
	@param unit			������ �δ�
	@param target		ƨ�ܳ��� ������Ʈ�� �浹�� ������Ʈ
*/
void PK_�浹�����(__damage damage, Unit unit, HexObject target)
{
	// ������ ����
	damage._20 = -std::max(rand(unit.����) + unit.���� / 2, 1);
	
	if (target.isInstance(kTypeIdUnit))
	{
		int n = unit.���� * 2 - Unit(target).���;
		if (n < 20)
			n = 20;
		damage.�������ط� = std::max(n + rand(n), 1);
	}
	else if (target.isInstance(kTypeIdBuilding) && !Building(target).isTrap())
	{
		int n = unit.���� + rand(unit.���� / 2);
		n /= 2;
		damage.�������ط� = std::max(n, 1);
	}

	// ȸ������ ������ ��� ��ȿ
	if (isinstance(target, kTypeIdBuilding))
	{
		Building building(target);
		if (building.�ü� == �ü�_���� && !building.�Ǽ��Ϸ�)
			damage.�������ط� = 0;
	}
}