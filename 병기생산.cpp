/**
	���� ���귮�� ����մϴ�.
	@param city ����
	@param actors ���� ����
	@param weapon_id #����Id
*/
int PK_�������(City city, const arrayptr<Person> &in actors, int weapon_id)
{
	if (!����Id_isValid(weapon_id))
		return 0;

	if (weapon_id >= ����_����)
		return 1;

	int skill_id = -1;
	if (weapon_id <= ����_��)
		skill_id = ��Ÿxml().���������尣Ư��;
	else if (weapon_id == ����_����)
		skill_id = ��Ÿxml().������긶����Ư��;

	int sum = 0, max = std::INT32_MIN;
	bool has_skill = false;

	for (int i = 0; i < 3; i++)
	{
		if (!isalive(actors[i]))
			continue;

		int n = actors[i].�ɷ�[��Ÿxml().�������ɷ�];

		sum += n;
		max = std::max(max, n);

		if (actors[i].hasSkill(skill_id))
			has_skill = true;
	}

	int result = sum + max + 200;
	result *= 5;
	if (has_skill)
		result *= 2;
	result *= func_5c7040(city, weapon_id);

	if (Scenario().���̵� == ���̵�_Ư�� && !city.isPlayer())
		result *= 2;

	return result;
}

float func_5c7040(City city, int weapon_id)
{
	int lv1 = 0, lv2 = 0;

	switch (weapon_id)
	{
	case ����_â:
	case ����_��:
	case ����_��:
		for (int i = 0; i < city.��������; i++)
		{
			Building building = city.������[i].�ǹ�;
			if (!isalive(building))
				continue;

			switch (building.�ü�)
			{
			case �ü�_���尣: if (building.�Ǽ��Ϸ�) lv1++; else 1; break;
			case �ü�_���尣2��: if (building.�Ǽ��Ϸ�) lv2++; else lv1++; break;
			case �ü�_���尣3��: if (building.�Ǽ��Ϸ�) 1; else lv2++; break;
			}
		}
		if (city.������갡��ī��Ʈ > lv1 + lv2)
			return 1.5f;
		else if (city.������갡��ī��Ʈ > lv1)
			return 1.2f;
		break;

	case ����_����:
		for (int i = 0; i < city.��������; i++)
		{
			Building building = city.������[i].�ǹ�;
			if (!isalive(building))
				continue;

			switch (building.�ü�)
			{
			case �ü�_������: if (building.�Ǽ��Ϸ�) lv1++; else 1; break;
			case �ü�_������2��: if (building.�Ǽ��Ϸ�) lv2++; else lv1++; break;
			case �ü�_������3��: if (building.�Ǽ��Ϸ�) 1; else lv2++; break;
			}
		}
		if (city.�������갡��ī��Ʈ > lv1 + lv2)
			return 1.5f;
		else if (city.�������갡��ī��Ʈ > lv1)
			return 1.2f;
		break;
	}
	return 1.0f;
}