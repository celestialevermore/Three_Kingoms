/**
	�׺��ǰ� ����� ����մϴ�.
	@param[out] accurate ������ ���� ����� ��Ȯ���� ����
	@param actor ���๫��
	@param target ��ǥ����
	@param gold ��(�׻� 0)
	@return 0: ����, 1: ����, 2: ����
*/
int PK_�׺��ǰ���(bool &out accurate, Person actor, Force target, int gold)
{
	accurate = true;

	// 1��1 ��Ȳ�� ��� ����
	if (List<Force>().init(���¼Ӽ�_��ȣ, ����_��, ������_��������) <= 2)
		return 2;

	Force source(actor.getForceId());
	if (!isalive(source))
		return 2;

	if (Scenario().getElapsedYears() < 1)
		return 2;

	if (source.���ü� < target.���ü� * 4)
		return 2;

	if (source.���� < target.���� * 3)
		return 2;

	if (target.���ü� >= 5)
		return 2;

	Person target_kunshu(target.����);
	if (!isalive(target_kunshu))
		return 2;

	if (!source.hasNeighborCity(target))
		return 2;

	if (target_kunshu.isDislike(source.����))
		return 2;

	if (target_kunshu.isDislike(actor.getId()))
		return 2;

	switch (target.����)
	{
	case ����_����:
	case ����_��Ź:
	case ����_�尢:
	case ����_����:
	case ����_����:
	case ����_���:
	case ����_�հ�:
	case ����_��å:
	case ����_����:
		return 2;
	}

	if (target.���ü� <= 0)
		return 2;

	int goal_value = (target_kunshu.���� * 7) - (target.��ȣ��[source.getId()] / 4);

	int value = 0;
	value += (source.���ü� / target.���ü�) / 2;
	value += (source.���ü� - target.���ü�) / 5;
	value -= target_kunshu.getAishouDistance(actor.getId()) / 7;
	value += source.isProtectingTheEmperor() ? 10 : 0;
	value += func_5b3f40(actor, target_kunshu, 0, 10, 20);
	value += actor.�ŷ�;
	switch (Scenario().���̵�)
	{
	case ���̵�_���: value *= 0.8f; break;
	case ���̵�_Ư��: value *= 0.7f; break;
	}
	value /= 2;
	value += rand(value, gold, target.getId(), actor.getId(), actor.�Ҽ�, 0, 0, 0);

	if (value * 2 >= goal_value + 100)
		accurate = false;

	if (value >= goal_value + 100)
		return 0;

	if (value >= goal_value + 95)
		return 1;

	return 2;
}

// ��ǥ���� ���ֿ� ���๫���� ���迡 ���� ���ʽ�
int func_5b3f40(Person actor, Person target_kunshu, int bad, int good, int best)
{
	int actor_id = actor.getId();

	if (target_kunshu.isGikyoudai(actor_id) || target_kunshu.isFuufu(actor_id))
		return best;

	if (target_kunshu.isLike(actor_id))
		return good;

	if (target_kunshu.isDislike(actor_id))
		return bad;

	return 0;
}