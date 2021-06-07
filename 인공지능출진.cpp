/**
	���� ������ ���¼��� ����մϴ�.
	@details	��ȯ������ ���� ������ ���� ������ �������� �ʽ��ϴ�.
				������ ���ø� �˰����� ������ ������ ����������� ����˴ϴ�.(���������ϴ�.)
	@param building	����
	@param troops	���� ������ �ִ� ���¼�(���� �� �δ� ���� �� + max(���� �Ҽ� ���� ���� ��, ���� ����))
*/
int PK_���뺴��(Building building, int troops)
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	// �÷��̾� ���� ������ ��� �׻� ����
	if (building.isPlayer())
		character = ����_����;
	return troops * (Person(Force(building.getForceId()).����).���� + 3);
	*/

	return troops * 125 / 100;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

/**
	������ ���¼��� ����մϴ�.
	@details	���� �������� ���� �����ϴ� ���� ���� ���Ե˴ϴ�.
				�Ʒ� ǥ�� ���ø� �˰����� ���� �������δ� ������ �ƹ��� ���Ƶ� ��ǥ ���� ���� ���� 2�� ������ �����մϴ�.

				�����¼� 1000 ����
				���¼��������(���� <-> ����)\n����|100\n\n|80\n\n|60\n\n|40\n\n|20\n\n|2(�ּ�)\n\n
				-|-|-|-|-|-|-
				�ҽ�|1950|1850|1750|1650|1550|1460
				����|1800|1700|1600|1500|1400|1310
				���|1650|1550|1450|1350|1250|1160
				����|1500|1400|1300|1200|1100|1010
				�׸��� ������ ���ϰ� ���� ������ ����������� �����ϴ� ���� ���� �پ��ϴ�.(���������ϴ�.)
	@param src			���� ����
	@param src_rank		���� ���� ���� ����� ����
	@param dst			��ǥ ����
	@param dst_troops	��ǥ ���� ���� ���� ��(���� �� �δ� ���� �� + max(���� �Ҽ� ���� ���� ��, ���� ����))
*/
int PK_��������(Building src, int src_rank, Building dst, int dst_troops)
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	int a = Person(Force(src.getForceId()).����).����;
	int b = (3 - a) * 15;
	int c = src_rank / 2;
	int result = dst_troops + (dst_troops * (b + c) / 100);
	return std::max(result, 5000);
	*/

	// �� ����
	if (dst.getForceId() == -1)
	{
		// �����̳� �ױ��� ��� 1/5
		if (dst.toGate().p != 0 || dst.toPort().p != 0)
			return dst.�ִ뺴�� / 5;

		// ������ ��� �̿� ���ÿ� �� ������ �����Ѵٸ� 1/2
		Force force(src.getForceId());
		City city(dst.toCity());
		for (int i = 0; i < 6; i++)
		{
			if (city.�̿�[i] != -1 && force.isEnemy(City(city.�̿�[i]).getForceId()))
				return dst.�ִ뺴�� / 2;
		}

		// ������ ������ ��� 1/4
		return dst.�ִ뺴�� / 4;
	}

	// ���� �� ����(�ٸ� ���� �δ� ���� ������ ����)
	int src_force_id = src.getForceId();
	int dst_building_id = dst.getId();
	dst_troops = dst.����;
	for (auto i = Scenario().�δ�.begin(); i; i++)
	{
		if (i().getAreaBuildingId() == dst_building_id && i().getForceId() != src_force_id)
			dst_troops += i().����;
	}

	if (dst_troops > dst.�ִ뺴��)
		return dst_troops + dst_troops / 4;

	if (dst_troops * 2 > dst.�ִ뺴��)
		return dst.�ִ뺴�� + dst.�ִ뺴�� / 4;

	return std::max(dst_troops, dst.�ִ뺴�� / 4) * 3;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}