/**
	��� ���� ���θ� �����մϴ�.
	@param target ��ǥ����
	@param actor ���๫��
	@param type	Ÿ��|����
				-|-
				0|�Ϲ� ���
				1|����ó�� �޴� ���
				2|����ó�� �޴� ���(���� ���)
	@param seed ������ �õ�
*/
bool PK_���������(Person target, Person actor, int type, int seed)
{
	if (!isalive(target) || !isalive(actor))
		return false;

	if (!isalive(Person(actor.����)))
		return false;

	// Ư���� ���谡 �ִ��� Ȯ��
	bool special = false;
	if (func_4b0040(target, actor, type, special))
		return special;

	int giri = 10;
	if (type != 0)
		giri = std::min(15 - target.�Ǹ� * 2, 10);

	int n = std::min(func_5c6030(target, actor, type, seed) * giri / 10, 100);

	if (type != 0)
		return randbool(n);

	int n2 = rand(100, seed, target.getId(), actor.getId(), target.�漺��, actor.�ŷ�, actor.getAishouDistance(target.getId()), 0);

	return n2 < n;
}

bool func_4b0040(Person target, Person actor, int type, bool &out special)
{
	special = false;
	int force_id = target.getForceId();
	bool can_return = ����Id_isValid(force_id);

	// ���� ���
	if (type == 2)
		can_return = false;

	if (!isalive(target) || !isalive(actor))
		return true;

	// ���๫�� ������ ���� ����
	Person actor_kunshu(actor.����);
	if (!isalive(actor_kunshu))
		return true;

	// ���๫�� ������ ���ְ� ��� ���� ������
	if (target.����������� == actor_kunshu.getId())
		return true;

	// ��ǥ������ ������
	if (target.isKunshu() && can_return)
		return true;

	// ��ǥ���� ������ ����(2��)
	Person gikyoudai(target.������);
	if (isalive(gikyoudai) && gikyoudai != target)
	{
		// ��ǥ������ �������� ���� ������
		if (can_return && ����Id_isValid(force_id) && gikyoudai.getForceId() == force_id)
			return true;

		// ��ǥ������ ���๫�� ������ ���ֳ� ���๫��� ��������
		if (gikyoudai == actor_kunshu || gikyoudai == actor)
		{
			special = true;
			return true;
		}
	}

	// ��ǥ������ ����ڿ� ���� ������
	Person spouse(target.�����);
	if (isalive(spouse))
	{
		if (can_return && ����Id_isValid(force_id) && spouse.getForceId() == force_id)
			return true;
	}

	// ��ǥ������ �������� ���� ������(3�� �̻�)
	List<Person> gikyoudai_list;
	if (����Id_isValid(target.������))
	{
		gikyoudai_list.init(����Ӽ�_������, target.������);
		gikyoudai_list.remove(target);
	}

	if (can_return && isalive(gikyoudai) && ����Id_isValid(force_id) && gikyoudai_list.contains(����Ӽ�_����, force_id))
		return true;

	// ��ǥ������ �������� �̹� �ٸ� ���¿� �ҼӵǾ� ����
	if (isalive(gikyoudai) && gikyoudai != target)
	{
		int gikyoudai_force_id = gikyoudai.getForceId();
		if (can_return || force_id != gikyoudai_force_id)
		{
			if (����Id_isValid(gikyoudai_force_id) && actor_kunshu.getForceId() != gikyoudai_force_id)
				return true;
		}
	}

	// ��ǥ������ ����ڰ� �̹� �ٸ� ���¿� �ҼӵǾ� ����
	if (isalive(spouse))
	{
		int spouse_force_id = spouse.getForceId();
		if (can_return || force_id != spouse_force_id)
		{
			if (����Id_isValid(spouse_force_id) && actor_kunshu.getForceId() != spouse_force_id)
				return true;
		}
	}

	// ���๫�� ������ ���ֳ� ���๫���� ��ǥ������ �ſ�����
	if (isalive(spouse))
	{
		if (spouse == actor_kunshu || spouse == actor)
		{
			special = true;
			return true;
		}
	}

	// ��ǥ������ ���๫�� ���� ���ָ� ������
	if (target.isDislike(actor_kunshu.getId()))
		return true;

	// ��ǥ������ ���๫���� ������
	if (target.isDislike(actor.getId()))
		return true;

	if (type == 0)
	{
		// ��ǥ������ ���๫��� ��������
		if (target.isGikyoudai(actor.getId()) ||
			// ��ǥ������ ���๫�� ���� ���ֿ� ��������
			target.isGikyoudai(actor_kunshu.getId()) ||
			// ��ǥ������ ���๫��� �κ���
			target.isFuufu(actor.getId()) ||
			// ��ǥ������ ���๫�� ���� ���ֿ� �κ���
			target.isFuufu(actor_kunshu.getId()))
		{
			special = true;
			return true;
		}

		// ��ǥ������ �漺�� + �Ǹ� ���� 96 �̻���
		if (target.�漺�� + target.�Ǹ� >= 96)
			return true;

		// �������� ���๫�� ���¿� �ҼӵǾ� ����
		if (isalive(gikyoudai) && gikyoudai.getForceId() == actor_kunshu.getForceId())
		{
			special = true;
			return true;
		}

		// ����ڰ� ���๫�� ���¿� �ҼӵǾ� ����
		if (isalive(spouse) && spouse.getForceId() == actor_kunshu.getForceId())
		{
			special = true;
			return true;
		}

		// ��ǥ������ ���ָ� ģ����
		int target_kunshu_id = target.����;
		if (!target.isKunshu() && ����Id_isValid(target_kunshu_id) && target.isLike(target_kunshu_id))
			return true;

		// ��ǥ������ ���๫���� ģ����
		if (target.isLike(actor.getId()) ||
			// ��ǥ������ ���๫�� ���� ���ָ� ģ����
			target.isLike(actor_kunshu.getId()))
		{
			special = true;
			return true;
		}
	}
	else
	{
		// ���๫�� ���¿� �������� �ҼӵǾ� ����
		if (gikyoudai_list.contains(����Ӽ�_����, actor_kunshu.getForceId()))
		{
			special = true;
			return true;
		}

		// ���๫�� ���¿� ����ڰ� �ҼӵǾ� ����
		if (isalive(spouse) && spouse.getForceId() == actor_kunshu.getForceId())
		{
			special = true;
			return true;
		}

		if (can_return)
		{
			// ��ǥ������ ���ָ� ģ����
			int target_kunshu_id = target.����;
			if (!target.isKunshu() && ����Id_isValid(target_kunshu_id) && target.isLike(target_kunshu_id))
				return true;
		}

		// ��ǥ������ ���๫�� ���� ���ָ� ģ����
		if (target.isLike(actor_kunshu.getId()))
		{
			special = true;
			return true;
		}
	}

	return false;
}

