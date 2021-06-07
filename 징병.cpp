/**
	¡�� �� ���� �������� ����մϴ�.
	@param building ����
	@param actors ���� ����
*/
int PK_¡��_��������(Building building, const arrayptr<Person> &in actors)
{
	if (!isalive(building) || !isalive(actors[0]))
		return 0;

	City city = building.toCity();
	if (!isalive(city))
		return 0;

	int sum = 0, mul = 10;
	for (int i = 0; i < 3; i++)
	{
		if (isalive(actors[i]))
		{
			sum += actors[i].�ɷ�[��Ÿxml().¡���ɷ�];
			if (actors[i].hasSkill(Ư��_��))
				mul = 15;
		}
	}

	int result = city.ġ�� + 20;
	result *= sum;
	result *= 5;
	result /= 100;
	result += 1000;
	result *= mul;
	result /= 10;
	result *= func_5c4600(city);

	if (Scenario().���̵� == ���̵�_Ư�� && !city.isPlayer())
		result *= 2;

	if (building.hasEnemy())
		result /= 2;

	return result;
}

float func_5c4600(City city)
{
	int lv1 = 0, lv2 = 0;

	for (int i = 0; i < city.��������; i++)
	{
		Building building = city.������[i].�ǹ�;
		if (!isalive(building))
			continue;

		switch (building.�ü�)
		{
		case �ü�_����: if (building.�Ǽ��Ϸ�) lv1++; else 1; break;
		case �ü�_����2��: if (building.�Ǽ��Ϸ�) lv2++; else lv1++; break;
		case �ü�_����3��: if (building.�Ǽ��Ϸ�) 1; else lv2++; break;
		}
	}

	if (city.¡������ī��Ʈ > lv1 + lv2)
		return 1.5f;
	else if (city.¡������ī��Ʈ > lv1)
		return 1.2f;
	return 1.0f;
}

/**
	¡�� �� ������ ġ�� �������� ����մϴ�.
	@param city ����
	@param actors ���� ����
	@param troops ¡���� ���� ��(PK_�������� ��ȯ ��)
*/
int PK_¡��_ġ������(City city, const arrayptr<Person> &in actors, int troops)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (isalive(actors[i]))
			sum += actors[i].�ɷ�[��Ÿxml().¡���ɷ�];
	}
	return -(troops / (sum + 100));
}