/**
	����, ���� ������ ������ �� ����� Ȯ���� ����մϴ�.
	@param leader ������ ����� �δ��� ����
	@param target ��� �δ� ���� �� ������ 1��(���� Ư�� ������ ����)
	@param critical ũ��Ƽ�� ����
	@param tactics #����Id
*/
int PK_�⺴�������Ȯ��(Person leader, Person target, bool critical, int tactics)
{
	int result = 0;

	// ���� ������ Ȯ���ϴ� �κ��� ������ ������ �������� �ʽ��ϴ�.
	switch (tactics)
	{
	case ����_����: result += 1; break;
	case ����_����: result += 2; break;
	}

	if (Scenario().���� == ����_����)
		result += 2;

	if (critical)
		result += 2;

	switch (target.����)
	{
	case ����_�ҽ�: result -= 1; break;
	case ����_����: result += 1; break;
	}

	int diff = std::max(leader.���, leader.����) - std::max(target.���, target.����);

	// ��ǥ ���庸�� �ɷ�ġ ����
	if (diff <= 0)
		result -= 3;
	// ��ǥ ���庸�� �ɷ�ġ ����
	else if (diff <= 6)
		result -= 1;
	else if (diff <= 12)
		result += 0;
	else
		result += 1;

	return result;
}