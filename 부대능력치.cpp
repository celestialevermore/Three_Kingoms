/**
	�δ� �ɷ�ġ ���.
	�ɷ�ġ�� ������ ��� ��� �ڵ����� �����˴ϴ�.
	@param[out] ability ���
	@param member ����
	@param weapon_id #����Id
	@param troops ����
	@param type #�δ�����Id
	@param status #�δ����Id
	@param navy ����δ�
	@param shoubyou ������
*/
void PK_�δ�ɷ�ġ(Unit__ac ability, const arrayptr<Person> &in member, int weapon_id, int troops, int type, int status, bool navy, bool shoubyou)
{
	Person leader = member[0];
	if (!isalive(leader))
		return;

	Force force = leader.getForceId();
	if (!isalive(force))
		return;

	if (!����Id_isValid(weapon_id) || !�δ�����Id_isValid(type) || !�δ����Id_isValid(status))
		return;

	// ���� ����
	if (bool(member[1]) || bool(member[2]))
	{
		// ���� ���谡 �ִٸ� �������� ����
		if (func_4960d0(leader, member[1]) || func_4960d0(leader, member[2]) || func_4960d0(member[1], member[2]))
		{
			for (int i = 0; i < ����ɷ�_��; i++)
				ability.�ɷ�[i] = leader.getStat(i, shoubyou);
		}
		// ���� ���谡 ���ٸ� ����
		else
		{
			for (int i = 0; i < ����ɷ�_��; i++)
			{
				int a = 0;
				int b = 0;
				int leader_stat = leader.getStat(i, shoubyou);

				// ���, ������ ���� ���迡 ���� ����
				if (i <= ����ɷ�_����)
				{
					if (member[1]) a = func_495ff0(leader, leader_stat, member[1], member[1].getStat(i, shoubyou));
					if (member[2]) b = func_495ff0(leader, leader_stat, member[2], member[2].getStat(i, shoubyou));
				}
				// ����, ��ġ, �ŷ��� �ִ밪
				else
				{
					if (member[1]) a = std::max(leader_stat, member[1].getStat(i, shoubyou));
					if (member[2]) b = std::max(leader_stat, member[2].getStat(i, shoubyou));
				}

				ability.�ɷ�[i] = std::max(a, b);
			}
		}
	}
	// ���� ����
	else
	{
		// ���� �ɷ�ġ �״�� ���
		for (int i = 0; i < ����ɷ�_��; i++)
			ability.�ɷ�[i] = leader.getStat(i, shoubyou);
	}

	for (int i = 0; i < ����_��; i++)
	{
		int max = 0;
		for (int j = 0; j < 3; j++)
		{
			if (member[j])
				max = std::max(max, member[j].����[i]);
		}
		ability.����[i] = max;
	}

	const float onethrid = (1.f / 3.f);
	const float twothrid = (2.f / 3.f);

	int tekisei = ability.����[����Id_to����Id(weapon_id)];
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	float tekisei_factor = (tekisei + 7) * 0.1f;
	*/
	float tekisei_factor = ��Ÿxml().�����δ�ɷ�[tekisei];
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	float status_factor = 1.0f;
	float type_factor1 = 1.0f;
	float type_factor2 = 1.0f;

	Equipment e(weapon_id);

	int atk = e.����;
	int def = e.���;
	int mov = e.�̵�;

	// �˺��̰ų� ���ۺδ�
	if (weapon_id == ����_�� || (weapon_id == ����_�ְ� && type == �δ�����_����))
		tekisei_factor = 0.6f;

	if (status == �δ����_ȥ��)
		status_factor = 0.8f;

	if (type == �δ�����_����)
	{
		type_factor1 = 0.4f;
		type_factor2 = onethrid;
	}

	if (weapon_id <= ����_����)
	{
		int tech_id = -1;
		switch (weapon_id)
		{
		case ����_â: tech_id = �ⱳ_����â��; break;
		case ����_��: tech_id = �ⱳ_�����غ�; break;
		case ����_��: tech_id = �ⱳ_�����뺴; break;
		case ����_����: tech_id = �ⱳ_�����⺴; break;
		}
		if (force.hasTech(tech_id))
		{
			atk += 10;
			def += 10;
		}
	}

	ability.�ɷ�[�δ�ɷ�_����] = int(std::max(1.f, ability.�ɷ�[�δ�ɷ�_����] * atk * tekisei_factor * 0.01f * type_factor1 * status_factor));
	ability.�ɷ�[�δ�ɷ�_���] = int(std::max(1.f, ability.�ɷ�[�δ�ɷ�_���] * def * tekisei_factor * 0.01f * type_factor2 * status_factor));
	float build = ((ability.�ɷ�[�δ�ɷ�_��ġ] * twothrid) + 50.f) * type_factor2 * status_factor;
	ability.�ɷ�[�δ�ɷ�_�Ǽ�] = int(std::max(1.f, build));

	if (type == �δ�����_����)
	{
		switch (weapon_id)
		{
		case ����_â:
			if (force.hasTech(�ⱳ_����â��))
				mov += 6;
			break;
		case ����_��:
			if (force.hasTech(�ⱳ_�����غ�))
				mov += 6;
			break;
		case ����_��:
			if (force.hasTech(�ⱳ_�����뺴))
				mov += 6;
			break;
		case ����_����:
			if (force.hasTech(�ⱳ_�����⺴))
				mov += 2;
			if (force.hasTech(�ⱳ_�縶����))
				mov += 4;
			break;
		case ����_����:
		case ����_����:
		case ����_����:
		case ����_���:
			if (force.hasTech(�ⱳ_���భȭ))
				mov += 4;
			break;
		}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		if (weapon_id <= ����_��)
		{
			mov += u::getSkillInt(member, Ư��_����);
		}
		else if (weapon_id == ����_����)
		{
			if (u::hasSkill(member, Ư��_����))
				mov += u::getSkillInt(member, Ư��_����);
			else if (u::hasSkill(member, Ư��_�౺))
				mov += u::getSkillInt(member, Ư��_�౺);
		}
	}
	else
	{
		if (force.hasTech(�ⱳ_�������))
			mov += 3;
		mov += 5;
		mov += u::getSkillInt(member, Ư��_���);
	}

	if (navy)
		mov += u::getSkillInt(member, Ư��_��Ÿ);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	ability.�ɷ�[�δ�ɷ�_�̵�] = mov;
}

// ���� ������ �����ϴ� ���谡 �ִ��� Ȯ��
bool func_4960d0(Person a, Person b)
{
	if (bool(a) && bool(b))
		return a.isDislike(b.getId()) || b.isDislike(a.getId());
	return false;
}

// ���迡 ���� �ɷ� ����
int func_495ff0(Person leader, uint8 leader_stat, Person deputy, uint8 deputy_stat)
{
	// ������ �ɷ�ġ�� ���庸�� ���ٸ� ���� ����
	if (leader_stat > deputy_stat)
		return leader_stat;

	int leader_id = leader.getId();
	int deputy_id = deputy.getId();

	if (leader.isGikyoudai(deputy_id) || leader.isFuufu(deputy_id))
		return deputy_stat;

	if (leader.isLike(deputy_id) || deputy.isLike(leader_id))
		return leader_stat + (deputy_stat - leader_stat) / 2;

	if (leader.isKetsuen(deputy_id))
		return leader_stat + (deputy_stat - leader_stat) / 3;

	if (leader.isDislike(deputy_id) || deputy.isDislike(leader_id))
		return leader_stat;

	return leader_stat + (deputy_stat - leader_stat) / 4;
}