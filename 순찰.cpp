/**
	���� �� ġ�� �������� ����մϴ�.
	@param building ����
	@param actors ���� ����
*/
int PK_����_ġ������(Building building, const arrayptr<Person> &in actors)
{
	if (!isalive(building) || !isalive(actors[0]))
		return 0;

	City city = building.toCity();
	if (!isalive(city))
		return 0;

	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		if (isalive(actors[i]))
			n += actors[i].�ɷ�[��Ÿxml().�����ɷ�];
	}
	n = n / 28 + 2;
	if (building.hasEnemy())
		n /= 2;
	return n;
}