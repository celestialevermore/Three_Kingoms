/**
	���� ���� �漺�� �������� ����մϴ�.
	@param building ����
	@param person ����(����, ����, �¼�, �Ϲ�, ���θ� �ش�)
*/
int PK_���������漺������(Building building, Person person)
{
	if (person.isKunshu())
		return 0;

	// ������ ���� Ư�� �����ڰ� ���� ��� �Ϲ� ������ �������� ����
	if (!person.isHoryo() && ����Id_isValid(building.getWhoHasSkill(Ư��_����)))
		return 0;

	// ���ְ� ���� ��� �������� ����(����� ������ ����)
	int kunshu_id = person.����;
	Person kunshu(kunshu_id);
	if (!isalive(kunshu))
		return 0;

	// �Ϲ� ������ �б⺰ ù �޿��� ������(1, 4, 7, 10��)
	if (!person.isHoryo() && !Scenario().isFirstMonthOfQuarter())
		return 0;

	// ���ָ� ģ���ϰų� �κ�, ������, �θ��ڽ� ������ ��� �������� ����
	if (person.isLike(kunshu_id) || person.isFuufu(kunshu_id) || person.isGikyoudai(kunshu_id) || person.isOyako(kunshu_id))
		return 0;

	// �Ϲ� �����̰� ���ֿ��� ���� 25 ����(����)
	if (!person.isHoryo() && person.getAishouDistance(kunshu_id) <= 25)
	{
		// �Ǹ��� ���� �̻��̰ų� �߸��� ���� ����
		if (person.�Ǹ� >= �Ǹ�_���� || person.�߸� <= �߸�_����)
		{
			// ���ָ� ���������� ������ �������� ����
			if (!person.isDislike(kunshu_id))
				return 0;
		}
	}

	// �ν���� �ⱳ�� ������ ��� 66% Ȯ���� ���� �� ��
	Force force(person.getForceId());
	if (isalive(force) && force.hasTech(�ⱳ_�ν����) && rand(3) >= 1)
		return 0;

	int n = rand(3);

	City city(building.toCity());
	if (isalive(city) && city.hasFacility(�ü�_������))
		n += 2;

	// ������ �Ǹ��� �ſ쳷�� �߸��� �ſ� ����
	if (kunshu.�Ǹ� == �Ǹ�_�ſ쳷�� && kunshu.�߸� == �߸�_�ſ����)
		n += (�Ǹ�_�ſ���� - person.�Ǹ�) / 2;

	n += rand(3);

	return -n;
}