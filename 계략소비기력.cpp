/**
	�跫�� �ʿ��� �Һ� ����� ����մϴ�.
	@param unit �δ�
	@param strategy #�跫Id
*/
int PK_�跫_�Һ���(Unit unit, int strategy)
{
	if (unit.hasSkill(Ư��_����))
		return 1;

	switch (strategy)
	{
	case �跫_ȭ��: return 10;
	case �跫_��ȭ: return 10;
	case �跫_����: return 15;
	case �跫_����: return 15;
	case �跫_����: return 10;
	case �跫_����: return 10;
	case �跫_����: return 20;
	case �跫_���: return 50;
	case �跫_����: return 50;
	}

	return 0;
}