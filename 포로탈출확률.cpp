/**
	���ΰ� Ż���� Ȯ���� ����մϴ�.
	@param person ����
*/
int PK_����Ż��Ȯ��(Person person)
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// �δ� ������ ��쿡�� Ż��
	/*
	Building building(person.getBuildingId());
	if (!isalive(building))
		return 0;
	*/
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	int n = person.���αⰣ;

	// 2���� �̸�
	if (n < 2)
		return 0;

	n -= 2;
	if (n < 1)
		n = 1;

	return std::max(n * n * std::max(person.����, person.����, 30) / 166, 1);
}