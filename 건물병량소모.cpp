/**
	�ǹ��� ���� �Ҹ��� ����մϴ�.
	@param building �ǹ�
	@bug ������ +-1 ������ �߻��� �� �ֽ��ϴ�.
*/
int PK_�ǹ������Ҹ�(Building building)
{
	if (!isalive(building) || !����Id_isValid(building.getForceId()))
		return 0;

	Person taishu(building.�¼�);
	float burned = 0.f;

	if (building.isOnFire())
	{
		int politics = 0;
		if (taishu)
			politics = taishu.��ġ;
		burned = (6.f - (politics / 20.f)) * building.���� / 100.f;
	}

	int n = building.���� / 40.f + burned;

	if (n <= 0 && building.���� > 0)
		return 1;

	return n;
}