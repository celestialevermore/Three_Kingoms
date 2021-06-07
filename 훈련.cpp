/**
	�Ʒ� �� ��� �������� ����մϴ�.
	@param building ����
	@param actors ���� ����
*/
int PK_�Ʒ�_�������(Building building, const arrayptr<Person> &in actors)
{
	if (!isalive(building) || !isalive(actors[0]))
		return 0;

	int sum = 0, max = std::INT32_MIN;
	for (int i = 0; i < 3; i++)
	{
		if (!isalive(actors[i]))
			continue;

		int n = actors[i].�ɷ�[��Ÿxml().�Ʒôɷ�];

		sum += n;
		max = std::max(max, n);
	}

	int result = sum + max;
	result /= std::min(building.���� / 2000 + 20, 100);
	result += 3;

	// �����Ұ� �ִٸ� 1.5��
	if (building.�ü� == �ü�_���� && building.toCity().hasFacility(�ü�_������))
		result = result * 3 / 2;

	return result;
}