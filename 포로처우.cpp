/**
	��ǻ���� ����ó�� ����� ����մϴ�.
	@param prisoner ����
	@param info ����
	@sa
	@code
	__ptr class __4b1690
	{
	public:
		__get HexObject object;			// ���η� ���� ������Ʈ
		__get HexObject captured_by;	// ���θ� ���� ������Ʈ
		__get bool can_return;			// ��ȯ����
	};
	@endcode
*/
int PK_����ó��(Person prisoner, __4b1690 info)
{
	Person kunshu(info.captured_by.����);

	if (func_4ae3a0(prisoner, kunshu))
		return ����ó��_ó��;

	if (PK_���������(prisoner, kunshu, (info.can_return ? 1 : 2), 0))
		return ����ó��_���;

	if (func_4af5b0(prisoner, kunshu))
		return ����ó��_ó��;

	if (prisoner.isKunshu())
		return ����ó��_�ع�;

	if (!func_4b0740(info))
		return ����ó��_�ع�;

	return ����ó��_����;
}

/**
	@param prisoner ����
	@param kunshu ���θ� ���� ������ ����(���ظ� ���� '��'��� ǥ����)
*/
bool func_4ae3a0(Person prisoner, Person kunshu)
{
	if (!isalive(prisoner) || !isalive(kunshu))
		return false;

	// ���� ���θ� ������ ��� ó��
	if (kunshu.isDislike(prisoner.getId()))
		return true;

	if (!prisoner.isKunshu())
		return false;

	Force force(kunshu.getForceId());
	Force prisoner_force(prisoner.getForceId());

	if (!isalive(force) || !isalive(prisoner_force))
		return false;

	// ���ΰ� Ȳ���̰� ���� ������ Ȳ���� ��ȣ���� ��� ó��
	if (prisoner_force.���� == ����_Ȳ�� && force.isProtectingTheEmperor())
		return true;

	// ���� Ȳ���̰� ���ΰ� ������ Ȳ���� ��ȣ���� ��� ó��
	if (prisoner_force.isProtectingTheEmperor() && force.���� == ����_Ȳ��)
		return true;

	return false;
}

/**
	@param prisoner ����
	@param kunshu ���θ� ���� ������ ����(���ظ� ���� '��'��� ǥ����)
*/
bool func_4af5b0(Person prisoner, Person kunshu)
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	if (kunshu.������ == prisoner.������)
		return false;
	*/

	// ���� ó�� Ȯ���ϸ� ������ ���� -1��(�������� ����) ����鵵 ���õǾ�
	// ��������� �������� �ٸ� ����鸸 ó������ Ȯ���ϰԵ�.
	// �Ϻη� �׷������� �𸣰�����...
	if (kunshu.isGikyoudai(prisoner.getId()))
		return false;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if (kunshu.isFuufu(prisoner.getId()))
		return false;

	if (kunshu.isLike(prisoner.getId()))
		return false;

	int max_stat = 0, avg_stat = 0;
	for (int i = 0; i < ����ɷ�_��; i++)
	{
		int n = prisoner.�ɷ�[i];
		max_stat = std::max(max_stat, n);
		avg_stat += n;
	}
	avg_stat /= ����ɷ�_��;

	int deaths = 10;
	switch (Scenario().����)
	{
	case ����_����: deaths = 20; break;
	case ����_ǥ��: deaths = 10; break;
	case ����_����: deaths = 0; break;
	}

	if (prisoner.isKunshu())
	{
		int value = 0;
		value += (kunshu.�߸� + prisoner.�߸�) * 2;
		value -= (std::max(max_stat, 50) + std::max(avg_stat, 50)) / 2;
		value += (16 - kunshu.�Ǹ�) * 5;
		value -= deaths;
		value -= rand(20);
		return randbool(std::max(value, 0));
	}

	float value = 0;
	value += 100 - (std::max(max_stat, 50) + std::max(avg_stat, 50)) / 2;
	value -= std::max(prisoner.����, 20000) / 2000 * (kunshu.��� == ���_���� ? 1.5f : 1);
	value -= prisoner.�߸� * (kunshu.��� == ���_�Ǹ� ? 5 : 1);
	value -= rand(25) * (kunshu.��� == ���_���� ? 1.5f : 1);
	value -= deaths;
	return randbool(std::max(value, 0.f));
}

bool func_4b0740(__4b1690 info)
{
	// �����Ų��� ��� �ع�
	if (!info.can_return)
		return false;

	// ������ ������ ���θ� ����
	if (info.object.isInstance(kTypeIdBuilding))
	{
		// �δ밡 ������ �ƴ϶�� �ع�
		if (!info.captured_by.isInstance(kTypeIdUnit))
			return false;

		Building building(info.object);
		Unit unit(info.captured_by);
		int pay_sum = 0;

		// �δ� ������� ���� �հ�
		for (int i = 0; i < 3; i++)
		{
			Person member(unit.����[i]);
			if (!isalive(member) || member.�ź� < �ź�_���� || member.�ź� > �ź�_�Ϲ�)
				continue;

			int rank_id;
			Rank rank;

			rank_id = member.����;
			if (!����Id_isValid(rank_id))
				rank_id = ����_����;

			rank = rank_id;
			if (!isalive(rank))
				continue;

			pay_sum += rank.����;
		}

		// �δ밡 ��� �ִ� ���� ��� �հ�
		List<Person> list;
		list.init(����Ӽ�_�ź�, �ź�_����);
		list.remove_all_but(����Ӽ�_����, unit.getLocationId());
		pay_sum += (list.size() + 2) * 50;

		pay_sum *= 2;

		// ���� �����ϴٸ� �ع�
		if (unit.�� + building.�� < pay_sum)
			return false;
	}
	// �δ븦 ������ ���θ� ����
	else
	{
		HexObject captured_by(info.captured_by);
		Person leader;
		Building service;
		int pay_sum = 0;

		// 4b08a4
		if (captured_by.isInstance(kTypeIdUnit))
			leader = Unit(captured_by).����;
		else if (captured_by.isInstance(kTypeIdBuilding))
			leader = Building(captured_by).�¼�;
		else
			leader = captured_by.����;

		if (isalive(leader))
			service = leader.�Ҽ�;

		// ���θ� ���� ������Ʈ�� �Ҽ��� Ȯ�ε��� ����
		if (!isalive(service))
			return false;

		// �ҼӰ��� ������� ���� �հ�
		for (auto i = service.�Ҽӹ���.begin(); i; i++)
		{
			if (!isalive(i()) || i().�ź� < �ź�_���� || i().�ź� > �ź�_�Ϲ�)
				continue;

			int rank_id;
			Rank rank;

			rank_id = i().����;
			if (!����Id_isValid(rank_id))
				rank_id = ����_����;

			rank = rank_id;
			if (!isalive(rank))
				continue;

			pay_sum += rank.����;
		}

		// �ҼӰ��� ���� ��� �հ�
		List<Person> list;
		list.init(����Ӽ�_�ź�, �ź�_����);
		list.remove_all_but(����Ӽ�_����, service.getId());
		pay_sum += (list.size() + 2) * 50;

		pay_sum *= 2;

		// �Ҽ� �������� ��ȯ���� �� ���θ� ������ �� �ִ� ����� �����ϴٸ� �ع�
		if (service.�� < pay_sum)
			return false;
	}

	return true;
}