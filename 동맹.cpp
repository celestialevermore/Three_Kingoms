/**
	���� ����� ����մϴ�.
	@param[out] accurate ������ ���� ����� ��Ȯ���� ����
	@param actor ���๫��
	@param target ��ǥ����
	@param gold ��
	@return 0: ����, 1: ����, 2: ����
*/
int PK_���Ͱ��(bool &out accurate, Person actor, Force target, int gold)
{
	accurate = true;

	Person target_kunshu(target.����);
	if (!isalive(target_kunshu))
		return 2;

	// ���� ������ ����
	if (func_5be0e0(actor.getForceId(), target.getId()) || func_5be0e0(target.getId(), actor.getForceId()))
		return 2;

	// ���� ������ �� Ư�Ⱑ ���� ��ǥ ���� ���ְ� ���� ���� ���ָ� ����
	if (!actor.hasSkill(Ư��_��) && target_kunshu.isDislike(actor.����))
		return 2;

	int goal_value = (110 - target.��ȣ��[actor.getForceId()]) * 2;

	int value = 0;
	value += func_5b3130(actor, target_kunshu, -1.f, 1.f, 1.5f) * 10.f;
	value += gold / 150;
	value -= target_kunshu.getAishouDistance(actor.getId()) / 5;
	value += actor.��ġ;
	switch (Scenario().���̵�)
	{
	case ���̵�_���: value *= 0.8f; break;
	case ���̵�_Ư��: value *= 0.7f; break;
	}

	if (value * 2 > goal_value)
		accurate = false;

	if (value > goal_value)
		return 0;

	// ���� ������ �� Ư�Ⱑ ����
	if (actor.hasSkill(Ư��_��))
	{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		/*
		// Ư�� ��� �÷��̾��� ��쿡�� 20%, ������ 100% ����
		if (Scenario().���̵� != ���̵�_Ư�� || !actor.isPlayer() || randbool(20))
			return 1;
		*/
		if (!actor.isPlayer() || randbool(����xml(actor.getId()).��[Scenario().���̵�]))
			return 1;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	}

	goal_value = (100 - target.��ȣ��[actor.getForceId()]) * 2;
	if (value > goal_value)
		return 1;

	return 2;
}

// src ������ dst ���� ������ ���η� ��� �ִ��� Ȯ��
bool func_5be0e0(int src, int dst)
{
	List<Person> list;
	if (list.init(����Ӽ�_�ź�, �ź�_����) <= 0)
		return false;

	for (auto i = list.begin(); i; i++)
	{
		if (i().������ != dst)
			continue;

		HexObject object(i().����);
		if (!isalive(object) || object.getForceId() != src)
			continue;

		return true;
	}

	return false;
}

// ��ǥ���� ���ֿ� ���๫���� ���迡 ���� ���ʽ�
float func_5b3130(Person actor, Person target_kunshu, float bad, float good, float best)
{
	int actor_id = actor.getId();

	if (target_kunshu.isGikyoudai(actor_id) || target_kunshu.isFuufu(actor_id))
		return best;

	if (target_kunshu.isLike(actor_id))
		return good;

	if (target_kunshu.isDislike(actor_id))
		return bad;

	return 0.f;
}