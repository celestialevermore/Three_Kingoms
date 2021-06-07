namespace u {

/** Ư�� Ȯ�� */
bool hasSkill(const arrayptr<Person> &in member, int skill_id)
{
	for (int i = 0; i < 3; i++)
	{
		if (member[i] && member[i].hasSkill(skill_id))
			return true;
	}
	return false;
}

/** Ư�� ��� �ִ� �� */
int getSkillInt(const arrayptr<Person> &in member, int skill_id, int n = 0)
{
	int value = 0;
	for (int i = 0; i < 3; i++)
	{
		if (member[i] && member[i].hasSkill(skill_id))
			value = std::max(value, ����xml(member[i].getId()).getInt(skill_id, n));
	}
	return value;
}

/** Ư�� ��� �ִ� �� */
int getSkillInt(Unit unit, int skill_id, int n = 0)
{
	int value = 0;
	for (int i = 0; i < 3; i++)
	{
		int person_id = unit.����[i];
		Person person(person_id);
		if (isalive(person) && person.hasSkill(skill_id))
			value = std::max(value, ����xml(person_id).getInt(skill_id, n));
	}
	return value;
}

/** Ư�� ��� �ִ� �� */
float getSkillFloat(const arrayptr<Person> &in member, int skill_id, int n = 0)
{
	float value = 0;
	for (int i = 0; i < 3; i++)
	{
		if (member[i] && member[i].hasSkill(skill_id))
			value = std::max(value, ����xml(member[i].getId()).getFloat(skill_id, n));
	}
	return value;
}

/** Ư�� ��� �ִ� �� */
float getSkillFloat(Unit unit, int skill_id, int n = 0)
{
	float value = 0;
	for (int i = 0; i < 3; i++)
	{
		int person_id = unit.����[i];
		Person person(person_id);
		if (isalive(person) && person.hasSkill(skill_id))
			value = std::max(value, ����xml(person_id).getFloat(skill_id, n));
	}
	return value;
}

/** �ұ� ���� �� */
bool test_fukutsu(Unit unit)
{
	int n = 0;
	int troops = unit.����;
	for (int i = 0; i < 3; i++)
	{
		int person_id = unit.����[i];
		Person person(person_id);
		if (isalive(person) && person.hasSkill(Ư��_�ұ�))
		{
			if (troops < ����xml(person_id).getInt(Ư��_�ұ�, 0))
				n = std::max(n, ����xml(person_id).getInt(Ư��_�ұ�, 1));
		}
	}
	return randbool(n);
}

/** �ݰ� ���� �� */
bool test_kongou(Unit unit, int damage)
{
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		int person_id = unit.����[i];
		Person person(person_id);
		if (isalive(person) && person.hasSkill(Ư��_�ݰ�))
		{
			if (damage < ����xml(person_id).getInt(Ư��_�ݰ�, 0))
				n = std::max(n, ����xml(person_id).getInt(Ư��_�ݰ�, 1));
		}
	}
	return randbool(n);
}

} // namespace u