int func_5c6030(Person target, Person actor, int type, int seed)
{
	if (!isalive(target) || !isalive(actor))
		return 0;

	int loyalty = target.�漺��;
	int aishou = 25;
	int giri = target.�Ǹ�;

	if (type == 2)
		loyalty = std::min(loyalty, 70);

	// ��ǥ������ ����̰ų� ����� ���� ������
	if (target.isZaiya() || (target.isHoryo() && !����Id_isValid(target.getForceId())))
		loyalty = Scenario().���̵� == ���̵�_�ʱ� ? 60 : 70;

	if (����Id_isValid(target.����))
		aishou = target.getAishouDistance(target.����);

	if (target.isZaiya())
		giri = �Ǹ�_����;

	int result = (aishou - target.getAishouDistance(actor.����)) / 5;
	result -= (giri + 18) * loyalty * 5 / 100;
	result += std::max(actor.�ŷ�, 30) * 3 / 5;
	result -= target.isLike(target.����) ? 15 : 0;
	result -= target.isOyako(target.����) ? 15 : 0;
	result += target.isDislike(target.����) ? 15 : 0;
	result += rand(�Ǹ�_�� - giri, actor.getId(), target.getId(), actor.�ŷ�, seed, actor.����, 0, 0);
	result += target.isHoryo() ? 15 : 0;
	result += 45;
	return std::max(result, 0);
}